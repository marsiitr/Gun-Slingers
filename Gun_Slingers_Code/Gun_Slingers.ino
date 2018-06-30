#include <PS3BT.h>

#ifdef dobogusinclude
#include <spi4teensy3.ha>
#include <SPI.h>
#endif
#include <usbhub.h>

#define motor1a 2
#define motor1b 3
#define motor1pwm 4
#define motor2a 5
#define motor2b 6
#define motor2pwm 7
#define motor_shota 8
#define motor_shotb 9
#define motor_shotpwm 10

USB Usb;
BTD Btd(&Usb); // You have to create the Bluetooth Dongle instance like so
PS3BT PS3(&Btd);

int l1, r1, l2, r2, l3, r3, start, sel, tri, squ, cross, circle, up, down, right, left = 0;
int LeftstickX = 125;
int LeftstickY = 125;
int RightstickX = 125;
int RightstickY = 125;
bool debug_flag = false;

int ir_state=0, ir_state_last=0;

  void remote_init()
  {
    #if !defined(MIPSEL)
      while (!Serial); // Wait for serial port to connect - used on Leonardo, Teensy and other boards with built-in USB CDC serial connection
    #endif
      if (Usb.Init() == -1) {
        if (debug_flag)
          Serial.println(F("\r\nOSC did not start"));
        while (1); //halt
      }
      if (debug_flag)
        Serial.println(F("\r\nPS3 Bluetooth Library Started"));
  }
 
 
 void remote_read()
 {
 
  if(LeftstickX<45)      ////anticlockwise
  {
    digitalWrite(motor1a,HIGH);
    digitalWrite(motor1b,LOW);
    analogWrite(motor1pwm, 150);
    
    digitalWrite(motor2a,LOW);
    digitalWrite(motor2b,HIGH);
    analogWrite(motor2pwm, 150);
    
  }
  else if(LeftstickX>180)      ////clockwise
  {
    digitalWrite(motor1a,LOW);
    digitalWrite(motor1b,HIGH);
    analogWrite(motor1pwm, 150);
    
    digitalWrite(motor2a,HIGH);
    digitalWrite(motor2b,LOW);
    analogWrite(motor2pwm, 150);
    
  }
  else  if(LeftstickY<45)      ///forward
  {
    digitalWrite(motor1a,HIGH);
    digitalWrite(motor1b,LOW);
    analogWrite(motor1pwm, 150);
    
    digitalWrite(motor2a,HIGH);
    digitalWrite(motor2b,LOW);
    analogWrite(motor2pwm, 150);
    
  }
     else if(LeftstickY>180)      ///backward
  {
    digitalWrite(motor1a,LOW);
    digitalWrite(motor1b,HIGH);
    analogWrite(motor1pwm, 150);
    
    digitalWrite(motor2a,LOW);
    digitalWrite(motor2b,HIGH);
    analogWrite(motor2pwm, 150);
    
  }
  else
  {
    digitalWrite(motor1a,HIGH);
    digitalWrite(motor1b,HIGH);
    
    
    digitalWrite(motor2a,HIGH);
    digitalWrite(motor2b,HIGH);
    
  }
    
  }

  if(RightstickX>180)
  {
    
    digitalWrite(motor_shota,HIGH);
    digitalWrite(motor_shotb,LOW);
    analogWrite(motor_shotpwm, 220);
   
  }
  else
  {
   digitalWrite(motor_shota,HIGH);
   digitalWrite(motor_shotb,HIGH);
     
  }
 }
void setup() {
  // put your setup code here, to run once:
remote_init();
Serial.begin(9600);

pinMode(motor1a,OUTPUT);
pinMode(motor1b,OUTPUT);
pinMode(motor1pwm,OUTPUT);
pinMode(motor2a,OUTPUT);
pinMode(motor2b,OUTPUT);
pinMode(motor2pwm,OUTPUT);
pinMode(motor_shota,OUTPUT);
pinMode(motor_shotb,OUTPUT);
pinMode(motor_shotpwm,OUTPUT);

Serial.begin(9600);
}

