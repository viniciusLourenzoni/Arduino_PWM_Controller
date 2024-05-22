#include <Arduino.h>

const int motor = 9;
const int button = 2;

int velocidadeMotor = 255;
int velocidadeInicialMotor;
int estadoBotao;
int ultimoEstadoBotao = LOW;

void setup()
{
  pinMode(button, INPUT);
  pinMode(motor, OUTPUT);
}

void loop()
{
  estadoBotao = digitalRead(button);

  if (estadoBotao == HIGH && ultimoEstadoBotao == LOW)
  {
    velocidadeMotor -= 64;

    if (velocidadeMotor <= 0)
    {
      velocidadeMotor = 255;
    }

    analogWrite(motor, velocidadeMotor);

    delay(50);
  }
  ultimoEstadoBotao = estadoBotao;
}
