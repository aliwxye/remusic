#include <Sound.h>
#include <filesystem>
#include <stdexcept>

namespace fs = std::filesystem;
using namespace remusic;

Sound::Sound(const fs::path& path, const ma_decoder_config* config) noexcept(false) : m_path{path}
{
	if (ma_decoder_init_file(path.c_str(), config, &m_decoder) != MA_SUCCESS)
		throw std::runtime_error("Failed to initialize decoder");
}

void Sound::read_pcm_frames(void* pOutput, ma_uint64 frameCount, ma_uint64* pFramesRead) noexcept(false)
{
	if (ma_data_source_read_pcm_frames(&m_decoder, pOutput, frameCount, pFramesRead) != MA_SUCCESS)
		throw std::runtime_error("Failed to read pcm frames");
}

void Sound::set_next(Sound& other) noexcept(false)
{
	if (ma_data_source_set_next(&m_decoder, &other.m_decoder) != MA_SUCCESS)
		throw std::runtime_error("Failed to set next sound decoder");
}

Sound::~Sound()
{
	ma_decoder_uninit(&m_decoder);
}
