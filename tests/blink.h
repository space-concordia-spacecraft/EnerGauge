//
// Created by william on 22/06/23.
//

#ifndef SC_BATTERY_TEST_JIG_BLINK_H
#define SC_BATTERY_TEST_JIG_BLINK_H

#include <stdio.h>
#include "pico/stdlib.h"

const uint LED_PIN = PICO_DEFAULT_LED_PIN;

void blink_init() {
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
}

void blink_led() {
    gpio_put(LED_PIN, 1);
    sleep_ms(250);
    gpio_put(LED_PIN, 0);
    sleep_ms(250);
}

#endif //SC_BATTERY_TEST_JIG_BLINK_H
