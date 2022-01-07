#include <SPI.h>
#include <RF24.h>

#define jX A0
#define jY A1
#define CE 9
#define CNS 10

RF24 transmiter(CE, CNS);
const uint64_t adress = 0x0F0F0F0F0E1LL;
const char text[] = "SPI IS WORKING!\n";
  
void setup()
{
  Serial.begin(9600);
  transmiter.begin();
  transmiter.openWritingPipe(adress);
  transmiter.setPALevel(RF24_PA_MIN);
  transmiter.stopListening();
}

void loop() 
{
  Serial.print(analogRead(jX));
  Serial.print(" : ");
  Serial.print(analogRead(jY));
  Serial.print("\n");

  transmiter.write(&text, sizeof(text));
  delay(500);
  
}
