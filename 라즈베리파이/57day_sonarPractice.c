#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wiringPi.h>

#define TRIGGER_NUM	28;
#define	ECHO_NUM	27;
#define	SONAR		340;	// 초음파 속도 :340m/sec

int main(void)
{
	// Ts : Trigger Start Time
	// Tr : Trigger Receive Time
	// Td : Trigger Distance
	
	long int Ts = 0, Tr = 0, Td = 0;
	double dist = 0;
	if( wiringPiSetup() == -1) exit(1);
	
	int trig = TRIGGER_NUM;
	int echo = ECHO_NUM;
	double sonar = SONAR;
	
	sonar /= 1000000;
	
	pinMode(trig, OUTPUT);	// TRIG
	pinMode(echo, INPUT);	// ECHO
	

	// 10us 트리거 = 측정 시작 신호
	// [Trigger 신호 발생]
	digitalWrite(trig, HIGH);
	delayMicroseconds(10);	// 10ms
	digitalWrite(trig, LOW);
	
	// [Echo 신호 측정]
	// 대기가 필요하다.
	
	// Echo Start
	// HIGH일 때까지 무한루프
	while(1)
	{
		if(digitalRead(echo) == HIGH)	break;
	}
	Ts = micros();	// 현재 시간(현재 클럭)
	
	// Echo Stop
	// LOW일 때까지 무한루프
	while(1)
	{
		if(digitalRead(echo) == LOW)	break;
	}
	Tr = micros();	// 현재 시간 (현재 클럭)
	Td = Tr - Ts;
	// 10ms
	// 
	
	dist = (double)Td / 2 * sonar * 10;
	printf("거리는 : %.4f m입니다.\n", dist);
	delay(200);


	
	
	
	return 0;
}
