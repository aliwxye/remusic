#include <Playlist.h>
#include <Sound.h>
#include <fstream>

using namespace remusic;
namespace fs = std::filesystem;

void Playlist::load_sound(const fs::path& song_path) noexcept(false)
{
	Sound* prev = nullptr;
	if (!m_sounds.empty())
		prev = &m_sounds.back();

	try {
		m_sounds.emplace_back(song_path);
	} catch (...) {
		throw;
	}

	m_current = &m_sounds.back();
	if (prev)
		prev->set_next(*m_current);

	if (m_loop)
		m_current->set_next(m_sounds.front());
}

void Playlist::save(const std::filesystem::path& save_path) const noexcept(false)
{
	std::ofstream save(save_path);
	// serialization, etc.
}

const std::deque<Sound>& Playlist::get_sounds() const noexcept
{
	return m_sounds;
}

void Playlist::loop_toggle() noexcept
{
	m_loop = !m_loop;
}
