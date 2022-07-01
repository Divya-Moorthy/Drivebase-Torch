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
    
    rightLeadMotor->Set(0);
    leftLeadMotor->Set(0);
  } else {
    //from the formula, slope from right side vs left
    rightLeadMotor->Set(ySign * (1/(1 - deadzone) * (yMovement) - (deadzone/(1 - deadzone)))); // left stick y-axis
    //rightLeadMotor would take in y movement
    leftLeadMotor->Set(xSign * (1/(1 - deadzone) * (xMovement) - (deadzone/(1 - deadzone))));
    //leftLeadMotor would take in x movement
  }
}

void Robot::DisabledInit() {} //closing sequence
void Robot::DisabledPeriodic() {} // checking for closing command

void Robot::TestInit() {
}
 //teleop dedicated place to test
void Robot::TestPeriodic() {
 /*
  for (double i=0; i <= 12; i += 0.5){
    counter = 0;
    if (counter == 10){
      rightLeadMotor->SetVoltage(0);
      leftLeadMotor->SetVoltage(0);
    } else {
      rightLeadMotor->SetVoltage(i);
      leftLeadMotor->SetVoltage(i);
      std::cout << "i value (0-12 by 0.5's) " << i << std::endl;
      std::cout << "current at voltage of i " << rev::CANSparkMax::GetOutputCurrent() << std::endl;

    }
  }
  */
//This is supposed to find correlation between voltage and current
//units did not match

//This one is for current and speed

 for (double i=-1.0; i <= 1.0; i += 0.5){
    counter = 0;
    if (counter == 10){
      rightLeadMotor->Set(0);
      leftLeadMotor->Set(0);
    } else {
      rightLeadMotor->Set(i);
      leftLeadMotor->Set(i);
      std::cout << "i value (-1 ti 1 by 0.5's) " << i << std::endl;
      std::cout << "current at speed of i for right motor " << rightLeadMotor->GetOutputCurrent() << std::endl;
      std::cout << "current at speed of i for left motor " << leftLeadMotor->GetOutputCurrent() << std::endl;
      counter ++;
    } 
  }

} //same 

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif
// dont touch this, it works


