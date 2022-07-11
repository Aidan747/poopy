// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/Command.h>
#include <ctre/Phoenix.h>
#include <frc/Joystick.h>
#include <frc/motorcontrol/MotorControllerGroup.h>

#include "Constants.h"
#include "commands/ExampleCommand.h"
#include "subsystems/ExampleSubsystem.h"
#include "subsystems/DriveTrain.h"
#include "commands/Drive.h"

/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and button mappings) should be declared here.
 */
class RobotContainer {
 public:
  RobotContainer();

  frc2::Command* GetAutonomousCommand();

  inline static WPI_TalonFX* testMotor = new WPI_TalonFX(1);

  inline static frc::Joystick* driveStick = new frc::Joystick(1);
  


 private:
  // The robot's subsystems and commands are defined here...
  ExampleSubsystem m_subsystem;
  ExampleCommand m_autonomousCommand;

  CANSparkMax driveFrontLeft{1, Constants::ControllerConstants::kBrushless};
  CANSparkMax driveFrontRight{2, Constants::ControllerConstants::kBrushless};
  CANSparkMax driveBackLeft{3, Constants::ControllerConstants::kBrushless};
  CANSparkMax driveBackRight{4, Constants::ControllerConstants::kBrushless};

  frc::MotorControllerGroup leftSide{driveBackLeft, driveFrontLeft};
  frc::MotorControllerGroup rightSide{driveFrontRight, driveBackRight};

  Drive driveCommand;

  void ConfigureButtonBindings();
 public:
  DriveTrain driveSub{leftSide, rightSide};
};
