#include <Arduino.h>
#include <SoftwareSerial.h>

SoftwareSerial BT(10, 11);

const int LeftMotorForward = 4;
const int LeftMotorBackward = 5;
const int RightMotorForward = 6;
const int RightMotorBackward = 7;

void setup()
{
  pinMode(RightMotorForward, OUTPUT);
  pinMode(LeftMotorForward, OUTPUT);

  pinMode(LeftMotorBackward, OUTPUT);
  pinMode(RightMotorBackward, OUTPUT);
  BT.begin(9600);
  Serial.begin(9600);
}

void moveStop()
{

  digitalWrite(RightMotorForward, LOW);
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);
  digitalWrite(LeftMotorBackward, LOW);
}

void moveForward()
{
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorForward, HIGH);

  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorBackward, HIGH);
}

void moveBackward()
{
  digitalWrite(LeftMotorBackward, HIGH);
  digitalWrite(RightMotorBackward, LOW);

  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorForward, LOW);
}

void turnRight()
{

  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorBackward, HIGH);

  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorForward, LOW);
}

void turnLeft()
{

  digitalWrite(LeftMotorBackward, HIGH);
  digitalWrite(RightMotorForward, HIGH);

  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);
}

void loop()
{
    BT.read();
    if (BT.read() == 'a') // DETENER
    {
      moveStop();
      Serial.println("DETENER");
    }
    else if (BT.read() == 'b') // ADELANTE
    {
      moveForward();
      Serial.println("ADELANTE");
    }

    else if (BT.read() == 'c')
    {
      moveBackward();
      Serial.println("ATRAS");
    }

    else if (BT.read() == 'd')
    {
      turnRight();
      Serial.println("DERECHA");
    }

    else if (BT.read() == 'e')
    {
      turnLeft();
      Serial.println("IZQUIERDA");
    }
}
