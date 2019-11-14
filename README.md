# STM32-SID-PLAYER
SID and 6502 emulator, with audio output, for STM32 line of microcontrollers, compiled with Arduino IDE.

My personal project that i was having fun for some time now.
Mainly done for STM32F103C8 (Blue Pill). Should work with other STM32 microcontrollers that Arduino IDE support
Tested also at STM32F401CCU6 dev board.

-Only IRQ based sids can be played (no digis, emulator is not fast enough)
-Maximum size of sid is limited by microcontrollers RAM (16384 bytes for STM32F103C8T6, 62464 bytes for STM32F401CCU6)
-sid load address must be at $0400 or greater.
-filter emulation is far from real SID chip, but, for me, it sound enough "SID-ish".
-for now, it plays sid from internal flash memory. Sid file is converted to array.  converter used is bin2c that can be found at https://sourceforge.net/projects/bin2c/files/
-It is configurable. On first tab in Arduino IDE is values that can be changed to match microcontroller used.
Currently it's set for STM32F103C8.

I'm not good at C, so code is maybe a mess, but it works :-)
Code used for emulator is found at  http://rubbermallet.org/fake6502.c

reSID can be found at https://en.wikipedia.org/wiki/ReSID.
This is not reSID port, but i did used some parts of reSID code.





// SCHEMATICS:
//
//
//    .-----------------.
//    |                 |
//    | STM32FxxxXXxx   |
//    .------------|----.
//     |G         P|
//     |N         A|
//     |D         8--R1----|------C2---------> OUDIO OUT
//     |                   C
//     |                   1
//     .-------------------|----------------- GND
//                        GND
//    R1 = 100-500 Ohm
//    C1 = 100 nF
//    C2 = 10 uF
//    
// If <period> is 1 , AUDIO OUT can be connected to PA8 (no need for R1,C1 and maybe C2). I don't think 1Mhz sample rate will be in hearing range
  
HAVE FUN :-)
  
  
