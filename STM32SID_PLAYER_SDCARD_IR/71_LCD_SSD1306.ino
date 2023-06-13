
#ifdef LCD_SSD1306
/*
  #include <Adafruit_BusIO_Register.h>
  #include <Adafruit_I2CDevice.h>                           // install from library manager or from: https://github.com/adafruit/Adafruit_BusIO
  #include <Adafruit_GFX.h>                                // download from library manager or from  https://github.com/adafruit/Adafruit-GFX-Library
  #include <Adafruit_SSD1306.h>                            // download from library manager or from  https://github.com/adafruit/Adafruit_SSD1306
*/
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>



//#define OLED_RESET 4
//Adafruit_SSD1306 display(OLED_RESET);

// OLED   -  STM32F103C8
//  SCK   -  PB6
//  SCL   -  PB7

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);


void LCD_SSD1306_init() { // Called from z_SetupLoop

  //  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x32
    debugPrintTXTln("ERROR3 - SSD1306 allocation failed");
    for (;;); // Don't proceed, loop forever
  }

  // Clear the buffer.
  display.clearDisplay();
  // text display tests
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 24);
  // display.invertDisplay(true);
  display.setRotation(2);
  display.println("SIDPlayer");

  display.display(); // actually display all of the above
  delay(1000); // Pause for 2 seconds

}

void LCD_SSD1306_info()  { // called from 70_SIDinfo.ino

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.clearDisplay();
  //display.println(">");
  //    display.println(SID_DIR_name);
  //display.print("Author:");
  display.println(SIDinfo_author);
  display.print("\n");
  display.println(SIDinfo_name);
  display.println(SIDinfo_MODEL);
  display.print(SID_current_tune);
  display.print("/");
  display.print(SID_number_of_tunes);
  display.print(" file:");
  display.print(current_file);
  display.print("/");
  display.println(total_sid_files);
  display.print("Folder: ");
  display.print(current_folder);
  display.print("/");
  display.print(NUMBER_OF_FOLDERS - 1);
  //display.drawLine(0, 54, 127, 54, SSD1306_WHITE);
  //display.display();
}

void LCD_SSD1306_hard_info()  { // called from 70_SIDinfo.ino

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.clearDisplay();
  //display.println(">");
  //    display.println(SID_DIR_name);
  //display.print("Author:");
  display.print("STM32 clock: ");
  display.print(uint32_t(F_CPU / 10000000));  
  display.println(" MHz ");
  display.print("\n");
  display.print("6502 CPU: ");  
  //display.print(emulate_cpu_speed);  
  display.println("%");
  display.print("Samplerate:");
  display.print(uint32_t(1000000 / multiplier));
  display.println("Hz");
  display.print("PWM freq:");
  display.print(uint32_t( (1000000 / period) / 1000));
  display.print("KHz");
  
  display.display();

  delay(3000);
}



#endif
