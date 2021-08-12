#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <conio.h>

// 문제 : 두 과목의 성적이 다음과 같을 때 배열을 이용하여 초기화하고, 
// 각각의 성적에 가중치를 곱한 후 개인별 합계를 구하여 합이 큰 순서대로
// 정렬하여 출력하시오.

/* data
			A	B	C	D	E	F	G
	국어		82	93	71	69	78	84	75	- 가중치 0.3
	영어		76	91	67	73	86	63	83	- 가중치 0.7
	*/

	/* 출력(예시1)
		1 :		91.60
		2 :		83.60
		3 :		80.60
		4 :		77.80
		5 :		71.80
		6 :		69.30
		7 :		68.20

		출력(예시2)
		순위:	이름		국어		영어		합계
		1:		B		93		91		91.60
		2:		E		78		86		83.60
		3:		G		75		83		80.60
		4 :		A		82		76		77.80
		5 :		D		69		73		71.80
		6 :		F		84		63		69.30
		7 :		C		71		67		68.20
		*/

		// 사용할 것 : 배열, 포인터, 정렬 알고리즘, swap 알고리즘



void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void charswap(char* a, char* b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}

void doubleswap(double* a, double* b)
{
	double temp = *a;
	*a = *b;
	*b = temp;
}

// 전역 변수
const int NUM = 7;			// 총 학생 수

char name[NUM] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G' };
int kor[NUM] = { 82, 93, 71, 69, 78, 84, 75 };
int eng[NUM] = { 76, 91, 67, 73, 86, 63, 83 };

void sort(double* a, int n)		// 배열과 배열의 길이
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = i; j < n; j++)
		{
			if (a[i] < a[j])
			{
				doubleswap(a + i, a + j);
				swap(kor + i, kor + j);
				swap(eng + i, eng + j);
				charswap(name + i, name + j);
			}
		}
	}

}

int main()
{
	int i, j, k;
	double total[NUM];

	for (i = 0; i < NUM; i++)
	{
		total[i] = (kor[i] * 0.3) + (eng[i] * 0.7);		// const를 넣으면 오류 발생
	}

	sort(total, NUM);

	for (j = 0; j < NUM; j++)
	{
		printf("%d :	%.2f\n", j+1, total[j]);		// 예제 1
	}

	printf("\n순위:	이름	    국어  영어	합계\n");
	for (k = 0; k < NUM; k++)
	{
		printf("%d:%7c	%7d	%7d%7.2f\n", k + 1, name[k], kor[k], eng[k], total[k]);
	}


}


