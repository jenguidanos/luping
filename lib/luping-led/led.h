#pragma once

#include "luping-module-interface.h"

class LedModule : public LupingModule {
 public:
  virtual uint8_t loop();
  virtual uint8_t init();
  static int getVbat();
};
