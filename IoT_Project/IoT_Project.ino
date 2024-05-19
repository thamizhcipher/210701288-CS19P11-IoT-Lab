#include<Arduino.h>
#include<LiquidCrystal_I2C.h>
#include<Wire.h>

LiquidCrystal_I2C lcd(0x27,16,2);
int count=0;
char input[12];
int count_prod=0;
double total=0;
void setup() {
  Serial.begin(9600);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);

  Serial.begin(9600);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Automatic bill");
  delay(2000);
  lcd.setCursor(0,1);
  lcd.print("Shop[ping cart");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Welcome to ");
  lcd.setCursor(0,1);
  lcd.print("BIG bazaar");
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available())
  {
    count = 0;
    while(Serial.available() && count<12)
    {
      input[count]=Serial.read();
      count++;
      delay(5);
    }
    if(input[0]=='0' && input[1]=='B' && input[2]=='0'&&input[3]=='0' && 
      input[4]=='2' && input[5]=='8' && input[6]=='4'&&input[7]=='7' &&
      input[8]=='1' && input[9]=='2' && input[10]=='7'&&input[11]=='6'
    )
    {
      lcd.setCursor(0,0);
      lcd.print("Biscuit added");
      lcd.setCursor(0,1);
      lcd.print("Price Rs. 90.0");
      digitalWrite(4,HIGH);
      digitalWrite(5,HIGH);
      delay(1000);
      total=total+4.00;
      count_prod++;
      digitalWrite(4,LOW);
      digitalWrite(5,LOW);
    }
    if(input[0]=='0' && input[1]=='B' && input[2]=='0'&&input[3]=='0' && 
      input[4]=='2' && input[5]=='4' && input[6]=='3'&&input[7]=='2' &&
      input[8]=='A' && input[9]=='1' && input[10]=='B'&&input[11]=='0'
    )
    {
      lcd.setCursor(0,0);
      lcd.print("Soap added");
      lcd.setCursor(0,1);
      lcd.print("Price Rs. 70.0");
      digitalWrite(4,HIGH);
      digitalWrite(5,HIGH);
      delay(1000);
      total=total+6.00;
      count_prod++;
      digitalWrite(4,LOW);
      digitalWrite(5,LOW);
    }
  }

}
