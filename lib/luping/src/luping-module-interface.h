#pragma once
#include <Arduino.h>

#include "core/debug.h"

class LupingModule {
 public:
  virtual uint8_t init() = 0;
  virtual uint8_t loop() = 0;

  void enable() { this->enabled = true; };

  void disable() { this->enabled = false; }

  bool isEnabled() { return this->enabled; };

  void test() {}

 private:
  bool enabled = false;
};
