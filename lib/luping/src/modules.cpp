#include "modules.h"

#include "luping.h"

BatteryModule *battery;

namespace lp {

void customModules() {
  lp::modules.add(battery);
}

}  // namespace lp

