// this example is public domain. enjoy!
// www.ladyada.net/learn/sensors/thermocouple

#include "max6675.h"

unsigned long old_millis = 0;
unsigned long delta = 1000;
int minuti = 1;

int thermoDO = 2;
int thermoCS = 3;
int thermoCLK = 4;

MAX6675 thermocouple(thermoCLK, thermoCS, thermoDO);
int vccPin = 5;
int gndPin = 6;

void setup() {
  Serial.begin(9600);
  // use Arduino pins
  pinMode(vccPin, OUTPUT); digitalWrite(vccPin, HIGH);
  pinMode(gndPin, OUTPUT); digitalWrite(gndPin, LOW);

  Serial.println("MAX6675 test");
  // wait for MAX chip to stabilize
  delay(500);
}

void loop() {
  // basic readout test, just print the current temp

  unsigned long now = millis () ; // variabile
  if (now > old_millis + delta) { //se il tempo attuale
  Serial.print (minuti);
    Serial.print (",");
    Serial.println(thermocouple.readCelsius());
    old_millis = now; // terminato il ciclo pone il valore
    minuti = minuti + 1; // incrementa il contatoredi minuti
  }
    delay(1); //pausa nell' esecuzione del ciclo
  }
