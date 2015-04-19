/*
 * findBaudTest - Test all supported baud settings
 *
 * The progress and results are printed to Serial, so open the 'Serial
 * Montitor'.
 *
 * The progress and results will be easier to read if you disable the
 * debugging (comment out or delete the "#define DEBUG_HC05" line in
 * HC05.h.
 */
#include <Arduino.h>
#include <SoftwareSerial.h>

#include "HC05.h"


HC05 btSerial = HC05(16, 17);  // cmd, state
void setup()
{
  DEBUG_BEGIN(57600);
  Serial.begin(57600);
  delay(1000);
  Serial.println("---------- Setup ----------");
  btSerial.findBaud();
  btSerial.setBaud(115200);
  Serial.println("---------- Starting Echo ----------");
}

void loop()
{
  if (Serial.available()) {
    btSerial.write(Serial.read());
  }
  
  if(btSerial.available()) {
    Serial.write(btSerial.read());
  }
  
  
}
