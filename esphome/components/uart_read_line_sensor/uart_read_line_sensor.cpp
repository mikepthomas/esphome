#include "esphome/core/log.h"
#include "uart_read_line_sensor.h"

namespace esphome {
namespace uart_read_line_sensor {

static const char *TAG = "uart_read_line_sensor.text_sensor";

void UartReadLineSensor::setup() {
    // nothing to do here
}

int readline(int readch, char *buffer, int len) {
    static int pos = 0;
    int rpos;

    if (readch > 0) {
      switch (readch) {
        case '\r': // Ignore CR
          break;
        case '\n': // Return on new-lines
          rpos = pos;
          pos = 0;  // Reset position index ready for next time
          return rpos;
        default:
          if (pos < len-1) {
            buffer[pos++] = readch;
            buffer[pos] = 0;
          }
      }
    }
    // No end of line has been found, so return -1.
    return -1;
}

void UartReadLineSensor::loop() {
    const int max_line_length = 80;
    static char buffer[max_line_length];
    while (available()) {
      if(readline(read(), buffer, max_line_length) > 0) {
        publish_state(buffer);
      }
    }
}

void UartReadLineSensor::dump_config() {
    ESP_LOGCONFIG(TAG, "UART Read Line Sensor");
}

}  // namespace uart_read_line_sensor
}  // namespace esphome
