#ifndef _REMUSIC_DEVICE_H_
#define _REMUSIC_DEVICE_H_

#include <miniaudio.h>
#include <Playlist.h>

namespace remusic {

	class Device
	{
	public:
		Device() : Device(nullptr) {}
		Device(ma_context* context) noexcept(false);

		void attach_playlist(const Playlist& playlist) noexcept;

		virtual ~Device();
	private:

		bool loop{false};
		ma_device m_device;
		Playlist m_playlist;
	};
}

#endif
