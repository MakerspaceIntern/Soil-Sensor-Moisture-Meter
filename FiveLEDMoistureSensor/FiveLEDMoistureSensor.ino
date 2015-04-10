//Defines A0 as the pin for reading data from a moisture sensor and D2-6 as pins for LEDs
int moisturePin = A0;
int lowPin = 2;
int lowishPin = 3;
int medPin = 4;
int highishPin = 5;
int highPin = 6;
int moistureValue = 0;

void setup() {
  // Declares all LED pins as output and begins Serial @ 9600 baud
pinMode (lowPin, OUTPUT);
pinMode (lowishPin, OUTPUT);
pinMode (medPin, OUTPUT);
pinMode (highishPin, OUTPUT);
pinMode (highPin, OUTPUT);
Serial.begin(9600);
}

void loop() {
  // reads the data from the moisture sensor as well as prints the values in the Serial Monitor
  moistureValue = analogRead(moistureValue);
  Serial.print("sensor = " );                       
  Serial.println(analogRead(A0));
  delay(2500);
  
  //if table for moisture thresholds 
  if (moistureValue >= 0) {
    digitalWrite (lowPin, HIGH);
  }
   if (moistureValue >= 15) {
    digitalWrite (lowishPin, HIGH);
  }
   if (moistureValue >= 30) {
    digitalWrite (medPin, HIGH);
  }
   if (moistureValue >= 45) {
    digitalWrite (highishPin, HIGH);
  }
   if (moistureValue >= 60) {
    digitalWrite (highPin, HIGH);
    }
  delay(2500);
 //manually sets all pins to low and writes the moistureValue back to 0 so the loop can begin again 
  digitalWrite (lowPin, LOW);
  digitalWrite (lowishPin, LOW);
  digitalWrite (medPin, LOW);
  digitalWrite (highishPin, LOW);
  digitalWrite (highPin, LOW);
  moistureValue = 0;
}


