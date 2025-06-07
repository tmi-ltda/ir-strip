#pragma once

#include <IRSensor.hpp>

#if !defined(SENSOR_N)
#define SENSOR_N 8
#endif
class IRStrip {
  private:
    IRSensor _sensors[SENSOR_N];
    int8_t _values[SENSOR_N];

  public:
    IRStrip(const ir_sensor_config_t configs[SENSOR_N]) {
      for (size_t i = 0; i < SENSOR_N; i++) {
        _sensors[i] = IRSensor(configs[i]);
      }
    }

    void read(IR_MODES mode) {
      for (size_t i = 0; i < SENSOR_N; i++) {
        _values[i] = _sensors[i].read(mode);
      }
    }

    int8_t getError() {
      int8_t error = 0;
      for (size_t i = 0; i < SENSOR_N; i++) {
        error += _values[i];
      }

      return error;
    }

    void setThreshold(uint16_t threshold) {
      for (size_t i = 0; i < SENSOR_N; i++) {
        _sensors[i].setThreshold(threshold);
      }
    }
};