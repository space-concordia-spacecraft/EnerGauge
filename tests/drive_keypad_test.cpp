//
// Created by william on 01/07/23.
//

#include "interfaces/Keypad.h"

//void setup()
//{
//    Serial.begin(115200);
//    Serial.println("SX1509 Example");
//
//    Wire.begin();
//
//    // Call io.begin(<address>) to initialize the SX1509. If it
//    // successfully communicates, it'll return 1.
//    if (io.validate(SX1509_ADDRESS) == false)
//    {
//        Serial.println("Failed to communicate. Check wiring and address of SX1509.");
//        while (1)
//            ; // If we fail to communicate, loop forever.
//    }
//
//    // To initialize the keypad, call io.keypad(<rows>, <cols>)
//    // You can also define the duration of inactivity before the
//    // keypad engine sleeps, time spent scanning each row, and
//    // the debounce time per button.
//
//    // After a set number of milliseconds, the keypad engine
//    // will go into a low-current sleep mode.
//    // Sleep time range: 128 ms - 8192 ms (powers of 2) 0=OFF
//    unsigned int sleepTime = 256;
//    // Scan time defines the number of milliseconds devoted to
//    // each row in the matrix.
//    // Scan time range: 1-128 ms, powers of 2
//    byte scanTime = 2; // Scan time per row, in ms
//    // Debounce sets the minimum amount of time that must pass
//    // before a button can be pressed again.
//    // Debounce time range: 0.5 - 64 ms (powers of 2)
//    byte debounceTime = 1; // Debounce time
//    // Note: Scan time must be greater than debounce time!
//    // Take all of those values to set up the keypad engine:
//    io.keypad(KEY_ROWS, KEY_COLS, sleepTime, scanTime, debounceTime);
//
//    // Note: we don't get to pick which pins the SX1509 connects
//    // to each row/column. They go up sequetially on pins 0-7
//    // (rows), and 8-15 (cols).
//}
//
//void loop()
//{
//    // Use io.readKeypad() to check if any keys have been pressed:
//    unsigned int keyData = io.readKeypad();
//    // If keyData is 0, then nothing has been pressed. Otherwise
//    // at least two bits in the 16-bit value will be set, each
//    // corresponding to either a row or a column.
//    if (keyData != 0) // If a key was pressed:
//    {
//        // Use io.getRow(<readKeypad>) and io.getCol(<readKeypad>)
//        // to find the active row and columns:
//        byte row = io.getRow(keyData);
//        byte col = io.getCol(keyData);
//
//        // Once you've found out the active row/col, put them in
//        // keyMap to get the character pressed.
//        char key = keyMap[row][col];
//        Serial.println("Row: " + String(row));
//        Serial.println("Col: " + String(col));
//        Serial.print("Key: ");
//        Serial.println(key);
//    }
//}