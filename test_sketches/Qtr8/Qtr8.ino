/**
 * @file QTR8.ino
 * @brief Example sketch demonstrating use of the QTR-8 reflectance sensor array.
 */

#define EMITTER_PIN 2  ///< Pin controlling the IR emitter LEDs on the QTR sensor
#define D1 3           ///< Sensor channel 1 pin
#define D2 4           ///< Sensor channel 2 pin
#define D3 A5          ///< Sensor channel 3 pin
#define D4 A4          ///< Sensor channel 4 pin
#define D5 A3          ///< Sensor channel 5 pin
#define D6 A2          ///< Sensor channel 6 pin
#define D7 A1          ///< Sensor channel 7 pin
#define D8 A0          ///< Sensor channel 8 pin

#include <QTRSensors.h>  ///< Pololu QTRSensors library for reflectance sensor arrays

QTRSensors qtr;              ///< QTRSensors object for handling sensor operations
uint16_t sensorValues[8];    ///< Array to store reflectance readings from all 8 sensors

/**
 * @brief Arduino setup function.
 *
 * Initializes serial communication, configures the QTR sensor array,
 * and performs calibration to determine reflectance range.
 */
void setup() {
  Serial.begin(9600);

  // Configure line sensor
  qtr.setTypeRC();  ///< Set sensor type to RC (for digital I/O operation)
  qtr.setSensorPins((const uint8_t[]){D1, D2, D3, D4, D5, D6, D7, D8}, 8);  ///< Assign pins
  qtr.setEmitterPin(EMITTER_PIN);  ///< Assign emitter control pin
  delay(1000);  ///< Allow time for sensor stabilization

  // Calibrate for ~10 seconds (400 iterations × ~2.5 ms each)
  Serial.println("Start of calibration!");
  for (int i = 0; i < 400; i++) qtr.calibrate();
  Serial.println("End of calibration!");
}

/**
 * @brief Arduino loop function.
 *
 * Continuously reads sensor reflectance values and prints them to the serial monitor.
 * The function also computes the estimated line position using `readLineBlack()`.
 */
void loop() {
  // Read calibrated sensor data and line position
  uint16_t position = qtr.readLineBlack(sensorValues);

  // Print sensor readings
  Serial.print("Read: ");
  for (int i = 0; i < 8; i++) {
    Serial.print(sensorValues[i]);
    Serial.print(' ');
  }
  Serial.print('\n');
}
