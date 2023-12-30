#include<Wire.h>
#include<LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

const int echo = A1;
const int trig = A3;
long duration;
int distance;


void setup() 
{
  pinMode(echo,INPUT);
  pinMode(trig,OUTPUT);
  Serial.begin(9600);
  lcd.begin();
}

void loop() {

  digitalWrite(trig,LOW);
  delayMicroseconds(2);

  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);

  duration = pulseIn(echo,HIGH);

  distance = (duration*0.034)/2;

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Distance:");
  lcd.setCursor(10,0); 
  lcd.print(distance);
  lcd.setCursor(14,0); 
  lcd.print("cm");


}
