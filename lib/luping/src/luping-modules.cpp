#include "luping-modules.h"

#include <stdarg.h>

#include "luping.h"
#include "modules.h"

LupingModules::LupingModules(const int size) {
  this->modules = new LupingModule*[size];
  this->enabled = new int[size];
  this->maxModules = size;
  this->reset();
}

uint8_t LupingModules::add(LupingModule* module) {
  int index = this->getEmptyIndex();
  if (index == -1) return 1;

  this->modules[index] = module;
  this->modules[index]->enable();
  return this->modules[index]->init();
}

uint8_t LupingModules::loop() {
  if (this->running >= this->maxModules) {
    this->running = 0;
  }

  int i = this->running;

  if (this->modules[i] == 0 || !this->modules[i]->isEnabled()) {
    this->running++;
    return 0;
  }

  this->modules[i]->loop();
  this->running++;

  return 0;
}

uint8_t LupingModules::begin() { return 0; }

void LupingModules::reset() {
  running = 0;
  for (int i = 0; i < this->maxModules; i++) {
    this->reset(i);
  }
}

void LupingModules::reset(int index) {
  this->modules[index] = 0;
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

void LupingModules::wait(uint32_t mill) {
  int i = this->running;

  this->modules[i]->disable();

  uint32_t timeout = millis();
  while (millis() - timeout < mill) {
    this->loop();
  }

  this->modules[i]->enable();
}
