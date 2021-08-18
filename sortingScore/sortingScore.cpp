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

// swap 알고리즘
// a = 1, b = 2
// temp = b; // 임시 저장소
// b = a;	// b = 1
// a = temp; // a = 2

// function define
// Prototype : void swap(int a, int b)
// 정수 변수 a와 b의 값을 교환

void swap(int *a, int *b)		// 배열을 받을 때와 주소를 전달받을 때 포인터를 사용할 수 있다.
{								// a, b를 포인터로 선언하고 전달된 매개변수 값으로 설정 (초기화)

								// 포인터를 사용방법 : 포인터가 가리키는 주소의 값 : *p
								//					주소 자체 : p

								// [] == *이므로, int c = a[0], int d = b[0]으로 사용 가능
								// (사용법이 포인터가 더 나아보인다.)
	int temp = *a;	// temporary variable

					// 우리가 필요한 값은, 매개변수에 기록된 주소에 있는 값이다.

//	printf("	Input > a(%08x) : %d, b(%08x) : %d\n", a, *a, b, *b);			// 표시x : 주소, * : 값
				// 변수 자체가 저장되는 것과 swap과는 다른 것이다. 즉, 다른 저장할 공간이 필요하다.
	*a = *b;
	*b = temp;
//	printf("	Result > a(%08x) : %d, b(%08x) : %d\n", a, *a, b, *b);
}

//void SwapTest()
//{
//	int a = 50, b = 60;
//	printf("Original> a(%08x) : %d, b(%08x) : %d\n", &a, a, &b, b);
//
//	swap(&a, &b);	// swap()의 a, b와 SwapTest의 a, b 가 저장된
//					// 공간은 서로 다르다. -> 포인터를 이용!
//					// local 변수로 받아서 swap 함수를 수행하는 것
//					// 변수 자체의 주소를 전달하도록 바꿔 주는 것이 필요
//					// (scanf("%d", &age))	// & : 변수의 주소를 표시
//					// '변수 자체의 주소를 던저준다' 라고도 한다.
//
//	printf("After swap> a(%08x) : %d, b(%08x) : %d\n", &a, a, &b, b);
//		// 변수의 유효범위를 고려해야 한다.
//		// %08x : 전체 8자리, 비어 있는 자리는 0(null)으로 채우고, 
//		// 부호 없는 16진 소문자 정수
//}

void sort(int* a, int n)		// swap 과정이 필요
{						// 두 개 값 비교, 그 후에 다른 값과 비교
						// 이중 반복 사용
						// 포인터, 배열의 개수
	int i, j, k;

	for (i = 0; i < n; i++)
	{
		for (j = i; j < n; j++)	// 시작 위치 : i부터
		{
			if (a[i] < a[j])	swap(a+i, a+j);		// a+i : i요소의 포인터, a+j : j요소의 포인터
							// = swap(&a[i], &a[j]);	(포인터가 익숙하지 않다면)
		}
	}
}

struct student {
	int kor;
	int eng;
	char name[10];
};


// 20210812 미션
// 위의 구조체를 이용하여 사용자 정의 자료형을 선언하고,
// 10명의 학생에 대한 데이터를 입력한 후 정렬하여 출력하시오.

// 전역변수 : 이하의 함수에서 사용 가능
const int nArr = 10;
int kor[] = { 67, 70, 77, 65, 68, 72, 79, 55, 85, 61 };
int eng[] = { 70, 75, 80, 60, 65, 55, 80, 95, 67, 84 };
//char name[] = "ABCDEFGHIJK"; // 문자열 포인터로 변경 :
							 // "홍길동" , "홍길이", "홍길삼", "홍길사", "홍길오", 
							 // "맹일", "맹이", "맹삼", "맹사", "맹오"
const char* name[nArr] = {				// 포인터 배열 = ** = *[] = [][] = 2차원 배열(string *)
	"홍길동", "홍길이",
	"홍길삼", "홍길사",
	"홍길오", "맹일",
	"맹이",   "맹삼",
	"맹사",   "맹오"	
};				// 스트링 어레이 (string array, string[] = string *) -> 포인터가 대상이 된다.

				// string data type은 없다. 다만, c/c++에서 MFC를 다룰 때, string data type과 같은
				// class를 다룬다.

// C 언어의 변수와 연산자 keyword가 40여개이다. 제약조건이 많지 않아서 프로그램을 작성하는데 유연성이
// 크다.

void swapEx(double* a, double* b)		
{
	double temp = *a;	
	*a = *b;
	*b = temp;
}

void swapCh(char* a, char* b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}

