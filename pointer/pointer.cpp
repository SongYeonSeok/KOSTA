#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

// 프로그래밍의 상당 부분은 '문자열 처리'이다!
// 문자열의 길이를 어떻게 아는가? 함수를 만들어 보자!

// function define (습관화 하기)
//		Prototype  :  int str_len(char *str)	// 포인터 (문자열의 포인터를 매개변수로 받는다.)
// 문자열 str을 받아서 해당 문자열의 길이를 되돌려 줌
// 전제 : 문자열 끝에는 null이 붙어 있다.
int str_len(char* str)		// 문자열 == 문자 배열
							// 포인터로 문자열을 받음
							// [] == *이므로, char str[]도 가능하다.

{							// Low level function : 함수 자체에 다른 함수를 부르지 않는 함수를 의미
							// 해보는 것이 중요하다.

	return strlen(str);		// #include <string.h>에서 제공하는 쉬운 버전 (= 프로그래밍 실력보다는 지식에 관련된 것)
	int ret = 0;	
//	while (*(str + ret++)); return ret; // 압축된 줄로도 쓸 수 있다.
				// while문에서 1은 true, 0은 false이다. 
				// *(str + ret++)에서 포인터에 값이 있다면 0이 아니게 되므로 false가 나와 while문을 돈다.
				// *(str + ret++)에서 포인터에 값이 없다면 1이 되므로 true가 나와 while문을 벗어난다.
				// 0인지 아닌지 판단하는 while문 안에서 ret값은 포인터 값이 나오지 않을 때까지
				// 1을 계속 더해지므로, 어떻게 보면 문자열의 길이를 셀 수 있다고 말할 수 있다.

	// 참고 : 프로그래밍을 할 때 (격언)
	// 1. 나도 쉽고 남도 읽기 쉽게 코드를 작성해야 한다.
	
	while (1)
	{
		if (*(str + ret) != 0) ret++;	// str[ret], 전제를 이용한 방법
		else break;		
	}
	return ret;
}

int solution1()
{
	//문1) scanf 함수를 이용하여 문자열을 입력 후
	//     해당 문자열을 한 글자씩 공백을 삽입하여 출력하시오.
	//     > 12345 ==> 1_2_3_4_5
	// 
	//문2) scanf 함수를 이용하여 문자열을 입력한 후
	//     getch() 함수를 이용하여 숫자 키를 누르면
	//     해당 위치의 문자를 출력하시오.

	char buf[512];		// buffer : 버퍼 (임시 저장용, 배열(의 이름), 포인터)
						// char buf[i] : value 값
						// 문자 배열의 선언
	int i, j, k;

	printf("문자열을 입력하세요: "); scanf("%s", buf);	// 배열은 &연산자 쓰는 것 아니다. // 입력

	j = str_len(buf);		// 매개 변수에 포인터가 아닌 배열?
							// [] == * 과 동일하다고 생각하면 다르다고 생각할 수 없다!
	printf("입력문자열 [%s] 의 길이는 %d 입니다. \n", buf, j);		// 효율적

	for (i = 0; i < j; i++)		// for문 안에 함수를 넣을 수는 있지만, 바람직하지 않다. (복잡한 계산이 들어간 함수일 경우, 처리속도가 느려질 수 있다.)
	{
		if (i == (j - 1)) printf("%c", buf[i]);
		else printf("%c_", buf[i]);
	}



	while (1)
	{
		k = getch() - 0x30;	// 0 ~ 9 숫자키 (ASCII 0x30 ~ 0x39) 입력
		if (k >= 0 && k <= 9)
		{
			printf("%c", buf[k]);
			continue;		// 순환
		}
		break;
	}


	return 0;
}



/*int CharToInt(int a)
{
//	int ret;		// 분류 값
//	ret = a - 0x30;

// switch (a)
//	{
//	case 0x30: ret = 0;
//	case 0x31: ret = 1;
//	case 0x32: ret = 2;
//	case 0x33: ret = 3;
//	case 0x34: ret = 4;
//	case 0x35: ret = 5;
//	case 0x36: ret = 6;
//	case 0x37: ret = 7;
//	case 0x38: ret = 8;
//	case 0x39: ret = 9;
//
//	}   /ctrl + k,c (블록 주석처리)

//	return ret;
}*/

const int num = 100;		// 입력할 최대 글자 수
/*int pointer(void)
{
	int a[3][2] = {1, 2, 3, 4, 5, 6};

	printf("a[0] : %x \n", a[0]);		// 메모리는 10진수 -> 16진수로
	printf("a[1] : %x \n", a[1]);
	printf("a[2] : %x \n", a[2]);
	printf("a    : %x \n", a);

	printf("a    : %x \n", a);
	printf("a+1  : %x \n", a+1);
	printf("a+2  : %x \n", a+2);

	int i, j, k;
	char str[num];
	char c;
	char paste[num * 2]; // 복사 배열

	printf("영문과 숫자를 포함하여 아무 글이나 작성하세요: ");
	scanf("%s", str);		// 배열은 &연산자 안하기

	for (i = 0; i < num; i++)
	{
		
		paste[2* i] = str[i];		// 포인터
		paste[2*i + 1] = ' ';		// "" : 문자열, '' : 문자
	} 


	while (1)
	{
		c = getch();
		if (CharToInt(c) >= 0 && CharToInt(c) <= 9)
		{
			printf("%c", paste[CharToInt(c)]);
			continue;
		}
		break;
	}
	//switch (CharToInt(c))
	//{
	//	case 0: 
	//	{ 
	//		printf("%c", paste[CharToInt(c)]);
	//		
	//	}	// %c로 변환
	//	case 1:	
	//	{ 
	//		printf("%c", paste[CharToInt(c)]);
	//		break;
	//	}
	//	case 2: 
	//	{
	//		printf("%c", paste[CharToInt(c)]);
	//		break;
	//	}
	//	case 3: 
	//	{
	//		printf("%c", paste[CharToInt(c)]);
	//		break;
	//	}
	//	case 4: 
	//	{
	//		printf("%c", paste[CharToInt(c)]);
	//		break;
	//	}
	//	case 5: 
	//	{
	//		printf("%c", paste[CharToInt(c)]);
	//		break;
	//	}
	//	case 6: 
	//	{
	//		printf("%c", paste[CharToInt(c)]); 
	//		break;
	//	}
	//	case 7: 
	//	{
	//	printf("%c", paste[CharToInt(c)]);
	//		break;
	//	}
	//	case 8: 
	//	{
	//		printf("%c", paste[CharToInt(c)]);
	//		break;
	//	}
	//	case 9: 
	//	{
	//		printf("%c", paste[CharToInt(c)]);
	//		break; 
	//	}
	//}
	return 0;
}*/ 

int main()
{
	//pointer();

	solution1();
}

// 정렬 알고리즘 : sorting (알고리즘에 있어서 가장 기본적인 형태 구현 rule)
