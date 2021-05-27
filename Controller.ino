//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
//Author : D.M.U.P. Suamansekara 
//Project : E19 Activity E03 -> Indoor Gardening System
//Team : Skull Crawlers (Team 13)


#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <RTClib.h>
#define LCDADDRESS 0x3F
#define LCD_COLS 16
#define LCD_ROWS 2
#define encoderPinA 2
#define encoderPinB 4


LiquidCrystal_I2C lcd(0x3F,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display
volatile int encoderStep = 0;

struct Hydroponics{

  unsigned int interval = 10; //default interval between flood proccesses (in Half Hours) 10 half hours = 5 hours
  unsigned int duration = 10; //default seconds duration of a flood process

  Hydroponics(){

  }


};

struct Light{

  unsigned int onTime = 10; // default on time in half hour 10 -> 5 a.m.
  unsigned int offTime = (12+7)*2 // default off time in hlf hours (12+7)*2 -> 7 p.m.
  /*
  0 < onTime, offTime < 48 must be obeyed (48 hafl hours = 24 hours)
  */
  Light(){

    
  }

  
};






void doEncode(){

  if(digitalRead(encoderPinB) == digitalRead(encoderPinA)){
    encoderStep++;
  }
  else{
    encoderStep--;
  }

}

void setup()
{
  lcd.init();                      // initialize the lcd 
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();

  pinMode(encoderPinA,INPUT_PULLUP);
  pinMode(encoderPinB,INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(encoderPinA),doEncode,RISING);

}


void loop()
{





}
