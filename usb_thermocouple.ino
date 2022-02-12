#include <SPI.h>
#include "Adafruit_MAX31855.h"

#define STATUS_OK 0
#define VERSION "1.00"
#define INTERVAL_UPDATE 1000


#define MAXDO   1
#define MAXCS   2
#define MAXCLK  3

Adafruit_MAX31855 tm(MAXCLK, MAXCS, MAXDO);

void setup() {
  Serial.begin(9600);

  while (!Serial) delay(1);

  delay(500);
  if (!tm.begin()) {
    Serial.println("ERROR.");
    while (1) delay(10);
  }
}

void loop() {
  Serial.print("te=");
  int c = tm.readCelsius()*100;
  if (isnan(c)) {
  } else {
    Serial.print(c);
  }
  Serial.print(";status=");
  Serial.print(STATUS_OK);
  Serial.print(";version=");
  Serial.print(VERSION);
  Serial.print("\n");

  delay(INTERVAL_UPDATE);
}
