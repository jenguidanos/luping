#pragma once
#include <Arduino.h>

class LupingModule {
 public:
  virtual uint8_t init() = 0;
  virtual uint8_t loop() = 0;
  uint8_t enable();
  uint8_t disable();

  bool isEnabled();

 private:
  bool enabled = false;
};
