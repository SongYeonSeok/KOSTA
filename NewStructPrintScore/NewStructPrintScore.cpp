#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <time.h>
#include <string.h>

// 20210812 미션
// 위의 구조체를 이용하여 사용자 정의 자료형을 선언하고,
// 10명의 학생에 대한 데이터를 입력한 후 정렬하여 출력하시오.

//struct student {
//	int kor;
//	int eng;
//	char name[10];
//};
//
//typedef struct student STU;



const int n = 10;

int kor[] = { 67, 70, 77, 65, 68, 72, 79, 55, 85, 61 };
int eng[] = { 70, 75, 80, 60, 65, 55, 80, 95, 67, 84 };
const char* name[n] = {"홍길동", "홍길이", "홍길삼", "홍길사", "홍길오", 
						"맹일", "맹이", "맹삼", "맹사", "맹오"};	


typedef struct {
	int kor;
	int eng;
	char name[10];
} STU;

STU student[n];
void totalswap(void* a, void* b, int op)
{

	switch (op)
	{
	case 1:  // char 
	{
		char temp = *(char*)a;		// 강제 형 변환 추가
		*(char*)a = *(char*)b;
		*(char*)b = temp;
	}
	case 4: // int (float, char* : 4byte)
	{
		int temp = *(int*)a;
		*(int*)a = *(int*)b;
		*(int*)b = temp;
	}
	case 8:  // double
	{
		double temp = *(double*)a;
		*(double*)a = *(double*)b;
		*(double*)b = temp;
	}
	case 18:	// STU (사용하기 전 선언되어야 한다.)
		STU temp = *(STU*)a;
		*(STU*)a = *(STU*)b;
		*(STU*)b = temp;
	}
}


void sort(double* a, int op)
{
	int i, j, k;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (a[i] < a[j])
			{
				totalswap(a + i, a + j, 8);
				totalswap(student + i, student + j, 18);
				// 문자열의 배열 == *
			}
		}
	}
}

// 학생 수는 10명이니, 구조체 배열을 선언해보자.

int sortTest()
{
	double f_kor = 0.3, f_eng = 0.7;	// 가중치
	double tot[n];
	int i, j, k;


	for (int i = 0; i < n; i++)
	{
		//student[i].kor = kor[i];
		//student[i].eng = eng[i];
		strcpy(student[i].name, name[i]);
		tot[i] = (student[i].kor = kor[i]) * f_kor + (student[i].eng = eng[i]) * f_eng;
		// tot[i] = student.kor[i] * f_kor + student.eng[i] * f_eng;
	}


	printf("Original : \n");
	printf("이름 : "); for (int i = 0; i < n; i++) printf("%7s ", student[i].name); printf("\n\n");
	printf("국어 : "); for (int i = 0; i < n; i++) printf("%7d ", student[i].kor); printf("\n\n");
	printf("영어 : "); for (int i = 0; i < n; i++) printf("%7d ", student[i].eng); printf("\n\n");
	printf("합계 : "); for (int i = 0; i < n; i++) printf("%7.2f ", tot[i]); printf("\n\n");

	sort(tot, n);		// 정렬

	printf("Sorted : \n");
	printf("이름 : "); for (int i = 0; i < n; i++) printf("%7s ", student[i].name); printf("\n\n");
	printf("국어 : "); for (int i = 0; i < n; i++) printf("%7d ", student[i].kor); printf("\n\n");
	printf("영어 : "); for (int i = 0; i < n; i++) printf("%7d ", student[i].eng); printf("\n\n");
	printf("합계 : "); for (int i = 0; i < n; i++) printf("%7.2f ", tot[i]); printf("\n\n");

	return 0;
}

int main()
{
	sortTest();
}