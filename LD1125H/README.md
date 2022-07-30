## HLK-LD1125H Connect Diagram
### ESP32:
LD1115H URX (RX) <----> ESP32 GPIO16 (TX)   
LD1115H UTX (TX) <----> ESP32 GPIO17 (RX)   
LD1115H GND <----> ESP32 GND   
LD1115H Vcc <----> 5V Source    
### ESP8266:
LD1115H URX (RX) <----> ESP8266 GPIO1 (TX)   
LD1115H UTX (TX) <----> ESP8266 GPIO3 (RX)   
LD1115H GND <----> ESP8266 GND   
LD1115H Vcc <----> 5V Source    

## Radar Setting   
mth1: 0 to 2.8m sensitive   
mth2: 2.8 to 8m sensitive   
mth3: above 8m sensitive   
rmax: max distance   
Clearance Time: Mov/Occ to Clearance waiting time   
Movement Time: Mov to Occ waiting time   

## YAML:
ESP32 YAML >[Normal](ESP32-LD1125H.yaml) >[Complete](ESP32-LD1125H-Complete.yaml)   
ESP8266 YAML >[Normal](ESP8266-LD1125H.yaml)   
If any compile problem occur, try **Clean Build Files** first
