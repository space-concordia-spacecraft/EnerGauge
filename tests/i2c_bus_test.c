//
// Created by william on 22/06/23.
//

#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/binary_info.h"
#include "hardware/i2c.h"

#include "blink.h"

int main() {
    blink_init();

    // Enable I2C 0 at 0.1 MHz and connect to GPIOs
    i2c_init(i2c_default, 100 * 1000);
    gpio_set_function(PICO_DEFAULT_I2C_SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(PICO_DEFAULT_I2C_SCL_PIN, GPIO_FUNC_I2C);
    gpio_pull_up(PICO_DEFAULT_I2C_SDA_PIN);
    gpio_pull_up(PICO_DEFAULT_I2C_SCL_PIN);

    bi_decl(bi_2pins_with_func(PICO_DEFAULT_I2C_SDA_PIN, PICO_DEFAULT_I2C_SCL_PIN, GPIO_FUNC_I2C));

    while (true) {
        int ret;
        uint8_t addr = 0x6f;
        uint8_t rxdata;

        ret = i2c_read_blocking(i2c_default, addr, &rxdata, 1, false);

        puts(ret < 0 ? "found device" : "no device found");

        blink_led();
    }
}