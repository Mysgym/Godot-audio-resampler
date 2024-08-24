#include "register_types.h"

#include "resampler.h"

#include <gdextension_interface.h>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>

using namespace godot;

void initialize_resampler_module(ModuleInitializationLevel p_level){
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}

	ClassDB::register_class<AudioResampler>();	
}

void uninitialize_resampler_module(ModuleInitializationLevel p_level){
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}

	return;
}

extern "C" {

	GDExtensionBool GDE_EXPORT godot_resampler_library_init(GDExtensionInterfaceGetProcAddress p_get_proc_address,
		   	const GDExtensionClassLibraryPtr p_library,
			GDExtensionInitialization *r_initialization)
	
	{
		godot::GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);

		init_obj.register_initializer(initialize_resampler_module);
		init_obj.register_terminator(uninitialize_resampler_module);
		init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);	

		return init_obj.init();
	
	}


}
