#include "battery.h"

#include "luping.h"

BatteryModule::BatteryModule() {}

uint8_t BatteryModule::init() {
  lp::printf("Hello From battery!!\n");
  return 0;
}

uint8_t BatteryModule::loop() {
  static uint32_t timeout = millis();
  while (millis() - timeout >= 1000) {
    lp::printf("Loop from battery\n");
    timeout = millis();
  }
  return 0;
}

int BatteryModule::getVbat() {
  // lp::wait(5000, []() { return 10; });
  return 0;
}
