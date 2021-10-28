#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wiringPi.h>
#include <softPwm.h>

/*
prof's advise
- 나의 작업물과 다른 점
1. 일일이 문자를 입력하지 않고도 엔터키만 사용해도 작동된다. => getc와 같은 stdio.h 헤더파일 IO함수를 잘 사용하도록 노력하자.
2. 삼항 연산자를 썼기 때문에 코드를 간결화하였다.

- 추가한 점
1. 작동이 완료되었을 때 LED는 종료되어야 하므로, iteration에서 작업을 잘 마쳤든 아니든 간에 꺼버리도록 작성함
*/


int main(int argc, char *argv[])
{
	int pn = 14;
	int c, dir, pwm = 0;
	wiringPiSetupGpio();		// GPIO(BCM) pin 번호로 사용
	pinMode(pn, OUTPUT);
	
	softPwmCreate(pn, 0, 100);
	
	// auto();
	for(int i = 0;i<5;i++)
	{
//			digitalWrite(pn, HIGH);	delay(1000);		// 0(LOW) or 1(HIGH)
//			digitalWrite(pn, LOW);	delay(1000);		
		for(int j=0;j<100;j++)	
		{
			softPwmWrite(pn, j);	delay(25);
		}

		for(int k=100;k>=0;k--)
		{
			softPwmWrite(pn, k);	delay(25);
		}					
	}
	
	while(1)
	{
		// 한번 입력한 후 enter키만 눌러도 작동되는 로직 
		c = getc(stdin);
		if (c == '+') dir = 1;
		else if (c == '-') dir = -1;
		else if (c == 'x') break;
		pwm += (pwm + dir < 0)? 0 : (pwm + dir > 100) ? 0 : dir;
		softPwmWrite(pn, pwm); delay(25);
		//printf("%d ", dir);
	}
	softPwmWrite(pn, 0);
	delay(25);


}
