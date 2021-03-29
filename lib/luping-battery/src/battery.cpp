#include "battery.h"

#include "luping.h"

BatteryModule::BatteryModule() {}

BatteryModule::~BatteryModule() {}

uint8_t BatteryModule::init() { return 0; }

uint8_t BatteryModule::enable() { return 0; }

uint8_t BatteryModule::disable() { return 0; }

int BatteryModule::getVbat() { return 10; }
