#pragma once
#include <Arduino.h>
#include <macros.h>

#include "luping-modules.h"

namespace lp {

extern LupingModules modules;

void begin();
void loop();
void yield();
void wait(unsigned long waitMillis);

}  // namespace lp

#include "conf/luping-conf.h"
#include "core/debug.h"
