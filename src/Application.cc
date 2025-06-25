#include <Application.h>
#include <Device.h>
#include <filesystem>

remusic::Remusic::Remusic(const ILogger& logger) noexcept : m_logger{logger}
{}

void remusic::Remusic::attach_options(const Options& options) noexcept
{
	m_options = options;
}

void remusic::Remusic::load_from_file(const std::filesystem::path& file) noexcept(false)
{
	// TODO
}

void remusic::Remusic::run() const noexcept(false)
{
	Device device;
	// TODO
}




