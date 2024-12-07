# Daisy Template
A template repo for creating new Daisy projects with CMake.

## How to use

### Requirements:
A modern version of the [Arm GNU Toolchain](https://developer.arm.com/downloads/-/arm-gnu-toolchain-downloads), installed either via download or the appropriate package manager like so:
#### Windows
```ps
winget install Arm.GnuArmEmbeddedToolchain
```
#### macOS
```bash
brew install arm-none-eabi-gcc
```
### VSCode Build
- Install the recommended extensions
- Run the "CMake: Scan for Kits" command from the command palette
- Run the "CMake: Select Kit" command from the command palette
- Select "GCC 13.3 arm-none-eabi"
- Run the "CMake: Configure" command from the command palette
- Run the "CMake: Build" Command from the command palette

Alternatively you can use the CMake tab in the sidebar and the UI.

### CLI Build
#### Configure
```
$ cmake -B build -G Ninja -D FETCHCONTENT_QUIET=OFF -D CMAKE_BUILD_TYPE=Debug CMAKE_C_COMPILER=path/to/arm-none-eabi-gcc CMAKE_CXX_COMPILER=path/to/arm-none-eabi-g++
```

#### Build
```
$ cmake --build build --target daisy_firmware-bin
```

### Upload
The output binary is at `build/daisy_firmware.bin`. It can be uploaded to the Seed using the [Daisy Web Programmer](https://electro-smith.github.io/Programmer/)
