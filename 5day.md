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
	* **전역 변수(Global Variable)** : 함수 외 선언되는 변수		-> 모두 static이라고 생각하면 된다. (중괄호 밖에 선언되는 변수, 가급적 사용. but, local 변수와 중복되지 않도록, 전역 변수의 일므이 식별이 용이한 가능한 길게 작성.)
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

* 지역변수와 매개변수(argument) : 매개 변수도 지역 변수의 일종이다. (주의)
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
	
	
* 재귀 함수의 기본적 이해 : 자기 자신을 다시 호출하는 형태의 함수 (= 팩토리얼과 비슷하다.)
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
  * ![image](https://user-images.githubusercontent.com/49339278/128629514-7367b167-789c-4258-8da0-432df9a18291.png)

```c
// recursive_basic2.c
#include <stdio.h>

void Recursive(int n)
{
  printf("Recursive Call! \n");
  if (n==1)
    return;
  Recursive(n-1);
}

int main(void)
{
  int a=2;
  Recursive(a);
  return 0;
}

```
* 재귀 함수 Design 사례
  * 팩토리얼(factorial) 계산을 위한 알고리즘
    *![image](https://user-images.githubusercontent.com/49339278/128629553-66c1664a-071d-4a4f-aac1-49703257a4c8.png)
 
  * 알고리즘을 코드로 옮기기 위한 pseudo code와 C 코드
  ```c
  /* 시작 조건 : n은 0 이상이다
  시작(Start) : f(n) 호출
    1. 만약에 n이 0이면 1을 반환
    2. 그렇지 않다면 n □ f(n-1)을 반환.
    끝
  */
  
  #include <stdio.h>
  int f(int n)
  {
    if (n==0)
      return 1;
    else
      return n*f(n-1);
  }
  ```

	
## 10장. 1차원 배열

* C : 하드웨어 제어하는 데 큰 장점이 있다. (= 배열을 공부할 때, Excel을 생각하면 편리하다.)
  | address | data |
  |:----:|:-----:|
  | 0001 | 01 |
  | 0002 | 02 |
  | 0003 | 03 |
  | 0004 | 04 |
  | 0005 | 05 |
  | 0006 | 06 |
  | 0007 | 07 | 
  | 0008 | 08 |
  | 0009 | 09 |
  | 0010 | 10 |
  | 0011 | 11 |
  | 0012 | 12 |
  | 0013 | 13 |
  | 0014 | 14 |
  
  * 포인터를 생각할 때 이 표 모양을  기억해두자. 그러면 이해하기가 쉬움
  * 포인터 : age와 같은 변수 X. 변수가 저장된 주소를 포인터가 접근할 수 있는 것 -> 하드웨어적으로 지식이 있으면 이해하기 쉽다.
  * 그래서 C 언어가 어렵다고 말하는 이유이다.

* 배열 이란? -> 위와 같은 상황에서 사용한다. 
	- 둘 이상의 동일한 Data type 변수를 동시에 선언하는 효과를 지닌다.
	- 많은 양의 데이터를 일관적으로 처리해야 하는 경우에 유용하다.
	- 지역적 특성을 지닐 수도 있고, 전역적 특성을 지닐 수도 있다.
	- 배열 = Pointer!, 혼용해도 될 정도로 밀접한 관계를 가지고 있다.

* 배열 선언에 있어서 필요한 것 세 가지 (변수(배열), 상수는 선언이 필요하다.)
	- 배열 길이 : 배열을 구성하는 변수의 개수 (반드시 상수를 사용)
	- 배열 요소 자료형 : 배열을 구성하는 변수의 자료형
	- 배열 이름 : 배열에 접근할 때 사용되는 이름
		- int array[10];	// 배열 선언문 (= 우리가 여행갈 때 숙소 유형과 숙소 이름, 숙소의 방 크기를 일일이 정하는 것과 같다)
			- int : 배열 요소 자료형
			- array : 배열 이름
			- [10] : 배열 길이 (반드시 상수로 지정! 만약에 변수를 쓰고 싶다면, const라는 키워드를 사용해서 작성하여 상수변수를 만들자.)
			
* 1차원 배열의 접근 (0호실과 0층이 존재한다.)
	- 배열 요소의 위치를 표현 : 인덱스(index)
	- **인덱스는 0에서부터 시작**	(0을 Zero Base라고 한다. 즉, 0층)	cf. R언어는 1부터 시작
		- **base + offset으로 인덱싱이 된다.**
		- ![image](https://user-images.githubusercontent.com/49339278/128467316-44b85e73-0115-4f78-8294-fcbf1f28f09b.png)

* 배열 선언과 접근의 예
	```c
	int main(void)
	{
		int array[10];	// 배열 선언 (선언 완료)
		
		array[0]=10;	// 첫 번째 요소 접근 (주의)
		array[1]=20;	// 두 번째 요소 접근 (주의)
		array[2]=30;	// 세 번째 요소 접근 (주의)
		...
		return 0;
	}
	```
	
	- array[s] = 10;	// S+1 번째 요소에 10을 대입하라. (배열과 반복문은 세트라고 할 수 있다.)
	
	```c
	// array1.c : 평균 구하는 문제
	#include <stdio.h>
	
	int main(void)
	{
		double total = 0;
		double val[5];
		int num = 5;	// 인원 수
		
		val[0]=1.01;
		val[1]=2.02;
		val[2]=3.03;
		val[3]=4.04;
		val[4]=5.05;
		
		for (i=0;i<num;i++)
		{
			total += val[i];
		}
		printf("평균 : %lf \n", total/num);
		
		return 0;
	}
	```

```c
// ArrayTest.c
#include <stdio.h>
#include <stdlib.h>   // standard library.h			
#include <math.h>     // 수학적인 계산이 필요할 때 사용
#include <conio.h>
#include <time.h>     // 랜덤 변수를 만들기 위해 사용
      
const int students = 20;    // global 변수
int main()
{
  int i, j, k;
  double average, total;    
  double kor[students], eng[students], mat[students];		// 배열의 선언
      /* C에서 배열의 개수를 선언할 때 반드시 변수가 아닌 상수를 지정해야 한다.
      하지만, 그럼에도 변수를 쓰고 싶다면 global 변수를 생성한 후, const를 써서 변수를 상수화 시켜야 한다.
      */
  
  // rand() : random 난수 함수다. 정확하게 진짜 난수가 아니다. 난수표에서 나온 난수들이다.
  // seed라는 것을 임의로 정해두자.
      
  srand(time(NULL));    // time이라는 변수가 정의되어 있지 않다.
                        // seed 지정 -> 이것으로 인해 디버깅할 때마다 다른 자료가 나온다.
      
  for (i = 0; i < students; i++)
  {
      kor[i] = (double) ((rand() % 1000) + 1) / 10;   // 난수 발생기 rand() : 정수 0 ~ 100.0 -> 0.1 ~ 100.0
                                                      // rand() : 정수, 나머지 계산도 전부 정수이다. 따라서 float형으로 변환
                                                      // float형으로 변환하기 위해서는 강제 형 변환(casting) 필요
      
      eng[i] = (double) ((rand() % 1000) + 1) / 10;   // 난수 발생기 rand() : int 0 ~ 100.0 -> 0~999 -> 1~1000 -> 0.1 ~ 100.0
      mat[i] = (double) ((rand() % 1000) + 1) / 10;	// 다음 숫자도 global const variable로 지정할 수도 있다. 따라서, 상수는 가급적 쓰지 않고 변수를 쓰도록 하자.
      
      
  }    
      
  // 국어 성적, 영어 성적, 수학 성적 출력하기
  /*
  for (j=0; j < students; j++)    
  {
    printf("%7.1f\n", kor[k]);
    total += kor[k];
  }
  average = total / students;
  */    
     

	printf("A학교 B반 국어 점수 현황\n========================\n\n개인점수 리스트:\n");

	for (total = 0,	k = 0; k < students; k++)		// total = 0, k = 0 부분은 초기값 부분이다. (스킬 높일 때 씀)
	{
		printf("%7.1f\n", kor[k]);					// 실수 출력의 전체 자리수를 7자리, 소수점 이하 1자리
		total += kor[k];
	}
	average = total / students;

	printf("총점 : %7.1f점\n", total);
	printf("평균 : %7.1f점\n", average);
	

	printf("\nA학교 B반 영어 점수 현황\n========================\n\n개인점수 리스트:\n");

	for (total = 0, k = 0; k < students; k++)		// total = 0, k = 0 부분은 초기값 부분이다. (스킬 높일 때 씀)
	{
		printf("%7.1f\n", eng[k]);					// 실수 출력의 전체 자리수를 7자리, 소수점 이하 1자리
		total += eng[k];
	}
	average = total / students;

	printf("총점 : %7.1f점\n", total);
	printf("평균 : %7.1f점\n", average);

	printf("\nA학교 B반 수학 점수 현황\n========================\n\n개인점수 리스트:\n");

	for (total = 0, k = 0; k < students; k++)		// total = 0, k = 0 부분은 초기값 부분이다. (스킬 높일 때 씀)
	{
		printf("%7.1f\n", mat[k]);					// 실수 출력의 전체 자리수를 7자리, 소수점 이하 1자리
		total += mat[k];
	}
	average = total / students;

	printf("총점 : %7.1f점\n", total);
	printf("평균 : %7.1f점\n", average);      
      
}      
                        
      
```      

* 선언과 동시에 초기화
	```c
	int main(void)
	{						// 상황극 : 단체로 숙소를 잡을 때,
		int arr1[5] = {1, 2, 3, 4, 5};		// 예1 : 5명이 왔으니, 방 5개 주세요.
		int arr2[] = {1, 3, 5, 7, 9};		// 예2 ; 5명이 왔으니 눈치껏 방 잡아주세요.
							// (멤버수에 따라 방 잡아줌) 
		int arr3[5] = {1, 2};			// 예3 : 2명이 왔으니 방 5개 주세요. 
							// 이 경우는 {1, 2, 0, 0, 0}으로 입력됨
	}
	```
	
	- ![image](https://user-images.githubusercontent.com/49339278/128467891-88b92f1f-0c3a-4f95-9bfa-9430881780c5.png)
	- ![image](https://user-images.githubusercontent.com/49339278/128467948-604ba6e6-c12f-481a-8863-57287ed96572.png)
	- ![image](https://user-images.githubusercontent.com/49339278/128467961-e64060e5-6539-4725-9e8b-cb7d5ca84192.png)

	
* 문자열 상수
	- 문자열이면서 상수의 특징을 지닌다. '상수처럼 변하는 것이 아니다'로 인식하게 된다.
	```c
	printf("Hello World!"\n");
	```
	
* 문자열 변수
	- 문자열이면서 변수의 특징을 지닌다.
	- 문자열은 꼭 null(\0)로 끝난다.
	```c
	char str1[5] = "Good";		// Good\0; G : 코드값, \0(null) 문자를 담을 마지막 공간이 필요!
	char str2[] = "morning";	// morning\0 ; m : 코드값
	```
	
	```c
	// ar_str.c
	
	#include <stdio.h>
	
	int main(void)
	{
	  char str1[5] = "Good";
	  char str2[] = "morning";
	  
	  printf("%s \n", str1);
	  printf("%s %s \n", str1, str2);
	  
	  return 0;
	}
	
	/* 결과
	Good
	Good Morning
	*/
	```

* 문자열은 char(문자형 데이터) 배열이다. 

* 문자열의 특징
  * 문자열은 널(null)문자를 끝에 지닌다.
  * 널(null) 문자 : '\0'(ASCII code : 0)
      - ![image](https://user-images.githubusercontent.com/49339278/128629649-d7c47581-cfea-433c-8d13-6c082710dc4e.png)

* 문자열과 문자 배열의 차이점
  * 문자열은 상수이지만, 문자 배열은 아니다.
    * char str[6] = "Hello";  // str[6] : 문자 배열(변수), "Hello" : 문자열(상수)
      * str[0] = H, str[1] = e, str[2] = l, str[3] = l, str[4] = o, str[5] = \n(null) 저장
    
  
* 널(null) 문자를 지녀야 하는 이유
  - 문자열의 끝을 표현하기 위해서
  - 쓰레기 값과 실제 문자열의 경계를 나타내기 위해
  - printf 함수는 널 문자를 통해서 출력의 범위를 결정짓는다.
    ```c
    int main(void)
    {
      char str[100]="Hello World!";
      printf("%s \n", str);
      
    ```
* 문자열과 char형 배열의 차이점
  * 문자열은 상수로, 무조건 null이 붙어야 되는데, char형 배열은 그러한 문자열을 갖기 위한 배열로, null을 붙여도 되고 붙이지 않아도 된다.
  ```c
  char arr1[] = "abc";	// 배열의 크기가 4 (null 포함)
  char arr2[] = {'a', 'b', 'c'}; // 배열의 크기가 3
  char arr3[] = {'a', 'b', 'c', '\0'};    // 배열의 크기가 4
      
  ```    
  
```c
// va_str.c
#include <stdio.h>
      
int main(void)
{
  int i;
  char ch;
  char str[6] = "Hello";
      
  printf("--변경 전 문자열--\n");
  printf("%s \n", str);		// Hello 출력
      
  for(i=0; i<6; i++) 
    printf("%c | ", str[i]);  // str[i] 출력
      
  // 문자열 변경 (글자 앞뒤 순서 바꾸기)
  for(i=0; i<3; i++)
  {
    ch = str[4-i];
    str[4-i] = str[i];
    str[i] = ch;      
  }      
      
  printf("\n\n--변경 후 문자열--\n");
  printf("%s \n", str);
  return 0;      
}     
```


- scanf 함수를 이용하여 문자열을 입력받아 한 문자씩 띄어서 출력하시오.
  * char 배열을 이용할 것 "abcde" -> "a b c d e"
- 대소문자가 혼합된 입력받은 문자열을 모두 대문자로 일괄 변환하기
      

```c
char str[100];
scanf("%s", str);
for(int i=0;i<100;i++)
{
	char a;
	a = str[i]
	if (str[i] == 0) break;
	if (a > 96 && a < 123) a -= 32; 	// a가 소문자이면
	printf("%c", a);
}
```
