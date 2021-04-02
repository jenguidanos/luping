#include "led.h"

#include "modules.h"

uint8_t LedModule::init() {
  lp::printf("Hello From led!!\n");
  pinMode(lp::conf.led.pin, OUTPUT);
  lp::on(0x01, LedModule::onBattery);
  return 0;
}

uint8_t LedModule::loop() {
  lp::wait(lp::conf.led.time);
  lp::printf("Loop from led\n");
  digitalWrite(lp::conf.led.pin, !digitalRead(lp::conf.led.pin));
  return 0;
}

int LedModule::getVbat() { return 0; }

lupingEvent LedModule::onBattery(int param) {
  lp::printf("Led: onBattery from lupingEvent: %d\n", battery->getVbat());
  return 0;
}
