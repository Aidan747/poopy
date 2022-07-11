// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <rev/CANSparkMax.h>



/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or boolean constants.  This should not be used for any other
 * purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */

namespace Constants {
    namespace Encoders {
        int encoderID = 1;
    }
    namespace ControllerConstants {
        auto kBrushless = rev::CANSparkMax::MotorType::kBrushless;
        auto kBrushed = rev::CANSparkMax::MotorType::kBrushed;
    }
}

#endif