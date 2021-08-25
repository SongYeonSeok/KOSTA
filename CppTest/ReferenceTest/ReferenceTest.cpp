#include <iostream>
#include <cstdio>
#include <cmath>
#include "C:\Users\KOSTA\source\repos\KOSTA\CppTest\MyHeader.h"

// 위의 MyHeader.h는 절대 경로가 필요하다.


/*	상대 경로 예시 : #include "MyHeader.h" (current directory 포함)
	절대 경로 예시 : #include "C:\users\....\MyHeader.h"
	..파일이름.h : current directory의 상위 디렉토리에 있는 헤더파일을 표시*/
using namespace std;

// 클래스 (모든 클래스에는 생성자가 있어야 한다고 했다!)
class Point		// 클래스 키워드, 클래스 이름
{
private:		// private, public 필요
	int x;   // 기본 접근 제어 지시자는 private이다.
	int y;	 // 기본 point : (x, y)

public:			// 멤버 변수 지정, 멤버 변수의 초기화, 생성자 작성

	//Point(int x=0, int y=0)	: x(x), y(y)	// Point p(10, 20) 형태로 호출할 수 있다. 
	//										// initializer을 하든지, 아니면 pointer을 쓰든지 편한 대로 시행하기
	//
	//	//this->x = x; this->y = y;	// Point 클래스의 x와 y임을 표시하기 위해!
	//}								// 이렇게 생성자를 만들어도 된다.

	Point(int x = 0, int y = 0) : x(x)
	{
		this->y = y;
	}

	int GetX() { return x; }
	int GetY() { return y; }
	void SetX(int x) { this->x = x; }
	void SetY(int y) { this->y = y; }  // private에 있는 값을 사용하기 위해서는...

	/*Point() : x(0), y(0)		// 아무 argument를 받지 않을 때(initializer) (기본 값 x=0, y=0)
	{
		x = 0; y=0;				// (위와 동일한 형태)
	};							// 생성자(클래스를 만든다면 무조건 해야 함!) */
	double distance(Point p);

};

// 2d -> 3d? => 상속 사용
class Point3D : public Point	// 2D Point class 상속
{
private:
	int z;	// z축

public:
	Point3D(int x = 0, int y = 0, int z = 0) : Point(x, y)
	{
		this->z =z;
	}
	int GetZ() { return z; }
	void SetZ() { this->z = z; }

	double distance3D(Point3D p);	// Point3D p와의 거리
};

// 함수의 프로토타입(원형) 선언 (헤더 파일로 지정함)
void swapRef(int& a, int& b);
void swapRef(int* a, int* b);

int main(void)
{
	//std::cout << "Hello C plus plus World!\n\n"; 
	//// IDE에서 중요한 키워드 : Debugging
	//// cout의 의미 : 전역 스트림을 지정한다. (exterm ostream cout;)
	//int a, b;
	//a = 10;
	//b = 20;
	//std::cout << "초기값은 a= " << a << ", b = " << b << std::endl; // %d과 같은 format 형식을 쓰지 않아도 된다.
	//// printf를 쓰는게 좋지 않을까요? -> 그러면 #include <stdio.h>를 사용하면 된다.(iostream은 없다.)
	//// call-by-value
	//swapValue(a, b);
	//std::cout << "결과 값(swapValue)은 a = " << a << ", b = " << b << std::endl;
	//// 값에 영향이 없다.
	//// call-by-reference
	//// 레퍼런스는 변수명의 별명이다! 값을 가지고 있는 것이 아닌 말 그대로 별명이다.
	//// 포인터를 사용하지 않음
	//swapRef(a, b);
	//printf("결과값(swapRef: reference)은 a = %d, b = %d \n\n", a, b);
	//swapRef(&a, &b); // 포인터를 사용한다면 주소&를 지정!
	//printf("결과값(swapRef : pointer)은 a = %d, b= %d \n\n", a, b);

	Point p1;		// 컴파일러가 혼동해서 오류 일으킴 // p(0,0)  struct -> typedef -> 사용
	Point p2(10, 20);
	Point* p3 = new Point(20, 30);  // p3라는 Point의 주소	// 동적 할당 (+초기화 실시)

	printf("Point class 변수의 동적 할당 : p3(%d, %d)\n\n", p3->GetX(), p3->GetY());

	printf("두 점 p1(%d, %d)과 p2(%d, %d)의 거리는 %f 입니다.\n", 
		p1.GetX(), p1.GetY(), p2.GetX(), p2.GetY(), p1.distance(p2));
	printf("두 점 p1(%d, %d)과 p2(%d, %d)의 거리는 %f 입니다.\n",
		p1.GetX(), p1.GetY(), p2.GetX(), p2.GetY(), p2.distance(p1));  // 같은 결과 나온다.



	Point3D pp1;
	Point3D pp2(10, 20, 30);
	Point3D* pp3 = new Point3D(40, 50, 60);
	printf("Point3D class 변수의 동적 할당 : p3(%d, %d, %d)\n\n", pp3->GetX(), pp3->GetY(), pp3->GetZ());

	printf("두 점 p3(%d, %d, %d)과 p2(%d, %d, %d)의 거리는 %f 입니다.\n",
		pp3->GetX(), pp3->GetY(), pp3->GetZ(), pp2.GetX(), pp2.GetY(), pp2.GetZ(), pp3->distance(pp2));  // pp3->distance(pp2) == pp2.distance(*pp3)
	printf("두 점 p3(%d, %d, %d)과 p2(%d, %d, %d)의 XY 평면거리는 %f 입니다.\n",
		pp3->GetX(), pp3->GetY(), pp3->GetZ(), pp2.GetX(), pp2.GetY(), pp2.GetZ(), pp2.distance(Point(pp3->GetX(), pp3->GetY())));

}

void swapValue(int a, int b)
{
	int c = a;
	a = b; 
	b = c;
}

void swapRef(int &a, int &b)  // 포인터를 사용하지 않음
{
	int c = a;
	a = b;
	b = c;
}

void swapRef(int *p1, int *p2)  // 포인터 사용
{
	int c = *p1;  // * == [], *a = *(a+0) = a[0]
	*p1 = *p2;
	*p2 = c;
}

double Point::distance(Point p)	// Point p와의 거리
{	// x과 y의 거리 : ((x2 - x1)^2 + (y2 - y1)^2)^(1/2) -> 유클리드 거리라고 말한다.
	int x2 = (x - p.x) * (x - p.x); // (x - p.x) ** 2
	int y2 = (y - p.y) * (y - p.y);
	return sqrt(x2 + y2);
}

double Point3D::distance3D(Point3D p)	// Point3D p와의 거리
{	// x과 y, z의 거리 : ((x2 - x1)^2 + (y2 - y1)^2 + (z2- z1)^2)^(1/2) -> 유클리드 거리라고 말한다.
	int x2 = (GetX() - p.GetX()) * (GetX() - p.GetX()); // 상속받은 x, y. private에 되어 있으므로, X(), Y()를 써야 한다.(public)
	int y2 = (GetY() - p.GetY()) * (GetY() - p.GetY());
	int z2 = (z - p.z) * (z - p.z);			// (GetZ() - p.GetZ())* (GetZ() - p.GetZ());도 가능
	return sqrt(x2 + y2 + z2);
}