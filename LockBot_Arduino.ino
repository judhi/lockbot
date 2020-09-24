/********************************************/
/* Smart Key with Single Button             */
/* by Judhi Prasetyo                        */
/* Sep 20, 2020                             */
/* https://github.com/judhi/lockbot         */
/* Unlocking by entering a binary sequence  */
/* using a single button                    */
/* Short press = 0, Long press = 1          */
/********************************************/
#include <Servo.h>
Servo Servo1;

int mySecretCode[6] = {0,0,1,0,1,1};     // our secret code here
int c;
int index = 0;
int button_pin = 7;
int LED_pin = 13;
int servoPin = 3;

bool b;
bool b_old = 0;
bool change_state;
unsigned long t_start, d;


void setup() {
  Servo1.attach(servoPin);
  pinMode(LED_pin, OUTPUT);
  pinMode(button_pin, INPUT);
  Serial.begin(115200);
  Serial.print("Code[");
  Serial.print(index);
  Serial.print("]:");
}

void loop() {
  b = digitalRead(7);

  if (b && !b_old) {                        // beginning of button pressed
    b_old = 1;
    t_start = millis();
  }

  if (!b && b_old) {                        // end of button pressed
    b_old = 0;
    d = millis() - t_start;
    if (d < 250) {                          //  if pressed less than 1/4s
      c = 0;                                // take it as 0
    } else {                                // otherwise
      c = 1;                                // take it as 1
    }
    Serial.println(c);
    if (mySecretCode[index] == c) {          // compare it with secret key index
      index++;                              // and move to next index if correct
    } else {                                // otherwise, start all over again
      index = 0;                            // by resetting the index
    }
    if (index == sizeof(mySecretCode) / 2) { // if full key is correct 
      success();                            // do something here
      index = 0;                            // and start over again
    }
    Serial.print("Code[");
    Serial.print(index);
    Serial.print("]:");
  }
  delay(20);
}

void success() {                            // executed when successfully entered the keys
  Serial.println("SUCCESS!!!");
  digitalWrite(LED_pin, HIGH);
  Servo1.write(0);
  delay(2000);
  digitalWrite(LED_pin, LOW);
  Servo1.write(90);
  delay(1000);
  return 0;
}
