#include "led.h"

#include "luping.h"

uint8_t LedModule::init() {
  lp::printf("Hello From led!!\n");
  pinMode(lp::conf.led.pin, OUTPUT);
  return 0;
}

uint8_t LedModule::loop() {
  lp::wait(lp::conf.led.time);
  lp::printf("Loop from led\n");
  digitalWrite(lp::conf.led.pin, !digitalRead(lp::conf.led.pin));
  return 0;
}

int LedModule::getVbat() { return 0; }
