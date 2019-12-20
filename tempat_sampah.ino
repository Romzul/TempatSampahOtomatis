#include<Servo.h>
Servo servo;
int const trigPin = 6;
int const echoPin = 5;

void setup()
{
pinMode(trigPin, OUTPUT); 
pinMode(echoPin, INPUT); 
    servo.attach(3);
}

void loop()
{
int duration, distance;
digitalWrite(trigPin, HIGH); 
delay(1);
digitalWrite(trigPin, LOW);
// Ukur input pulsa di pin echo
duration = pulseIn(echoPin, HIGH);
// Jarak adalah setengah dari durasi yang dibagi 29.1 (from datasheet)
distance = (duration/2) / 29.1;
// jika jarak kurang dari 30cm dan lebih dari 0 (0 atau kurang berarti jarak) 
if (distance <= 50 && distance >= 0) {
  servo.write(50);
    delay(400);
} else {
  
  servo.write(160);
}
// Menunggu 60 ms tidak akan menyakiti siapa pun
delay(60);
}
