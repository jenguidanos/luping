#pragma once
// CAUTION! DO NOT EDIT THIS FILE
// This is an autogenerated file. Please see conf.json at project root

namespace lp {

struct SystemConf {
  unsigned char test;
};

struct BatteryConf {
  unsigned char test;
};

struct LupingConf {
  SystemConf system;
  BatteryConf battery;
};

extern LupingConf conf;

void initConf();

}  // namespace lp
