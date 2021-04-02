#include "modules.h"

#include "luping.h"

BatteryModule *battery = new BatteryModule();
LedModule *led = new LedModule();

namespace lp {

void customModules() {
  lp::modules.add(battery);
  lp::modules.add(led);
}

}  // namespace lp

