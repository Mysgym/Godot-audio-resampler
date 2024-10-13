#!/usr/bin/env python
import os
import sys

try:
    Import("env")
except Exception:
    env = SConscript("godot-cpp/SConstruct")
    env["rootpath"]="."
    env["buildpath"] = ""

rootpath = env["rootpath"]
buildpath = env["buildpath"]

# For reference:
# - CCFLAGS are compilation flags shared between C and C++
# - CFLAGS are for C-specific compilation flags
# - CXXFLAGS are for C++-specific compilation flags
# - CPPFLAGS are for pre-processor flags
# - CPPDEFINES are for pre-processor defines
# - LINKFLAGS are for linking flags

# tweak this if you want to use different folders, or more folders, to store your source code in.
env.Append(CPPPATH=["src/"])
env.Append(CCFLAGS=["-I"+rootpath+"/inc","-I"+rootpath+"lib/inc"])

sources = Glob("src/*.cpp")


if env["platform"] == "macos":
    print("ERROR : This project doesn't support macos yet.")
if env["platform"] == "windows":
    print("INFO : Compiling for windows, unsure if this works")
    env.Tool('mingw')
    env.Append(CPPPATH=['#lib/inc'])
    env.Append(CXXFLAGS=['-fPIC'])
    env.Append(LIBPATH=['#lib/bin/windows'])
    env.Append(LIBS=['speex'])
    library = env.SharedLibrary(
        "addons/Godot-audio-resampler/libgodotaudioresampler{}{}".format(env["suffix"], env["SHLIBSUFFIX"]),
        source=sources,
    )

else:
    env.Append(CPPPATH=['/usr/include/speex'])
    env.Append(LIBPATH=['/usr/lib'])
    env.Append(LIBS=['speex', 'speexdsp'])
    library = env.SharedLibrary(
        "addons/Godot-audio-resampler/libgodotaudioresampler_linux_{}{}".format(env["suffix"], env["SHLIBSUFFIX"]),
        source=sources,
    )

    if(buildpath != ""):
        os.system("cp addons/Godot-audio-resampler " + buildpath + "/ -r")

Default(library)
