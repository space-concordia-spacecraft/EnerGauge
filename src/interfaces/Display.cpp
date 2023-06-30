//
// Created by william on 30/06/23.
//

#include "interfaces/Display.h"
#include "Definitions.h"
#include "comm_busses/SPIBus.h"

Display::Display() {
    gpio_init(DISPLAY_CS_PIN);
    gpio_set_dir(DISPLAY_CS_PIN, GPIO_OUT);

    gpio_init(DISPLAY_RS_PIN);
    gpio_set_dir(DISPLAY_RS_PIN, GPIO_OUT);

    initLCD();
}

void Display::initLCD()  {
    commWrite(0xA0);    // ADC select
    commWrite(0xAE);   // Display OFF
    commWrite(0xC8);   // COM direction scan
    commWrite(0xA2);   // LCD bias set
    commWrite(0x2F);   // Power Control set
    commWrite(0x21);   // Resistor Ratio Set
    commWrite(0x81);   // Electronic Volume Command (set contrast) Double Btye: 1 of 2
    commWrite(0x20);   // Electronic Volume value (contrast value) Double Byte: 2 of 2
    commWrite(0xAF);   // Display ON
}

void Display::dataWrite(unsigned char d) {
    gpio_put(DISPLAY_RS_PIN, HIGH);
    SPI::dataWrite(d, DISPLAY_CS_PIN);
}


void Display::commWrite(unsigned char d) //Command Output Serial Interface
{
    gpio_put(DISPLAY_RS_PIN, LOW);
    SPI::dataWrite(d, DISPLAY_CS_PIN);
}


void Display::displayPicture(unsigned char *lcd_string) {
    unsigned int i,j;

    unsigned char page = PAGE_START_ADDRESS;
    commWrite(DISPLAY_OFF);
    commWrite(DISPLAY_START_ADDRESS);         // Display start address + 0x40
    for(i=0;i<PAGES;i++) {
        commWrite(page);
        commWrite(COLUMN_ADDRESS_UPPER);       // column address upper 4 bits + 0x10
        commWrite(COLUMN_ADDRESS_LOWER);       // column address lower 4 bits + 0x00
        for(j=0;j<COLUMNS;j++) {
            if (lcd_string != nullptr) {
                dataWrite(*lcd_string);    // send picture data
                lcd_string++;
            } else {
                dataWrite(0x0);         // if nullptr, clear display
            }
        }
        page++;         // go to next page
    }
    commWrite(0xAF);

}

void Display::clearDisplay() {
    displayPicture(nullptr);
}