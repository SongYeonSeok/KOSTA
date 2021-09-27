# 목차
1. C++ 시작하기 (생략)
2. C++ 데이터 표현 방법
3. 프로그램의 흐름을 제어하는 선택문과 반복문
4. 배열과 포인터
5. 구조체와 공용체
6. C++에서의 함수 사용
7. 객체지향 프로그램의 기초, 클래스
8. 객체지향 프로그램의 도약, 상속
9. 객체지향 프로그램의 활용, 연산자 오버로딩
10. 템플릿 이해하기
11. 파일 입출력 및 예외처리

-------

## 2. C++ 데이터 표현 방법
1. 지원되는 자료형
  - 기본 자료형 : 각종 프로그램 언어마다 기본적으로 제공되는 자료형.
  변수나 객체(Object)의 형식 또는 그 크기를 구분하는 용도로 사용
  - C++ 제공 자료형 : 기본 자료형 + 사용자 정의 자료형
    - 기본 자료형 : 논리형, 문자형, 정수형, 실수형
    - 사용자 정의 자료형 : 열거형, 문자열, 포인터, 배열, 구조체, 공용체, 클래스
    - ![image](https://user-images.githubusercontent.com/49339278/134845550-0177af5e-398a-4d2a-9e26-c0e9c713d103.png)

    - 문자 셋 : 컴퓨터에서 문자를 표현하기 위해 정해놓은 것
      - SBCS, MBCS, WBCS가 있다.
  - 자료형 크기 확인 방법 : 프로그램을 실행하는 운영체제에 따라 다를 수 있으므로 sizeof 연산자로 크기를 확인하고 사용(32비트 운영체제 기준)
    - 형식 : ```sizeof(자료형), sizeof(표현식)```
  - 정수형 기본 자료형의 크기
    - signed < unsigned(양수 자료형)
    - unsigned : 0 이상의 양수를 나타내는 자료형으로 전체를 모두 데이터 비트로 사용 (signed보다 표현 범위가 비교적 길다)
  - 자료형의 크기를 기억해야 하는 이유 : **데이터 오버플로우(Overflow)가 일어날 수 있기 때문** -> 프로그램 작성 시 데이터의 최대값을 고려하여 자료형 선택해야 한다.

  - 사용자 정의 자료형 : 개발자가 정의하여 사용할 수 있는 사용자 정의 자료형
    - typedef : 사용자가 새로운 형의 이름을 선언할 수 있도록 해주는 typedef
      - 주의사항 : 새로운 형을 만드는 것이 아니라 **기존의 자료형에 새로운 이름을 부여**
      - 형식 : ```typedef 기존 자료형명 새로운_형명;```
        ```c++
        typedef unsigned char BYTE;
        typedef unsigned short WORD;
        typedef unsigned long DWORD;
        ```
      - typedef를 이용하여 새로운 이름을 부여하는 이유
        1. 프로그램의 **가독성을 높여** 소스코드 분석이 용이함
        2. **다양한 플랫폼에 포팅(Porting)** 이 가능한 프로그램의 작성 가능
        
          ```
          // 기본 자료형으로 작성
          unsigned int num1, num2;
          unsigned int get_addr(char* addr);
          char* put_addr(unsigned int addr);
          
          // typedef으로 작성
          typedef unsigned int uint32;
          uint32 num1, num2;
          uint32 get_addr(char* addr);
          char* put_addr(uint32 addr);
          ```
					
	- 32비트의 정수
		- int형의 크기가 4byte(32비트)인 플랫폼 : int형 사용
		- int형의 크기가 2byte(16비트)인 플랫폼 : 4바이트 자료형은 long형 -> 기존 방식은 프로그램을 일일이 변경해야 하지만, typedef 방식을 사용하면 수정할 부분이 적어진다.

			```c++
			//예시
			#include <iostream>
			using namespace std;

			int main(void)
			{
				typede unsigned short uint16;		// 재정의
				uint16 port;

				port = 65535;
				cout << port<< endl;

				return 0;
			}
			```
        
    - enum : 하나 이상의 정수형 상수를 원소로 갖는 열거형의 enum
    	- 형식 : ```enum 태그명 { 멤버명[=값], ...} 변수명;```
    		- 태그명(tag_name) : 변수 선언 시 **enum 자료형의 이름** 으로 사용
    		- 중괄호 사이에 열거되는 멤버들에게 특별히 값을 지정하지 않으면 **0, 1, 2, ...의 정수 값이 자동으로 할당** (실수, 문자열 지정불가)
    			```c++
					enum colors{ red, blue, yellow, green, white, black} mycolor;
					```
					
			- enum 사용 이유
				- 소스 코드 작성 시 가독성, **다른 사람이 읽기 쉬운 프로그램 작성 위해**
				- 소스코드 작성 시 **수가 상징하는 의미를 문자로 작성**하여 프로그램 분석이 용이함.
				- enum 멤버에 있는 값들은 **사용자가 지정 가능하다.**
				- 따로 **지정하지 않은 멤버들은 순차적인 값**을 가지게 됨 
			- 주의할 점 : enum 목록에 나열된 것은 문자열이 아니라 **정수형 상수**이므로 enum 자료형에 선언한 변수는 **정수형 변수와 동일하게 처리**
			
				```c++
				#include <iostream>
				using namespace std;
				
				int main(void)
				{
					enum languages {c = 10, cplusplus = 20, java = 30} myLanguage;

					myLanguage=cplusplus;

					cout <<"cplusplus"<<myLanguage<<endl;

					return 0;
				}
				```
				
    - struct
    - union
    - class

2. 변수와 상수, 그리고 표준입출
	- 변수 
		- 프로그램에서 데이터를 처리하기 위해 변수를 사용
		- 변수 : 데이터를 저장할 수 있는 메모리 공간의 이름
		- 변수의 이름 : 프로그램에서 다른 것과 구분하기 위해 개발자가 정해 사용하는 각종 이름들 -> 이를 식별자라고 한다.
		- 식별자의 종류
			- 변수 또는 오브젝트 이름
			- 클래스, 구조체, 공용체, 열거형 이름
			- 클래스, 구조체, 공용체, 열거형의 멤버 이름
			- 함수 이름
			- typedef 이름
			- 레이블 이름
			- 매크로 이름
			- 매크로 인자 이름
			
		- 식별자 이름의 규칙
			- 식별자에 사용될 수 있는 문자 : 문자, 영어 대문자, 영어 소문자, 숫자만 가능
			- 식별자의 첫 글자는 _ 문자나 영문자로 시작
			- 식별자에서 대소문자는 서로 구별
			- 키워드는 식별자로 사용 불가
			- 식별자의 길이에는 제헌이 없지만 **컴파일러 자체에서 허용하는 길이**가 있음
		
		- c++ 키워드
			
			| asm | auto | bad_cast | bad_typeid |
			|:--:|:--:|:--:|:--:|
			|bool|break|case|catch|
			|char|class|const|const_cast|
			|continue|default|delete|do|
			|double|dynamic_cast|else|enum|
			|except|explicit|extern|false|
			|finally|float|for|friend|
			|goto|if|inline|int|
			|long|mutable|namespace|new|
			|operator|private|protected|public|
			|register|reinterpret_cast|return|short|
			|signed|sizeof|static|static_cast|
			|struct|switch|template|this|
			|throw|true|try|type_info|
			|typedef|typeid|typename|union|
			|unsigned|using|virtual|void|
			|volatile|while|||
			
		- 변수 선언 :변수 사용 위해서는 선언부터 해야 함.
			- 변수 선언의 위치에 따라 그 변수의 유효 범위가 달라짐
				- 변수 선언하는 방법
					: 변수 선언과 동시에 초기화 가능, 변수 선언 후 나중에 초기화 가능
					- 만약 변수 선언 후 따로 초기화하지 않는다면?
						- 메모리에 이전 값이 남아있어 프로그램의 오동작 발생
						- **변수를 선언하면 초기화하는 습관**을 가지는 것이 좋다.
					- 변수 선언 시 같은 자료형의 변수와 함께 선언이 가능하다.
					- C++ 에서는 변수도 객체의 한 종류로 생각하기 때문에 **변수를 다루는 방법을 잘 알고 있어야 객체도 잘 다룰 수 있다.**
					
				- 전역변수와 지역변수
					- 지역변수 : 함수 내부에 선언되는 변수
					- 전역변수 : 함수 외부에 선언되는 변수
					
					- 프로그램이 실행되면, 운영체제에서 메모리 공간을 할당한다.
						- 프로세스 : 메모리 공간에서 실행 중인 프로그램을 말함.

						| 구성 | 의미 |
						|:---:|:---|
						|**스택 세그먼트(Stack Segment)**|지역 변수 및 리턴 주소. **함수가 수행되는 동안만 할당**|
						|**힙 세그먼트(Heap Segment)**|동적으로 할당되는 메모리|
						|**데이터 세그먼트(Data Segment)**|전역변수 및 정적(static) 변수. **프로그램 종료 시까지 해제되지 않음**|
						|**코드 세그먼트(Code Segment)**|프로그램의 실행코드|
						
				- 지역 변수는 함수의 수행 종료 시 사용이 불가능하다.
				- 전역 변수는 프로그램의 수행 종료 시 지속적 사용이 가능하다.

				```c++
				// 예시
				#include <iostream>
				using namespace std;
				
				int count = 100;	// 전역 변수
				int Func(void);
				
				int main(void)
				{
					Func();
					cout <<"main : count = "<<count<<endl;
					return 0;
				}
				
				int Func(void)
				{
					int number = 10;
					
					cout << "Func : number = " <<number<<endl;
					cout << "Func : count = " <<count<<endl;
					return 0;
				}
				
				// 지역 변수명과 전역 변수명이 동일하면 -> 지역 변수명이 처리 됨
				```
						
				- 정적변수 : 함수 내에서만 사용하는 정적(static) 변수

3. 연산자 종류

4. namespace

## 3. 프로그램의 흐름을 제어하는 선택문과 반복문


## 4. 배열과 포인터


## 5. 구조체와 공용체


## 6. C++에서의 함수 사용


## 7. 객체지향 프로그램의 기초, 클래스


## 8. 객체지향 프로그램의 도약, 상속


## 9. 객체지향 프로그램의 활용, 연산자 오버로딩


## 10. 템플릿 이해하기


## 11. 파일 입출력 및 예외처리
