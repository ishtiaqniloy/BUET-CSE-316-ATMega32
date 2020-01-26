avr-gcc -g -Os -mmcu=atmega32 -c LCDandADC.c
avr-gcc -g -mmcu=atmega32 -o LCDandADC.elf LCDandADC.o
avr-objcopy -j .text -j .data -O ihex LCDandADC.elf LCDandADC.hex
avr-size --format=avr --mcu=atmega32 LCDandADC.elf
