#include "luping.h"

#include "modules.h"

namespace lp {

LupingModules modules(LUPING_MAX_MODULES);

void begin() {
  lp::initConf();
  lp::initDebug();
  lp::modules.begin();
}

void loop() {
  static uint32_t timeout = millis();
  if (millis() - timeout > 1000) {
    timeout = millis();
    lp::printf("%s: %d", "Battery", battery->getVbat());
  }
}

}  // namespace lp

void loop() { lp::loop(); }
