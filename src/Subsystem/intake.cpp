#include "main.h"

int hold_power = 0;
// true = up and false = down
bool last_key;
void setIntake(int power)
{
  intake_top.move(power);
  intake_bottom.move(power);
}

void setIntakeMotor()
{
  int intake_power = 127 * (con.get_digital(pros::E_CONTROLLER_DIGITAL_UP) - (con.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)));
  if(abs(intake_power) == 127)
  {
    hold_power = intake_power;
  }
  if(con.get_digital(pros::E_CONTROLLER_DIGITAL_R2))
  {
    hold_power = 0;
  }
  setIntake(hold_power);
}
