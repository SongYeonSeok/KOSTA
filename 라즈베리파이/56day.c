// led_02.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wiringPi.h>

// 1 입력하면 빨간불만 light on
// 2 입력하면 빨간불과 노란불 lights on
// 3 입력하면 모든 lights on
// 이외의 숫자를 입력하면 실행 

#define PORT_RED 15		// 연결된 포트 번호(wPi 번호) - RED LED
#define PORT_YELLOW 16		// YELLOW LED
#define PORT_GREEN 1		// GREEN LED

// .. $ ledtest 15  
// ==> argc == 2, *(v+0) == ledtest, *(v+1) == wPi 번호

void Usage()
{
	printf("\n\nUsage :  ledtest  <type_Num>\n\n");
	printf("type 1 : one light on (red)\n");
	printf("type 2 : two lights on (red, yello)\n");
	printf("type 3 : all lights on\n");
}

int type1()
{
	int red = PORT_RED;

	// define pin how to use it
	pinMode(red, OUTPUT);
								
	// signal iteration
	for(int i=0;i<10;i++)
	{
		digitalWrite(red, HIGH); // lights on (1)
		delay(1000);				
		digitalWrite(red, LOW);	// lights off (0)
		delay(1000);
	}
}	
	
int type2()
{
	int red = PORT_RED;
	int yellow = PORT_YELLOW;

	// define pin how to use it
	pinMode(red, OUTPUT);
	pinMode(yellow, OUTPUT);

								
	// signal iteration
	for(int i=0;i<10;i++)
	{
		digitalWrite(red, HIGH); // lights on (1)
		digitalWrite(yellow, HIGH); // lights on (1)
		delay(1000);				
		digitalWrite(red, LOW);	// lights off (0)
		digitalWrite(yellow, LOW);	// lights off (0)
		delay(1000);
	}
}

int type3()
{	
	int red = PORT_RED;
	int yellow = PORT_YELLOW;
	int green = PORT_GREEN;
	
	// define pin how to use it
	pinMode(red, OUTPUT);
	pinMode(yellow, OUTPUT);
	pinMode(green, OUTPUT);

								
	// signal iteration
	for(int i=0;i<10;i++)
	{
		digitalWrite(red, HIGH); // lights on (1)
		digitalWrite(yellow, HIGH); // lights on (1)
		digitalWrite(green, HIGH);	// lights on (1)
		delay(1000);				
		digitalWrite(red, LOW);	// lights off (0)
		digitalWrite(yellow, LOW);	// lights off (0)
		digitalWrite(green, LOW);	// lights off (0)
		delay(1000);
	}
}

// 헤더 파일을 실행하게 되면, reference 목록이 나온다.
int main(int argc, char **argv)		// argc : 입력 개수, argv : 입력 문자열
{
	if(argc < 2)		// 인수가 2보다 작다면(1개 이상)
	{
		Usage();
		return 0;
	}
	
	int types = atoi(argv[1]);
	wiringPiSetup();			// setup
	
	switch(types)
	{
		case 1:
			type1();
			break;
			
		case 2:
			type2();
			break;
			
		case 3:
			type3();
			break;
			
		default:
			printf("1, 2, 3 중에 입력하시기 바랍니다.\n");
			break;
	}

}
