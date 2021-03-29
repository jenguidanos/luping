#include "luping-modules.h"

#include <stdarg.h>

#include "luping.h"

LupingModules::LupingModules(const size_t size) {
  this->modules = new LupingModule*[size];
}

uint8_t LupingModules::add(LupingModule* module) {
  this->modules[0] = module;
  return 0;
}

uint8_t LupingModules::enable(LupingModule* module) { return 0; }

uint8_t LupingModules::disable(LupingModule* module) { return 0; }

uint8_t LupingModules::begin() { return 0; }
