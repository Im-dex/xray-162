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
* cmake .. -DBIN_PATH=%BIN_PATH% -G "Visual Studio 14 2015" -T "host=x64"

Open generated solution and build the engine.

> %BIN_PATH% - path to your stalker bin folder.
