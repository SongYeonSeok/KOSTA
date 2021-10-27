#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>

// File Name : twozerogame.c

// stdlib.h : rand() 함수 포함 헤더파일
// time.h : time을 사용하기 위한 헤더파일


// 참고사항
// printf가 두번 출력되는 것을 해결하기 위해서는?
// 입력 버퍼에 개행 문자가 포함되어 있기 때문!
// 코드에서 scanf("%c", &select);를 scanf(" %c", &select);로 바꾸어서
// 개행문자를 무시하도록 하면 된다.

const int MAX_NUM = 1000000;
int main(void)
{
	/*
	srand(time(NULL));		// 난수 초기화
	printf("범위를 입력하세요.\n");
	while(1)
	{
		scanf(" %d", &r);
	
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
	*/
	
	int i = 0;
	int max, min = 0;
	char answer = NULL;
	printf("스무고개 게임에 오신 걸 환영합니다.\n");
	printf("범위를 입력하세요.\n");
	while(1)
	{
		scanf(" %d", &max);
		if(max > MAX_NUM)
		{
			printf("게임에서 범위의 최댓값은 %d입니다.", MAX_NUM);
			printf("다시 입력해주세요.\n");
		}
		else break;
	}
	
	while(1)
	{
		if((i>20) || (answer == 'S'))
		{
			printf("당신이 생각한 숫자는 %d입니다.\n", temp);
			break;
		}
		else
		{
			int temp = (min + max) / 2;
			printf("%d, 이 숫자보다 큽니까?\n", temp);
			printf("크면 Y, 작으면 N, 일치하면 S를 입력하세요.\n");
			scanf(" %c", &answer);
		}
		if(answer == 'Y')
		{
			min = temp;
			i++;
		}
		else if (answre == 'N')
		{
			max = temp;
			i++;
		}
	}
	return 0;
}
