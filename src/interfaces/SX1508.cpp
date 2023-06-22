//
// Created by william on 22/06/23.
//

#include "interfaces/SX1508.h"

void _SX1508::initSX1508() {
    gpio_init(KEY_ALERT_PIN);
    gpio_set_dir(KEY_ALERT_PIN, GPIO_IN);
//    gpio_set_irq_enabled_with_callback(KEY_ALERT_PIN, GPIO_IRQ_LEVEL_LOW, true, _SX1508::inputCallback);
// Interrupt is not necessary, can simply just check if the pins are active for triggering events. (create event listeners)
}
