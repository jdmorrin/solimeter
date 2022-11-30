/*
  Solimeter project: 

  Circuit: connect + end of of solar cell to pin "A0"
           connect - end to GND pin

  LCD:  Vss => GND
        Vdd => +
        Vo => Potentiometer mid pin
        RS => 12
        RW => GND
        E => 11
        K => GND
        A => 330 Ohms => +
        D7 => 2
        D6 => 3
        D5 => 4
        D4 => 5        
        
*/

#include <LiquidCrystal.h>


// pins
const int analogIn = A0;
const int analogOut = 9;
const int rs = 12, e =11, d7= 2, d6 = 3, d5 = 4, d4 = 5; 

// LCD
LiquidCrystal lcd(rs, e, d4, d5, d6, d7);

int input;
long startTime = 0;
long elapsedTime = 0;
long totalTime = 0;

void setup() {
  lcd.begin(16,1);
//  lcd.print("Hello World!");
  Serial.begin(9600);
}

void loop() {
  input = analogRead(analogIn);
  Serial.print(input); Serial.print("\t");
  lcd.print(input); lcd.print("\n");

  // 
  if(input >= 850){
    if(startTime == 0){
      startTime = millis();
    }else{
      elapsedTime = (millis() - startTime)/1000.0;
      Serial.print(elapsedTime);
    }
    delay(1000);   
  }else if(input < 850){
    totalTime = totalTime + elapsedTime;
    elapsedTime = 0;
    startTime = 0;
    Serial.print("Total sunlight time: "); Serial.print(totalTime);
  }

  Serial.println();
  
  if(input == 0){
    Serial.print("The total time today was: ");
    Serial.print(totalTime);
    Serial.println();
    Serial.end();
  }
}
