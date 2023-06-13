SID chip (6581 and 8580) and 6502 CPU emulator, with audio output on pin PA8, for STM32 line of microcontrollers, compiled with Arduino IDE, uploaded with ST-LINK V2.

  -Only PSID V2 sids, no digis, emulator is not fast enough.

  -Maximum size of sid is limited by microcontrollers RAM

  -Sid load address must be at $0400 or greater.

  -Filter emulation is far from real SID chip, but, for me, it sound enough "SID-ish".

  -Plays sid from hardcoded folders from SD CARD. Use buttons or infrared remote control (NEC protocol) to switch to next tune/file/folder.

  -SID tune database can be found at  https://www.hvsc.c64.org/
  
Code used for emulator is found at http://rubbermallet.org/fake6502.c

reSID can be found at https://en.wikipedia.org/wiki/ReSID. This is not reSID port, but i did used some parts of reSID code.


In this fork I have added:
- LCD SSD1306
- rotary encoder
- I2C controlled digital potentiometer (DS1803) to control output volume
- voices LED (code from Nightfall Xad)

Compile with Arduino IDE, uploaded with ST-LINK V2.

SCHEMATICS for  STM32F411CE (not to scale) :

irPIN --> PB13

LED_VOICE_1 --> PB0 
LED_VOICE_2 --> PB1 
LED_VOICE_3 --> PB2 

LCD_SSD1306 I2C pins 
SCK --> PB6
SCL --> PB7

DS1803 I2C pins 
PIN 9 --> PB7 (SCL)
PIN 9 --> PB6 (SCK)

ROTARY_ENCODER
button --> PA4                                  
CLK    --> PA2                         
DT     --> PA3 



            .----------.
            |          |
            |  SSD1306 |
            |          |
            .----------.
               | |
               | |
               P P
               B B
               7 6
  .------------------------------------------------------.                                    +----------+
  |                                                      |--------< 3.3V  >-------------------| infrared |
  | STM32F411CE                                          |--------< irPIN >-------------------| receiver |
  .-----------------------|-|-|----|--|--|----|----------.--------< GND   >-------------------|          |
  |  P   P P P            P P P    P  P  P   P|                                               +----------+
  |  A   A A A            A A A    B  B  B   A|                                     .--------------.
  |  1   5 6 7            2 3 4    0  1  2   8.------|R1|---+---|C2|----------|12   |10            |
  |  |   | | -- SD_MOSI   | | |    |  |  |                  |           16.-------------------.9   |
  |  |   | ---- SD_MISO   rotary   |  |  |                  C             |     DS1803        |    | 
  |  |   ------ SD_CLK    enc      R2 R3 R4                 1             .-------------------.    .----| OUDIO OUT
  |  ---------- CS_SDARD           |  |  |                  |              1                  8
  |                                L  L  L                 -+-
 -+-                               E  E  E                 GND
 GND                               D  D  D
                                   1  2  3
                                   |  |  |
                                   +--+--+
                                     GND

  R1 = 100-500 Ohm
  R2 = R3 = R4 = 390 Ohm
  C1 = 10-100 nF
  C2 = 10 uF
  
 


Demonstration video: 
 - https://www.youtube.com/watch?v=b2ATIwBYpg0
 
To control the volume by remote control use digit 8 --> volume down and digit 9 --> volume up
Much more details are in versions subfolder.
  
HAVE FUN :-)
  
  
PS: 
Special thanks to Branko for the help and for sharing his project ;)

        
