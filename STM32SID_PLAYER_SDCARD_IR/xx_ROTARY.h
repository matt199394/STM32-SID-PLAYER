
#ifdef ROTARY_ENCODER
byte controlByte = B0101000; // 7 bits, 
byte commandByte = B10101001; // last 2 bits is potmeter selection.
int volume = 130;                   
int pinAcurrentState = LOW;                // Current state of Pin A
int pinAlastState = pinAcurrentState;      // Last read value of Pin A
volatile int Direction;
volatile boolean redFlag = false;
boolean button = false;
boolean volumeFlag = false;

int currentButtonState = 0;        
int lastButtonState = 0;

int menuitem = 0;
int page = 0;

void irq_rotary();
void check_rotary_button();
void check_rotary();
#endif
