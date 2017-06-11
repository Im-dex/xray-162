# xray-162
XRay engine 1.6.2

## Build instructions
### Prerequisites
* CMake 3.8 or later
* DirectX SDK (June 2010)

> Be sure DirectX SDK installer added DXSDK_DIR environment variable.

### Visual Studio solution generation
Open command line at the root of repository and execute the following commands:

* mkdir build
* cd build
Visual Studio 2015:
 * x86: cmake .. -DBIN_PATH=%BIN_PATH% -G "Visual Studio 14 2015" -T "host=x64"
 * x64: cmake .. -DBIN_PATH=%BIN_PATH% -G "Visual Studio 14 2015 Win64" -T "host=x64"
Visual Studio 2017:
 * x86: cmake .. -DBIN_PATH=%BIN_PATH% -G "Visual Studio 15 2017" -T "host=x64"
 * x64: cmake .. -DBIN_PATH=%BIN_PATH% -G "Visual Studio 15 2017 Win64" -T "host=x64"

If you want to build utils projects add -DBUILD_UTILS=ON parameter to cmake command line.

Open generated solution and build the engine.

> %BIN_PATH% - path to your stalker bin folder.

If you have issues with openal when the game is starting, install extras\oalinst.exe.