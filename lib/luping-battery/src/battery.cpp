#include "battery.h"

#include "luping.h"

uint8_t BatteryModule::init() {
  lp::printf("Hello From battery!!\n");
  return 0;
}

uint8_t BatteryModule::loop() {
  lp::wait(1000);
  lp::printf("Loop from battery\n");
  lp::emit(0x01, 0);
  return 0;
}

int BatteryModule::getVbat() { return random(1000, 5000); }
