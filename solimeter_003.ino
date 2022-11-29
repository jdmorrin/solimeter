/*
  Solimeter project: 

  Circuit: connect + end of of solar cell to pin "A0"
           connect - end to GND pin
*/

// analog pins
const int analogIn = A0;
const int analogOut = 9;

int input;
long startTime = 0;
long elapsedTime = 0;
long totalTime = 0;

void setup() {
  
  Serial.begin(9600);
}

void loop() {
  input = analogRead(analogIn);
  Serial.print(input); Serial.print("\t");

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
