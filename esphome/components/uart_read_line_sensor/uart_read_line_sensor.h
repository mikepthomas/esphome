#pragma once

#include "esphome/core/component.h"
#include "esphome/components/text_sensor/text_sensor.h"
#include "esphome/components/uart/uart.h"

namespace esphome {
namespace uart_read_line_sensor {

class UartReadLineSensor : public Component, public uart::UARTDevice, public text_sensor::TextSensor {
  public:
    void setup() override;
    void loop() override;
    void dump_config() override;
};


}  // namespace uart_read_line_sensor
}  // namespace esphome
