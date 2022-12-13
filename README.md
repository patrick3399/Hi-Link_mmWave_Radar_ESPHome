# Hi-Link mmWave Radar For ESPHome
Suggest used ESP-IDF framework to improve efficiency and stabilized.   
If using Arduino Framework, disconnect the UART cable might cause API error(disconnect).
## Plan to Support:
:white_check_mark: LD1115H UART/GPIO output, UART with sensitivity adjustable >[Link](./LD1115H)    
:white_check_mark: LD1125H UART output, UART with sensitivity adjustable >[Link](./LD1125H)  
:negative_squared_cross_mark: LD2410 UART/GPIO output, UART with sensitivity adjustable   
:white_check_mark: LD112 GPIO output without adjustable >[Link](./LD112)  
:white_check_mark: LD017 IIC/GPIO output, IIC/GPIO for sensitivity adjustable >[Link](./LD017)   
:negative_squared_cross_mark: LD016 GPIO output, UART for sensitivity adjustable   
:white_check_mark: LD012 GPIO output with sensitivity adjustable pins >[Link](./LD012)  

Code at each Radar Folder   
Note: Don't use 5V on LD017 and LD012   

### Similar Device:
CEM5825F = LD1125H   
CEM5855H = LD1115H   


## No Plan to Support:   
LD7901B: 79Ghz Water Level Detection Radar   
LD303: 24Ghz   
LD116: 24Ghz   
LD101: 10Ghz   
LD102: 10Ghz   
LD105: 5.8Ghz   

## Reference:  
  ESPHOME:  
    <https://esphome.io/cookbook/uart_text_sensor.html>  
    https://esphome.io/custom/uart.html  
    https://esphome.io/components/uart.html  
    https://esphome.io/components/sensor/custom.html   
