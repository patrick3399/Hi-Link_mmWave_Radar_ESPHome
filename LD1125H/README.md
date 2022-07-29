## HLK-LD1125H Connect Diagram
   
LD1125H UR (RX) <----> ESP32 GPIO16 (TX)   
LD1125H UT (TX) <----> ESP32 GPIO17 (RX)   
LD1125H G <----> ESP32 GND   
LD1125H 5V <----> 5V Source   

## Radar Setting   
mth1: 0 to 2.8m sensitive   
mth2: 2.8 to 8m sensitive   
mth3: above 8m sensitive   
rmax: max distance   
Clearance Time: Mov/Occ to Clearance waiting time   
Movement Time: Mov to Occ waiting time   

ESP32 YAML >[Normal](ESP32-LD1125H.yaml) >[Complete](ESP32-LD1125H-Complete.yaml)   
ESP8266 YAML >[Normal](ESP8266-LD1125H.yaml)   
If any compile problem occur, try **Clean Build Files** first
