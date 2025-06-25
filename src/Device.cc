#include <Device.h>
#include <miniaudio.h>
#include <stdexcept>

static void data_callback(ma_device* pDevice, void *pOutput, const void* pInput, ma_uint32 frameCount)
{
	// TODO
}

remusic::Device::Device(ma_context* context) noexcept(false)
{
	ma_device_config config = ma_device_config_init(ma_device_type_playback);
	config.playback.format = ma_format_unknown;
	config.playback.channels = 0;
	config.sampleRate = 0;
	config.dataCallback = data_callback;

	if (ma_device_init(context, &config, &m_device) != MA_SUCCESS)
		throw std::runtime_error("Failed to initialize device");
}

remusic::Device::~Device()
{
	ma_device_uninit(&m_device);
}
