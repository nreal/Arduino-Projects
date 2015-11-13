int relay2 = 7;                // relay
int led = 13;                 // led
int sensor = 2;              // the pin that the sensor is atteched to
int state = LOW;             // by default, no motion detected
int val = 0;                 // variable to store the sensor status (value)

void setup() {
  pinMode(relay2, OUTPUT);      // initalize LED as an output
  pinMode(sensor, INPUT);    // initialize sensor as an input
  pinMode(led,OUTPUT); // Initialize parlante
}

void loop(){
  val = digitalRead(sensor);   // read sensor value
  if (val == HIGH) 
  {
        digitalWrite(relay2, HIGH);   // turn relay ON
        digitalWrite(led, HIGH);   // turn LED ON
        delay(3000);
 
    if (state == LOW) {
      Serial.println("Motion detected!"); 
      state = HIGH;       // update variable state to HIGH
    }
  } 
  else {
      digitalWrite(relay2, LOW); // turn LED OFF
      digitalWrite(led, LOW); // turn LED OFF
      
      if (state == HIGH){
        Serial.println("Motion stopped!");
        state = LOW;       // update variable state to LOW
    }
  }
}
