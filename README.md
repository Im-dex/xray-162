# xray-1.7
XRay engine 1.7

[![Build status](https://ci.appveyor.com/api/projects/status/fo8iwn5bvcmgnh8e?svg=true)](https://ci.appveyor.com/project/Im-dex/xray-162)

## Branches
[master](https://github.com/Im-dex/xray-16) - stable code

[develop](https://github.com/Im-dex/xray-162/tree/develop) - latest, unstable and possibly broken code (time to time merged into master)

## Build instructions
### Prerequisites
* CMake 3.8 or later

### Supported compilers
* Visual C++ 15.2 (2017) and higher

### Visual Studio solution generation
Open command line at the root of repository and execute the following commands:

* mkdir build
* cd build
* x86: cmake .. -DBIN_PATH=%BIN_PATH% -G "Visual Studio 15 2017" -T "host=x64"
* x64: cmake .. -DBIN_PATH=%BIN_PATH% -G "Visual Studio 15 2017 Win64" -T "host=x64"

Open generated solution and build the engine.

> %BIN_PATH% - path to your stalker bin folder.
          
### Additional CMake command line options

#### BUILD_UTILS (boolean)
Enable utils projects build

#### REL_DEVELOP (boolean)
Switch the following useful options for development using RelWithDebInfo build configuration
* Enable incremental linking
* Disable LTCG
* Disable unreferenced function elimination by linker

If you have issues with openal when the game is starting, install extras\oalinst.exe.
