#include <stdio.h>
// 세 정수의 값을 입력하고 중앙값을 구합니다.

// a, b, c의 중앙값을 구합니다.
int midpoint(int a, int b, int c)
{
	int mid = a;		// 중앙값
	if (a > b)
	{
		if (b > c)
		{
			mid = b;
		}
		else
		{
			if (a > c)
			{
				mid = c;
			}
			else mid = a;
		}
	}
	else
	{
		if (b > c)
		{
			if (a > c)
			{
				mid = a;
			}
			else mid = c;
		}
		else mid = b;
	}

	return mid;
}
/* 실행 결과
	세 정수의 중앙값을 구합니다.
	a의 값 : 1
	b의 값 : 3
	c의 값 : 2
	중앙값은 2입니다.
	*/