# Godot-rnnoise

This is a godot extension based on the [speex codec](https://www.speex.org) allowing for real-time resampling of audio signals.
<br>
## Building

This project is built using Scons, and requires an [speex](https://www.speex.org/downloads) static library. It should already be installed on most systems. 

  1 - Clone this repo and the godot-cpp submodule  
  ```
  git clone --recurse-submodules https://github.com/Mysgym/Godot-audio-resampler && cd Godot-audio-resampler
  ```

  2 - Build using scons.  
  (Godot-cpp sometimes doesn't compile correctly, try running the command again if you get a missing file)
  ```
  scons
  ```

  3 - Add the extension to your own project by copying the contents of the addons folder to your project's addons folder.  

Although this project has only been tested on linux, it should work on windows and macos provided a speex binary and minor adjustments to the SConstruct file.  
Windows and macOS support is currently a work in progress, I encourage anyone attempting to compile for those OS to report any encountered issue and create pull requests for functional builds.

## Usage

### Demo

### Methods detail
This extension adds a "Resampler" object to godot, which itself implements the following methods :

| Method definition | Method description |
| ------------------|--------------------|
|init(input : int, output : int, quality : int) | Initializes the resampler to use the specified input and output sampling rate. Quality should be set between 0 (worst) and 10 (best), 3 is a good middle ground for most uses.|
|resample(samples : PackedVector2Array) -> PackedVector2Array | returns the provided frame resampled, according to the initialized sampling rates|

<br>  

## Contributing

This project is being actively maintained, any reported issue and contributions are greatly appreciated.

Windows and macOS users are encouraged to attempt compilation and share their work as I personally lack easy access to those OS.  

## License

This project is MIT licensed.
