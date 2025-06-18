# Xbox2PS-HID-Bridge

**BLE Xbox One S → DualShock 4 USB HID Emulator Bridge**

This firmware runs on an nRF52840 Sense to:

1. **Connect** over BLE to an **Xbox One S** controller  
2. **Translate** incoming HID reports into a **PS4 DualShock 4** USB-HID report  
3. **Enumerate** as a DS4 device when plugged into a PlayStation 4



## Building with Zephyr

1. Install [Zephyr SDK & toolchain].
2. `west init -m https://github.com/zephyrproject-rtos/zephyr`
3. `west update`
4. `cd app` (this repo)
5. `west build -b adafruit_feather_nrf52840_sense`
6. `west flash`



## License

This project is released under the [MIT License](LICENSE).  
