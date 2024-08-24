#ifndef GODOTAUDIORESAMPLER_H
#define GODOTAUDIORESAMPLER_H

#include <godot_cpp/classes/object.hpp>
#include <speex/speex_resampler.h>

namespace godot {
	
	class AudioResampler: public Object{
		GDCLASS(AudioResampler, Object);

		protected:
			SpeexResamplerState *resampler = NULL;
			float resamplingFactor;
			
			static void _bind_methods();

		public:
			AudioResampler();
			//Can't expose constructor parameters to godot scripting, gotta have a separate init
			void init(float inputSampleRate_f, float outputSampleRate_f, uint8_t quality);
			~AudioResampler();
			PackedVector2Array resample(PackedVector2Array samples);

	};

}

#endif
