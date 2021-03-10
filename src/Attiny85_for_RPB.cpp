#include <Arduino.h>
#include "RPB.h"


void setup()
{
  pinMode(sig_in, INPUT);
  pinMode(req_in, INPUT);
  pinMode(pwm_out, OUTPUT);
}


void loop()
{
  int sensor_val = analogRead(sig_in);
  int req_val = analogRead(req_in);
  
  pwm_val(sensor_val, pwm_out, req_val);
}