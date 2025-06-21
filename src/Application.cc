#include <Application.h>
#include <ArgParser.h>
#include <cargs.h>
#include <array>
#include <stdexcept>
#include <format>

remusic::Remusic::Remusic(int argc, char* argv[], const ILogger& logger) noexcept(false) : m_logger{logger}
{
	m_options = process_arguments(argc, argv);
}

remusic::Remusic::Options remusic::Remusic::process_arguments(int argc, char* argv[]) noexcept(false)
{
	std::array<cag_option, 1> cag_opts
	{
		cag_option{
			.identifier='l',
			.access_letters="l",
			.access_name="loop"
		},
	};
	auto args = parse_args(argc, argv, cag_opts);
	Options parsed;
	for (const auto& i : args.options)
	{
		switch (i.identifier)
		{
			case 'l':
				parsed.looped = true;
				break;
			default:
				m_logger.log(ILogger::LogLevel::ERROR, std::format("Identifier {} not implemented", i.identifier));
				break;
		}
	}
	return parsed;
}

void remusic::Remusic::run() const noexcept(false)
{
	// TODO
}


