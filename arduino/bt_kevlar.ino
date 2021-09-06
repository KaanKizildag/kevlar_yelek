#include<SoftwareSerial.h>

#define RX 10
#define TX 11
#define baud 9600
#define input 5

SoftwareSerial mySerial = SoftwareSerial(RX, TX);

unsigned long timer;

void setup() {
  pinMode(input, INPUT);
  Serial.begin(baud);
  mySerial.begin(baud);
  timer = millis();
}

void loop() {

  if (digitalRead(input) == 0) {
    if (millis() - timer > 3000) {
      String data = "{\"mesaj\" : \"Mesaj gonder\",\"zaman\": " + String(millis()) + "\"}";
      Serial.println(data);
      mySerial.print(data + "\r");
      timer = millis();
    }
  }
  else {
    Serial.println("timer sıfırlandı");
    timer = millis();
  }

}
