#include "modules.h"

#include "luping.h"

BatteryModule *battery = new BatteryModule();

namespace lp {

void customModules() {
  lp::modules.add(battery);
}

}  // namespace lp

