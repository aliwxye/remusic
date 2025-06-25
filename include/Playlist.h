#ifndef _REMUSIC_PLAYLIST_H
#define _REMUSIC_PLAYLIST_H

#include <deque>
#include <filesystem>
#include <Sound.h>

namespace remusic
{
	class Playlist
	{
	public:
		Playlist() = default;

		void load_sound(const std::filesystem::path& song_path);
		const std::deque<Sound>& get_sounds() const noexcept;

	private:
		std::deque<Sound> m_sounds; 
	};
}

#endif
