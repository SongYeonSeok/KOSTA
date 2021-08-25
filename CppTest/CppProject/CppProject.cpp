#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>

class Person
{
public:
	char name[10];
	int age;
};

class Student : public Person
{
public:
	int kor;	// 국어 성적
	int eng;	// 영어 성적

	int tot;		// 합계
	double avg;		// 평균

};

// prototype
void FileLoadnSort();
void swap(int& a, int& b);
void swap(double& a, double& b);
void swap(char& a, char& b);
void sort(int a, int b);

//파일을 이용하여 이름, 과목명과 점수를 입력받고
//과목별 합계 및 평균을 구하여 성적순으로 정렬하여 파일로 출력하시오.
//단, 아래 구조를 갖는 person class를 구성하고, 이를 상속하는
//student class를 구성하여 구현하시오.


const int num = 10;

int main(void)
{
	FileLoadnSort();
	return 0;
}

// 파일에 입력하기
void FileLoadnSort()	// File Load & Swap
{

	int i;

	FILE* fin = fopen("C:/Users/KOSTA/table2.txt", "r");  // 문제가 여기서 생긴거 같다
	FILE* fout = fopen("C:/Users/KOSTA/results.txt", "a+b");

	if (fin != NULL)
	{
		printf("%s", "파일 오픈 성공");
	}

	Person* per = new Person[10];		
	Student* std = new Student[10];		

	for (i = 0; i < num; i++)	fscanf(fin, "%7s ", per[i].name);	printf("\n\n");
	for (i = 0; i < num; i++)	fscanf(fin, "%7d ", per[i].age);	printf("\n\n");
	for (i = 0; i < num; i++)	fscanf(fin, "%7d ", std[i].kor);	printf("\n\n");
	for (i = 0; i < num; i++)	fscanf(fin, "%7d ", std[i].eng);	printf("\n\n");
	for (i = 0; i < num; i++)
	{
		std[i].tot = std[i].kor + std[i].eng;
		std[i].avg = (std[i].kor + std[i].eng) / 2;
	}

	fprintf(fout, "기존 : \n");
	fprintf(fout, "%-7s %-7s %-7s %-7s %-7s %-7s\n", "	이름", "	나이", "	국어", "	영어", "	총점", "	평균");

	for (int i = 0; i < num; i++)
	{
		fprintf(fout, "%-7s %-7s %-7d %-7d %-7d %-7f\n", per[i].name, per[i].age,
			std[i].kor, std[i].eng, std[i].tot, std[i].avg);
	}
	
	for (int i = 0; i < num; i++)
	{
		printf("%-7s %-7s %-7d %-7d %-7d %-7f\n", per[i].name, per[i].age,
			std[i].kor, std[i].eng, std[i].tot, std[i].avg);
	}

	fclose(fin); fclose(fout); // 파일 닫기
}

// swap
void swap(int& a, int& b)
{
	int temp = a;
	a = b; b = temp;
}

void swap(double& a, double& b)
{
	double temp = a;
	a = b; b = temp;
}

void swap(char& a, char& b)
{
	char temp = a;
	a = b; b = temp;
}

void sort(int a, int b)
{
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{

		}
	}
}