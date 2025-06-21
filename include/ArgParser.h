#ifndef _ARGUMENT_PARSER_H_
#define _ARGUMENT_PARSER_H_

#include <optional>
#include <string>
#include <array>
#include <cargs.h>
#include <stdexcept>
#include <format>
#include <utility>
#include <vector>
#include <string_view>

namespace remusic
{

	struct ParsedOptions
	{
		char identifier;
		std::optional<std::string> value;

		ParsedOptions(char identifier, std::string_view value)
			: identifier{identifier}, value{value}
		{}
		ParsedOptions(char identifier)
			: identifier{identifier}, value{}
		{}
	};

	struct ParseResult
	{
		std::vector<ParsedOptions> options;
		std::vector<std::string> additional_parameters;

		ParseResult(std::vector<std::string> additional_parameters, std::vector<ParsedOptions> options)
			: additional_parameters{std::move(additional_parameters)}, options{std::move(options)}
		{}
	};

	template<std::size_t ARGS_LEN>
	ParseResult parse_args(int argc, char *argv[], const std::array<cag_option, ARGS_LEN>& opts) noexcept(false)
	{
		cag_option_context context;
		cag_option_init(&context, opts.data(), ARGS_LEN, argc, argv);

		std::vector<ParsedOptions> parsed_opts;
		parsed_opts.reserve(ARGS_LEN);
		std::vector<std::string> additional_parameters;
		additional_parameters.reserve(ARGS_LEN);

		while (cag_option_fetch(&context))
		{
			char identifier = cag_option_get_identifier(&context);
			for (const auto& i : opts)
			{
				if (identifier != i.identifier)
					continue;
				
				if (i.value_name) {
					const char* value = cag_option_get_value(&context);
					if (!value)
						throw std::invalid_argument(std::format("Option {} does not have value, but it\'s required", identifier));

					parsed_opts.emplace_back(identifier, value);
				} else {
					parsed_opts.emplace_back(identifier);
				}

				break;
			}
		}

		for (int param_index = cag_option_get_index(&context); param_index < argc; ++param_index)
			additional_parameters.emplace_back(argv[param_index]);
		return ParseResult{additional_parameters, parsed_opts};
	}
}

#endif
