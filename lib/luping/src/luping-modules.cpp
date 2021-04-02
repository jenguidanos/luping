#include "luping-modules.h"

#include <stdarg.h>

#include "luping.h"
#include "modules.h"

LupingModules::LupingModules(const int size) {
  this->modules = new LupingModule*[size];
  this->enabled = new int[size];
  this->yielding = new int[size];
  this->maxModules = size;
  this->reset();
}

uint8_t LupingModules::add(LupingModule* module) {
  int index = this->getEmptyIndex();
  if (index == -1) return 1;
  lp::printf("index %d\n", index);
  this->modules[index] = module;
  this->modules[index]->init();
  return 0;
}

uint8_t LupingModules::loop() {
  if (this->running + 1 >= this->maxModules) {
    this->running = 0;
  }

  if (this->modules[this->running]) {
    this->modules[this->running]->test();
    this->modules[this->running]->loop();
  }

  this->running++;

  return 0;
}

uint8_t LupingModules::enable(LupingModule* module) { return 0; }

uint8_t LupingModules::disable(LupingModule* module) { return 0; }

uint8_t LupingModules::begin() { return 0; }

void LupingModules::reset() {
  running = 0;
  for (int i = 0; i < this->maxModules; i++) {
    this->reset(i);
  }
}

void LupingModules::reset(int index) {
  this->modules[index] = 0;
  this->yielding[index] = 0;
  this->enabled[index] = 0;
}

int LupingModules::getEmptyIndex() {
  for (auto i = 0; i < this->maxModules; i++) {
    if (this->modules[i] == 0) {
      return i;
    }
  }

  return -1;
}

int LupingModules::getModule(LupingModule* module) {
  int result = -1;
  for (auto i = 0; i < this->maxModules; i++) {
    if (this->modules[i] == module) {
      result = i;
    }
  }

  return result;
}
