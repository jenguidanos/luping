#pragma once

#include <Arduino.h>

#include "luping-modules.h"

namespace lp {

extern LupingModules modules;

void begin();
void loop();

}  // namespace lp

#include "luping-conf.h"
#include "modules/debug.h"
