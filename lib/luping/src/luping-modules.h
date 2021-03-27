#pragma once
#include "luping-module.h"

class LupingModules {
 public:
  LupingModules(const size_t size);
  uint8_t begin();
  uint8_t add(LupingModule* module);
  uint8_t enable(LupingModule* module);
  uint8_t disable(LupingModule* module);

 private:
  LupingModule** modules;
};
