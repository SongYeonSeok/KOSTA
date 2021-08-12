#include <stdio.h>
#include <stdlib.h>		// standard library.h 많이 쓰임. 따라서 넣는 것도 좋다.
#include <math.h>		// 수학적인 계산이 필요할 때 사용
#include <conio.h>
#include <time.h>		// 랜덤 변수를 만들 기 위해 사용

const int students = 20;	// global 변수
int main()
{
	int i, j, k;
	double average, total;
	double kor[students], eng[students], mat[students];			// c에서 배열의 개수를 선언할 때 반드시 변수가 아닌 상수를 지정해야 한다.
																// 하지만, 그럼에도 변수를 쓰고 싶다면 const를 써서 변수를 상수화 시켜야 한다.
	
	// rand() : random 난수 함수 (정확하게 진짜 난수가 아니다. 난수표에서 나온 난수들이다.) => seed라는 것을 임의로 정해두자.

	srand(time(NULL));	//time이라는 변수가 정의되어 있지 않다.	// seed 지정 -> 이것으로 인해 디버깅할 때마다 다른 자료가 나온다.
	for (i = 0; i < students; i++)							
															
	{
		kor[i] = (double) ((rand() % 1000) + 1) / 10;		// 난수 발생기 rand() : 정수 0 ~ 100.0	->	0 ~ 999 -> 1 ~ 1000 -> 0.1 ~ 100.0
															// rand() : 정수, 나머지 계산도 전부 정수이다. 따라서 float형으로 변환해야 한다.
															// -> 강제 형 변환 (Casting) 필요!

		eng[i] = (double) ((rand() % 1000) + 1) / 10;		// 난수 발생기 rand() : 정수 0 ~ 100.0	->	0 ~ 999 -> 1 ~ 1000 -> 0.1 ~ 100.0

		mat[i] = (double) ((rand() % 1000) + 1) / 10;		// 난수 발생기 rand() : 정수 0 ~ 100.0	->	0 ~ 999 -> 1 ~ 1000 -> 0.1 ~ 100.0
	}

	//for (j = 0; j < students; j++)
	//{
	//	printf("%.1f  %.1f  %.1f\n", kor[j], eng[j], mat[j]);
	//}

	printf("A학교 B반 국어 점수 현황\n========================\n\n개인점수 리스트:\n");

	for (total = 0,	k = 0; k < students; k++)		// total = 0, k = 0 부분은 초기값 부분이다. (스킬 높일 때 씀)
	{
		printf("%7.1f\n", kor[k]);					// 실수 출력의 전체 자리수를 7자리, 소수점 이하 1자리
		total += kor[k];
	}
	average = total / students;

	printf("총점 : %7.1f점\n", total);
	printf("평균 : %7.1f점\n", average);
	

	printf("\nA학교 B반 영어 점수 현황\n========================\n\n개인점수 리스트:\n");

	for (total = 0, k = 0; k < students; k++)		// total = 0, k = 0 부분은 초기값 부분이다. (스킬 높일 때 씀)
	{
		printf("%7.1f\n", eng[k]);					// 실수 출력의 전체 자리수를 7자리, 소수점 이하 1자리
		total += eng[k];
	}
	average = total / students;

	printf("총점 : %7.1f점\n", total);
	printf("평균 : %7.1f점\n", average);

	printf("\nA학교 B반 수학 점수 현황\n========================\n\n개인점수 리스트:\n");

	for (total = 0, k = 0; k < students; k++)		// total = 0, k = 0 부분은 초기값 부분이다. (스킬 높일 때 씀)
	{
		printf("%7.1f\n", mat[k]);					// 실수 출력의 전체 자리수를 7자리, 소수점 이하 1자리
		total += mat[k];
	}
	average = total / students;

	printf("총점 : %7.1f점\n", total);
	printf("평균 : %7.1f점\n", average);
}