#include "esphome.h"
class LD1125UART : public Component, public UARTDevice, public TextSensor {
 public:
  UartReadLineSensor(UARTComponent *parent) : UARTDevice(parent) {}
  Sensor *status_sensor = new Sensor();
  Sensor *distance_sensor = new Sensor();

  void setup() override {
    // nothing to do here
  }
  void loop() override {
    String line = readString();
    int i = parseInt();
    while (available()) {
      char c = read();
    }

  }
};
