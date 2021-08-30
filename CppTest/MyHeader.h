#include <iostream>

// strcpy�� �� ��, c ��������� string.h�� �ۼ��ϴ� �� ������, �̿��̸� C++�� �ϴϱ� iostream�� �ϴ� �� ���� ��!
void swapValue(int a, int b);  // �Լ��� ����(prototype) ����
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



// ���࿡ ���� #define�� ����Ѵٸ� ������ �Լ��� �ʿ����� �ʴ�. 
/*int MIN(int X, int Y)
{
	if (X > Y) return Y;
	else return X;
}

double MIN(double X, double Y)
{
	if (X > Y) return Y;
	else return X;
}  // �����ε� ���
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

	double distance(Point p);	// Point p���� �Ÿ�

	Point operator+(Point p)	// ���ο� point!
	{
		return Point(this->x + p.x, this->y + p.y);		// ���⼭ ���� ���ο� point�� �����Ǹ鼭 
	}
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
	char Name[100];				// �̸� : �ѱ� 10�ڱ��� ���� �� �ֵ���!
							// ���ڿ��� ���� �׸���? => malloc or new�� �̿��ؼ� �������� �Ҵ� �ʿ�
	int Age;
	std::string nam;

public:
	// Person(int num) : Number(num), Age(0) {}	// initializer (�ʱ�ȭ, �ּ� num�� �־��־�� ��)

	Person(int num, char* str=0, int a=0) : Number(num), Age(a)
	{
		//strcpy(Name, str); // ���� �߻� �� strcpy_s ����ϱ�
		strcpy(Name, str);	// strcpy_s�� size�� �����ؾ� �Ѵ�. 

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
		str_cpy(Name, str);
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
		Avg = (double)Tot / 2.0;
	}

public:
	Student(int num, int kor, int eng, char *str=0, int age=0) : Person(num, str, age)  // initializer  
												// str : �̸�, age : ���� (������ ���� �ְ� ���� ���� �ִ�.)
	{
		this->Kor = kor;
		this->Eng = eng;
		calc();			// ������ ���Ἲ�� �����ϴ� ���α׷��� �����̴�. (����� ����)
	}		// ������

	/*Student(int num, int kor, int eng, const char* str = NULL, int age = 0) : Person(num, str, age)  // initializer  
	{
		this->Kor = kor;
		this->Eng = eng;
		calc();
	} */

	/*Student(int num, int kor, int eng, std::string str = NULL, int age = 0) : Person(num, str.c_str(), age)	// Person�� string, char*, const char* ����
	{
		this->Kor = kor;
		this->Eng = eng;
		calc();
	}*/

	int kor() { return Kor; }  // private �������� ���� �����ϵ��� ��
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
