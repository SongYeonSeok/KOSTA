#include <iostream>
#include <cstdio	>
#include "MyHeader.h" 

// 위의 MyHeader.h는 절대 경로가 필요하다.


/*	상대 경로 예시 : #include "MyHeader.h" (current directory 포함)
	절대 경로 예시 : #include "C:\users\....\MyHeader.h"
	..파일이름.h : current directory의 상위 디렉토리에 있는 헤더파일을 표시*/
using namespace std;

// 함수의 프로토타입(원형) 선언 (헤더 파일로 지정함)
void swapRef(int& a, int& b);

int main(void)
{
	cout << "Hello C plus plus World!\n\n"; 
	// IDE에서 중요한 키워드 : Debugging
	// cout의 의미 : 전역 스트림을 지정한다. (exterm ostream cout;)
	int a, b;
	a = 10;
	b = 20;

	cout << "초기값은 a= " << a << ", b = " << b << endl; // %d과 같은 format 형식을 쓰지 않아도 된다.
	// printf를 쓰는게 좋지 않을까요? -> 그러면 #include <stdio.h>를 사용하면 된다.(iostream은 없다.)

	// call-by-value
	swapValue(a, b);
	cout << "결과 값(swapValue)은 a = " << a << ", b = " << b << endl;
	// 값에 영향이 없다.

	// call-by-reference
	// 레퍼런스는 변수명의 별명이다! 값을 가지고 있는 것이 아닌 말 그대로 별명이다.
	// 포인터를 사용하지 않음
	swapRef(a, b);
	printf("결과값(swapRef)은 a = %d, b = %d \n\n", a, b);

}

void swapValue(int a, int b)
{
	int c = a;
	a = b; 
	b = c;
}

void swapRef(int &a, int &b)
{
	int c = a;
	a = b;
	b = c;
}

