#include "esphome.h"
#include <string>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::string;
class LD1125H : public Component, public UARTDevice {
 public:
  LD1125H(UARTComponent *parent) : UARTDevice(parent) {}
  TextSensor *uart_text = new TextSensor();
  TextSensor *status_sensor = new TextSensor();
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

  void loop() override {
    const int max_line_length = 40;
    static char buffer[max_line_length];
    while (available()) {
      if(readline(read(), buffer, max_line_length) > 0) {
        uart_text->publish_state(buffer);
		//Distance Program
		const char* dis_buffer = buffer;
		string dis_string(dis_buffer);
		string dis_st1(dis_string.substr(9));
		distance_sensor->publish_state(atof(dis_st1.c_str()));
		//delay(200);
		//Occ Display
		string dis_st2(dis_string.substr(0,3));
		if (dis_st2 == "occ") {
			status_sensor->publish_state("Occupancy");
		}
		else {
			status_sensor->publish_state("Movement");
		}
      }
    }
  }
};
