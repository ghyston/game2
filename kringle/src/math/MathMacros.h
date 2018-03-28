//
//  MathMacros.h
//  kringle
//
//  Created by Ilja Stepanow on 28.03.18.
//  Copyright © 2018 Ilja Stepanow. All rights reserved.
//

#ifndef MathMacros_h
#define MathMacros_h

// Pre-calculated value of PI / 180.
#define kPI180   0.017453

// Pre-calculated value of 180 / PI.
#define k180PI  57.295780

// Converts degrees to radians.
#define degreesToRadians(x) (x * kPI180)

// Converts radians to degrees.
#define radiansToDegrees(x) (x * k180PI)

#endif /* MathMacros_h */
