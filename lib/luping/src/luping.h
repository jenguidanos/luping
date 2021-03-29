#pragma once

#include <Arduino.h>

#include "luping-modules.h"

namespace lp {

extern LupingModules modules;

void begin();
void loop();

}  // namespace lp

#include "conf/luping-conf.h"
#include "core-modules/debug.h"
