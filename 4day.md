# 4. 함수와 배열

* 공부의 비급, 왕도, 최적화는 없다. 오직 시간을 갈아서 노력을 하여 많은 경험을 쌓아야 한다.
* 차근차근 나의 노력 + 경험을 통해 구현하는 것이 서서히 쌓여서 나중에 큰 자산으로 돌아온다.
* 결국에는 나의 의지와 노력을 통해 실력을 쌓을 수 있다는 것이다.
* 현직으로 들어가면, 개발보다 다른 사람들이 개발한 것들을 해석하는 경우가 95%이다. 해석을 꼼꼼하게 하여 실력을 쌓고, 클린 코드를 작성하도록 노력하여 가독성을 높이고, 후배들에게 본보기가 될 수 있도록 노력하자!

## 9장. C언어의 핵심! 함수
* 함수 = function, 모듈(복수)
* y = f(x) = ax + b
	- y = output variable, return value
	- x = input variable
* 함수 = 입력값 + 출력값 (유형이 다르다.)
---------------

* main 함수 다시 보기 : 함수의 기본 형태
	<pre><code>
	#include <stdio.h>
	
	int main(void)		// int : 반환의 형태(= 변수 선언과 동일)	-> 시작을 int main으로 시작하는 구나 생각하기
	{					// main : 함수의 이름
						// (void) : 입력의 형태 - void는 무엇인가? data type이 정의되지 않은 것을 의미 (미정의)
		함수의 몸체
						// { } : main 몸체의 시작과 끝
	}
	</code></pre>
	
* 함수를 정의하는 이유
	* 모듈화에 의한 프로그램의 질 향상이 가능
	* 유지 보수 및 확장의 용이성
	* 문제 해결의 용이성 : "Divided and Conquer!"
		* 모래알처럼 잘게 문제를 나눈 후에 굳혀서 문제를 해결하는 것이다.
	
* 4가지 형태의 함수
	* 전달 인자 O, 반환 값 O
	* 전달 인자 O, 반환 값 X
	* 전달 인자 X, 반환 값 O
	* 전달 인자 X, 반환 값 X
	
* 전달 인자와 반환 값, 둘 다 있는 함수
	```c
	int Add (int i, int j)		// 두 수를 입력 받아 그 합을 되돌려 줌
	{
		int result = i + j;
		return result;			// i + j값인 result 값을 반환하라.
	}
	```
* 함수 호출 과정의 이해
	```c
	#include <stdio.h>
	
	int Add(int i, int j)
	{
		int result = i + j;
		return result;
	}
	
	int main(void)
	{
		int d;
		d = Add(3, 4);
		printf("%d \n", d);
		return 0;
	}
	```
