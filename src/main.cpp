#include <Arduino.h>
/**
 * @file main.ino
 * @brief Embedded Temperature and Humidity Monitoring using DHT11
 * @author MANISH_KUMAR
 * @date 2026-02-09
 *
 * @details
 * This program reads environmental data from the DHT11 sensor
 * and displays temperature and humidity values on Serial Monitor.
 * Students must complete the TODO sections.
 */

#include <DHT.h>

// TODO 1:
// Define the DHT data pin (Use digital pin 2)

// TODO 2:
// Define the DHT sensor type (DHT11)

// TODO 3:
// Create a DHT object using the defined pin and sensor type
#define DHTPIN 2

byte data[5];

void setup()
{
  Serial.begin(9600);
  pinMode(DHTPIN, OUTPUT);
}

void loop()
{
  if (readDHT())
  {
    Serial.print("Temperature: ");
    Serial.print(data[2]);
    Serial.print(" °C  ");

    Serial.print("Humidity: ");
    Serial.print(data[0]);
    Serial.println(" %");
  }
  else
  {
    Serial.println("Error reading DHT11");
  }

  delay(2000);
}

int readDHT()
{
  byte i, j;

  for (i = 0; i < 5; i++)
    data[i] = 0;

  pinMode(DHTPIN, OUTPUT);
  digitalWrite(DHTPIN, LOW);
  delay(20);
  digitalWrite(DHTPIN, HIGH);
  delayMicroseconds(30);
  pinMode(DHTPIN, INPUT);

  if (pulseIn(DHTPIN, LOW) == 0) return 0;
  if (pulseIn(DHTPIN, HIGH) == 0) return 0;

  for (i = 0; i < 40; i++)
  {
    pulseIn(DHTPIN, LOW);
    if (pulseIn(DHTPIN, HIGH) > 40)
      data[i / 8] |= (1 << (7 - (i % 8)));
  }

  if (data[4] == (data[0] + data[1] + data[2] + data[3]))
    return 1;
  else
    return 0;
}
