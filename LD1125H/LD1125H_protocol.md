ASCII transmission, the command is terminated by the carriage return and line feed key 

1. `th1_mov=xx`: set the motion detection threshold within 2.8 meters, the default value is 30 
2. `th2_mov=xx`: set the motion detection threshold within 2.8~8 meters, the default value is 15 
3. `th3_mov=xx`: set the motion detection threshold more than 8 meters, the default value is 6 
4. `th1_occ=xx`: set the presence detection threshold within 2.8 meters, the default value is 30 
5. `th2_occ=xx`: set the presence detection threshold within 2.8~8 meters, the default value is 15 
6. `th3_occ=xx`: set the presence detection threshold more than 8 meters, the default value is 6 
7. `rmax=xx`: set the maximum detection threshold, the default value is 60 
8. `eff_th=xx`: in the presence detection, the target detection for a period of time is counted; when the ratio of the detected target times to the total detected times exceeds (eff_th/100), it is determined that there is a real target, default value is 20 
9. `accu_num=xx`: chirp accumulation times, increasing this value can appropriately reduce the influence of noise, the default value is 8 
10. `occ_st=xx`: In the presence detection, the time between canceling the chirp, the unit is ms, when the value is appropriate, the higher the target strength of the presence detection, the default value is 250
11. `test_mode=xx`: Set the test mode, the default value is 0 
  - When `test_mode=0`, output detection status and target distance
  - When `test_mode=1`, output detection status, target distance, signal strength 
  - When `test_mode=2`, output the signal spectrum detected by the current occ 
  - When `test_mode=3`, output the signal spectrum detected by the current mov 
  - When `test_mode=4`, enter the spot frequency mode from the normal working mode, or enter the normal working mode from the spot frequency mode
12. `opt_mode=xx`: Set the format of the detection target output, the default value is 0 
  - When `opt_mode=0`, the detection result is displayed in characters through the serial port 
  - When `opt_mode=1`, the tx port of the serial port is configured as a common GPIO port, and the target is detected with a high level, and the duration of the high level is led_tim 
13. `led_tim=xx`: high level duration, unit is s, the default value is 1
14. `get_all`: Get all current parameter values 
15. `save`: save the above parameters 
16. `VER`: get version number 
17. `update_fir`: online update 
18. `vt=xx`: In point frequency mode, set VT voltage (mv)
