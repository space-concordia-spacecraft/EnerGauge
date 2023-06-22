# System Tasks
## Open Circuit Voltage Measurement
1. Fully charge batteries to recommended level.
2. Measure the OCV of the batteries.
3. Record OCV for each battery to SD card in mV into table C-6 to SD card.

## Closed-Circuit Voltage Measurement
1. Fully charge batteries to recommended level.
2. Setup programmable load to a constant current defined in data sheet.
3. Load batteries and wait for 30 seconds.
4. Record Closed-Circuit Voltages in mV into table C-7 to SD card

## Charge Cycling Test
### Carry out steps
1. Charge battery packs to max voltage using recommend current.
2. Maintain the batteries at constant charge voltage until the charge current drops below the manufacturer's recommended termination current.
3. Wait 10 mins for battery temp to stabilize.
4. Discharge the batteries at recommend rate to min voltage.
5. Repeat charge cycling test procedures as outlined in Nanoracks Test Requirements document on page 16.
6. Record Data To SD Card
		**Into table C-8:**
			* Capacity (mAh)
			* Temperature (C) 

# Requirements For System
- Allow tests to be user configurable.
- Allow tests to be user started.
- Record timestamped test data onto SD card.
- Display data in progress on display.
- Monitor space usage on SD card and alert user on high usage.
- Capture and record all battery monitoring and power supply data with a DAC system at 1 Hz.
