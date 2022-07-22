# Hi-Link mmWave Radar For ESPHome
Suggest used ESP-IDF to improve efficiency and stabilized.   
If using Arduino Framework, disconnect the UART cable might cause API error(disconnect).
## Current Support:
:white_check_mark: LD1115H UART/GPIO output, UART with sensitivity adjustable >[Link](https://github.com/patrick3399/Hi-Link_mmWave_Radar_ESPHome/tree/main/LD1115H)   
:white_check_mark: LD1125H UART output, UART with sensitivity adjustable >[Link](https://github.com/patrick3399/Hi-Link_mmWave_Radar_ESPHome/tree/main/LD1125H)   
:negative_squared_cross_mark: LD112 GPIO output without adjustable   
:negative_squared_cross_mark: LD017 IIC/GPIO output, IIC for sensitivity adjustable   
:negative_squared_cross_mark: LD016 GPIO output, UART for sensitivity adjustable   
:negative_squared_cross_mark:LD012 GPIO output with sensitivity adjustable pins

Code at each Folder   
>[Link](/tree/main/LD1125H)  
## Reference:  
  ESPHOME:  
    <https://esphome.io/cookbook/uart_text_sensor.html>  
    https://esphome.io/custom/uart.html  
    https://esphome.io/components/uart.html  
    https://esphome.io/components/sensor/custom.html   
