#include "main.h"
int power = 0;
void setFlywheel(int power)
{
    flywheel_front.move(power);
    flywheel_back.move(power);
}

void setFlywheelMotors() {
  if(con.get_digital(pros::E_CONTROLLER_DIGITAL_L1) == 1)
  {
    power = 90;
  }
  if(con.get_digital(pros::E_CONTROLLER_DIGITAL_L2) == 1)
  {
    power = 127;
  }
  if(con.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT))
  {
    power += 5;
    pros::delay(100);

  }
  else if(con.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT))
  {
    if(power > 0)
      power -= 5;
      pros::delay(100);
  }
  else if(con.get_digital(pros::E_CONTROLLER_DIGITAL_R1))
  {
    power = 0;
  }

  if(con.get_digital(pros::E_CONTROLLER_DIGITAL_Y))
  {
    power = -20;
    //work
  }

    setFlywheel(power);
}
// check
