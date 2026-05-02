#ifndef _MPU6050_H_
#define _MPU6050_H_
#include <stdint.h>
#include "PinFun.h"
#if USE_MPU6050

typedef struct
{
    int16_t Accel_X_RAW;//原始读出的数据
    int16_t Accel_Y_RAW;
    int16_t Accel_Z_RAW;
    double Ax;			//计算得出的数据
    double Ay;
    double Az;

    int16_t Gyro_X_RAW;//原始读出的数据
    int16_t Gyro_Y_RAW;
    int16_t Gyro_Z_RAW;
    double Gx;		   //计算得出的数据
    double Gy;
    double Gz;

    float Temperature;	//温度

    double KalmanAngleX;//计算得出的角度X
    double KalmanAngleY;//计算得出的角度Y
} MPU6050_t;

typedef struct	//计算角度
{
    double Q_angle;		//参数 0.001f
    double Q_bias;		//参数 0.003f
    double R_measure;	//参数 0.03f
    double angle;	//算出结果
    double bias;	//算出结果
    double P[2][2];	//算出结果
} Kalman_t;


uint8_t MPU6050_Init();

bool MPU6050_Read_Accel(MPU6050_t *DataStruct);

bool MPU6050_Read_Gyro(MPU6050_t *DataStruct);

bool MPU6050_Read_Temp(MPU6050_t *DataStruct);

bool MPU6050_Read_All(MPU6050_t *DataStruct);

double Kalman_getAngle(Kalman_t *Kalman, double newAngle, double newRate, double dt);



#endif
#endif

