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

void Robot::TeleopInit() {
  //init temp PID values
  lPID.SetP(1);
  lPID.SetI(0);
  lPID.SetD(0);

  rPID.SetP(1);
  rPID.SetI(0);
  rPID.SetD(0);

  //Change from 7/2 #2 
} 

//Taxing init sequence
void Robot::TeleopPeriodic() { //periodic
  deadzone = 0.02;
//deadzone is margin of error

  leftStick = l_Joystick->GetRawAxis(0);
  rightStick = r_Joystick->GetRawAxis(1);
//rawAxis is forward and backward
// 0 on x, 1 on y 

  yMovement = leftStick - rightStick;
  xMovement = leftStick + rightStick;
//pattern in table

  ySign = 1;
  xSign = 1;
  
// deadzone stuff

  prcY = fabs(leftStick);
  prcX = fabs(rightStick);
  
  //checks to see if command could be from an error

  if (prcY <= deadzone) {
    
    rPID.SetReference(0, rev::ControlType::kCurrent);
    lPID.SetReference(0, rev::ControlType::kCurrent);
    
  } else {
    //from the formula, slope from right side vs left
    rSet = (ySign * (1/(1 - deadzone) * (yMovement) - (deadzone/(1 - deadzone)))); // left stick y-axis    
    lSet = (xSign * (1/(1 - deadzone) * (xMovement) - (deadzone/(1 - deadzone))));
    
    
    rPID.SetReference(rSet, rev::ControlType::kCurrent);
    
    lPID.SetReference(lSet, rev::ControlType::kCurrent);
  }


  
  //Example code to set the motor. PID's initted in Teleopinit might not work, I can give other ones later
 // double setpoint = 1; //example voltage
 // lPID.SetReference(setpoint, rev::ControlType::kCurrent);
  //rPID.SetReference(setpoint, rev::ControlType::kCurrent);

  //Change from 7/2 #3
}

void Robot::DisabledInit() {} //closing sequence
void Robot::DisabledPeriodic() {} // checking for closing command

void Robot::TestInit() {
}
 //teleop dedicated place to test
void Robot::TestPeriodic() {
 
} //same 

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif
// dont touch this, it works


