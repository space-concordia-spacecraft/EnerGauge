cmake_minimum_required(VERSION 3.25)

set(PICO_SDK_PATH $ENV{PICO_SDK_PATH})

# Fetch dependencies
IF(NOT PICO_SDK_PATH) # Only fetch if SDK is not already found on system
    include(FetchContent)

    set(PICO_SDK_COMMIT 6a7db34ff63345a7badec79ebea3aaef1712f374) # Version 1.5.1

    FetchContent_Declare(PICO_SDK
            GIT_REPOSITORY https://github.com/raspberrypi/pico-sdk
            GIT_TAG ${PICO_SDK_COMMIT})
    FetchContent_MakeAvailable(PICO_SDK)
    set(PICO_SDK_PATH $ENV{PICO_SDK_PATH})
ENDIF()

# Setup Project
include(${PICO_SDK_PATH}/pico_sdk_init.cmake)

project(sc_battery_test_jig CXX C ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Build Pico test binaries
pico_sdk_init()

# blink test program
add_executable(blink_test tests/blink_test.c)
target_link_libraries(blink_test pico_stdlib)
pico_add_extra_outputs(blink_test)

# I2C test program
add_executable(bus_test tests/bus_test.c)
target_link_libraries(bus_test pico_stdlib hardware_i2c)
pico_add_extra_outputs(bus_test)

