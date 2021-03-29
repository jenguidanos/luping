#pragma once

#include "luping-module-interface.h"

class BatteryModule : public LupingModule {
 public:
  BatteryModule();
  virtual ~BatteryModule();

  virtual uint8_t init();
  virtual uint8_t enable();
  virtual uint8_t disable();

  static int getVbat();
};
