#include "main.h"

void setDrive(int fr, int fl, int br, int bl);
void setDriveMotors();
void translate(int units, int voltage);
double avgDriveEncoderVal();
void resetDriveEncoder();
void rotate(int degrees, int voltage);
