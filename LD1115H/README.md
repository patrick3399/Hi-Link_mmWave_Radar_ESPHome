## HLK-LD1115H Connect Diagram
   
LD1115H URX (RX) <----> ESP32 GPIO16 (TX)   
LD1115H UTX (TX) <----> ESP32 GPIO17 (RX)   
LD1115H GND <----> ESP32 GND   
LD1115H Vcc <----> 5V Source    

## Radar Setting
1. th1: movement sensitive   
2. th2: occupancy sensitive   
3. Clearance Time: Mov/Occ to Clearance waiting time   
4. Movement Time: Mov to Occ waiting time   

If any compile problem occur, try **Clean Build Files** first
