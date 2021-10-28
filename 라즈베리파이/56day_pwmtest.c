#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wiringPi.h>
#include <softPwm.h>

/* Manual
Please input "pwmtest [BCM pin number] [manual / auto]".
option manual => input '+' words -> lights on slowly.
                 input '-' words -> lights off slowly.
                 input 's' words -> iteration stop and lights off immediately.

option auto => lights on and off

make by yeonseok.
*/

void usage()
{
	printf("Please input BCM pin number/right options!\n");
	printf("input ==>  pwmtest __BCM-pin__  [manual / auto ]\n");
}

int rightNum(int num)		// right pin num = 14, 15, 18
{
	if(num < 14)
	{
		printf("wrong BCM pin number!\n");
		return 0;
	}
	else if ((num == 16) || (num == 17))
	{
		printf("wrong BCM pin number!\n");
		return 0;
	}
	else if (num > 19)
	{
		printf("wrong BCM pin number!\n");
		return 0;
	}
	return 1;	// no problems
}


// .. $ pwmtest 15 [manual / auto]
int main(int argc, char *argv[])
{
	if(argc < 3)	
	{
		usage();
		return 0;
	}

	int pn = atoi(argv[1]);
	int check = rightNum(pn);
	if(check == 0) return 0;	// problem = 0, no problem = 1
	
	wiringPiSetupGpio();		// using BCM-GPIO pin number
	pinMode(pn, OUTPUT);
	
	softPwmCreate(pn, 0, 100);	// value ~ range == 0 ~ 100
	
	// 출처 : https://dojang.io/mod/page/view.php?id=346
	int type1 = strcmp(argv[2], "manual");	// correct :0 / no : 1
	int type2 = strcmp(argv[2], "auto");
	
	
	if(type1 == 0)
	{
		int px = 0;
		printf("프로그램을 멈추고 싶다면 s를 누르세요.\n");
		while(1)
		{
			char in[2];
			
			scanf("%s", in);
			if(strcmp(in, "s") == 0)
			{
				softPwmWrite(pn, 0);
				delay(25);
				break;
			}
			
			if(strcmp(in, "+") == 0)
			{
				px++;
				if(px <= 100)
				{
					softPwmWrite(pn, px);	delay(25);
				}
				else
				{
					printf("최대 밝기입니다. \'-\'키를 누르십시오.\n");
				}
			}
			else if (strcmp(in, "-") == 0)
			{
				px--;
				if(px >= 0)
				{
					softPwmWrite(pn, px);	delay(25);
				}
				else
				{
					printf("최대 밝기입니다. \'+\'키를 누르십시오.\n");
				}
			}
		}
	}
	
	else if(type2 == 0)
	{
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
	}
	else
	{
		usage();
		return 0;
	}

	


}
// 14, 15, 18
