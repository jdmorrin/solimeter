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
const int rs = 12, e =11, d7= 5, d6 = 4, d5 = 3, d4 = 2; 

// LCD
LiquidCrystal lcd(rs, e, d4, d5, d6, d7);

int input;
long startTime = 0;
long elapsedTime = 0;
long totalTime = 0;

void setup() {
  lcd.begin(16,2);
//  lcd.print("Hello World!");
  Serial.begin(9600);
}

void loop() {
//  lcd.setCursor(0,0);
  input = analogRead(analogIn);
  Serial.print("Input pin: "); Serial.print(analogIn); Serial.print("\t"); Serial.print(input); Serial.print("\t");
//  lcd.print("input: "); lcd.print(input);

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
  lcd.setCursor(0,0);
  lcd.print(elapsedTime);
  
  lcd.setCursor(0, 1);
  lcd.print(totalTime);
  
  // When the solar cell no longer outputs any voltage, end the loop
  if(input == 0){
    Serial.print("The total time today was: ");
    Serial.print(totalTime);
    Serial.println();
    Serial.end();

    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Total time today:");
    lcd.setCursor(0,1);
    lcd.print(totalTime); lcd.print(" secs");
  }
}
