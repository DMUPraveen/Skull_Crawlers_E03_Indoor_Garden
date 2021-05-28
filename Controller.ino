//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
//Author : D.M.U.P. Suamansekara 
//Project : E19 Activity E03 -> Indoor Gardening System
//Team : Skull Crawlers (Team 13)


#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <RTClib.h>
#define C_LCD_ADDRESS 0x3F
#define C_LCD_COLS 16
#define C_LCD_ROWS 2
#define encoderPinA 2
#define encoderPinB 4
#define buttonPin 5


struct Hydroponics{

  unsigned int interval = 10; //default interval between flood proccesses (in Half Hours) 10 half hours = 5 hours
  unsigned int duration = 10; //default seconds duration of a flood process

  Hydroponics(){

  }


};

struct Light{

  unsigned int onTime = 10; // default on time in half hour 10 -> 5 a.m.
  unsigned int offTime = (12+7)*2 ;// default off time in hlf hours (12+7)*2 -> 7 p.m.
  /*
  0 < onTime, offTime < 48 must be obeyed (48 hafl hours = 24 hours)
  */
  Light(){


  }

  
};


LiquidCrystal_I2C lcd(C_LCD_ADDRESS,C_LCD_COLS,C_LCD_ROWS);  // set the LCD address to 0x27 for a 16 chars and 2 line display
Light light();
Hydroponics Hydroponic();
volatile int encoderStep = 0;



//char* HydroponicsMenunItems[2] = {"Duration ","Interval "};
//char* LightMenuItems[2] = {"OnTime   ","OffTime  "};
//unsigned int selectedMainMenuItem = 0;

struct MenuItem{
  char* name;
  unsigned int* value;

  MenuItem(char* name,unsigned int* value)
    :name(name),value(value)
  {
  }
  virtual void display(){
    lcd.print(name);
  }

  virtual void encoderchange(){

  }

  virtual void buttonpress(){
    
  }

};

void writeTime(unsigned int halfHours){
  //helper function for writing half hours
  //the cursor needs to be set at the correct position
  int hours = halfHours /2;

  if(hours < 10){
    lcd.print('0');
  }
  lcd.print(hours);
  lcd.print(':');
  if(halfHours % 2 == 0){
    lcd.print("00");
  }
  else{
    lcd.print("30");
  }

}

struct TimeItem : public MenuItem{

  TimeItem(char* name,unsigned int*value)
    :MenuItem(name,value)
    {}

  void display(){
    lcd.print(' ');
    lcd.print(name);
    lcd.print(' ');
    writeTime(*value);
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

  //pinMode(encoderPinA,INPUT_PULLUP);
  //pinMode(encoderPinB,INPUT_PULLUP);
  //pinMode(buttonPin,INPUT_PULLUP);
  //attachInterrupt(digitalPinToInterrupt(encoderPinA),doEncode,RISING);

}


void loop()
{





}
