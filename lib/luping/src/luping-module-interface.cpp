#include "luping-module-interface.h"

#include <stdarg.h>

#include "luping.h"

LupingModule::LupingModule() {}
LupingModule::~LupingModule() {}

bool LupingModule::isEnabled() { return this->enabled; }
