// 1wire.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wiringPi.h>

#define	MAX_BIT		40		// 5 byte * 8 bit
#define	THRESHOLD	40		// 40 ~ 45
#define	PIN			26		// GPIO 12

int pin = PIN;
char Data[10];

// Start 신호 전송 
void StartSignal()		// send Start Signal
{
	pinMode(pin, OUTPUT);
	digitalWrite(pin, HIGH);	delay(1);
	digitalWrite(pin, LOW);		delay(18);
	digitalWrite(pin, HIGH);
}

int GetResponse()		// Response Signal
{
	pinMode(pin, INPUT);
	while(digitalRead(pin) == HIGH);
	int st = micros();
	while(digitalRead(pin) == LOW);
	int en = micros();
	while(digitalRead(pin) == HIGH);
	while(en - st < 10)	return -1;
	return 0;
}

int ReadData()			// 데이터 비트 수신
{
	int st, en;
	
	for(int i=0;i<5;i++)		// 배열 초기화 필요!
	{
		Data[i] = 0;
	}
	
	for(int i=0;i<MAX_BIT;i++)
	{
		while(digitalRead(pin) == LOW);
		st = micros();
		while(digitalRead(pin) == HIGH);
		en = micros();
		Data[i/8] <<= 1;		// SHL 후 최하위 비트는 0
		if(en - st > THRESHOLD)	Data[i/8] |= 1;		// Data[] += 1(가능하지만 no 안전)
		
		// 최상위 비트(MSB)는 부호 비트이다. unsigned를 한다면 부호 비트는 없다.
	}
	if(Data[0] + Data[1] + Data[2] + Data[3] == Data[4]) return 1;	// checksum	
	return 0;
}

int main(int argc, char **argv)
{
	wiringPiSetup();
	
	while(1)
	{
		StartSignal();
		GetResponse();
		int ret = ReadData();
		printf("습도 : %d.%d		온도 : %d.%d		Checksum : %d   ", Data[0], Data[1], Data[2], Data[3], Data[4]);
		if(ret == 1) printf("....OK\n");
		else  		 printf("....ERROR\n");
		delay(2000);			// 딜레이 필요
	}
	return 0;
}
