#ifndef _REMUSIC_H_
#define _REMUSIC_H_

#include <string_view>
#include <optional>

namespace remusic {
	class ILogger
	{
	public:
		enum class LogLevel
		{
			INFO,
			WARNING,
			ERROR,
			FATAL,
		};

		virtual void log(LogLevel level, std::string_view message) const noexcept = 0;
	};

	class Remusic final
	{
	public:
		Remusic(int argc, char* argv[], const ILogger& logger) noexcept(false);

		void run() noexcept(false);

	private:
		struct Options
		{
			bool looped;
		};

		Options process_arguments(int argc, char* argv[]) noexcept(false);
		Options m_options;
		const ILogger& m_logger;
	};
};

#endif
