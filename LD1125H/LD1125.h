#include "esphome.h"
#include <string>
#include <iostream>
#include <ctime>
#define clear_idletime 5 //Set Clear Idle Time Here
using std::cout;
using std::cin;
using std::endl;
using std::string;
time_t receive_time;
bool clear_sent;
class LD1125H : public Component, public UARTDevice {
 public:
  LD1125H(UARTComponent *parent) : UARTDevice(parent) {}
  TextSensor *uart_text = new TextSensor();
  TextSensor *status_sensor = new TextSensor();
  Sensor *distance_sensor = new Sensor();
  void setup() override {
	  receive_time = time(NULL);
	  clear_sent = false;
  }

  int readline(int readch, char *buffer, int len)
  {
    static int pos = 0;
    int rpos;

    if (readch > 0) {
      switch (readch) {
        case '\n':
          break;
        case '\r':
          rpos = pos;
          pos = 0;
          return rpos;
        default:
          if (pos < len-1) {
            buffer[pos++] = readch;
            buffer[pos] = 0;
          }
      }
    }
    return -1;
  }

  void loop() override {
    const int max_line_length = 50;
    static char buffer[max_line_length];
    while (available()) {
      if(readline(read(), buffer, max_line_length) > 0) {
        receive_time = time(NULL);
        uart_text->publish_state(buffer);
        //Distance Program
        const char* dis_buffer = buffer;
        string dis_string(dis_buffer);
        string dis_st1(dis_string.substr(9));
        distance_sensor->publish_state(atof(dis_st1.c_str()));
        //Occ Display
        string dis_st2(dis_string.substr(0,3));
        if (dis_st2 == "occ") {
            status_sensor->publish_state("Occupancy");
        }
        else if (dis_st2 == "mov") {
            status_sensor->publish_state("Movement");
        }
        else {
            status_sensor->publish_state("Status Unknown");
        }
        clear_sent = false;
      }
      if (((time(NULL) - receive_time) >= clear_idletime)&(clear_sent = false)) {
            status_sensor->publish_state("Clear");
            clear_sent = true;
      }
      //delay(200);
    }
  }
};
