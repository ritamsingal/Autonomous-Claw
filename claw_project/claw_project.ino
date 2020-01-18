#include <NewPing.h>   // include the NewPing library for this program
#include <Servo.h> //include the servo library for this program

#define VCC_PIN 13
#define TRIGGER_PIN 12 // sonar trigger pin will be attached to Arduino pin 12
#define ECHO_PIN 11 // sonar echo pint will be attached to Arduino pin 11
#define GROUND_PIN 10
#define MAX_DISTANCE 200 // fmaximum distance set to 200 cm

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // initialize NewPing

Servo servo; //create servo object to control a servo


void setup(){

  Serial. begin(9600);  // set data transmission rate to communicate with computer

  pinMode(ECHO_PIN, INPUT);  
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(GROUND_PIN, OUTPUT);  // tell pin 10 it is going to be an output
  pinMode(VCC_PIN, OUTPUT);  // tell pin 13 it is going to be an output

  digitalWrite(GROUND_PIN,LOW); // tell pin 10 to output LOW (OV, or ground)
  digitalWrite(VCC_PIN, HIGH) ; // tell pin 13 to output HIGH (+5V)
  pinMode(8,INPUT_PULLUP); //pin 8 forced to HIGH when there is no external input

  servo.attach(6); //attaches the servo on pin 6 to the servo object
}


int pos = 180;

void loop(){

  delay(100); // wait for this number of milliseconds
  
  int DISTANCE_IN_CM = sonar.ping_cm(); // read the sonar sensor, using a variable

  Serial.print("Ping: "); //print “Ping:" on the computer display
  Serial.print(DISTANCE_IN_CM); //print the value of the variable next
  Serial.println("cm"); //print "cm" after that, then go to next line

  if(DISTANCE_IN_CM < 6){
    servo.write(pos); 
  }
  else{
    servo.write(0);
  }


}