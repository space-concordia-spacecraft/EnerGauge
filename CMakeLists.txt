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

pico_sdk_init()

# Build Pico test binaries
add_executable(blink_test tests/blink_test.c)
target_link_libraries(blink_test pico_stdlib)
pico_add_extra_outputs(blink_test)

add_executable(i2c_bus_test tests/i2c_bus_test.c)
target_link_libraries(i2c_bus_test pico_stdlib hardware_i2c)
pico_add_extra_outputs(i2c_bus_test)

add_executable(spi_bus_test tests/spi_bus_test.c)
target_link_libraries(spi_bus_test pico_stdlib hardware_spi)
pico_add_extra_outputs(spi_bus_test)

