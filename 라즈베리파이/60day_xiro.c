#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>

#define	DEVICE_ADDRESS	0X68

// Register Address
#define PWR_MGMT_1    0x6B
#define SMPLRT_DIV    0x19
#define CONFIG        0x1A
#define GYRO_CONFIG   0x1B
#define INT_ENABLE    0x38

#define ACCEL_XOUT_H  0x3B
#define ACCEL_YOUT_H  0x3D
#define ACCEL_ZOUT_H  0x3F

#define	TEMPERTURE	  0x41

#define GYRO_XOUT_H   0x43
#define GYRO_YOUT_H   0x45
#define GYRO_ZOUT_H   0x47

// LED 
#define	RED		27
#define	YELLOW	28
#define	GREEN	29


int fd;

int ReadReg(int addr)		// addr : address
{
	short data_h, data_l, data;	
	data_h = wiringPiI2CReadReg8(fd, addr);		// 16bit data의 상위 8bit data
	data_l = wiringPiI2CReadReg8(fd, addr + 1);	// 16bit data의 하위 8bit data
	//int data = data_h * 256 + data_l;		// 문제 발생 가능성 높음 
	data = (data_h << 8) | data_l;		// 비트 연산 
	return data;
}

void mpu_init()
{
	/*
	PWR_MGMT_1	= 1;
	SMPLRT_DIV	= 7;
	CONFIG		= 1;
	GYRO_CONFIG	= 24;
	INT_ENABLE	= 1;
	*/
	wiringPiI2CWriteReg8(fd, PWR_MGMT_1 , 0x01);
	wiringPiI2CWriteReg8(fd, SMPLRT_DIV, 0x07);
	wiringPiI2CWriteReg8(fd, CONFIG, 0x01);
	wiringPiI2CWriteReg8(fd, GYRO_CONFIG, 0x24);
	wiringPiI2CWriteReg8(fd, INT_ENABLE, 0x01);
}

int lights(double x, double y, double z)
{
	pinMode(RED, OUTPUT);
	pinMode(YELLOW, OUTPUT);
	pinMode(GREEN, OUTPUT);
	
	if(x > 0.0)
	{
		digitalWrite(RED, HIGH);
		delay(1000);
		digitalWrite(RED, LOW);
		delay(1000);
	}
	if(y > 0.0)
	{
		digitalWrite(YELLOW, HIGH);
		delay(1000);
		digitalWrite(YELLOW, LOW);
		delay(1000);
	}
	if(z > 0.0)
	{
		digitalWrite(GREEN, HIGH);
		delay(1000);
		digitalWrite(GREEN, LOW);
		delay(1000);
	}
	return 0;
}

int main(void)
{
	// gx = 도 / 초 단위의 자이로 x 축 데이터
	// gy = 도 / 초 단위의 자이로 y 축 데이터
	// gz = 도 / 초 단위의 자이로 z 축 데이터
	// ax = 가속도계 x축 데이터 (g)
	// ay = 가속도계 y축 데이터 (g)
	// az = 가속도계 z축 데이터 (g)
	double acl_x = 0, acl_y = 0, acl_z = 0;
	double gyro_x = 0, gyro_y = 0, gyro_z = 0;
	double ax = 0, ay = 0, az = 0, gx = 0, gy = 0, gz = 0;
	fd = wiringPiI2CSetup(DEVICE_ADDRESS);
	
	mpu_init();
	wiringPiSetup();
	
	while(1)
	{
		acl_x = ReadReg(ACCEL_XOUT_H);
		acl_y = ReadReg(ACCEL_YOUT_H);
		acl_z = ReadReg(ACCEL_ZOUT_H);
		
		gyro_x = ReadReg(GYRO_XOUT_H);
		gyro_y = ReadReg(GYRO_YOUT_H);
		gyro_z = ReadReg(GYRO_ZOUT_H);
		
		// 각속도 : values / 131;
		// 가속도 : values / 16384;
		
		ax = acl_x / 16384.0;	ay = acl_y / 16384.0;	az = acl_z / 16384.0;
		gx = gyro_x / 131;		gy = gyro_y / 131;		gz = gyro_z / 131;
		
		printf("\n===================================================\n");
		printf("가속도 : x = %.3f, y = %.3f, z = %.3f\n", ax, ay, az);
		lights(ax, ay, az);
		printf("각속도 : x = %.3f, y = %.3f, z = %.3f\n", gx, gy, gz);
		printf("온도 : %.3f\n", 36.53 + ReadReg(TEMPERTURE)/340.0);

		delay(1500);
	}
}
