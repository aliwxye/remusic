#include <ArgParser.h>
#include <Application.h>
#include <vector>
#include <array>
#include <span>
#include <format>
#include <iostream>
#include <filesystem>

using namespace remusic;

static std::array<cag_option, 1> options = {
	cag_option{
		.identifier = 'l',
		.access_letters = "l",
		.access_name = "loop",
	},
};

static Remusic::Options intoAppOptions(const ParseResult& res) noexcept
{
	Remusic::Options opts{};
	for (const auto& option : res.options)
	{
		switch (option.identifier)
		{
			case 'l':
				opts.looped = true;
				break;
		}
	}
	return opts;
}

class Logger : public ILogger
{
	public:
		void log(LogLevel level, std::string_view message) override
		{
			switch (level)
			{
				using enum LogLevel;
				case INFO:
					std::cerr << std::format("INFO: {}\n", message);
					break;
				case WARNING:
					std::cerr << std::format("WARNING: {}\n", message);
					break;
				case ERROR:
					std::cerr << std::format("ERROR: {}\n", message);
					break;
				case FATAL:
					std::cerr << std::format("FATAL: {}\n", message);
					break;
			}
		}
};

int main(int argc, char* argv[])
{
	auto arguments = parse_args(argc, argv, std::span(options));
	if (arguments.additional_parameters.size() < 1)
	{
		std::cerr << "Input file was not provided\n";
		return -1;
	}

	Logger application_logger;
	auto app = Remusic(application_logger);
	app.attach_options(intoAppOptions(arguments));
	app.load_from_file(std::filesystem::path{arguments.additional_parameters[0]});
	app.run();
}
