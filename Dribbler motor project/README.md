# Dribbler motor project - high-speed HALL sensing plotting enabled

Current status: see Nov 17 update on Trello
https://trello.com/c/zfotdNE5/181-evspin32f02q1s1-development-motordriver

Dribbler motor troubleshooting and rough notes:
https://docs.google.com/document/d/1ftBo4Nyr78oGb1bgYVR70WMXjlDhPlK50mX6eQnU8a8/edit#heading=h.wbdym1qkgtzy

Modified source code:
* Inc > drive_parameters.h > PWM_FREQUENCY = 13100
* Inc > pmsm_motor_parameters.h > HALL_PHASE_SHIFT = 60
* Src > main.c > main() L#118-134
  * Added hardcoded speedramp with delayed start/stop
* Src > register_interface.c
  * Added cases for MC_REG_HALL_EL_ANGLE and MC_REG_HALL_SPEED, so that we can perform high-speed plotting of these registers
