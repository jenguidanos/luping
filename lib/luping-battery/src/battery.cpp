#include "battery.h"

#include "luping.h"

BatteryModule::BatteryModule() {}

uint8_t BatteryModule::init() {
  lp::printf("Hello From battery!!\n");
  return 0;
}

uint8_t BatteryModule::loop() { return 0; }

uint8_t BatteryModule::enable() { return 0; }

uint8_t BatteryModule::disable() { return 0; }

int BatteryModule::getVbat() {
  // lp::wait(5000, []() { return 10; });
  return 0;
}
