#pragma once
#include "luping-module-interface.h"

class LupingModules {
 public:
  LupingModules(const int size);

  uint8_t begin();
  uint8_t add(LupingModule* module);
  uint8_t loop();

  void wait(uint32_t mill);

 private:
  int running;
  int maxModules;
  LupingModule** modules;
  int* enabled;

  int getEmptyIndex();
  int getModule(LupingModule* module);
  void reset();
  void reset(int i);
};
