/**
 * @file L298nDriver.ino
 * @brief Example of controlling two DC motors with the L298N driver using Arduino Uno.
 *
 * This example demonstrates how to control the speed and direction of
 * two DC motors connected to an L298N dual H-bridge motor driver.
 * It uses PWM pins for speed control and digital pins for direction.
 */

#define ENA 9     ///< Enable pin (PWM) for left motor
#define IN1 8     ///< Input 1 for left motor direction
#define IN2 11    ///< Input 2 for left motor direction
#define IN3 12    ///< Input 3 for right motor direction
#define IN4 13    ///< Input 4 for right motor direction
#define ENB 10    ///< Enable pin (PWM) for right motor

#define BAUD_RATE 9600  ///< Serial communication baud rate
#define FORWARD 0       ///< Motor direction: forward
#define BACKWARD 1      ///< Motor direction: backward

/**
 * @class L298n
 * @brief Class to control two DC motors via an L298N dual H-bridge motor driver.
 *
 * This class provides methods to set direction and speed of each motor,
 * as well as to stop both motors. It supports PWM-based speed control
 * and digital direction control.
 */
class L298n {
  private:
    int ena;  ///< Left motor enable (PWM) pin
    int in1;  ///< Left motor direction control pin 1
    int in2;  ///< Left motor direction control pin 2
    int in3;  ///< Right motor direction control pin 1
    int in4;  ///< Right motor direction control pin 2
    int enb;  ///< Right motor enable (PWM) pin

  public:
    /**
     * @brief Construct a new L298n motor driver object.
     *
     * Initializes internal pin assignments for both motors.
     * Default pins are defined by macros at the top of this file.
     */
    L298n() {
      this->ena = ENA;
      this->in1 = IN1;
      this->in2 = IN2;
      this->in3 = IN3;
      this->in4 = IN4;
      this->enb = ENB;
    }

    /**
     * @brief Set the direction of the left motor.
     *
     * @param direction Motor direction: FORWARD or BACKWARD.
     */
    void setLeftMotorDirection(bool direction) {
      if (direction == FORWARD) {
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
      } else if (direction == BACKWARD) {
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
      }
    }

    /**
     * @brief Set the direction of the right motor.
     *
     * @param direction Motor direction: FORWARD or BACKWARD.
     */
    void setRightMotorDirection(bool direction) {
      if (direction == FORWARD) {
        digitalWrite(in3, LOW);
        digitalWrite(in4, HIGH);
      } else if (direction == BACKWARD) {
        digitalWrite(in3, HIGH);
        digitalWrite(in4, LOW);
      }
    }

    /**
     * @brief Set the speed of the left motor using PWM.
     *
     * @param speed PWM value (0–255), where 0 = stop, 255 = full speed.
     * @note The value is automatically constrained to the valid range.
     */
    void setLeftMotorSpeed(int speed) {
      analogWrite(ena, constrain(speed, 0, 255));
    }

    /**
     * @brief Set the speed of the right motor using PWM.
     *
     * @param speed PWM value (0–255), where 0 = stop, 255 = full speed.
     * @note The value is automatically constrained to the valid range.
     */
    void setRightMotorSpeed(int speed) {
      analogWrite(enb, constrain(speed, 0, 255));
    }

    /**
     * @brief Stop both motors immediately by setting PWM to zero.
     */
    void stopMotors() {
      analogWrite(ena, 0);
      analogWrite(enb, 0);
    }
};

// Create a global instance of the motor driver
L298n l298n;

/**
 * @brief Arduino setup function.
 *
 * Initializes serial communication and configures all motor driver pins as outputs.
 */
void setup() {
  Serial.begin(BAUD_RATE);

  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);
}

/**
 * @brief Arduino loop function.
 *
 * Demonstrates forward, backward, and stop motor actions in a repeating sequence.
 */
void loop() {
  // Move forward for 2 seconds
  Serial.println("Motors move forward!");
  l298n.setLeftMotorDirection(FORWARD);
  l298n.setRightMotorDirection(FORWARD);
  l298n.setLeftMotorSpeed(200);
  l298n.setRightMotorSpeed(200);
  delay(2000);

  // Move backward for 2 seconds
  Serial.println("Motors move backward!");
  l298n.setLeftMotorDirection(BACKWARD);
  l298n.setRightMotorDirection(BACKWARD);
  l298n.setLeftMotorSpeed(200);
  l298n.setRightMotorSpeed(200);
  delay(2000);

  // Stop motors for 2 seconds
  Serial.println("Motors are stopped!");
  l298n.stopMotors();
  delay(2000);
}

