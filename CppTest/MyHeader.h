#include <iostream>
#define _CRT_SECURE_NO_WARNINGS

// strcpy�� �� ��, c ��������� string.h�� �ۼ��ϴ� �� ������, �̿��̸� C++�� �ϴϱ� iostream�� �ϴ� �� ���� ��!
void swapValue(int a, int b);  // �Լ��� ����(prototype) ����
void swapRef(int& a, int& b); 
void swapRef(int* p1, int* p2);
void str_cpy(char* dest, char* src);




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

	double distance(Point p);

};

// 2d -> 3d? => ��� ���
class Point3D : public Point	// 2D Point class ���
{
private:
	int z;	// z��

public:
	Point3D(int x = 0, int y = 0, int z = 0) : Point(x, y)
	{
		this->z = z;
	}
	int GetZ() { return z; }
	void SetZ() { this->z = z; }

	double distance3D(Point3D p);
};

class Person		// ����
{
private:
	int Number;	// ���� ��ȣ(index number), unsigned int : ��� int -> ���� �о���
	char Name[20];				// �̸� : �ѱ� 10�ڱ��� ���� �� �ֵ���!
							// ���ڿ��� ���� �׸���? => malloc or new�� �̿��ؼ� �������� �Ҵ� �ʿ�
	int Age;

public:
	// Person(int num) : Number(num), Age(0) {}	// initializer (�ʱ�ȭ, �ּ� num�� �־��־�� ��)

	Person(int num, char* str=0, int a=0) : Number(num), Age(a)
	{
		//strcpy(Name, str); // ���� �߻� �� strcpy_s ����ϱ�
		str_cpy(Name, str);	// strcpy_s�� size�� �����ؾ� �Ѵ�. 

		//strcpy(Name, str);	// val = num (-> num ���� val�� �Ѱܰ��� ���� ���� �������� Ư¡�̴�.) ���� : ���Ӻ���, ������ : �Էº���
		// Name�� ���� �ֱ� ���ؼ�.... malloc, new�� �̿��ؼ� �������� �Ҵ��� �ʿ��ϴ�.
		// strcpy�� <string.h>�� ����... -> ������Ͽ� ���� �����ϱ�! (�����ϸ� �Լ��� ����� ���� ������ ����! => ���� �߻� ���ɼ� ����...)
		


		// strcpy �Լ� �����!

	}// initializer
	int age() { return Age; }  // ������ ���̸� ��ȯ��
	char* name() { return Name; }  // �̸��� ��ȯ��
	int number() { return Number; }
	void SetAge(int a) { Age = a; }
	void SetName(char* str)  // ���� ���� ����(delete) �� ���� ����. 
	{
		strcpy(Name, str);
	}
};

class PersonEx		// ���� + �Ҹ���
{
private:
	int Number;	// ���� ��ȣ(index number), unsigned int : ��� int -> ���� �о���
	char* Name;				// �̸� : �ѱ� 10�ڱ��� ���� �� �ֵ���!
							// ���ڿ��� ���� �׸���? => malloc or new�� �̿��ؼ� �������� �Ҵ� �ʿ�
	int Age;

public:
	PersonEx(int num, char* str, int a) : Number(num), Age(a)
	{
		Name = new char[strlen(str)];  // data �������� ���� heap�� ����ǰ�, �����ʹ� ���ÿ� ����ȴ�. 
			// (�� �游 ���ϰ�, �ּҴ� �˷��� ���� - �� �����ϰ�, � ���� ��Ҵ��� ȣ���� �˷��� ����)
		// ���Ҵ� �ɼ� (�޸� ���� �Ҵ�) -> �Ҹ��� ������ ��!(��ó�� �� �ؾ� ��.)

		strcpy(Name, str);	// val = num (-> num ���� val�� �Ѱܰ��� ���� ���� �������� Ư¡�̴�.) ���� : ���Ӻ���, ������ : �Էº���
		// Name�� ���� �ֱ� ���ؼ�.... malloc, new�� �̿��ؼ� �������� �Ҵ��� �ʿ��ϴ�.
	}// initializer

	~PersonEx()		// �Ҹ���
	{
		delete[]Name;
	}	

	int age() { return Age; }  // ������ ���̸� ��ȯ��
	char* name() { return Name; }  // �̸��� ��ȯ��
	void SetAge(int a) { Age = a; }
	void SetName(char* str)  // ���� ���� ����(delete) �� ���� ����. ���Ҵ� �ʿ䰡 ����
	{
		delete[]Name;
		Name = new char[strlen(str)];	// ���Ҵ� �ɼ�(�޸� ���� �Ҵ�)  -> �Ҹ��ؾ� �� �� ��ó�� �� �ؾ���(delete ���)
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
		Avg = Tot / 2;
	}

public:
	Student(int num, int kor, int eng, char *str=0, int age=0) : Person(num, str, age)  // initializer  
												// str : �̸�, age : ���� (������ ���� �ְ� ���� ���� �ִ�.)
	{
		this->Kor = kor;
		this->Eng = eng;
		calc();			// ������ ���Ἲ�� �����ϴ� ���α׷��� �����̴�. (����� ����)
	}		// ������

	int kor() { return Kor; }
	int eng() { return Eng; }
	int tot() { return Tot; }
	double avg() { return Avg; }
	int rank() { return Rank; }

	void SetKor(int k) { Kor = k; calc(); }
	void SetEng(int e) { Eng = e; calc(); }
	void SetRank(int r) { Rank = r; }
};

void str_cpy(char* dest, char* src)	// strcpy �Լ��� ������ ����
{
	while (*src) *dest++ = *src++;
}

void swapValue(int a, int b)
{
	int c = a;
	a = b;
	b = c;
}

void swapRef(int& a, int& b)  // �����͸� ������� ����
{
	int c = a;
	a = b;
	b = c;
}

void swapRef(int* p1, int* p2)  // ������ ���
{
	int c = *p1;  // * == [], *a = *(a+0) = a[0]
	*p1 = *p2;
	*p2 = c;
}
