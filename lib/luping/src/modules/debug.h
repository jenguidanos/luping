#pragma once
#include <Arduino.h>

namespace lp {

void initDebug();
void print();
void printf(const char *fmt, ...);
void _printf(const __FlashStringHelper *fmt, ...);

}  // namespace lp
