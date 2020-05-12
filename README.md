### Source repository for "MCU firmware testing" article
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
