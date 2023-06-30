//
// Created by william on 30/06/23.
//

#include "comm_busses/SPIBus.h"
#include "Definitions.h"

void SPI::init() {
    gpio_init(SPI_SCLK_PIN);
    gpio_set_dir(SPI_SCLK_PIN, GPIO_OUT);

    gpio_init(SPI_MOSI_PIN);
    gpio_set_dir(SPI_MOSI_PIN, GPIO_OUT);
}

void SPI::dataWrite(unsigned char d, uint CS) {
    unsigned int n;
    gpio_put(CS, LOW);
    for(n=0;n<8;n++){
        if((d&0x80)==0x80)
            gpio_put(SPI_MOSI_PIN, HIGH);
        else
            gpio_put(SPI_MOSI_PIN, LOW);
        while(0);
        d=(d<<1);
        gpio_put(SPI_SCLK_PIN, LOW);
        while(0);
        gpio_put(SPI_SCLK_PIN, HIGH);
        while(0);
        gpio_put(SPI_SCLK_PIN, LOW);
    }
    gpio_put(CS, HIGH);
}