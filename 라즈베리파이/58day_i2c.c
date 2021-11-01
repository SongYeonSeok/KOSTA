#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <softPwm.h>


//==============입력 전압======================
// AINO(조도) 		: 125 ~ 245 (밝기에 반비례)
// AIN1(온도) 		: X
// AIN3(가변 저항)	: 0 ~ 255, 최대 100 Ohm
//============================================


//================
// A0 Light P5
// A1 Temp P4
// A2 Volume P6
//================

#define	RED		27
#define	YELLOW	23
#define	GREEN	24

// ..$ i2c [ch1 ch2 ch3 ...]

int main(int n, char *v[])
{
	// reg : bit 수
	// normal하게 read, write를 사용하면 된다.
	int fd, data;
	int ch[4], chnum;
	
	if(n< 2)
	{
		printf("Usage : i2c [ch1 ch2 ch3 ...]\n\n\n");	return 0;
	}
	
	for(int i=0;i<n-1;i++)
	{
		ch[i] = atoi(v[i+1]);
	}
	chnum = n - 1;
	
	
	fd = wiringPiI2CSetup(0x48);	// I2C address
	
	wiringPiSetup();
	
	int pin;
	printf("LED 색을 지정해 주세요.\n1 : RED(default)\t2 : YELLOW\t3 : GREEN\n");
	while(1)
	{
		int type;
		scanf("%d", &type);
		if(type <= 1)	
		{
			pin = RED;
			break;
		}
		else if(type == 2)	
		{
			pin = YELLOW;
			break;
		}
		else if(type == 3)	
		{
			pin = GREEN;	
			break;
		}
		else	
		{
			printf("다시 입력해 주십시오.\n");
		}
		
	}
	
	pinMode(pin, OUTPUT);		
	
	softPwmCreate(pin, 0, 100);
	
	
	
	while(1)
	{
		for(int i=0;i<chnum;i++)
		{
			wiringPiI2CWrite(fd, 0x00|ch[i]);		// Read Channel
			// data : 채널 넘버
			// 온도 : 0(00)
			// 조도 : 1(01)
			// 입력 신호 : 2(10) -> 아날로그 신호 받을 수 있다.
			// 가변 저항 : 3(11)
			data = wiringPiI2CRead(fd);
			data = wiringPiI2CRead(fd);
			if(ch[i] == 0)	printf("[%d]현재 밝기는 %d(%d) %%입니다.\n", ch[i], (int)(((254 - data) / 120) * 100), data);		// 조도(10진수 %), 125 ~ 245 (밝기에 반비례)
			if(ch[i] == 1)	printf("[%d]현재 온도는 %d도(%d)입니다.\n", ch[i], (int)((data * 0.25) - 15), data);		// 온도, 125 ~ 245 [85](온도에 비례) (현재 온도 : 15 ~ 36 [21])
			if(ch[i] == 2)	
			{
				// Volumn 회로(가변저항)를 조절하여 그 값에 따라 LED의 밝기가 조절되도록 구현
				// 가변 저항 값 읽기 : wiringPi2CRead
				// LED 밝기 제어 : PwmWrite
				int lights = (int)(data * 100 / 255) > 100 ? 100 : (int)(data * 100 / 255);
				softPwmWrite(pin, lights);
				printf("현재 밝기는 %d %%입니다.\n", lights);
				// printf("[%d]저항값은 %d ohm(%d) 입니다.\n", ch[i], (int)(data * 0.4), data);
			}
			if(ch[i] == 3)	printf("[%d]저항값은 %d ohm(%d) 입니다.\n", ch[i], (int)(data * 0.4), data);				// 가변저항 0 ~ 255 [255] 최대 100 ohm
			delay(10);
		}
		delay(1000);
	}
}

// A0 Light P5
// A1 Temp P4
// A2 Volume P6
