#include "debug.h"

#include <Arduino.h>
#include <stdarg.h>

namespace lp {

void initDebug() {
  Serial.begin(115200);
  delay(1000);
  printf("Welcome!");
}
void print() {}

// credits: https://playground.arduino.cc/Main/Printf/
void printf(const char *fmt, ...) {
  char buf[128];  // resulting string limited to 128 chars
  va_list args;
  va_start(args, fmt);
  vsnprintf(buf, 128, fmt, args);
  va_end(args);
  Serial.print(buf);
}

// credits: https://playground.arduino.cc/Main/Printf/
void _printf(const __FlashStringHelper *fmt, ...) {
  char buf[128];  // resulting string limited to 128 chars
  va_list args;
  va_start(args, fmt);
#ifdef __AVR__
  vsnprintf_P(buf, sizeof(buf), (const char *)fmt, args);  // progmem for AVR
#else
  vsnprintf(buf, sizeof(buf), (const char *)fmt,
            args);  // for the rest of the world
#endif
  va_end(args);
  Serial.print(buf);
}

}  // namespace lp
