// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"


void Robot::RobotInit() {
  rightLeadMotor->RestoreFactoryDefaults();
  leftLeadMotor->RestoreFactoryDefaults(); 

// restore default values

  rightLeadMotor->SetInverted(false);
  leftLeadMotor->SetInverted(true);

//set motors for directions
// Init starts immediatly, runs once

}

//RobotInit sets everything to "nuetral"

void Robot::RobotPeriodic() {
// runs throught the period every few milli seconds
}

void Robot::AutonomousInit() {} // first few seconds, creates variable/objects
void Robot::AutonomousPeriodic() {} //repeats during autonomous period

void Robot::TeleopInit() {} //Taxing init sequence
void Robot::TeleopPeriodic() { //periodic
  float deadzone = 0.02;
  double leftStick = l_Joystick->GetRawAxis(0);
  double rightStick = r_Joystick->GetRawAxis(1);
  double yMovement = leftStick - rightStick;
  double xMovement = leftStick + rightStick;
  int ySign = 1;
  int xSign = 1;
  double prcX, prcY;

  prcY = fabs(leftStick);
  prcX = fabs(rightStick);
  
  if (prcY <= deadzone) {
    
    rightLeadMotor->Set(0);
    leftLeadMotor->Set(0);
  } else {

    rightLeadMotor->Set(ySign * (1/(1 - deadzone) * (yMovement) - (deadzone/(1 - deadzone)))); // left stick y-axis
    leftLeadMotor->Set(xSign * (1/(1 - deadzone) * (xMovement) - (deadzone/(1 - deadzone))));

  }
}

void Robot::DisabledInit() {} //closing sequence
void Robot::DisabledPeriodic() {} // checking for closing command

void Robot::TestInit() {} //teleop dedicated place to test
void Robot::TestPeriodic() {} //same 

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif
// dont touch this, it works