![image](https://user-images.githubusercontent.com/49339278/128442683-a9fa03fd-3a46-4ec4-9062-d8ec3044c85c.png)

* 다양한 형태의 함수
	```c
	void Result_Print(int val)		// void : 데이터 타입 미정의, 없다는 뜻! 단, 1가지 예외는 있다.
	{								// 입력된 인자를 받아서 설명문을 덧붙여서 출력하는 함수
		printf("덧셈에 대한 결과 : %d \n", val);
		printf("****** END ******** \n");
	}
	
	int Input(void)					// 빈 괄호 써도 된다. (기본형이 integer이므로 생략해도 integer라고 C언어는 인식됨.)
	{								// 하지만, C++이 개발되면서 문법이 엄격해져서, void는 물론이고, int라도 int로 표시해야 한다.
		int input;					// 단, 아무것도 입력하는 것이 없다면 생략해도 된다.
		scanf("%d", &input);
		return input;
	}
	
	void Intro(void)				// 리턴되는 값도 없고, 입력되는 값도 void라서 아무런 입력되는 값이 없다고 선언
	{
		printf("****** START ****** \n");
		printf("두개의 정수 입력 : ");
	}
	```
	
* 함수 선언의 필요성 : 컴파일러의 특성상, 함수는 호출되기 전에 정의되어야 한다.
* ![image](https://user-images.githubusercontent.com/49339278/128443552-d794db5a-be13-4d6a-9976-fdeba7cd7b0a.png)
	* 함수는 호출되기 전에 작성되어야 한다. 그래야 컴파일러가 좋아한다.
	* main 함수가 제일 마지막에 위치되어 있어야 한다.

* 함수 선언의 의미 : 이후에 정의될 함수에 대한 정보를 제공한다.
	* 보통 함수 작성할 때, 사용자 정의 함수 먼저, main 함수가 마지막이지만, 사용자가 만든 함수 선언을 먼저하게 되면 main 함수 뒤에 작성할 수 있다.
	* 귀찮지만, 복잡한 함수를 작성할 때 함수 선언이 많아져서 길어지는 경우가 많다. -> 본체는 별로 없지만, 함수 선언으로 인해 코드가 많아지는 경우가 있다.
		* 그럴 때, 함수 선언들을 모아 .h(헤더 파일) 파일로 모아서 #include로 정리 및 실행하면 편리하다. (이름은 내가 작성해도 가능)
	* ![image](https://user-images.githubusercontent.com/49339278/128443266-8a7996b9-7a45-4c4a-9653-fc032253ad6f.png)
		* Add 함수의 원형 선언을 Prototype이라고 한다. (= 함수의 head와 같다.) , 세미콜론을 표시하여야 한다.

* 실습 문제
	* 입력받은 KEY 값을 함수의 매개변수로 전달하고 함수 내에서 대/소문자/숫자/특수키 종류를 구분하여 출력하는 프로그램을 작성
	* main 함수에 sub 함수를 불러 쓸 것
	
	* 참고 : ASCII 코드 
		* ![image](https://user-images.githubusercontent.com/49339278/128447206-65ca1e10-8d06-4269-8ef3-ce120bc1c5d9.png)
		* NUL(NULL) - 0, LF - 10, CR - 13 꼭 외워두기
		* 0부터는 48 ~ 57(decimal)	/ 0x30 ~ 0x39 (hexadecimal)까지
		* A부터 Z까지는 65 ~ 90(decimal)	/ 0x40 ~ 0x4F (hexadecimal)까지
		* a부터 z까지는 97 ~ 122(decimal) / 0x61 ~ 0x7A (hexadecimal)까지
	
	
	```c
	#include <stdio.h>
	#include <conio.h>


	// Function Test 프로그램
	// 기능 : 키보드에서 단일 문자를 입력받고
	//	 해당 문자가 대문자0/소문자1/특수2/숫자키3 임을 분류 
	//-> 유형에 대한 특정한 값을 만들어서 값에 따라서 분류를 할 수 있도록
	//	----- 함수를 선언하고 호출할 것. -- 함수명 : sub

	/* 프로그램을 작성할 때, 누구한테 보여준다고 생각하고 클린하고 작성하고
	설명을 위해 가능한 많이 주석을 달아 놓자. 주석을 작성하지 않으면 잊어먹는 경우가 많기 때문에
	나중을 위해 친절하고 상세하게 작성해 두자*/

	int sub(char a);

	int main(void)
	{
		int i, j, k;
		char c;

		c = getch();		// sdl 검사 아니오 체크하기 (하나의 단일 문자를 돌려 받는 일종의 함수이다)

		// 숫자 키인지 아닌지 판별하는 구분 -> 구분하기 위해 ASCII 코드 확인해야 한다. (깃허브에 ASCII 코드 목록 첨부)
		if (sub(c) == 3)
		{
			printf(">입력하신 Key ['%c']는 숫자키 입니다.\n", c);		// 0 ~ 9번 키에 해당하는가?		
																	// 0 ~ 9 : 48 ~ 57 (decimal)
																	//-> 컴퓨터 : 0x30 ~ 0x39 (hexadecimal)로 인식
		}
		else if (sub(c) == 0)
		{
			printf(">입력하신 Key ['%c']는 대문자 키 입니다.\n", c);	// A ~ Z 키에 해당하는가?
																	// A ~ Z : 65 ~ 90 (decimal) 
																	//-> 컴퓨터 : 0x41 ~ 0x5A (hexadecimal)로 인식
		}
		else if (sub(c) == 1)
		{
			printf(">입력하신 Key ['%c']는 소문자키 입니다.\n", c);		// a ~ z 키에 해당하는가?
																	// a ~ z : 97 ~ 122 (decimal)
																	//-> 컴퓨터 : 0x61 ~ 0x7A (hexadecimal)로 인식
		}
		else
		{
			printf(">입력하신 Key ['%c']는 특수문자 키 입니다.\n", c);
		}
		
		/*
		
		// switch문 
		num = sub(c);
		switch (num)
		{
		case 0:  printf(">입력하신 Key ['%c']는 대문자입니다.\n", c);	break;
		case 1:  printf(">입력하신 Key ['%c']는 소문자입니다.\n", c);	break;
		case 2:  printf(">입력하신 Key ['%c']는 특수키입니다.\n", c);	break;
		case 3:  printf(">입력하신 Key ['%c']는 숫자입니다.\n", c);	 break;
		default: 	break;

		}
		
		*/
	}

	int sub(char a)		// 입력 값에 대한 키 분류 값 리턴
	{
		int ret;		// 분류 값

		if (a >= 0x30 && a <= 0x39) ret = 3;		// 숫자 키 : 3
													

		else if (a >= 0x41 && a <= 0x5A) ret = 0; 	// 대문자 키 : 0
		else if (a >= 0x61 && a <= 0x7A) ret = 1; 	// 소문자 키 : 1
		else ret = 2;					// 특수문자 키(기타 나머지) : 2

		return ret;
	}

	```
* 변수의 특성에 따른 분류
	* 지역 변수(Local Variable) : 중 괄호 내에 선언되는 변수
	* **전역 변수(Global Variable)** : 함수 외 선언되는 변수		-> 모두 static이라고 생각하면 된다.
	* 정적 변수(Static Variable) : 함수 내부, 외부 모두 선언 가능. 하지만 내부에는 사용하지 않는 것을 권장한다.
	* 레지스터 변수(Register Variable) : 선언에 제한이 많이 따름 (신경 쓸 필요가 없다. 안써도 된다.)
	
	* 중요한 변수는 처음 시작할 때 한꺼번에 선언하고(전역 변수), 그렇지 않은 것들은 지역 변수로 사용해야 한다.(지역 변수)
	
	* 잘 짜인 프로그램은 누가 봐도 알기 쉬운 코드를 작성하는 것이다.
	
* 지역 변수의 접근 범위
	* 지역 변수는 선언 된 함수 내에서만 접근 가능
	- ![image](https://user-images.githubusercontent.com/49339278/128459341-105a45cd-ff6d-497a-97ca-ce9cdb4a32db.png)

* 지역 변수의 메모리상 존재 기간
	```c
	int fct_one(void)
	{
		int one=10;
		return 0;
	}
	
	int fct_two(void)
	{
		int one=20;
		int two=30;
		return 0;
	}
	
	int main(void)
	{
		int val=10;
		fct_one();
		fct_two();
		return 0;
	}
	```
	
	- 1단계
		- ![image](https://user-images.githubusercontent.com/49339278/128459506-daf3407f-b68c-4283-bd92-22233cc7283c.png)

	- 2단계
		- ![image](https://user-images.githubusercontent.com/49339278/128459531-fb6e2534-f241-4c60-a3ca-34f20f66a10d.png)

	- 3단계
		- ![image](https://user-images.githubusercontent.com/49339278/128459560-fe2ebc61-a2f8-4ba8-99a5-685e2ab35f9b.png)

	- 4단계
		- ![image](https://user-images.githubusercontent.com/49339278/128459577-cbee8b7b-e62b-409e-ae00-a83a6999298f.png)

* 또 다른 형태의 지역 변수 : while, for, if와 같은 문장에 의해 형성되는 지역 내에서 선언되는 변수
	- ![image](https://user-images.githubusercontent.com/49339278/128463106-f6ff057b-5ed5-4fb4-a43d-0114b047b70d.png)

* 지역 변수의 또 다른 특성 : 경우에 따라서 지역 변수는 다른 지역 변수를 가리기도 한다.
	- ![image](https://user-images.githubusercontent.com/49339278/128463158-fad91caa-5e47-44ff-b2e3-55e1aa085dd5.png)
	- 가급적 쓰지 않는 것이 좋다.

* 지역변수와 매개변수 : 매개 변수도 지역 변수의 일종이다. (주의)
	- ![image](https://user-images.githubusercontent.com/49339278/128463201-727f0af0-09e2-49da-9ce4-7437dbd62897.png)

* 전역변수 : 변수 명에 주의해야 한다. 가능하면 복잡하고 길고 명확하게 써라. (i, j, k는 전역변수로 쓰지 않고 지역 변수로 써라.)
	- 프로그램 어디에서나 접근이 가능한 변수
	- 특정 영역(함수, 반복문, ...)에 속하지 않는다.
	- 프로그램이 종료될 때까지 존재
	- 같은 이름의 지역 변수에 의해서 가려지기도 한다.

* static 변수
	- 함수 내부 및 외부에 선언 가능하다.
	- 한번만 초기화된다. : 전역 변수의 특징
	- 함수 내부에서 선언될 경우 함수 내에서만 접근이 가능하다. : 지역 변수의 특징
	
* 보다 빠르게! register 변수 (넘어가기)
	```c
	int main(void)
	{
		int a;
		register int b; 	// 레지스터 변수 b선언
	}
	
	```
```c
// static_val.c
#include <stdio.h>

void fct(void);

int main(void)
{
	int i;
	for (i=0;i<5;i++)
		fct();
	
	return 0;
}

void fct(void)
{
	int val = 0;	// static int val=0;
	val++;
	printf("%d ", val);
}

```
	
	
* 재귀 함수의 기본적 이해 : 자기 자신을 다시 호출하는 
	```c
	/* recursive_basic.c */
	#include <stdio.h>
	
	void Recursive(void)
	{
		printf("Recursive Call! \n");
		// Recursive();
	}
	
	int main(void)
	{
		Recursive();
		return 0;
	}
	```
* 탈출 조건의 필요성 : 무한 재귀 호출을 피하기 위해서
* 탈출 조건의 이해
* 재귀 함수 Design 사례


	- 정리하기
	
## 10장. 1차원 배열
* 배열이란? -> 위와 같은 상황에서 사용한다.
	- 둘 이상의 동일한 Data type 변수를 동시에 선언하는 효과를 지닌다.
	- 많은 양의 데이터를 일관적으로 처리해야 하는 경우에 유용하다.
	- 지역적 특성을 지닐 수도 있고, 전역적 특성을 지닐 수도 있다.
	
* C : 하드웨어 제어하는 데 큰 장점이 있다.
	
* 배열 선언에 있어서 필요한 것 세 가지
* 1차원 배열의 접근
* 배열 선언과 접근의 예
* 선언과 동시에 초기화
* 문자열 상수
* 문자열 변수
* 문자열의 특징
* 널(null) 문자를 지녀야 하는 이유
* 문자열과 char형 배열의 차이점


## 11장. 다차원 배열
* 다차원 배열 : 2차원 이상의 배열을 의미
* 다차원 배열의 선언
* 2차원 배열의 선언
* 2차원 배열 요소의 접근 방법
* 다차원 배열의 실제 메모리 구성
* 2차원 배열! 선언과 동시에 초기화
* 초기화 리스트에 의한 배열 크기의 결정
* 3차원 배열의 선언과 의미

## 12장. 다차원 배열 그리고 포인터
* 1차원 배열 이름의 포인터 타입 결정 포인트!
* 1차원 배열 이름
* 다차원 배열의 포인터 타입 결정 포인트
* 2차원 배열 이름
