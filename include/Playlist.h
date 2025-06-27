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

		void save(const std::filesystem::path& save_path) const noexcept(false);

		void loop_toggle() noexcept;

	private:
		bool loop{false};
		std::deque<Sound> m_sounds; 
		Sound* m_current{nullptr};
	};
}

#endif
