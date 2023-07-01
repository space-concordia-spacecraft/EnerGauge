//
// Created by william on 22/06/23.
//

#include "comm_busses/I2CBus.h"

void I2C::init() {
    // Enable I2C 0 at 0.1 MHz and connect to GPIOs
    i2c_init(i2c_default, 100 * 1000);
    gpio_set_function(PICO_DEFAULT_I2C_SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(PICO_DEFAULT_I2C_SCL_PIN, GPIO_FUNC_I2C);
    gpio_pull_up(PICO_DEFAULT_I2C_SDA_PIN);
    gpio_pull_up(PICO_DEFAULT_I2C_SCL_PIN);

    bi_decl(bi_2pins_with_func(PICO_DEFAULT_I2C_SDA_PIN, PICO_DEFAULT_I2C_SCL_PIN, GPIO_FUNC_I2C));
}

uint8_t I2C::readByte(uint8_t deviceAddress, uint8_t registerAddress) {
    uint8_t readValue;

    i2c_write_blocking(i2c_default, deviceAddress, &registerAddress, sizeof(registerAddress), false);

    uint8_t byte_data;
    i2c_read_blocking(i2c_default, deviceAddress, &byte_data, 1, false);

    return byte_data;
}

uint16_t I2C::readWord(uint8_t deviceAddress, uint8_t registerAddress) {
    uint16_t readValue;
    uint16_t msb, lsb;

    i2c_write_blocking(i2c_default, deviceAddress, &registerAddress, sizeof(registerAddress), false);

    uint8_t *word_data;
    i2c_read_blocking(i2c_default, deviceAddress, word_data, 2, false);

    msb = (*word_data & 0x00FF) << 8;
    word_data++;
    lsb = (*word_data & 0x00FF);
    readValue = msb | lsb;

    return readValue;
}

bool I2C::writeByte(uint8_t deviceAddress, uint8_t registerAddress, uint8_t writeValue) {
    int result = i2c_write_blocking(i2c_default, deviceAddress, &registerAddress, sizeof(registerAddress), false)
            && i2c_write_blocking(i2c_default, deviceAddress, &writeValue, sizeof(writeValue), false);
    return result != PICO_ERROR_GENERIC;
}
