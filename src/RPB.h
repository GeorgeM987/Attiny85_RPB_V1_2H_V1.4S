#ifndef _RPB_H
#define _RPB_H


const int req_in = 3;
const int sig_in = 2;
const int pwm_out = 0;


int sensor_val(int sensor_input, int limits);
void pwm_val(int sig_val, int pwm_val, int user_req);

#endif

