#include <Arduino.h>
#include <TFT_eSPI.h>                                           // Hardware-specific library
#include <SPI.h>

uint32_t cpufreq;
uint8_t state = 0;

TFT_eSPI mydisplay = TFT_eSPI();                                //Objekt mydisplay erzeugen

void setup() {
  pinMode(25, OUTPUT);
  mydisplay.resetViewport();
  mydisplay.init();                                             //Initialisierung
  mydisplay.setRotation(1);
  mydisplay.fillScreen(TFT_DARKGREY);
  mydisplay.fillRoundRect(10,10,300,220,20,TFT_LIGHTGREY);
  mydisplay.setTextColor(TFT_BLACK);
  mydisplay.drawCentreString("aktuelle Frequenz:",160,30,4);
}

void loop() {
  setCpuFrequencyMhz(80);
  cpufreq = getCpuFrequencyMhz();
  mydisplay.drawNumber(cpufreq,160,100,4);
  switch (state) {
    case 0:
      digitalWrite(25, HIGH);
      state = 1;
      break;

    case 1:
      digitalWrite(25, LOW);
      state = 0;
      break;
  }
}
