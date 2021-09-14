```c
// WhatTimeIsIt.c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <conio.h>

const int AFTERNOON = 12;   // 점심 기준은 12시
const int EVENING = 18;     // 저녁 기준은 18시
const int DAY = 24;         // 하루는 24시간!
const int MINUTE = 60;      // 분 최대치는 59분

int time()
{
  int h, m;   // h : 시간, m : 분
  char good[5] = "Good";
  char morn[8] = "Morning";   // 아침
  char noon[10] = "Afternoon";// 점심
  char even[8] = "Evening";   // 저녁
  
  while (true)
  {
    printf("현재 시간을 입력해 주세요. ");
    scanf("%d %d" &h, &m);    // 몇시 몇분 입력 (__ : __ 이렇게 형식을 만들려면, 입력함수를 만들어야 한다.)
                              
    if (h < AFTERNOON && m < MINUTE)
    {
      printf("현재 시각은 %d시 %d분\n", h, m);
      printf("%s %s!\n", good, morn);
      break;
    }
    
    else if (h < EVENING && h >= AFTERNOON && m < MINUTE)
    {
      printf("현재 시각은 %d시 %d분\n", h, m);
      printf("%s %s!\n", good, noon);
      break;
    }
    
    else if (h <= DAY && m < MINUTE)
    {
      printf("현재 시각은 %d시 %d분\n", h, m);
      printf("%s %s!\n", good, even);
      break;
    }
    else printf("다시 입력해 주세요.");
  }
  return 0;
}

int main(void)
{
  time();
  return 0;
}


```

```c
// teacher's advise.c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <conio.h>

const int MORNING = 7;		// 아침 기준은  7시
const int AFTERNOON = 12;	// 점심 기준은 12시
const int EVENING = 18;		// 저녁 기준은 18시
const int DAY = 24;		// 하루는 24시간!

int Good()
{
	int i, j, k;		// 지역변수
	char good[5] = "Good";
	char morn[8] = "Morning";		// 아침
	char non[10] = "Afternoon";		// 점심
	char even[8] = "Evening";		// 저녁

	while (1)
	{
		printf("지금 몇시인가요? ");
		scanf("%d", &k);
		if (k > MORNING && k < AFTERNOON)
		{
			printf("%s %s\n", good, morn);		break;
		}
		else if (k < EVENING && k >= AFTERNOON)
		{
			printf("%s %s\n", good, non);		break;
		}
		else if (k < DAY)
		{
			printf("%s %s\n", good, even);		break;
		}
		else printf("Hi!\n");
	}
	return 0;		// 넣지 않으면 오류 발생

}

int main()
{
	// score();
	Good();
}

```