void swapCh2(const char** a, const char** b)		// 2차원 배열과 똑같다 ** = [][] = *[] (string * : 4byte)
//void swapCh2(const char*a[], const char*b[])
{
	const char* temp = *a;	// 임시 저장 변수도 string array 형으로 지정해주기.
	*a = *b;					// 값이 바뀐 것이 아니라, swap에서만 바꾸어서 돌려줌
	*b = temp;				// 그렇게 하려면 *를 붙여야 한다. (마지막은 왜??)

	// 'abc' 중, **a라고 한다면, **a = 'a' 이렇게 된다. 
	// 그러면 결국은, *로 표시해 놓는것이다.

	/* const char *c = a[0];
	   a[0] = b[0];
	   b[0] = c;*/

	// 스트링 배열도 1차원 배열로 볼 수 있다.
	
}

/* 앞으로 char은 문자
   char* : string
   char** : string array로 생각하자. */

/* 개발용 노트북 고려사항
	램 최소 8gb + 확장성 가능
	사양은 i5 9세대 이상, 클럭수가 높으면 좋다.
	해상도*/

void sortEx(double* a, int n)		
{
	int i, j, k;

	for (i = 0; i < n; i++)
	{
		for (j = i; j < n; j++)	
		{
			if (a[i] < a[j])
			{
				swapEx(a + i, a + j);	// = swap(&a[i], &a[j]);	   // tot : double swap
				swap(kor + i, kor + j);
				swap(eng + i, eng + j);
				//swapCh(name + i, name + j);
				//swap((int*)name + i, (int*)name + j);	// 곤란한 방법
				swapCh2(name + i, name + j);								// name
							// char* = string 으로 각인하자.
			}
		}
	}
}

// 통합 swap 함수
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
	}
}

void sortEx2(double* a, int n)
{
	int i, j, k;

	for (i = 0; i < n; i++)
	{
		for (j = i; j < n; j++)
		{
			if (a[i] < a[j])
			{
				totalswap(a + i, a + j, 8);
				totalswap(kor + i, kor + j, 4);
				totalswap(eng + i, eng + j, 4);
				totalswap(name + i, name + j, 4);

			}
		}
	}
}




void sortTest()  // 배열을 이용한 성적 처리
{
		
	//int arr[] = { 67, 70, 77, 65, 68, 72, 79, 55, 85, 61 };

	int i, j, k;
	const int nArr = 10;
	double f_kor = 0.3, f_eng = 0.7;	// 가중치
	double tot[nArr];

	for (i = 0; i < nArr; i++)
	{
		tot[i] = kor[i] * f_kor + eng[i] * f_eng;
	}

	printf("Original : \n");
	printf("이름 : "); for (int i = 0; i < nArr; i++) printf("%7s ", name[i]); printf("\n\n");
	printf("국어 : "); for (int i = 0; i < nArr; i++) printf("%7d ", kor[i]); printf("\n\n");
	printf("영어 : "); for (int i = 0; i < nArr; i++) printf("%7d ", eng[i]); printf("\n\n");
	printf("합계 : "); for (int i = 0; i < nArr; i++) printf("%7.2f ", tot[i]); printf("\n\n");
	
	sortEx2(tot, nArr);		// 정렬

	printf("Sorted : \n");
	printf("이름 : "); for (int i = 0; i < nArr; i++) printf("%7s ", name[i]); printf("\n\n");
	printf("국어 : "); for (int i = 0; i < nArr; i++) printf("%7d ", kor[i]); printf("\n\n");
	printf("영어 : "); for (int i = 0; i < nArr; i++) printf("%7d ", eng[i]); printf("\n\n");
	printf("합계 : "); for (int i = 0; i < nArr; i++) printf("%7.2f ", tot[i]); printf("\n\n");

	
	//printf("Original : ");	
	//for (int i = 0; i < nArr; i++) printf("%d ", arr[i]);  
	//printf("\n\n");

	//sort(arr, nArr);		// 함수 만들 때, 매개변수의 이름이 달라도 되지만, 자료형은 맞춰주어야 한다.
	//// sort(arr, (float)nArr);		// 안되는것

	//printf("Sorted : ");	
	//for (int i = 0; i < nArr; i++)	printf("%d ", arr[i]);
	//printf("\n\n");
}

void VoidPrint(void* p, int i)		// void pointer의 casting
{
	if (i == 1)		// char
	{
		char* cp = (char*)p;
		printf("%c\n", *cp);
	}
	if (i == 2)	printf("%d\n", *(int*)p);		// int
	if (i == 3)	printf("%f\n", *(double*)p);	// double
	if (i == 4) printf("%f\n", *(float*)p);		// float
	if (i == 5) printf("%s\n", *(char**)p);		// string

}





void VoidTest()
{
	char c = 'z';
	int n = 10;
	double a = 1.414;

	void* vp;
	VoidPrint(vp = &c, 1);
	VoidPrint(vp = &n, 2);
	VoidPrint(vp = &a, 3);
}



void TotalSwapTest()
{
	int a = 1;
	int b = 2;
	void* vp1;
	void* vp2;

	printf("before : a : %d, b : %d\n", a, b);
	totalswap(&a, &b, 1);
	printf("after : a : %d, b : %d", a, b);
}
int main()
{
	//SwapTest();
	sortTest();
	//VoidTest();
	//TotalSwapTest();
}