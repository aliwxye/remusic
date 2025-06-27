#ifndef _REMUSIC_DEVICE_H_
#define _REMUSIC_DEVICE_H_

#include <Playlist.h>
#include <miniaudio.h>

namespace remusic {

	class Device
	{
	public:
		Device() : Device(nullptr) {}
		Device(ma_context* context) noexcept(false);
		void attach_playlist(const Playlist& playlist) noexcept;

		Device(const Device&) = delete;
		Device& operator=(const Device&) = delete;

		virtual ~Device();
	private:
		static void data_callback(ma_device*, void*, const void*, ma_uint32);

		ma_device m_device;
		Playlist m_playlist;
	};
}

#endif
