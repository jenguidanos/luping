#include "luping.h"

namespace lp {

LupingModules modules(LUPING_MAX_MODULES);

void begin() {
  lp::initConf();
  lp::initDebug();
}

void loop() {
  static uint32_t timeout = millis();
  if (millis() - timeout > 1000) {
    timeout = millis();
    lp::printf("%s", "Looping");
  }
}

}  // namespace lp

void loop() { lp::loop(); }
