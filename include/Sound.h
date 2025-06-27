#ifndef _REMUSIC_SOUND_H_
#define _REMUSIC_SOUND_H_

#include <filesystem>
#include <miniaudio.h>

namespace remusic
{
	class Sound
	{
	public:
		Sound(const std::filesystem::path& path) : Sound{path, nullptr} {}
		Sound(const std::filesystem::path& path, const ma_decoder_config* config) noexcept(false);

		Sound(const Sound& other) = delete;
		Sound& operator=(const Sound& rhs) = delete;

		void read_pcm_frames(void* pOutput, ma_uint64 frameCount, ma_uint64* pFramesRead) noexcept(false);
		void set_next(Sound& other) noexcept(false);

		virtual ~Sound();
	private:
		ma_decoder m_decoder;
		const std::filesystem::path m_path;
	};
}

#endif
