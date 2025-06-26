#include <Application.h>
#include <Device.h>
#include <filesystem>

using namespace remusic;

Remusic::Remusic(const ILogger& logger) noexcept : m_logger{logger}
{}

void Remusic::attach_options(const Options& options) noexcept
{
	m_options = options;
}

void Remusic::load_from_file(const std::filesystem::path& file) noexcept(false)
{
	// TODO
}

void Remusic::run() const noexcept(false)
{
	// TODO
}




