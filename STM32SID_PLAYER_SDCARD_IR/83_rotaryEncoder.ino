
#ifdef ROTARY_ENCODER
//#include "xx_ROTARY.h"

void irq_rotary() {
  
  redFlag = true;

  // ROTATION DIRECTION
     pinAcurrentState = digitalRead(pinA);    // Read the current state of Pin A
  
  // If there is a minimal movement of 1 step
  if ((pinAlastState == LOW) && (pinAcurrentState == HIGH)) {
    
    if (digitalRead(pinB) == HIGH) {      // If Pin B is HIGH
      Direction = 1;
      
    } else {
      Direction = -1;
    }
    
  }

  
  pinAlastState = pinAcurrentState;        // Store the latest read value in the currect state variable

/*
  current_file += Direction;

  if (current_file > total_sid_files) current_file = 0;
  if (current_file < 0) current_file = total_sid_files;

  Direction=0;
*/
  //----------------------------------------

 if (Direction == 1 && page == 0 ) {
    Direction = 0;
    menuitem++;
    if (menuitem==3)
    {
      menuitem=0;
    }      
  }
  else if (Direction == 1 && page == 1 ) {
    Direction = 0;
    current_file++;
    if (current_file > total_sid_files-1) current_file = 0;
    
  }
  else if (Direction == 1 && page == 2 ) {
    Direction = 0;
    current_folder++;
    if (current_folder > (NUMBER_OF_FOLDERS - 1)) current_folder = 0;
    
  }

  else if (Direction == 1 && page == 3 ) {
    Direction = 0;
    volume +=10;
    if (volume > 255) volume  = 250;
    
  }

  else if (Direction == -1 && page == 0 ) {
    Direction = 0;
    menuitem--;
    if (menuitem < 0) menuitem = 1;
    
  }

 else if (Direction == -1 && page == 1 ) {
    Direction = 0;
    current_file--;
    if (current_file < 0) current_file = total_sid_files-1;
    
  }

else if (Direction == -1 && page == 2 ) {
    Direction = 0;
    current_folder--;
    if (current_folder < 0) current_folder = (NUMBER_OF_FOLDERS -1);
}


else if (Direction == -1 && page == 3 ) {
    Direction = 0;
    volume -=10;
    if (volume < 0) volume = 0;

//--------------------------------------
}

}

void irq_button()
{
//button=true;
}

void check_rotary_button(){
     currentButtonState = digitalRead(buttonPin);
     checkIfbuttonIsPressed();
 
//----------------------------------
 if (button && menuitem == 0 && page == 0) {
      redFlag = true; 
      page=1;
      }
 else if (button && menuitem == 1 && page == 0) {
      redFlag = true; 
      page=2;     
      }
 else if (button && menuitem == 2 && page == 0) {
      redFlag = true; 
      page=3;     
      }          
 else if (button && page == 1){
      redFlag = false;
      page=0;
  // play next file
      mode_play_ON = true;
      tune_play_counter = 0;
      change_file = true;
      player = false;
   //   file_mode = 0; // next
      tune_play_counter = 0;    
 }
else if (button && page == 2){  
      redFlag = false;
      page=0;
   // play next folder
      mode_play_ON = true;
      count_sids = true;
      tune_play_counter = 0;
      change_folder = true;
      player = false;
   //   folder_mode = 0; // next     
 }
 else if (button && page == 3){  
      redFlag = false;
      page=0;        
 }
 
 button = false; 
}


void checkIfbuttonIsPressed()
{
   if (currentButtonState != lastButtonState) 
  {
    if (currentButtonState == 0) {
      button=true;
    }
    delay(50);
  }
   lastButtonState = currentButtonState;
}

void check_rotary(){
  while(redFlag){
    check_rotary_button();
    
    #ifdef LCD_SSD1306
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 24);
  if(page == 0 && menuitem == 0 && redFlag == true ){
    display.print("Files");
    display.display();
  }
  else if(page == 0 && menuitem == 1 && redFlag == true){ 
    display.print("Folders");
    display.display();
  }
  else if(page == 0 && menuitem == 2 && redFlag == true){ 
    display.print("Volume");
    display.display();
  }
  else if(page == 1 && redFlag == true){ 
    display.print(current_file+1);
    display.print("/");
    display.println(total_sid_files);
    display.display();
  }
  else if(page == 2 && redFlag == true){ 
    display.print(current_folder);
    display.print("/");
    display.println(NUMBER_OF_FOLDERS - 1);
    //display.print(FOLDER_PLAYLIST[current_folder]);
    display.display();
  }
  else if(page == 3 && redFlag == true){
    display.print("Volume:"); 
    display.print(volume/10);
    display.display();
    Wire.beginTransmission(controlByte);  // start transmitting
    Wire.write(commandByte);              // selection of potmeters
    Wire.write(volume);              // send 1st byte of potmeter data 
    Wire.endTransmission();               // stop transmitting 
  }
  }
}
 #endif
 #endif
