## HLK-LD1125H Connect Diagram
   
LD1125H UR (RX) <----> ESP32 GPIO16 (TX)   
LD1125H UT (TX) <----> ESP32 GPIO17 (RX)   
LD1125H G <----> ESP32 GND   
LD1125H 5V <----> 5V Source   

## Radar Setting   
mth1: 0~2.8m sensitive   
mth2: 2.8~8m sensitive   
mth3: above 8m sensitive   
rmax: max distance   
Clearance Time: Mov/Occ to Clearance waiting time   
Movement Time: Mov to Occ waiting time   

If any compile problem occur, try **Clean Build Files** first
