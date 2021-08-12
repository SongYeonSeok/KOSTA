#include <stdio.h>
#include <conio.h>

// 2단 4열의 구구단

int main()	// C/C++는 필수적으로 작성해야 한다.
{
//	int dan = 2;	// 구구단의 2단
//	int nDan = 9;	// xx단 : 9

//	for (int idx = 1; idx <= nDan; idx += 1)	// ++는 1씩 증가
//  for (int idx = 1; idx < nDan + 1; idx++)	// 위와 같은 방식(위의 방식이 편리할 때가 많다.)
// 		
											    // 프로그래머는 한 가지 방법이 아니라 여러 가지 방법을 사용하도록 해보자.
//	{
		// 임계 조건 : nDan은 9로 주어졌으므로, 결과도 nDan까지 나올 수 있도록 해야 한다.
//		printf("%d x %d = %2d\n", dan, idx, dan * idx);	// 2 x 2 = 4	dan x idx = (dan * idx)
														// 결과값이 2자리수이기 때문에, 큰 자릿수로 바꿔야 한다. %2d로 지정
//	}
	
	// console 프로그램은 Line 단위 출력이다.

//	printf("\n");

	// teacher's advise
//	int dan = 1;
//	int nDan = 9;

//	for (int idx = 1; idx <= nDan; idx++)
//	{
//		printf("%d x %d = %2d		", dan, idx, dan * idx);
//		printf("%d x %d = %2d		", (dan + 1), idx, (dan + 1) * idx);
//		printf("%d x %d = %2d		", (dan + 2), idx, (dan + 2) * idx);
//		printf("%d x %d = %2d		", (dan + 3), idx, (dan + 3) * idx);
//		printf("%d x %d = %2d\n", (dan + 4), idx, (dan + 4) * idx);
//
//	}

//	printf("\n");
//	dan = 6;
//	for (int idx = 1; idx <= nDan; idx++)
//	{
//		printf("%d x %d = %2d		", dan, idx, dan * idx);
//		printf("%d x %d = %2d		", (dan + 1), idx, (dan + 1) * idx);
//		printf("%d x %d = %2d		", (dan + 2), idx, (dan + 2) * idx);
//		printf("%d x %d = %2d\n", (dan + 3), idx, (dan + 3) * idx);
//
//	}

	// for문 중첩
//	for (dan = 2; dan < 10; dan += 4)
//	{
//		for (int idx = 1; idx <= nDan; idx++)
//		{
//			printf("%d x %d = %2d		", dan, idx, dan * idx);
//			printf("%d x %d = %2d		", (dan + 1), idx, (dan + 1) * idx);
//			printf("%d x %d = %2d		", (dan + 2), idx, (dan + 2) * idx);
//			printf("%d x %d = %2d\n", (dan + 3), idx, (dan + 3) * idx);
//		}
//		printf("\n\n\n");
//	}

	// 프로그래밍할 때 중요한 것 : 중복되는 것을 최소화!
	// 프로그래밍할 때 참고할 것 : 결과물은 같더라도, 코드는 모두 다르다. 코드는 같더라도 이름은 다르다. 따라서 효율적인 면을 따르는 것이 중요
	
	// teacher's advise 2

//int main()
//{		// 2단 4열 구구단
//	int i, j, k;	// 이렇게 먼저 자료형을 선언하는 방식을 사용하는 것을 적극적으로 권장!
//	int dan = 2;	// 구구단의 2단 ~ 9단
//	int nDan = 9;	// xx 단 : 9
//	for (dan = 2; dan < 10; dan += 4)
//	{
//		for (int idx = 1; idx <= nDan; idx++)
//		{
//			for (i = 0; i < 4; i++)		// i < 4도 반복 조건이지만, 탈출 조건도 가능 (초기값과 종료값을 주의하자)
//										// 4와 같은 상수를 안쓰는 것이 유연성을 높이는 길이다. 
//										// 4는 가로 방향 열 수를 의미
//			{
//				printf("%d x %d = %2d		", dan+i, idx, (dan + i) * idx);
//			}
//			printf("\n");
//		}
//		printf("\n\n\n");
//	}
	


//}

	// 상수, 설정값들을 위에 정의시켜 놓고, 초기값과 여러 설정값들을 미리 설정하고,
	// 	   그 외의 구간에 숫자를 입력하지 않도록 하자(권장, 잘하면 프로그래머로서 좋음)
	// 	   이유1 : 디버깅할 때 굉장히 유리 (값을 수정할 때 변수 하나만 변경하면 다 변경이 가능하니까, 시간도 줄이기 가능)
	// 	   이유2 : 코딩 시에 유연성 증가 
	// 	   따라서 가급적 상수를 많이 사용하지 않도록 하자

// 3단 3열 구구단
//int main()
//{
	int i, j, k;
//	int dan, nDan = 9;	// nDan : 9
	int hDan = 3;		// 가로 방향 열의 개수

	for (dan = 1; dan <= nDan; dan += hDan)
	{
		for (int idx = 1; idx <= nDan; idx++)
		{
			for (i = 0; i < hDan; i++)
			{
				printf("%2d x %2d = %3d		", dan + i, idx, (dan + i) * idx);
			}
			printf("\n");
		}
		printf("\n\n\n");
	}
//}
	// 최종 단계
//	for (int idx = 1; idx <= 9; idx++)
//	{
//		for (int dan = 1; dan <= 9; dan++)
//		{
//			printf("%d * %d = %2d\n", idx, dan, idx * dan);	// 결과값이 최대 2자릿수이기 때문
//		}
//		printf("\n");	// 구분
//	}
	
	getch();	// 프로젝트 -> 속성 -> C/C++ -> sdl 속성 (아니요) 설정
	return 0;
}

