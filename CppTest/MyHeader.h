#include <iostream>

// strcpy를 할 때, c 헤더파일인 string.h을 작성하는 게 좋지만, 이왕이면 C++을 하니까 iostream을 하는 게 좋을 것!
void swapValue(int a, int b);  // 함수의 원형(prototype) 선언
void swapRef(int& a, int& b); 
void swapRef(int* p1, int* p2);
void str_cpy(char* dest, char* src);
/*define MAX(X, Y) ((X)>(Y)) ? (X) : (Y)
#define MIN(X, Y) ((X)<(Y))? (X):(Y)
#define ABS(X)	  ((x)<0)?(-x):(x)*/

template <typename T>
T Add(T num1, T num2)
{
	return num1 + num2;
}

template <typename T>
T MAX(T num1, T num2)
{
	if (num1 > num2) return num1;
	else return num2;
}

template <typename T>
T MIN(T num1, T num2)
{
	if (num1 < num2) return num1;
	else return num2;
}

template <typename T>
T ABS(T num)
{
	if (num < 0) return -num;
}



// 만약에 위에 #define을 사용한다면 다음의 함수는 필요하지 않다. 
/*int MIN(int X, int Y)
{
	if (X > Y) return Y;
	else return X;
}

double MIN(double X, double Y)
{
	if (X > Y) return Y;
	else return X;
}  // 오버로드 방식
*/



class Point
{
private:
	int x;
	int y;

public:	


	Point(int x = 0, int y = 0) : x(x)
	{
		this->y = y;
	}

	int GetX() { return x; }
	int GetY() { return y; }
	void SetX(int x) { this->x = x; }
	void SetY(int y) { this->y = y; }

	double distance(Point p);	// Point p와의 거리

	Point operator+(Point p)	// 새로운 point!
	{
		return Point(this->x + p.x, this->y + p.y);		// 여기서 계산된 새로운 point가 생성되면서 
	}
};

// 2d -> 3d? => 상속 사용
class Point3D : public Point	// 2D Point class 상속
{
private:
	int z;	// z축

public:
	Point3D(int x = 0, int y = 0, int z = 0) : Point(x, y)
	{
		this->z = z;
	}
	int GetZ() { return z; }
	void SetZ() { this->z = z; }

	double distance3D(Point3D p);
};

class Person		// 정적
{
private:
	int Number;	// 고유 번호(index number), unsigned int : 양수 int -> 범위 넓어짐
	char Name[100];				// 이름 : 한글 10자까지 담을 수 있도록!
							// 문자열을 담을 그릇은? => malloc or new를 이용해서 동적으로 할당 필요
	int Age;
	std::string nam;

public:
	// Person(int num) : Number(num), Age(0) {}	// initializer (초기화, 최소 num은 있어주어야 함)

	Person(int num, char* str=0, int a=0) : Number(num), Age(a)
	{
		//strcpy(Name, str); // 오류 발생 시 strcpy_s 사용하기
		strcpy(Name, str);	// strcpy_s는 size를 지정해야 한다. 

		//strcpy(Name, str);	// val = num (-> num 값이 val로 넘겨가는 것이 대입 연산자의 특징이다.) 왼쪽 : 종속변수, 오른쪽 : 입력변수
		// Name에 값을 넣기 위해서.... malloc, new를 이용해서 동적으로 할당이 필요하다.
		// strcpy는 <string.h>에 있음... -> 헤더파일에 같이 지정하기! (가능하면 함수를 만들어 보는 것으로 하자! => 오류 발생 가능성 높음...)
		


		// strcpy 함수 만들기!

	}// initializer
	int age() { return Age; }  // 현재의 나이를 반환함
	char* name() { return Name; }  // 이름을 반환함
	int number() { return Number; }
	void SetAge(int a) { Age = a; }
	void SetName(char* str)  // 기존 방을 비우고(delete) 새 방을 잡자. 
	{
		str_cpy(Name, str);
	}
};

