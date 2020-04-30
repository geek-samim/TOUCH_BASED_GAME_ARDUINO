 #include <UTFT.h> 
#include <URTouch.h>
#include <EEPROM.h>
//==== Creating Objects
UTFT    myGLCD(SSD1289,38,39,40,41); //Parameters should be adjusted to your Display/Schield model
URTouch  myTouch( 6, 5, 4, 3, 2);
//==== Defining Fonts
extern uint8_t SmallFont[];
extern uint8_t BigFont[];
extern uint8_t SevenSegNumFont[];
extern unsigned int bird01[0x41A]; // Bird Bitmap
int x, y; // Variables for the coordinates where the display has been pressed
// Floppy Bird
int xP = 319;
int yP = 100;
int yB = 50;
int movingRate = 3;
int fallRateInt = 0;
float fallRate = 0;
int score = 0;
int lastSpeedUpScore = 0;
int highestScore;
boolean screenPressed = false;
boolean gameStarted = false;
void setup() {
  // Initiate display
  myGLCD.InitLCD();
  myGLCD.clrScr();
  myTouch.InitTouch();
  myTouch.setPrecision(PREC_MEDIUM);
  
  highestScore = EEPROM.read(0); // Read the highest score from the EEPROM
  
  initiateGame(); // Initiate the game
}
