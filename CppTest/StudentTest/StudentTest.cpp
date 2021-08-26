#include <iostream>
#include <cstring>
#include "..\MyHeader.h"
#define _CRT_SECURE_NO_WARNINGS

void ShowClass(Student st1)
{
	std::cout << "st1.Number : " << st1.number() << "      ";
	std::cout << "st1.name : " << st1.name() << "      ";
	std::cout << "st1.Age : " << st1.age() << "      ";
	std::cout << "st1.kor : " << st1.kor() << "      ";
	std::cout << "st1.eng : " << st1.eng() << "      ";
	std::cout << "st1.tot : " << st1.tot() << "      ";
	std::cout << "st1.avg : " << st1.avg() << std::endl;
}

void ClassSort(Student* stu[])
{

}
int main(void)
{
	//Student st1(1, 80, 75, (char*)"홍길동", 15); 		// 1. 초기화  // 1. Student(const Student &) : default
												// 2. Student(Student &&) : meaningless
												// 3. Student(int num, int kor, int eng, char *str=(char*)0, int age=0)

	//ShowClass(st1);

	int num, age, kor, eng;
	char name[20];
	int count = 0;
	Student* stu[100];		// pointer 방식으로 array 선언 (but pointer 타입이 아님) (4byte -> 유리한 면 있지만, 실 데이터가 없다는점이 단점)
							// 일정한 간격으로 지정이 안 될수도 있다. 
	//Student	 st1[100];		// 실변수 타입으로 배열을 선언  (100byte) // 좋은 방법은 아니다.(추천하지 않는다.)
	//Student* stu = new Student* [100];
	
	FILE* fp = fopen("C:\\Users\\KOSTA\\source\\repos\\KOSTA\\CppTest\\student.csv", "r");
	fgets(name, 250, fp);		// 이렇게 날려 보낼 수도 있다.
								// 첫줄 무시 ==> file read pointer를 다음 줄로 이동
	while (1)
	{
		if (fscanf(fp, "%d %s %d %d %d", &num, name, &age, &kor, &eng) < 1) break;	// 참고 : fscanf는 ,(컴마) 구분자를 인식하지 못한다.
		stu[count++] = new Student(num, kor, eng, name, eng);		// 동적할당
		ShowClass(*stu[count - 1]);	
	}
	// Class sorting
	for (int i = 0; i < count- 1; i++)
	{
		for (int k = i+ 1; k < count; k++)
		{
			if (stu[i]->avg() > stu[k]->avg());
			{
				swapRef((int*)stu[i],(int*)stu[k]);  // 값이 바뀌는 것이 아니고, 이름표만 교환한다!
													// student 자체의 값을 의미함. (int *)형으로 전환
										// 여기까지
			}
		}
	}
	for (int i = 0; i < count; i++)
	{

	}

	


	return 0;
}