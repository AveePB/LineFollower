#define ECHO 12
#define TRIG 13
#define BAUD_RATE 9600

class UltrasonicSensor {
  private:
    int trig;
    int echo;
  
  public:
    UltrasonicSensor() {
      this->echo = ECHO;
      this->trig = TRIG;
    }

    float measureDistance() {
      // Send a 10us pulse to trigger pin
      digitalWrite(trig, LOW);
      delayMicroseconds(2);
      digitalWrite(trig, HIGH);
      delayMicroseconds(10);
      digitalWrite(trig, LOW);

      // Read the echo pin
      long duration = pulseIn(echo, HIGH);

      // Convert to centimeters (speed of sound ~ 343 m/s)
      float distance = duration * 0.0343 / 2;
      return distance;
    }
};

UltrasonicSensor ultraSensor;

void setup() {
  Serial.begin(BAUD_RATE);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
}

void loop() {
  float dist = ultraSensor.measureDistance();
  Serial.print("Distance: ");
  Serial.print(dist);
  Serial.println(" cm");
  delay(500);
}
