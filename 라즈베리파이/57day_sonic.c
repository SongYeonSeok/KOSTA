#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>

#define TRIGGER	28	// wPi	OUTPUT
#define	ECHO	27	// wPi	INPUT
#define	SONAR	340	// 초음파 속도 :340m/sec

#define	RED		15	// wPi
#define	YELLOW	16	// wPi
#define	GREEN	1	// wPi

int WaitEchoFor(int state)
{
	// state == 1 : HIGH
	// state == 0 : LOW
	while(1)
	{
		if(digitalRead(ECHO) == state)	break;
	}
	return 0;
}

double GetDistance()
{
	int Ts, Tr, Td;
	int sonar = SONAR;
	double dist;
	
	// 트리거 신호 전송
	digitalWrite(TRIGGER, LOW);		// 트리거 신호 이전의 상태를 LOW로 확정
	delayMicroseconds(100);
	digitalWrite(TRIGGER, HIGH);
	delayMicroseconds(10);
	digitalWrite(TRIGGER, LOW);
	delayMicroseconds(60);
	
	
	WaitEchoFor(LOW);
	
	// 트리거 신호에 대한 에코 시그널 모니터링
	WaitEchoFor(HIGH);
	Ts = micros();
	WaitEchoFor(LOW);
	Tr = micros();
	
	Td = Tr - Ts;	// micro second
	// sonar / 1000000 == 0.00017
	dist = 0.00017 * Td;
	
	
	// delay(1000);
	return dist;
}

int LightsType(double dist)
{
	// >= 2m : Yellow
	// < 2m and >= 1m : Green
	// < 1 : Red
	int types = 0;
	if(dist >= 2)	types = YELLOW;
	else if((dist < 2) && (dist >= 1))	types = GREEN;
	else 	types = RED;
	digitalWrite(types, HIGH);
	delay(1000);
	digitalWrite(types, LOW);
}


int main(void)
{

	wiringPiSetup();
	//wiringPiSetupGpio();
	
	pinMode(TRIGGER, OUTPUT);
	pinMode(ECHO, INPUT);
	
	// lights
	pinMode(RED, OUTPUT);
	pinMode(YELLOW, OUTPUT);
	pinMode(GREEN, OUTPUT);
	
	
	while(1)
	{
		LightsType(GetDistance());
		printf("Distance : %.2fm\n", GetDistance());	delay(1000);
	}
}
