#include "resampler.h"

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;	 

Resampler::Resampler(){
}

void Resampler::init(unsigned int inputSampleRate, unsigned int outputSampleRate, uint8_t quality = 3){

	if(resampler != NULL){
		UtilityFunctions::printerr("GODOT AUDIO RESAMPLER ERROR : Double initialization of resampler");
		return;
	}

	if(quality < 0 || quality > 10){
		UtilityFunctions::printerr("GODOT AUDIO RESAMPLER ERROR : Quality must be between 0 (worst) and 10 (best)");
		return;
	}

	int err;	
	resampler = speex_resampler_init(2,inputSampleRate,outputSampleRate,quality,&err);
   	ERR_FAIL_COND(resampler == NULL);

	resamplingFactor = outputSampleRate/inputSampleRate;

}

Resampler::~Resampler(){
	
	if(resampler != NULL){
		speex_resampler_destroy(resampler);
	}
}


PackedVector2Array Resampler::resample(PackedVector2Array samples){
	
	if(resampler == NULL){
		UtilityFunctions::printerr("GODOT AUDIO RESAMPLER ERROR : Use of uninitialized resampler");
		return samples;
	}

	PackedVector2Array resampled;

	unsigned int resamplerInLength = samples.size();
	unsigned int resamplerOutLength = samples.size() * resamplingFactor;
	
	resampled.resize(resamplerOutLength);
	
	int err = speex_resampler_process_interleaved_float(
			resampler,
			(float*) samples.ptr(), &resamplerInLength,
			(float*) resampled.ptrw(), &resamplerOutLength	
			);
	
	if(err != RESAMPLER_ERR_SUCCESS){
		UtilityFunctions::printerr("GODOT AUDIO RESAMPLER ERROR : Speex error code ", err);
		return resampled;
	}

	return resampled;

}

void Resampler::_bind_methods(){
	
	ClassDB::bind_method(D_METHOD("resample"), &Resampler::resample);
	ClassDB::bind_method(D_METHOD("init"), &Resampler::init);

}
