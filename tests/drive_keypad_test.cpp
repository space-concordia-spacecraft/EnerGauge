//
// Created by william on 01/07/23.
//

#include "interfaces/Keypad.h"
#include "blink.h"

int main() {
    stdio_init_all();

    blink_init();

    Keypad keypad;

    if (keypad.validate()) {
        keypad.setup(4, 4, 0b001, 0b001);
        while (1) {
            if (keypad.inputAvailable()) {
                KeyButton keyButton = keypad.getKeyInput();

                const char keyLetter = KEY_LETTERS[keyButton];

                printf("Key Pressed!: ");
                printf(&keyLetter);
                printf("\n\n\n");
            }
        }
    } else {
        blink_led();
        return 1;
    }
}