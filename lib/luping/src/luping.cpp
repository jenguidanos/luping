#include "luping.h"

#include "modules.h"

namespace lp {

LupingModules modules(LUPING_MAX_MODULES);

void begin() {
  lp::initConf();
  lp::initDebug();
  lp::customModules();
}

void yield() {}

void wait(unsigned long waitMillis) { modules.wait(waitMillis); }

}  // namespace lp

void loop() { lp::modules.loop(); }
