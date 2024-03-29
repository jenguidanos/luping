#pragma once

#include "luping-module-interface.h"

class BatteryModule : public LupingModule {
 public:
  virtual uint8_t loop();
  virtual uint8_t init();

  static int getVbat();
};
