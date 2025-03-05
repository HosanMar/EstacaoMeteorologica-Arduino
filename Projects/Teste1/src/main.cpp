#include <Arduino.h>
#include <dht.h>
#include <Wire.h>
#include <Adafruit_BMP085.h>

Adafruit_BMP085 bmp;
dht DHT;

#define DHT11_PIN 7

int LDR = A0;
const int motorPin = A2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  if (!bmp.begin()) {
    Serial.println("Erro ao iniciar o sensor BMP085!");
    while (1); // Para o código aqui caso o sensor falhe
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  
  DHT.read11(DHT11_PIN);

  Serial.print("Temperature = ");
  Serial.println(DHT.temperature);

  Serial.print("Humidity = ");
  Serial.println(DHT.humidity);


  int pressure = bmp.readPressure();
  Serial.print("Pressure = ");
  Serial.print(pressure);
  Serial.println(" Pa");

  int LDRValue = analogRead(LDR);
  Serial.print("Luminosidade = ");
  Serial.println(LDRValue);

  if (LDRValue >= 700)
  {
    Serial.println("Está ensolarado!");
  } else if (LDRValue <= 300)
  {
    Serial.println("Está de noite.");
  } else {
    Serial.println("Está nublado.");
  }

  int velocidadeVento = analogRead(motorPin);
  Serial.print("Velocidade do Vento = ");
  Serial.println(velocidadeVento); // Exibe o valor no monitor serial
    

  //Serial.print("   ");

  
  delay(5000);
}

