#include "main.h"
// parameters are 2 lettes, first letter defines weather its front(f) or back(b)
// the second letter defines left(l) or right(r).
pros::ADIGyro gyro('A', 0.96);

void setDrive(int fr, int fl, int br, int bl)
{
  front_right_drive.move(fr);
  front_left_drive.move(fl);
  back_right_drive.move(br);
  back_left_drive.move(bl);
}

void setDriveMotors()
{
   int power = (con.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y)* -1);
   int strafe = con.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X);
   int turn = con.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
   int FL  = power - turn - strafe;///(++)
   int BL  = power - turn + strafe;//(+-)
   int FR  = power + turn + strafe;//(--)
   int BR  = power + turn - strafe;//(-+)
   setDrive(FR,FL,BR,BL);
}
void resetDriveEncoder()
{
  front_right_drive.tare_position();
  back_right_drive.tare_position();
  back_left_drive.tare_position();
  back_right_drive.tare_position();
}

double avgDriveEncoderVal()
{
    return (fabs(front_left_drive.get_position()) +
            fabs(front_right_drive.get_position()) +
            fabs(back_left_drive.get_position()) +
            fabs(back_right_drive.get_position())) / 4;
}

void translate(int units, int voltage){
  int direction = abs(units) / units;
  resetDriveEncoder();
  gyro.reset();
  setDrive(voltage * direction, voltage * direction, voltage * direction, voltage * direction);
  while(avgDriveEncoderVal() < abs(units))
  {
    setDrive(voltage * direction, voltage * direction, voltage * direction, voltage * direction);
    pros::delay(10);
  }
  setDrive(0,0,0,0);
}

void rotate(int degrees, int voltage)
{
  int direction = abs(degrees) / degrees;
  gyro.reset();
  setDrive(-1 * voltage * direction, voltage * direction, -1 * voltage * direction, voltage * direction);
  while(fabs(gyro.get_value()) < abs(degrees * 10) - 70)
  {
      pros::delay(10);
  }
  setDrive(0,0,0,0);
/*  if(fabs(gyro.get_value()) > abs(degrees * 10))
  {
    voltage *= 0.5;
    setDrive(voltage * direction, -1 * voltage * direction, voltage * direction, -1 * voltage * direction);

    while(fabs(gyro.get_value()) > abs(degrees * 10) )
    {
      pros::delay(10);
    }
  }

 if(fabs(gyro.get_value()) < abs(degrees * 10))
  {
    voltage *= 0.5;
    setDrive(-1 * voltage * direction, voltage * direction, -1 * voltage * direction, voltage * direction);
    while(fabs(gyro.get_value()) < abs(degrees * 10))
    {
      pros::delay(10);
    }
  }
  */
  setDrive(0,0,0,0);
  gyro.reset();
}
