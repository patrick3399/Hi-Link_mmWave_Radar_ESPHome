#include "esphome.h"

class LD1125H : public PollingComponent, public UARTDevice {
 public:
  LD1125H(UARTComponent *parent) : UARTDevice(parent) {}
  TextSensor *uart_text = new TextSensor();
  Sensor *distance_sensor = new Sensor();
  void setup() override {
    // nothing to do here
  }

  int readline(int readch, char *buffer, int len)
  {
    static int pos = 0;
    int rpos;

    if (readch > 0) {
      switch (readch) {
        case '\n': // Ignore new-lines
          break;
        case '\r': // Return on CR
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

  void update() override {
    const int max_line_length = 80;
    static char buffer[max_line_length];
    while (available()) {
      if(readline(read(), buffer, max_line_length) > 0) {
        uart_text->publish_state(buffer);
		distance_sensor->publish_state(5.65);
      }
    }
  }
};
