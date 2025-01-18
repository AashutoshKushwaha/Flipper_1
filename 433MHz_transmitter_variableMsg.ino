#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

// Define the GPIO pins for the switches
#define SWITCH_1 D1
#define SWITCH_2 D2
#define SWITCH_3 D3

void setup() {
  Serial.begin(115200);          // Initialize Serial communication at 115200 baud
  mySwitch.enableTransmit(D4);   // Transmitter is connected to GPIO2 (D4 on NodeMCU)
  Serial.println("Transmitter ready");

  // Configure switches as input with pull-up resistors
  pinMode(SWITCH_1, INPUT_PULLUP);
  pinMode(SWITCH_2, INPUT_PULLUP);
  pinMode(SWITCH_3, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(SWITCH_1) == LOW) { // Check if Switch 1 is pressed
    mySwitch.send(12345, 24);         // Send code for Switch 1
    Serial.println("Sent: 12345 (Switch 1)");
    delay(300);                       // Debounce delay
  } 
  else if (digitalRead(SWITCH_2) == LOW) { // Check if Switch 2 is pressed
    mySwitch.send(67890, 24);              // Send code for Switch 2
    Serial.println("Sent: 67890 (Switch 2)");
    delay(300);                            // Debounce delay
  } 
  else if (digitalRead(SWITCH_3) == LOW) { // Check if Switch 3 is pressed
    mySwitch.send(24680, 24);              // Send code for Switch 3
    Serial.println("Sent: 24680 (Switch 3)");
    delay(300);                            // Debounce delay
  }
}
