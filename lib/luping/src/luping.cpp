#include "luping.h"

#include "modules.h"

Puf lupingPuf;

namespace lp {

LupingModules modules(LUPING_MAX_MODULES);

void begin() {
  lp::initConf();
  lp::initDebug();
  lupingPuf.reset();
  lp::customModules();
}

void yield() { /* modules.yield() */ }

void wait(unsigned long waitMillis) { modules.wait(waitMillis); }

bool on(unsigned char eventName, lupingEvent (*callback)(int param)) {
  return lupingPuf.on(eventName, callback);
}

unsigned char emit(unsigned char eventName, int param) {
  return lupingPuf.emit(eventName, param);
}

}  // namespace lp

void loop() { lp::modules.loop(); }
