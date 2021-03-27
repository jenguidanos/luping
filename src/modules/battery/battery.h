#pragma once

#include "luping-module.h"

class Battery : public LupingModule {

public:
  Battery();
  virtual ~Battery();

  virtual uint8_t init();
  virtual uint8_t enable();
  virtual uint8_t disable();
};
