//
// Created by william on 01/07/23.
//

#ifndef SC_BATTERY_TEST_JIG_SX1508B__H
#define SC_BATTERY_TEST_JIG_SX1508B__H

namespace SX1508B {
    namespace DeviceAndIO {
        const unsigned int RegInputDisable = 0x00;
        const unsigned int RegLongSlew = 0x01;
        const unsigned int RegLowDrive = 0x02;
        const unsigned int RegPullUp = 0x03;
        const unsigned int RegPullDown = 0x04;
        const unsigned int RegOpenDrain = 0x05;
        const unsigned int RegPolarity = 0x06;
        const unsigned int RegDir = 0x07;
        const unsigned int RegData = 0x08;
        const unsigned int RegInterruptMask = 0x09;
        const unsigned int RegSenseHigh = 0x0A;
        const unsigned int RegSenseLow = 0x0B;
        const unsigned int RegInterruptSource = 0x0C;
        const unsigned int RegEventStatus = 0x0D;
        const unsigned int RegLevelShifter = 0x0E;
        const unsigned int RegClock = 0x0F;
        const unsigned int RegMisc = 0x10;
        const unsigned int RegLEDDriverEnable = 0x11;
    }
    namespace DebounceAndKeypadEngine {
        const unsigned int RegDebounceConfig = 0x12;
        const unsigned int RegDebounceEnable = 0x13;
        const unsigned int RegKeyConfig = 0x14;
        const unsigned int RegKeyData = 0x15;
    }
    namespace LedDriver {
        const unsigned int RegIOn0 = 0x16;
        const unsigned int RegIOn1 = 0x17;
        const unsigned int RegTOn2 = 0x18;
        const unsigned int RegIOn2 = 0x19;
        const unsigned int RegOff2 = 0x1A;
        const unsigned int RegTOn3 = 0x1B;
        const unsigned int RegIOn3 = 0x1C;
        const unsigned int RegOff3 = 0x1D;
        const unsigned int RegTRise3 = 0x1E;
        const unsigned int RegTFall3 = 0x1F;
        const unsigned int RegIOn4 = 0x20;
        const unsigned int RegIOn5 = 0x21;
        const unsigned int RegTOn6 = 0x22;
        const unsigned int RegIOn6 = 0x23;
        const unsigned int RegOff6 = 0x24;
        const unsigned int RegTOn7 = 0x25;
        const unsigned int RegIOn7 = 0x26;
        const unsigned int RegOff7 = 0x27;
        const unsigned int RegTRise7 = 0x28;
        const unsigned int RegTFall7 = 0x29;
    }
    namespace Miscellaneous {
        const unsigned int RegHighInput = 0x2A;
    }
    namespace SoftReset {
        const unsigned int RegReset = 0x7D;
    }
}

#endif //SC_BATTERY_TEST_JIG_SX1508B__H
