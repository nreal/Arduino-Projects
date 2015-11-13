/*  
    Arduino with PIR motion sensor
    For complete project details, visit: http://RandomNerdTutorials.com/pirsensor
    Modified by Rui Santos based on PIR sensor by Limor Fried
*/
 
int relay2 = 13;                // the pin that the LED is atteched to
int parlante = 12;           // pin to parlante
int sensor = 2;              // the pin that the sensor is atteched to
int state = LOW;             // by default, no motion detected
int val = 0;                 // variable to store the sensor status (value)
int freq = 440;               // frecuencia para el parlante
int duration = 1000;          // Duracion de sonido para el parlante

void setup() {
  pinMode(relay2, OUTPUT);      // initalize LED as an output
  pinMode(sensor, INPUT);    // initialize sensor as an input
  pinMode(parlante,OUTPUT); // Initialize parlante
  Serial.begin(9600);        // initialize serial
}

void loop(){
  val = digitalRead(sensor);   // read sensor value
  if (val == HIGH) 
  {
      for(int i=0; i<7 ; i++) 
      {
        digitalWrite(relay2, HIGH);   // turn LED ON
        tone(parlante, freq*i, duration);
        delay(duration);
        digitalWrite(relay2, LOW);   // turn LED ON
        noTone(parlante);
      }
  
    if (state == LOW) {
      Serial.println("Motion detected!"); 
      state = HIGH;       // update variable state to HIGH
    }
  } 
  else {
      digitalWrite(relay2, LOW); // turn LED OFF
      
      if (state == HIGH){
        Serial.println("Motion stopped!");
        state = LOW;       // update variable state to LOW
    }
  }
}
