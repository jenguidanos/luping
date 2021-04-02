#pragma once
#include <Arduino.h>
#include <macros.h>

#include "core/puf.h"
#include "luping-modules.h"

typedef pufcb lupingEvent;

namespace lp {

extern LupingModules modules;

void begin();
void loop();
void yield();
bool on(unsigned char eventName, lupingEvent (*callback)(int param));
void off(unsigned char eventName, lupingEvent (*callback)());
unsigned char emit(unsigned char eventName, int param);
void wait(unsigned long waitMillis);

}  // namespace lp

#include "conf/luping-conf.h"
#include "core/debug.h"
