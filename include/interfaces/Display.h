//
// Created by william on 30/06/23.
//

#ifndef SC_BATTERY_TEST_JIG_DISPLAY_H
#define SC_BATTERY_TEST_JIG_DISPLAY_H

#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/binary_info.h"

#define DISPLAY_CS_PIN 27
#define DISPLAY_RS_PIN 17

class Display {
private:
    static const unsigned char DISPLAY_OFF = 0xAE;
    static const uint PAGES = 4; //32pixel display / 8 pixels per page = 4 pages
    static const uint COLUMNS = 128;

    static const unsigned char PAGE_START_ADDRESS = 0xB0;
    static const unsigned char DISPLAY_START_ADDRESS = 0x40;
    static const unsigned char COLUMN_ADDRESS_UPPER = 0x10;
    static const unsigned char COLUMN_ADDRESS_LOWER = 0x00;

    void initLCD();

    void dataWrite(unsigned char d);

    void commWrite(unsigned char d);

public:
    Display();

    void displayPicture(unsigned char *lcd_string);

    void clearDisplay();
};

#endif //SC_BATTERY_TEST_JIG_DISPLAY_H
