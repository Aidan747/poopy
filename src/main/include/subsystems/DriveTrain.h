// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <ctre/Phoenix.h>
#include <rev/CANSparkMax.h>
#include <frc/drive/DifferentialDrive.h>

#include "Constants.h"
#include "RobotContainer.h"


using rev::CANSparkMax;

class DriveTrain : public frc2::SubsystemBase {
 public:
  DriveTrain();
  DriveTrain(frc::SpeedController& leftSide, frc::SpeedController& rightSide);

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;
  void Drive();
  void setMotors(double speed);

 private:
  CANSparkMax frontLeft;
  CANSparkMax frontRight;
  CANSparkMax backLeft;
  CANSparkMax backRight;

  frc::DifferentialDrive* differentialDrive;
};
