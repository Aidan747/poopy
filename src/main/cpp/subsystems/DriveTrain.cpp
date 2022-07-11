// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/DriveTrain.h"

using Constants::ControllerConstants::kBrushless;

DriveTrain::DriveTrain() = default;

DriveTrain::DriveTrain(frc::SpeedController& leftSide, frc::SpeedController& rightSide) : frontLeft(1,kBrushless), frontRight(2, kBrushless), backLeft(3, kBrushless), backRight(4, kBrushless) {
    differentialDrive = new frc::DifferentialDrive(leftSide, rightSide);
}

void DriveTrain::setMotors(double speed) {
    frontLeft.Set(speed);
    backLeft.Set(speed);
    frontRight.Set(speed);
    backRight.Set(speed);
}

void DriveTrain::Drive() {
    double speed = RobotContainer::driveStick->GetRawAxis(0);
    double rot = RobotContainer::driveStick->GetRawAxis(1);
    differentialDrive->ArcadeDrive(speed, rot);
}

// This method will be called once per scheduler run
void DriveTrain::Periodic() {}
