#pragma once

#include "luping-module-interface.h"

class BatteryModule : public LupingModule {
 public:
  BatteryModule();
  ~BatteryModule();
  using LupingModule::init;

  virtual uint8_t loop();
  virtual uint8_t init();

  static int getVbat();
};
