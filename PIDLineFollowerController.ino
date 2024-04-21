/*
This Arduino program implements a PID controller for a line-following robot. It reads analog values from three sensors (left, middle, right) to 
determine the robot's position relative to a line. Based on these readings, it calculates a PID (Proportional, Integral, Derivative) control value to 
adjust the speeds of two motors, ensuring the robot follows the line accurately. The motor_drive function then applies these speed adjustments to the 
motors. The code also includes functions for sensor reading, PID calculations, and motor control. The system operates in a loop, continually adjusting 
based on sensor input to maintain the set path.
*/



float sensors_sum; 
int sensors_average; 
int position;
float proportional;
float set_point = 0;
float integral = 0;
float derivative = 0;
float last_proportional;
float error_value;
float right_speed;
float left_speed;
int max_speed = 200;
long sensors[] = {0, 0, 0};
float Kp = 1;
float Ki = 1;
float Kd = 1;
int midsensor;
int leftsensor;
int rightsensor;

void setup() {
  // put your setup code here, to run once:
  int PWMA = 11;
  int PWMB = 10;
  int max_speed = 200;
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  Serial.begin(9600);
}

void sensors_read(){
  midsensor = analogRead(A0);
  leftsensor = analogRead(A1);
  rightsensor = analogRead(A2);
  sensors_average = (midsensor + leftsensor + rightsensor) / 3;
  sensors_sum = midsensor + leftsensor + rightsensor;

}

void pid_calc() {
  position = int(sensors_average / sensors_sum);
  proportional = position - set_point;
  integral = integral + proportional;
  derivative = proportional - last_proportional;
  last_proportional = proportional;

  error_value = int(proportional * Kp + integral * Ki + derivative * Kd);  
  }

void calc_turn() {
  if (error_value < -256)
    {
  error_value = -256;
    }
  if (error_value > 256)
    {
  error_value = 256;
    }

  if (error_value < 0)
    { 
  right_speed = max_speed + error_value;
  left_speed = max_speed;
    }
  else
    {
  right_speed = max_speed;
  left_speed = max_speed - error_value;
    }
}

void motor_drive(int right_speed, int left_speed) 
{
  analogWrite(10, right_speed);
  analogWrite(11, left_speed);
  delay(50); // Optional
}

void loop() 
{
  sensors_read();
  pid_calc();
  calc_turn();
  motor_drive(right_speed, left_speed);
  Serial.println(analogRead(A0));
  Serial.println(' ');
  Serial.println(analogRead(A1));
  Serial.println(' ');
  Serial.println(analogRead(A2));
  delay(1000);
}