void loop() 
{
remote_read();
}#include <PS3BT.h>

#ifdef dobogusinclude
#include <spi4teensy3.ha>
#include <SPI.h>
#endif
#include <usbhub.h>

#define motor1a 2
#define motor1b 3
#define motor1pwm 4
#define motor2a 5
#define motor2b 6
#define motor2pwm 7
#define motor_shota 8
#define motor_shotb 9
#define motor_shotpwm 10

USB Usb;
BTD Btd(&Usb); // You have to create the Bluetooth Dongle instance like so
PS3BT PS3(&Btd);

int l1, r1, l2, r2, l3, r3, start, sel, tri, squ, cross, circle, up, down, right, left = 0;
int LeftstickX = 125;
int LeftstickY = 125;
int RightstickX = 125;
int RightstickY = 125;
bool debug_flag = false;

int ir_state=0, ir_state_last=0;

  void remote_init()
  {
    #if !defined(MIPSEL)
      while (!Serial); // Wait for serial port to connect - used on Leonardo, Teensy and other boards with built-in USB CDC serial connection
    #endif
      if (Usb.Init() == -1) {
        if (debug_flag)
          Serial.println(F("\r\nOSC did not start"));
        while (1); //halt
      }
      if (debug_flag)
        Serial.println(F("\r\nPS3 Bluetooth Library Started"));
  }
 
 
 void remote_read()
 {
 
  if(LeftstickX<45)      ////anticlockwise
  {
    digitalWrite(motor1a,HIGH);
    digitalWrite(motor1b,LOW);
    analogWrite(motor1pwm, 150);
    
    digitalWrite(motor2a,LOW);
    digitalWrite(motor2b,HIGH);
    analogWrite(motor2pwm, 150);
    
  }
  else if(LeftstickX>180)      ////clockwise
  {
    digitalWrite(motor1a,LOW);
    digitalWrite(motor1b,HIGH);
    analogWrite(motor1pwm, 150);
    
    digitalWrite(motor2a,HIGH);
    digitalWrite(motor2b,LOW);
    analogWrite(motor2pwm, 150);
    
  }
  else  if(LeftstickY<45)      ///forward
  {
    digitalWrite(motor1a,HIGH);
    digitalWrite(motor1b,LOW);
    analogWrite(motor1pwm, 150);
    
    digitalWrite(motor2a,HIGH);
    digitalWrite(motor2b,LOW);
    analogWrite(motor2pwm, 150);
    
  }
     else if(LeftstickY>180)      ///backward
  {
    digitalWrite(motor1a,LOW);
    digitalWrite(motor1b,HIGH);
    analogWrite(motor1pwm, 150);
    
    digitalWrite(motor2a,LOW);
    digitalWrite(motor2b,HIGH);
    analogWrite(motor2pwm, 150);
    
  }
  else
  {
    digitalWrite(motor1a,HIGH);
    digitalWrite(motor1b,HIGH);
    
    
    digitalWrite(motor2a,HIGH);
    digitalWrite(motor2b,HIGH);
    
  }
    
  }

  if(RightstickX>180)
  {
    
    digitalWrite(motor_shota,HIGH);
    digitalWrite(motor_shotb,LOW);
    analogWrite(motor_shotpwm, 220);
   
  }
  else
  {
   digitalWrite(motor_shota,HIGH);
   digitalWrite(motor_shotb,HIGH);
     
  }
 }
void setup() {
  // put your setup code here, to run once:
remote_init();
Serial.begin(9600);

pinMode(motor1a,OUTPUT);
pinMode(motor1b,OUTPUT);
pinMode(motor1pwm,OUTPUT);
pinMode(motor2a,OUTPUT);
pinMode(motor2b,OUTPUT);
pinMode(motor2pwm,OUTPUT);
pinMode(motor_shota,OUTPUT);
pinMode(motor_shotb,OUTPUT);
pinMode(motor_shotpwm,OUTPUT);

Serial.begin(9600);
}

void loop() 
{
remote_read();
}
