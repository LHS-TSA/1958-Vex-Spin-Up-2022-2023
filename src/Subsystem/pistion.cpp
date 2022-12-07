#include "main.h"

void setPistonState()
{
  if(con.get_digital(pros::E_CONTROLLER_DIGITAL_A))
  {
    pisty.set_value(true);
    pros::delay(250);
    pisty.set_value(false);
    Piston.set_value(0);
    pros::delay(250);
  }

  if(con.get_digital(pros::E_CONTROLLER_DIGITAL_L2) && con.get_digital(pros::E_CONTROLLER_DIGITAL_R2))
  {
    Piston.set_value(127);
    pros::delay(250);
    Piston.set_value(0);
  }

}
