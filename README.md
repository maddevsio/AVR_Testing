### Source repository for "MCU firmware testing" article
Branch with unity framework instead of native testing.

Requirements:

- AVR GNU Toolchain
- Unity Framework in `/usr/lib/unity/`

Project structure:

```
├── builds -  executable and firmware files
│   ├── firmware
│   └── tests
└── src
    ├── inc - firmware modules
    │   ├── adc.c
    │   ├── adc.h
    │   ├── calculate.c
    │   ├── calculate.h
    │   ├── lcd.c
    │   └── lcd.h
    ├── main.c
    ├── Makefile
    ├── obj - objects for firmware linker
    ├── test_obj - objects for testing executable linking
    └── tests
        ├── test.c
        └── test.h
  ```
