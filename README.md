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
* For Win32 build: cmake .. -DBIN_PATH=%BIN_PATH% -G "Visual Studio 14 2015" -T "host=x64"
* For Win64 build: cmake .. -DBIN_PATH=%BIN_PATH% -G "Visual Studio 14 2015 Win64" -T "host=x64"

If you want to build utils projects add -DBUILD_UTILS=ON parameter to cmake command line.

Open generated solution and build the engine.

> %BIN_PATH% - path to your stalker bin folder.

If you have issues with openal when the game is starting, install code\SDK\oalinst.exe.