class PersonEx		// 동적 + 소멸자
{
private:
	int Number;	// 고유 번호(index number), unsigned int : 양수 int -> 범위 넓어짐
	char* Name;				// 이름 : 한글 10자까지 담을 수 있도록!
							// 문자열을 담을 그릇은? => malloc or new를 이용해서 동적으로 할당 필요
	int Age;

public:
	PersonEx(int num, char* str, int a) : Number(num), Age(a)
	{
		Name = new char[strlen(str)];  // data 구조에서 값은 heap에 저장되고, 포인터는 스택에 저장된다. 
			// (빈 방만 정하고, 주소는 알려준 상태 - 방 예약하고, 어떤 방을 잡았는지 호수는 알려준 상태)
		// 재할당 옵션 (메모리 동적 할당) -> 소멸자 만들어야 함!(뒷처리 잘 해야 함.)

		strcpy(Name, str);	// val = num (-> num 값이 val로 넘겨가는 것이 대입 연산자의 특징이다.) 왼쪽 : 종속변수, 오른쪽 : 입력변수
		// Name에 값을 넣기 위해서.... malloc, new를 이용해서 동적으로 할당이 필요하다.
	}// initializer

	~PersonEx()		// 소멸자
	{
		delete[]Name;
	}	

	int age() { return Age; }  // 현재의 나이를 반환함
	char* name() { return Name; }  // 이름을 반환함
	void SetAge(int a) { Age = a; }
	void SetName(char* str)  // 기존 방을 비우고(delete) 새 방을 잡자. 재할당 필요가 없음
	{
		delete[]Name;
		Name = new char[strlen(str)];	// 재할당 옵션(메모리 동적 할당)  -> 소멸해야 할 때 뒤처리 잘 해야함(delete 사용)
		strcpy(Name, str);
	}

};

class Student : public Person
{
private:
	int Kor;
	int Eng;
	int Tot;
	double Avg;
	int Rank;
	void calc()
	{
		Tot = Kor + Eng;
		Avg = (double)Tot / 2.0;
	}

public:
	Student(int num, int kor, int eng, char *str=0, int age=0) : Person(num, str, age)  // initializer  
												// str : 이름, age : 나이 (설정할 수도 있고 안할 수도 있다.)
	{
		this->Kor = kor;
		this->Eng = eng;
		calc();			// 데이터 무결성을 보증하는 프로그램의 예시이다. (고급의 과정)
	}		// 생성자

	/*Student(int num, int kor, int eng, const char* str = NULL, int age = 0) : Person(num, str, age)  // initializer  
	{
		this->Kor = kor;
		this->Eng = eng;
		calc();
	} */

	/*Student(int num, int kor, int eng, std::string str = NULL, int age = 0) : Person(num, str.c_str(), age)	// Person에 string, char*, const char* 설정
	{
		this->Kor = kor;
		this->Eng = eng;
		calc();
	}*/

	int kor() { return Kor; }  // private 변수들을 수정 가능하도록 함
	int eng() { return Eng; }
	int tot() { return Tot; }
	double avg() { return Avg; }
	int rank() { return Rank; }

	void SetKor(int k) { Kor = k; calc(); }
	void SetEng(int e) { Eng = e; calc(); }
	void SetRank(int r) { Rank = r; }
};

void str_cpy(char* dest, char* src)	// strcpy 함수와 동일한 역할
{
	while (*src) *dest++ = *src++;
}

void swapValue(int a, int b)
{
	int c = a;
	a = b;
	b = c;
}

void swapRef(int& a, int& b)  // 포인터를 사용하지 않음
{
	int c = a;
	a = b;
	b = c;
}

void swapRef(int* p1, int* p2)  // 포인터 사용
{
	int c = *p1;  // * == [], *a = *(a+0) = a[0]
	*p1 = *p2;
	*p2 = c;
}
