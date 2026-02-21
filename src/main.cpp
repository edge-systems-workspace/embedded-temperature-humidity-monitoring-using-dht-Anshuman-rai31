#include <Arduino.h>
#include <DHT.h>

/**
 * @file `main.cpp`
 * @author Anshuman Rai
 * @date 2026-02-21
 * @brief Simple Arduino sketch to read temperature and humidity from a DHT11 sensor and print results to Serial.
 *
 * This sketch initializes a DHT11 sensor on the specified pin, reads humidity and temperature
 * every two seconds, checks for read errors, and prints values to the Serial console.
 */

/**
 * @brief Pin where the DHT sensor data line is connected.
 */
#define DHTPIN 2

/**
 * @brief DHT sensor model used (DHT11).
 */
#define DHTTYPE DHT11

/**
 * @brief DHT sensor object instantiated with the configured pin and type.
 */
DHT dht(DHTPIN, DHTTYPE);

/**
 * @brief Arduino setup function.
 *
 * Initializes the Serial interface and the DHT sensor.
 */
void setup() {
    Serial.begin(9600);
    dht.begin();
    Serial.println("DHT11 initialized");
}

/**
 * @brief Arduino main loop.
 *
 * Reads humidity and temperature from the DHT sensor, validates values,
 * and prints them to the Serial console. Delays 2000 ms between reads.
 */
void loop() {
    float humidity = dht.readHumidity();
    float temperature = dht.readTemperature();
    if (isnan(humidity) || isnan(temperature)) {
        Serial.println("Failed to read from DHT sensor!");
        delay(2000);
        return;
    }
    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.print(" %\t");
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" *C");
    delay(2000);
}