/*
This Arduino script is designed to continuously read analog values from three specific pins (presumably sensors) and print these values to the serial monitor, separated by spaces for clarity. It initializes serial communication at 9600 baud rate in the setup function. In the main loop, it reads values from analog pins 0, 1, and 2 sequentially. After printing each value, it inserts a space for separation. The loop incorporates a delay of 1500 milliseconds (1.5 seconds) between each cycle to make the serial output readable and manageable. This simple utility is useful for monitoring and debugging sensor outputs in real-time, especially in testing environments or initial stages of sensor-related project development.
*/

void setup() {

   Serial.begin(9600);

}

void loop() {

   // put your main code here, to run repeatedly:
   Serial.print(analogRead(0));
   Serial.print(' ');
   Serial.print(analogRead(1));
   Serial.print(' ');
   Serial.print(analogRead(2));
   Serial.print(' ');
   delay(1500);
 
}
