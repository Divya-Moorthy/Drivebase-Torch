// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc/TimedRobot.h>
#include <rev/CANSparkMax.h>
#include <frc/Joystick.h>

class Robot : public frc::TimedRobot {
 public:
  void RobotInit() override;
  void RobotPeriodic() override;

  void AutonomousInit() override;
  void AutonomousPeriodic() override;

  void TeleopInit() override;
  void TeleopPeriodic() override;

  void DisabledInit() override;
  void DisabledPeriodic() override;

  void TestInit() override;
  void TestPeriodic() override;
  
  int rightLeadMotorID = 12;
  int leftLeadMotorID = 3;

  // lMotor = 3;
  // rMotor = 12;
  
  //Joysticks 
  frc::Joystick * l_Joystick = new frc::Joystick(0); // assign to port 0
  frc::Joystick * r_Joystick = new frc::Joystick(1); // assign to port 0


  rev::CANSparkMax *rightLeadMotor = new rev::CANSparkMax(rightLeadMotorID, rev::CANSparkMax::CANSparkMaxLowLevel::MotorType::kBrushless);
  rev::CANSparkMax *leftLeadMotor = new rev::CANSparkMax(leftLeadMotorID, rev::CANSparkMax::CANSparkMaxLowLevel::MotorType::kBrushless);
 };
