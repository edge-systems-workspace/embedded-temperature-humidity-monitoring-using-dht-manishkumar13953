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

void setup() {

    // TODO 4:
    // Initialize Serial communication (9600 baud rate)

    // TODO 5:
    // Initialize the DHT sensor

    // TODO 6:
    // Print a system initialization message
}

void loop() {

    // TODO 7:
    // Read humidity value from sensor

    // TODO 8:
    // Read temperature value from sensor

    // TODO 9:
    // Check if either reading failed using isnan()
    // If failed, print error message and return

    // TODO 10:
    // Print formatted temperature and humidity values

    // TODO 11:
    // Add a 2-second delay before next reading
}
