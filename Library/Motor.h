/* 
 * File:   Motor.h
 * Author: David Ledger
 *
 * Created on 1 November 2016, 12:53 PM
 */

#ifndef MOTOR_H
#define	MOTOR_H
#include "Timer0.h"
#include "Port.h"
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
typedef struct Motor    Motor;
typedef Motor *         MotorPtr;
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
struct Motor
{
    INT16   mDelta;
    INT16   mFrequency;
    UINT16  mAddress;
};

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//  Motor_Move
//      pMotor -> A pointer to the motor structure to initialize
//      pAddress -> The address of the module that the motor is on.
//  Return:
//      Returns false when previous movement isn't complete
void Motor_Init(MotorPtr pMotor, UINT16 pAddress);

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//  Motor_Move
//      pMotor -> A pointer to the motor structure
//      pDelta -> The distance to move the motor in steps
//  Return:
//      Returns false when previous movement isn't complete
bool Motor_Move(MotorPtr pMotor, INT16 pDelta);

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//  Motor_SetSpeed
//      pMotor -> A pointer to the motor structure
//      pFrequency -> The step rate in Hz
//
//  Return:
//      Returns false when previous movement isn't complete
bool Motor_Speed(MotorPtr pMotor, UINT16 pFrequency);

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//  Motor_Continious
//      pMotor -> A pointer to the motor structure
//	pDirection -> This is a value which when positive indicates foward.
//          
//      This function makes the motor move continiously at the speed defined
//      by the function above. The speed can be changed during operation.
//      continious mode is defined when mDelta is equal to +-(2^15 - 1) = +-32767
//  Return:
//      Returns false when previous movement isn't complete
bool Motor_Continious(MotorPtr pMotor, INT16 pDirection);

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

#endif