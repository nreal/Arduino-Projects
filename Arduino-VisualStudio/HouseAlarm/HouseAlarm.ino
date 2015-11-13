int relay2 = 13;                // the pin that the LED is atteched to
int parlante = 12;           // pin to parlante
int led2= 11;
int sensor = 2;              // the pin that the sensor is atteched to
int state = LOW;             // by default, no motion detected
int val = 0;                 // variable to store the sensor status (value)
int freq = 440;               // frecuencia para el parlante
int duration = 500;          // Duracion de sonido para el parlante

void setup() {
  pinMode(relay2, OUTPUT);      // initalize LED as an output
  pinMode(sensor, INPUT);    // initialize sensor as an input
  pinMode(parlante,OUTPUT); // Initialize parlante
  pinMode(led2, OUTPUT);
  Serial.begin(9600);        // initialize serial
}

void loop(){
  val = digitalRead(sensor);   // read sensor value
  if (val == HIGH) 
  {
      for(int i=0; i < 6 ; i++) 
      {
        digitalWrite(relay2, HIGH);   // turn LED ON
		digitalWrite(led2, HIGH);   // turn LED ON
        tone(parlante, freq*i, duration);
		delay(duration);
		digitalWrite(relay2, LOW);   // turn LED OFF
		digitalWrite(led2, LOW);   // turn LED OFF
        delay(duration);
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