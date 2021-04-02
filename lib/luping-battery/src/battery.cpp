#include "battery.h"

#include "luping.h"

uint8_t BatteryModule::init() {
  lp::printf("Hello From battery!!\n");
  return 0;
}

uint8_t BatteryModule::loop() {
  lp::wait(1000);
  lp::printf("Loop from battery\n");
  return 0;
}

int BatteryModule::getVbat() { return 0; }
