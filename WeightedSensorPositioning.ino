/*
This Arduino program calculates a weighted position based on readings from three sensors, likely used for position detection 
or balancing purposes. It initializes the serial communication, reads values from three analog sensors, and computes a weighted 
average by multiplying each sensor reading by its index and a factor of 1000. It then calculates the total sum of sensor values. 
The position is determined as the ratio of the weighted average to the total sensor sum. These values (weighted average, sum, and position)
are printed to the serial monitor every two seconds. The approach can be particularly useful in applications where sensor positioning relative 
to a specific point is critical, such as in robotics or automated systems.
*/



long sensors_average;
int sensors_sum;
int position = 0;
long sensors[] = {0, 0, 0};

void setup() {

   // put your setup code here, to run once:
   Serial.begin(9600);

}

void loop() {
   // put your main code here, to run repeatedly:
   sensors_average = 0;
   sensors_sum = 0; 

   for (int i = 0; i < 3; i++) {
      sensors[i] = analogRead(i);
      sensors_average += sensors[i] * i * 1000;
      sensors_sum += int(sensors[i]);
   }
 
   position = int(sensors_average / sensors_sum);
   Serial.print(sensors_average);
   Serial.print(' ');
   Serial.print(sensors_sum);
   Serial.print(' ');
   Serial.print(position);
   Serial.println();
   delay(2000);

}
