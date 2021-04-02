#pragma once

#include "luping-module-interface.h"
#include "luping.h"

class LedModule : public LupingModule {
 public:
  virtual uint8_t loop();
  virtual uint8_t init();

  int getVbat();

  static lupingEvent onBattery(int param);
};
