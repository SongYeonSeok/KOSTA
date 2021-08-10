```c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <conio.h>

// 정렬 알고리즘 : sorting (알고리즘에 있어서 가장 기본적인 형태 구현 rule)
//
// 문제 : 두 과목의 성적이 다음과 같을 때 개인별 합계를 구하여 합이 큰 순서대로
// 정렬하여 출력하시오.

/* data

	국어		82	93	71	69	78	84	75
	영어		76	91	67	73	86	63	83
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

	printf("	Input > a(%08x) : %d, b(%08x) : %d\n", a, *a, b, *b);			// 표시x : 주소, * : 값
				// 변수 자체가 저장되는 것과 swap과는 다른 것이다. 즉, 다른 저장할 공간이 필요하다.
	*a = *b;
	*b = temp;
	printf("	Result > a(%08x) : %d, b(%08x) : %d\n", a, *a, b, *b);
}

void SwapTest()
{
	int a = 50, b = 60;
	printf("Original> a(%08x) : %d, b(%08x) : %d\n", &a, a, &b, b);

	swap(&a, &b);	// swap()의 a, b와 SwapTest의 a, b 가 저장된
					// 공간은 서로 다르다. -> 포인터를 이용!
					// local 변수로 받아서 swap 함수를 수행하는 것
					// 변수 자체의 주소를 전달하도록 바꿔 주는 것이 필요
					// (scanf("%d", &age))	// & : 변수의 주소를 표시
					// '변수 자체의 주소를 던저준다' 라고도 한다.

	printf("After swap> a(%08x) : %d, b(%08x) : %d\n", &a, a, &b, b);
		// 변수의 유효범위를 고려해야 한다.
		// %08x : 전체 8자리, 비어 있는 자리는 0(null)으로 채우고, 부호 없는 16진 소문자 정수


}

int main()
{
	SwapTest();
}
```
