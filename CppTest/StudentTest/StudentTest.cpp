#include <iostream>
#include "..\MyHeader.h"
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS

void ShowClass(Student st1)
{
	std::cout << "st1.Number : " << st1.number() << "      ";
	std::cout << "st1.name : " << st1.name() << "      ";
	std::cout << "st1.Age : " << st1.age() << "      ";
	std::cout << "st1.kor : " << st1.kor() << "      ";
	std::cout << "st1.eng : " << st1.eng() << "      ";
	std::cout << "st1.tot : " << st1.tot() << "      ";
	std::cout << "st1.avg : " << st1.avg() << "\n";
}

void swap(int *a, int *b)  // 포인터 사용  : call-by-reference
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
int main(void)
{
	// string st = "텍스트"
	std::string fname;  // string은 std::string을 사용하면 된다. 만약 귀찮으면 맨 앞에 using namespace std; 작성
	//st = "문자열";

	std::string nm = "춘향이";			
	fname = "C:\\Users\\KOSTA\\source\\repos\\KOSTA\\CppTest\\student2.txt";	// 이것도 가능		// 스트링 변수에 대한 대입문

	std::string strAdded = fname + nm;	//string에서 find, c_str, length, replace;
	std::cout << strAdded << std::endl << std::endl;



	Student st(0, 80, 76, nm, 15);
	ShowClass(st);
	std::cout << std::endl << std::endl;
	//Student st1(1, 80, 75, (char*)"홍길동", 15); 		// 1. 초기화  // 1. Student(const Student &) : default
												// 2. Student(Student &&) : meaningless
												// 3. Student(int num, int kor, int eng, char *str=(char*)0, int age=0)

	//ShowClass(st1);
		
	int num, age, kor, eng;
	char name[100];
	int count = 0;
	Student* stu[100];		// pointer 방식으로 array 선언 (but pointer 타입이 아님) (4byte -> 유리한 면 있지만, 실 데이터가 없다는점이 단점)
							// 일정한 간격으로 지정이 안 될수도 있다. 
	//Student	 st1[100];		// 실변수 타입으로 배열을 선언  (100byte) // 좋은 방법은 아니다.(추천하지 않는다.)
	//Student* stu = new Student* [100];
	
	FILE* fp = fopen(fname.c_str(), "r");	// 기본 argument 타입 : const char* -> string을 바로 쓸 수는 없다.
									// 다만, string에 .c_str()을 사용하면 된다.
	fgets(name, 250, fp);		// 이렇게 날려 보낼 수도 있다.
								// 첫줄 무시 ==> file read pointer를 다음 줄로 이동
	while (1)
	{
		if (fscanf(fp, "%d %s %d %d %d", &num, name, &age, &kor, &eng) < 1) break;	// 참고 : fscanf는 ,(컴마) 구분자를 인식하지 못한다.
		stu[count++] = new Student(num, kor, eng, name, eng);		// 동적할당
																	// 만약, name을 string, char*, const이든 간에 한번에 하고 싶다? -> 그런 방법은 없다
																	// 그래서 데이터 타입에 따라서 overload가 필요한 것임
		ShowClass(*stu[count - 1]);	
	}

	std::cout << std::endl << std::endl;
	// Class sorting
	for (int i = 0; i < count- 1; i++)
	{
		for (int k = i+ 1; k < count; k++)
		{
			if (stu[i]->avg() > stu[k]->avg());
			{
				//swap((int*)&stu[i], (int*)&stu[k]);  // 값이 바뀌는 것이 아니고, 이름표만 교환한다!
													// student 자체의 값을 의미함. (int *)형으로 전환
										// 힙 영역에는 값이 들어 있는 주소가 있고, 스택에는 그 값이 있다.
										// 힙 영역에서 주소만 swap하면 sort가 되므로 굳이 스택까지 값을 바꾸지 않아도 된다.
										// 그 후에 swap의 매개변수는 int 포인터로 4byte이다. 따라서 int형으로 형변환을 시켜주어야 한다.

				swapRef((int&)stu[i], (int&)stu[k]);		// call-by-reference
			}
		}
	}

	std::cout << "\n";
	for (int i = 0; i < count; i++)
	{
		ShowClass(*stu[i]);
	}

	return 0;
}// 다시 해보기 (이상함)


// string = char*(문자열 , object(= class but, 꼭 class가 아닐 수도 있다.)이다.)
// string = 문자열(data type) -> double quotient(쌍따옴표로 구분된 문장)
// char : 문자(data type) -> single quotient(홑따옴표로 구분된 문장)
// 
// object = class = data(struct) = 프로그램 = 함수
// . (점)을 많이 시도해 보면 class를 많이 다룰 수 있다.