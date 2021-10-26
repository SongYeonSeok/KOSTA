#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// File Name : twozerogame.c

// stdlib.h : rand() 함수 포함 헤더파일
// time.h : time을 사용하기 위한 헤더파일



int main(void)
{
	srand(time(NULL));		// 난수 초기화
	int i = 0;
	int r;					// 범위 최댓값 설정
	char answer;			// Y : 큼, N : 작음, S : 맞음
	printf("범위를 입력하세요.\n");
	scanf("%d", &r);
	
	int random = rand() % r;
	int temp = random;
	
	while(1)
	{
		scanf("%c", &answer);
		// 20번이 지났거나, 대답을 S를 했다면
		if((i > 20) || (answer == 'S'))
		{
			printf("당신이 생각한 숫자는 %d입니다.\n", temp);
			break;
		}
		
		printf("%d, 이 숫자보다 큽니까?\n", temp);
		if(answer == 'Y')
		{
			int answer2 = rand() % ((r - temp -1) + 1) + (temp + 1);
			temp = answer2;
			i++;
		}
		else if(answer == 'N')
		{
			int answer3 = rand() % (temp -1);
			temp = answer3;
			i++;
		}
		else
		{
			printf("잘못 입력하셨습니다.\n");
		}
	}
	
	
	return 0;
}
