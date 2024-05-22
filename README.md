# Controle de Velocidade de Motor DC com Arduino

## Componentes necessários
- 1x Arduino Nano
- 1x Motor DC
- 1x Driver de motor L293D
- 1x Botão
- 1x Resistor 10kΩ
- 1x Fonte de alimentação 5V
- Fios e protoboard

## Esquemático
O esquemático do projeto é mostrado dentro da pasta schematics.

## Código-fonte

```cpp
#include <Arduino.h>

// Definições de pinos
const int motorPin = 9;  // Pino do motor (PWM)
const int buttonPin = 2; // Pino do botão

// Variáveis
int motorSpeed = 0; // Velocidade inicial do motor (parado)
int buttonState;    // Estado atual do botão
int lastButtonState = LOW; // Estado anterior do botão

void setup()
{
  pinMode(buttonPin, INPUT); // Define o pino do botão como entrada
  pinMode(motorPin, OUTPUT); // Define o pino do motor como saída
}

void loop()
{
  // Lê o estado atual do botão
  buttonState = digitalRead(buttonPin);

  // Verifica se o botão foi pressionado
  if (buttonState == HIGH && lastButtonState == LOW)
  {
    // Incrementa a velocidade do motor
    motorSpeed += 64;
    
    // Verifica se a velocidade ultrapassou o máximo (255)
    if (motorSpeed > 255)
    {
      motorSpeed = 0; // Reinicia a velocidade do motor para parado
    }
    
    // Define a velocidade do motor
    analogWrite(motorPin, motorSpeed);

    // Pequena pausa para evitar leitura múltipla do botão
    delay(50);
  }

  // Atualiza o estado anterior do botão
  lastButtonState = buttonState;
}
