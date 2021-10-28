// ledtest.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wiringPi.h>

#define PORT_NUM 15		// 연결된 포트 번호(wPi 번호)

// .. $ ledtest 15  
// ==> argc == 2, *(v+0) == ledtest, *(v+1) == wPi 번호

int port[3];		// 포트 번호 배열 (최대 40개까지)
int pnum;			// 포트 번호의 수 

void Usage()
{
	printf("\n\nUsage :  ledtest  <wPi_Num1>    <wPi_Num2> ... \n\n");
}

// 헤더 파일을 실행하게 되면, reference 목록이 나온다.
int main(int argc, char **argv)		// argc : 입력 개수, argv : 입력 문자열
{
	if(argc < 2)		// 인수가 2보다 작다면(1개라면)
	{
		Usage();
		return 0;
	}
	pnum = argc - 1;
	
	for(int i=0;i<pnum;i++)	port[i] = atoi(argv[i+1]);
	wiringPiSetup();			// setup
	
	// define pin how to use it
	for(int i=0;i<pnum;i++)
	{
		pinMode(port[i], OUTPUT);		// pin num : wPI num
										// use : output	
	}
	// signal iteration
	for(int i=0;i<5;i++)
	{// digital value : 1(high) / 0(low)
		for(int j=0;j<pnum;j++) 
		{
			digitalWrite(port[j], HIGH);	// light on	 (1)
			delay(1000);				// 밀리초 단위, 잠깐 쉬어가는 것
			digitalWrite(port[j], LOW);	// light off (0)
			delay(1000);
		}
	}
}
