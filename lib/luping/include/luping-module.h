#pragma once
#include <Arduino.h>

class LupingModule {
 public:

  LupingModule();
  virtual ~LupingModule();

  virtual uint8_t init() = 0;
  virtual uint8_t enable() = 0;
  virtual uint8_t disable() = 0;
  bool isEnabled();

 private:
  bool enabled = false;
};
