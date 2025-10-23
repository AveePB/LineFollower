/**
 * @file UltrasonicSensor.ino
 * @brief Example sketch using an UltrasonicSensor class to measure distance.
 */

#define ECHO 6   ///< Pin connected to the echo pin of the ultrasonic sensor
#define TRIG 5   ///< Pin connected to the trigger pin of the ultrasonic sensor
#define BAUD_RATE 9600  ///< Serial communication baud rate

/**
 * @class UltrasonicSensor
 * @brief A simple class for measuring distance using an ultrasonic sensor.
 */
class UltrasonicSensor {
  private:
    int trig; ///< Trigger pin
    int echo; ///< Echo pin
  
  public:
    /**
     * @brief Constructor initializes trigger and echo pins using predefined macros.
     */
    UltrasonicSensor() {
      this->echo = ECHO;
      this->trig = TRIG;
    }

    /**
     * @brief Measures the distance using the ultrasonic sensor.
     *
     * Sends a short pulse on the trigger pin and reads the time it takes
     * for the echo to return. Converts the duration to distance in centimeters.
     *
     * @return Distance in centimeters.
     */
    float measureDistance() {
      // Send a 10µs pulse to trigger pin
      digitalWrite(trig, LOW);
      delayMicroseconds(2);
      digitalWrite(trig, HIGH);
      delayMicroseconds(10);
      digitalWrite(trig, LOW);

      // Read the echo pin (time in microseconds)
      long duration = pulseIn(echo, HIGH);

      // Convert to centimeters (speed of sound ~343 m/s)
      float distance = duration * 0.0343 / 2;
      return distance;
    }
};

/// Global ultrasonic sensor instance
UltrasonicSensor ultraSensor;

/**
 * @brief Arduino setup function.
 *
 * Initializes serial communication and configures the trigger and echo pins.
 */
void setup() {
  Serial.begin(BAUD_RATE);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
}

/**
 * @brief Arduino loop function.
 *
 * Continuously measures distance and prints the result to the serial monitor.
 */
void loop() {
  float dist = ultraSensor.measureDistance();
  Serial.print("Distance: ");
  Serial.print(dist);
  Serial.println(" cm");
  delay(500);
}
