#include<SoftwareSerial.h>

#define RX 10
#define TX 11
#define baud 9600
#define input A0

SoftwareSerial mySerial = SoftwareSerial(RX, TX);

unsigned long timer;

void setup() {
  pinMode(input, INPUT);
  Serial.begin(baud);
  mySerial.begin(baud);
  timer = millis();
}

void loop() {

  if (!baglantiVarmi()) {
    if (millis() - timer > 3000) {
      String data = "{\"mesaj\" : \"Mesaj gonder\",\"zaman\": " + String(millis()) + "\"}";
      Serial.println(data);
      mySerial.print(data + "\r");
      timer = millis();
      // geçici
      while(1);
    }
  }
  
  else {
    Serial.println("timer sıfırlandı");
    timer = millis();
  }

}

bool baglantiVarmi(){
  return analogRead(input) > 1000;
}
