#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>


/* Uncomment the initialize the I2C address , uncomment only one, If you get a totally blank screen try the other*/
#define i2c_Address 0x3c //initialize with the I2C addr 0x3C Typically eBay OLED's
//#define i2c_Address 0x3d //initialize with the I2C addr 0x3D Typically Adafruit OLED's

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET -1   //   QT-PY / XIAO
Adafruit_SH1106G display = Adafruit_SH1106G(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2


#define LOGO16_GLCD_HEIGHT 16
#define LOGO16_GLCD_WIDTH  16
static const unsigned char PROGMEM logo16_glcd_bmp[] =
{ B00000000, B11000000,
  B00000001, B11000000,
  B00000001, B11000000,
  B00000011, B11100000,
  B11110011, B11100000,
  B11111110, B11111000,
  B01111110, B11111111,
  B00110011, B10011111,
  B00011111, B11111100,
  B00001101, B01110000,
  B00011011, B10100000,
  B00111111, B11100000,
  B00111111, B11110000,
  B01111100, B11110000,
  B01110000, B01110000,
  B00000000, B00110000
};

#define UpPin D2
#define DownPin D3
#define LeftPin D4
#define RightPin D5
#define MiddlePin D6
#define SetPin D7
#define ResetPin D8

void setup()   {

  Serial.begin(9600);

  // Show image buffer on the display hardware.
  // Since the buffer is intialized with an Adafruit splashscreen
  // internally, this will display the splashscreen.

  delay(250); // wait for the OLED to power up
  display.begin(i2c_Address, true); // Address 0x3C default
 //display.setContrast (0); // dim display
 
  display.display();
  delay(2000);

  // Clear the buffer.
  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(SH110X_WHITE);

  // // invert the display
  // display.invertDisplay(true);
  // delay(1000);
  // display.invertDisplay(false);
  // delay(1000);
  // display.clearDisplay();

  pinMode(UpPin, INPUT_PULLUP);
  pinMode(DownPin, INPUT_PULLUP);
  pinMode(LeftPin, INPUT_PULLUP);
  pinMode(RightPin, INPUT_PULLUP);
  pinMode(MiddlePin, INPUT_PULLUP);
  pinMode(SetPin, INPUT_PULLUP);
  pinMode(ResetPin, INPUT_PULLUP);

}

void loop() {
  display.clearDisplay();
  display.setCursor(0, 0);
  display.setTextSize(5);
  switch (buttonPressed()) {
    case 1:
      display.print("UP");
      display.display();
      break;
    case 2:
      display.print("DOWN");
      display.display();
      break;
    case 3:
      display.print("LEFT");
      display.display();
      break;
    case 4:
      display.print("RIGHT");
      display.display();
      break;
    case 5:
      display.print("Middle");
      display.display();
      break;
    case 6:
      display.print("Set");
      display.display();
      break;
    case 7:
      display.print("Reset");
      display.display();
      break;
    default:
      display.display();
      break;
  }
  
}

int buttonPressed() {
  if (digitalRead(UpPin) == 0){
    return 1;
  }
  else if (digitalRead(DownPin) == 0) {
    return 2;
  }
  else if (digitalRead(LeftPin) == 0) {
    return 3;
  }
  else if (digitalRead(RightPin) == 0) {
    return 4;
  }
  else if (digitalRead(MiddlePin) == 0) {
    return 5;
  }
  else if (digitalRead(SetPin) == 0) {
    return 6;
  }
  else if (digitalRead(ResetPin) == 0) {
    return 7;
  }
  else {
    return 0;
  }
}
