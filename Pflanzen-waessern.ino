/*
  Analog Input

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/AnalogInput
*/

int sensorPin = A0;    // select the input pin for the potentiometer
int ledPin = 13;      // select the pin for the LED
int FeuchtigkeitsSensor = 0;  // variable to store the value coming from the sensor
int motorPin = A1; // PWM for 5V pump

void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);
  pinMode(sensorPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // read the value from the sensor:
  FeuchtigkeitsSensor = analogRead(sensorPin);
  Serial.println(FeuchtigkeitsSensor);
  
// 800 und 900 trockene erde --> pumpe an--> pause 5 Sek
// 700 geht noch so  --> pumpe langsamer --> pause 5 Sek
// 600 gut feucht    --> pumpe langsamer --> pause 4 Sek
// 350 450 feucht - genau richtig --> pumpe aus
// 300 zu gut stopp --> pumpe aus
// schlafe 2h  
  if ( FeuchtigkeitsSensor > 800 ) 
  {
      pumpe(1, 10, 100 );
  }
  else if (FeuchtigkeitsSensor > 700)
  {
      pumpe(1, 8, 100 );
  }
  else if (FeuchtigkeitsSensor > 600)
  {
      pumpe(1, 4 ,80);
  }
  else if (FeuchtigkeitsSensor > 450)
  {
      pumpe(1, 4 ,50);
  }
  else if (FeuchtigkeitsSensor > 350)
  {
      pumpe(0, 3600 , 0);
  }
  else
  {
      pumpe(0, 7200 , 0);
  }  


}

void pumpe (int zustand, int dauer, int speed ) {
  if (zustand > 0 ){
    motor (1,speed);
    digitalWrite(ledPin, HIGH);
  }
  else
  {
    motor (0,0);
    digitalWrite(ledPin, LOW);
  }
  delay(dauer * 1000);
}

void motor (int zustand, int speed ){

}

