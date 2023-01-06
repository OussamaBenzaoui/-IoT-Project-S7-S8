#include <SPI.h>
#include <LoRa.h>

int counter = 0;
#define SS      18//5
#define RST     14
#define DI0     26//33

void setup() {
  
  SPI.begin(5 , 19, 27, 18);
  LoRa.setPins(SS, RST, DI0);
  
  Serial.begin(115200);
  while (!Serial);

  Serial.println("LoRa Sender");

  if (!LoRa.begin(868E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
   LoraBegin(868E6, 125E3, 9, 7, 0x12, 8,25);
   Serial.println("test");
}

void loop() {
  Serial.print("Sending packet: ");
  Serial.println(counter);

  // send packet
  LoRa.beginPacket();
  LoRa.print(" mission done ");
  LoRa.print(counter);
  LoRa.endPacket();

  counter++;

  //delay(5000);
}
void LoraBegin(float freq, float bw, uint8_t sf, uint8_t cr, uint8_t syncWord, uint16_t preambleLength, int power)  {

  LoRa.begin(freq);

  LoRa.setSignalBandwidth(bw);

  LoRa.setSpreadingFactor(sf);

  LoRa.setCodingRate4(cr);

  LoRa.setSyncWord(syncWord);

  LoRa.setPreambleLength(preambleLength);

  LoRa.setTxPower(power);

}
