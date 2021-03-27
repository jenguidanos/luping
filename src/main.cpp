#include "luping.h"
#include "modules/battery/battery.h"

Battery *batteryModule;

void setup() {
  lp::modules.add(batteryModule);
  lp::begin();
}
