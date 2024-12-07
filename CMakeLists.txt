cmake_minimum_required(VERSION 3.26)
cmake_policy(SET CMP0048 NEW)

# Fetch libDaisy
include(FetchContent)
FetchContent_Declare(daisy

  # Replace this with the path to libDaisy
  SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}/../libDaisy
)
FetchContent_MakeAvailable(daisy)

# Our project declaration
project(daisy_firmware VERSION 0.0.1)

set(FIRMWARE_NAME ${CMAKE_PROJECT_NAME})
set(FIRMWARE_SOURCES
  src/main.cpp
  # add more source files here
)
set(DAISY_STORAGE flash) # other options are "qspi" and "sram"
set(DAISY_GENERATE_BIN TRUE)

# DaisyProject.cmake uses FIRMWARE_NAME and FIRMWARE_SOURCES to create a target called ${FIRMWARE_NAME}
include(DaisyProject)

target_include_directories(${FIRMWARE_NAME} PUBLIC include)
target_compile_features(${FIRMWARE_NAME} PUBLIC cxx_std_23)

set_target_properties(${FIRMWARE_NAME} PROPERTIES
  CXX_STANDARD 23
  CXX_STANDARD_REQUIRED YES
  CXX_EXTENSIONS YES
)
