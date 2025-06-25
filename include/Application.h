#ifndef _REMUSIC_H_
#define _REMUSIC_H_

#include <string_view>
#include <filesystem>
#include <Playlist.h>

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

		virtual void log(LogLevel level, std::string_view message) = 0;
	};

	class Remusic final
	{
	public:
		Remusic(const ILogger& logger) noexcept;

		struct Options
		{
			bool looped;
		};
		void attach_options(const Options& options) noexcept;

		void run() const noexcept(false);
		void load_from_file(const std::filesystem::path& file) noexcept(false);

	private:
		Options m_options;
		Playlist m_playlist;
		const ILogger& m_logger;
	};
};

#endif
