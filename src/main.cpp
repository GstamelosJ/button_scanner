// Wire Slave Receiver
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Receives data as an I2C/TWI slave device
// Refer to the "Wire Master Writer" example for use with this

// Created 29 March 2006

// This example code is in the public domain.


#include <Arduino.h>
#include <Bounce2.h>
#include <Wire.h>

#define butt1 2
#define butt2 3
#define butt3 4
#define butt4 5
#define butt5 6
#define butt6 7
#define butt7 8
#define butt8 9

uint8_t buttons_pressed;

void requestEvent();
Bounce bouncer_butt1=Bounce();
Bounce bouncer_butt2=Bounce();
Bounce bouncer_butt3=Bounce();
Bounce bouncer_butt4=Bounce();
Bounce bouncer_butt5=Bounce();
Bounce bouncer_butt6=Bounce();
Bounce bouncer_butt7=Bounce();
Bounce bouncer_butt8=Bounce();

void buttons_check()
{
  //Serial.println("Button scan enter");
  
  bouncer_butt1.update();
  if (bouncer_butt1.fell())
  {
    buttons_pressed=1;
    Serial.print("Button pressed= ");
    Serial.println(buttons_pressed);
    digitalWrite(LED_BUILTIN,HIGH);
  }
  bouncer_butt2.update();
  if (bouncer_butt2.fell())
  {
    buttons_pressed=2;
    Serial.print("Button pressed= ");
    Serial.println(buttons_pressed);
    digitalWrite(LED_BUILTIN,HIGH);
  }
  bouncer_butt3.update();
  if (bouncer_butt3.fell())
  {
    buttons_pressed=3;
    Serial.print("Button pressed= ");
    Serial.println(buttons_pressed);
    digitalWrite(LED_BUILTIN,HIGH);
  }
  bouncer_butt4.update();
  if (bouncer_butt4.fell())
  {
    buttons_pressed=4;
    Serial.print("Button pressed= ");
    Serial.println(buttons_pressed);
    digitalWrite(LED_BUILTIN,HIGH);

  }
  bouncer_butt5.update();
  if (bouncer_butt5.fell())
  {
    buttons_pressed=5;
    Serial.print("Button pressed= ");
    Serial.println(buttons_pressed); 
    digitalWrite(LED_BUILTIN,HIGH);
  }
  bouncer_butt6.update();
  if (bouncer_butt6.fell())
  {
    buttons_pressed=6;
    Serial.print("Button pressed= ");
    Serial.println(buttons_pressed);
    digitalWrite(LED_BUILTIN,HIGH);
  }
  bouncer_butt7.update();
  if (bouncer_butt7.fell())
  {
    buttons_pressed=7;
    Serial.print("Button pressed= ");
    Serial.println(buttons_pressed);
    digitalWrite(LED_BUILTIN,HIGH);
  }
  bouncer_butt8.update();
  if (bouncer_butt8.fell())
  {
    buttons_pressed=8;
    Serial.print("Button pressed= ");
    Serial.println(buttons_pressed);
    digitalWrite(LED_BUILTIN,HIGH);
  }

}

void setup() {
  Wire.begin(8);                // join i2c bus with address #8
  Wire.onRequest(requestEvent); // register event
  Serial.begin(9600);           // start serial for output
  pinMode(butt1,INPUT_PULLUP);
  pinMode(butt2,INPUT_PULLUP);
  pinMode(butt3,INPUT_PULLUP);
  pinMode(butt4,INPUT_PULLUP);
  pinMode(butt5,INPUT_PULLUP);
  pinMode(butt6,INPUT_PULLUP);
  pinMode(butt7,INPUT_PULLUP);
  pinMode(butt8,INPUT_PULLUP);
  pinMode(LED_BUILTIN,OUTPUT);
  bouncer_butt1.attach(butt1);
  bouncer_butt1.interval(15);
  bouncer_butt2.attach(butt2);
  bouncer_butt1.interval(15);
  bouncer_butt3.attach(butt3);
  bouncer_butt1.interval(15);
  bouncer_butt4.attach(butt4);
  bouncer_butt1.interval(15);
  bouncer_butt5.attach(butt5);
  bouncer_butt1.interval(15);
  bouncer_butt6.attach(butt6);
  bouncer_butt1.interval(15);
  bouncer_butt7.attach(butt7);
  bouncer_butt1.interval(15);
  bouncer_butt8.attach(butt8);
  bouncer_butt1.interval(15);
Serial.println("setup finished....");
}

void loop() {
  digitalWrite(LED_BUILTIN,0);
  delay(100);
  buttons_check();

}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void requestEvent() {
  Wire.write(buttons_pressed); // respond with message of 1 byte
  // as expected by master
  Serial.print("I2C request sent, button pressed resonce: ");
  Serial.println(buttons_pressed);
  buttons_pressed=0xff;
}