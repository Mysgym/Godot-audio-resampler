#ifndef GODOTAUDIORESAMPLER_H
#define GODOTAUDIORESAMPLER_H

#include <godot_cpp/classes/object.hpp>
#include <speex/speex_resampler.h>

namespace godot {
	
	class Resampler : public Object{
		GDCLASS(Resampler, Object);

		protected:
			SpeexResamplerState *resampler = NULL;
			float resamplingFactor;
			
			static void _bind_methods();

		public:
			Resampler();
			//Can't expose constructor parameters to godot scripting, gotta have a separate init
			void init(unsigned int inputSampleRate, unsigned int outputSampleRate, uint8_t quality);
			~Resampler();
			PackedVector2Array resample(PackedVector2Array samples);

	};

}

#endif
