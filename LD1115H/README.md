## HLK-LD1115H Connect Diagram
   
LD1115H URX (RX) <----> ESP32 GPIO16 (TX)   
LD1115H UTX (TX) <----> ESP32 GPIO17 (RX)   
LD1115H GND <----> ESP32 GND   
LD1115H Vcc <----> 5V Source    

## Radar Setting
th1: movement sensitive   
th2: occupancy sensitive   
Clearance Time: Mov/Occ to Clearance waiting time   
Movement Time: Mov to Occ waiting time   

YAML >[Normal](ESP32-LD1115H.yaml) >[Complete](ESP32-LD1115H-Complete.yaml)   
If any compile problem occur, try **Clean Build Files** first
