#include <Arduino.h>


int sensor_val(int sensor_input, int user_input)
{
  int user_limit = 925;
  user_input = constrain(user_input, user_limit, 1023);
  int* ptr = &sensor_input;
  *ptr = sensor_input * 1.25;

  if(user_input < 1023)
  {
    int mapped_val = map(sensor_input, 0, 1023, user_input, 920);
    return (mapped_val /204.6) * 51;
  }

  else return 255;
}


void pwm_val(int sig_val, int pwm_val, int user_req)
{
  const int rpm_low_limit = 375;
  const int rpm_high_limit = 515;
  int write_pwm_val = sensor_val(sig_val, user_req);

  if(sig_val > rpm_low_limit && sig_val < rpm_high_limit)
  {
    analogWrite(pwm_val, write_pwm_val);
    delay(1);
  }

  else
  {
    analogWrite(pwm_val, 255);
    delay(1);
  }
}