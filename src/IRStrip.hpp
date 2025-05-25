#pragma once

#include <IRSensor.hpp>
#include <strip_config.h>

class IRStrip {
  private:
    IRSensor _sensors[SIZE];
    int8_t _values[SIZE];

  public:
    IRStrip(const ir_sensor_config_t configs[SIZE]) {
      for (size_t i = 0; i < SIZE; i++) {
        _sensors[i] = IRSensor(configs[i]);
      }
    }

    void read() {
      for (size_t i = 0; i < SIZE; i++) {
        _values[i] = _sensors[i].read();
      }
    }

    int8_t getError() {
      int8_t error = 0;
      for (size_t i = 0; i < SIZE; i++) {
        error += _values[i];
      }
    }
};