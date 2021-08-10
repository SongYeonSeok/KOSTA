## 11. 다차원 배열
* 2차원 배열 이상 : 인덱스가 2개 이상인 배열
* 1차원 : 인덱스가 1개인 배열
--------
* 점 -> 선(1차원 ; x) -> 면(2차원 ; x, y) -> 입체도형(3차원 ; 상자(x, y, z))
* 다차원 배열이란 무엇인가? : 2차원 이상의 배열을 의미함
  * 컴퓨터는 256차원까지 사용이 가능하다. 보통 3차원 정도까지만 이해해도 된다. 
  그리고 3차원을 사용하도록 애를 쓰지 않아도 된다.
  * 2차원 배열을 생각할 때, Excel를 생각하자.
  
* 다차원 배열의 선언 (인덱스가 몇개 들어가 있냐의 차이)
     | 배열 선언 예시 | 몇 차원 배열인가? |
     |:---------|:----------|
     |int arr[100] | 1차원 배열|
     |int arr[10][10]|10x10, 2차원 배열|
     |int arr[5][5][5]|5x5x5, 3차원 배열|

-----------
* 일정
  * 14(토) 휴일
  * 15(일) 휴일(광복절)
  * 16(월) 대체휴일
  * 17(화) 휴강(강사님 휴가)
-------------
* 2차원 배열의 선언 : 2차원적 메모리를 구성
  * ![image](https://user-images.githubusercontent.com/49339278/128656846-d5ee11dc-d463-48a9-a71c-e2c074f4b10b.png)


* 2차원 배열 요소의 접근 방법 
(어떠한 기준을 가지고 사고의 형태에 의해 배열을 맞추는 것이 협력에 큰 도움이 된다. 따라서 생각의 기준은 공통적이어야 한다.)
  * ![image](https://user-images.githubusercontent.com/49339278/128656974-0f2db7f4-896a-4644-8763-cf5ee60533ae.png)
  * 쓰레기 값이란? dummy data라고 하는데, 초기화가 되어 있지 않아서 
  프로그램에서 아무런 의미가 없는 미개척지라고 할 수 있다.
  
* 다차원 배열의 실제 메모리 구성
  * 1차원 배열과 동일하다.
  다만 접근 방법을 2차원적으로 해석할 뿐이다.
  * 2차원적으로 이해하는 것이 좋은 습관!
  ```c
  int a[2][3]   // 인덱싱 : Indexing (배열에 있는 요소를 찾아서 호출한다.-> 읽거나 쓸 수 있다.)
  
  /* a[0][0] : 4byte, 주소 : 0x1000 ~ 0x1003
     a[0][1] : 4byte, 주소 : 0x1004 ~ 0x1007
     a[0][2] : 4byte, 주소 : 0x1008 ~ 0x100b
     a[1][0] : 4byte, 주소 : 0x100c ~ 0x101f
     a[1][1] : 4byte, 주소 : 0x1010 ~ 0x1013
     a[1][2] : 4byte, 주소 : 0x1014 ~ 0x1017
     */
  ```
  ![image](https://user-images.githubusercontent.com/49339278/128657197-bc162a53-5972-42c5-ba57-42c2a2270026.png)
     |  | 0 | 1 | 2 |
     |:---------:|:----------:|:---------:|:----------:|
     | 0 | int a[0][0] | int a[0][1] | int a[0][2] |
     | 1 | int a[1][0] | int a[1][1] | int a[1][2] |
    * int : 4byte, i = 2, j = 3 -> 4x6 = 24 -> 메모리에 24byte를 지정, 인덱스 당 4개씩 나눈다.
  * 이미지를 잘 기억해 두자!

* 2차원 배열! 선언과 동시에 초기화 (머리에 구상한 대로 그대로 작성하는 것이 좋다.)
  * 단, 인덱스를 생략하는 것을 조심해야 한다. 
  (여러 단어마다 차이점이 있으므로 다른 언어를 학습할 때 차이점에 유의하자)
  * case 1 : 행 단위로 모든 요소들을 초기화
  * case 2 : 행 단위로 일부 요소들만 초기화
    * ![image](https://user-images.githubusercontent.com/49339278/128657761-e761a2fc-1f05-4556-b8ef-d0b6aeae43eb.png)
  * case 3 : 1차원 배열 형태의 초기화(유의하기)
    * ![image](https://user-images.githubusercontent.com/49339278/128657871-ef5a62a7-63d1-467d-8338-5cb7b4eb60d5.png)

* 초기화 리스트에 의한 배열 크기의 결정
  * 1차원 배열의 예
    * int arr[] = {1, 2, 3, 4, 5};
    
  * 2차원 배열의 예
    * int arr[][] = {1, 2, 3, 4, 5, 6, 7, 8};   // error (컴파일러 오류)
    * int arr[][4] = {1, 2, 3, 4, 5, 6, 7, 8};  // ok
    * int arr[][2] = {1, 2, 3, 4, 5, 6, 7, 8};  // ok

* 3차원 배열의 선언과 의미
  * 3차원적 메모리 구조를 의미함
  * 개념만 이해하면 충분! 일반적으로 필요 없다.
  * 4차원 이상의 배열은 4차원의 형태가 되므로 구조적인 이해가 불가하다. (형상화하기 힘듬)
  * ![image](https://user-images.githubusercontent.com/49339278/128658056-eb352c2d-afcc-4e68-8d90-41adbb431ce8.png)


# 12장. 다차원 배열 그리고 포인터
* 포인터 : 주소를 가리키는 변수
* C언어 = 포인터 -> 'c'언어 = everybody think difficult. but, easy

* ![image](https://user-images.githubusercontent.com/49339278/128658175-6466bfc1-6e16-4d35-9fc8-16aa85cb97d9.png)
*  ```c *(a+2) == arr1[2] ```
*  ```c * == [ ] ``` (포인터는 배열의 크기와 같다.)
*  ```c(int **a) : 이중 포인터
  * ```c *(*(a+1) + 2)) = arr2[1][2]```

* 예시... 한 호텔에서 30명의 단체 손님을 받아야 하는 상황. 그리고 방이 6개밖에 없는 상황이다.
  그러면 5명씩 한 방에 지정을 하면 된다. 그러면... 한 방의 이름, 즉 room number이 필요한데
  1층이니까 100호, 101호, 102호, 103호, 104호, 105호로 지정하자. 이것이 포인터다.(맞나??)
  
  * 보통, 노트북의 메모리는 8gb, 스마트폰 고급형 메모리는 16gb이다.
  * address의 길이는? 8gb이므로, 32bit(= 4GB, 16진수의 8자리로 표현됨.)
    * 8gb를 불러내기 위해서는? 33bit ->  16진수의 8자리로 표현되는데... 페이지가 달라진다. (이를 mapping이라 한다.) -> 이는 Linux Device에서 다룰 것임


| address | data|
|:---:|:---:|
|0001|00|
|0002|00|
|0003|00|
|0004|00|
|**0005**|**05**|
|**0006**|**00**|
|**0007**|**00**|
|**0008**|**0**0|
|*0009*|*0005*|
|0010|00|
|0011|00|
|0012|00|
|0013|00|
|0014|00|

* 0005 ~ 0008에 int age = 5로 지정하였다는 것이라면,
0009 ~ 0012는 int * age = 5 (0009 : 0005)
  
* 모든 데이터는 주소가 부여가 되어 있다. pointer라는 것은
  * ![image](https://user-images.githubusercontent.com/49339278/128663061-9240c91d-187f-4d39-9682-e1fc98732a70.png)

  * int age -> 4byte로, age가 어디 주소로 되어 있는가? age의 주소? ex) 0005에 저장되었으므로 주소는 0005이다. 이 age의 주소를 변수로 다룰 수 있다.
  * 0005를 가리키는 주소를 밝히는 변수를 포인터라고 한다.
  * 포인터도 변수이다. 변수의 한 종류. 단지, 포인터라는 변수가 타입이 가지고 있는 것은 다른 변수의 주소를 가지고 있다.
  * ![image](https://user-images.githubusercontent.com/49339278/128663408-0ad50765-5d85-4ad3-b0de-5ac51fac63c3.png)

* 1차원 배열 이름의 포인터 타입 결정 포인트
  * 포인터가 가리키는 **요소의 자료형** (포인트의 선언 : * add.age)
  * 포인터 연산 시 증가하는 바이트의 크기
    * +, ++, -, -- 가능, x, /, *, 
  * 배열은 변수와 달리 casting에 의해 데이터 손실이 발생하지 않는다. 다만 사용하는 주소값만 유지하게 되면 사실상 무관하게 된다. 
  * 저장장소를 기록하는 주소가 있다. 주소를 다루는 변수가 포인터 (공인중개사...)

* 1차원 배열 이름 -> 왜 포인터와 연결시키는가?
  * 배열 이름이 곧 포인터이기 때문!
  * 포인터와 배열을 혼용해도 무방할 정도
  * 배열 이름이 가리키는 요소의 자료형이 일치한다면, 
  포인터 연산 시 증가하는 값의 크기도 일치
  * 따라서 1차원 배열 이름의 경우 가리키는 요소만 참조

* 다차원 배열의 포인터 타입 결정 포인트
  * 포인터가 가리키는 요소의 자료형
  * 포인터 연산 시 증가하는 바이트의 크기

* 2차원 배열의 이름
  * 포인터가 가리키는 요소의 자료형이 같다고 해도 포인터 연산 시 증가하는 값의 크기는 불일치힌다.
  * 포인터 연산 결과도 생각해 봐야 한다.

* 2차원 배열 이름의 특성 이해 (1단계)
```c
// two_array1.c
#include <stdio.h>
int main(void)
{
  int a[3][2] = {1, 2, 3, 4, 5, 6};   // int a [y][x] (기억해두기) // 2차원 data
  
  printf("a[0] : %x \n", a[0]);  // 1차원 data, 참고 : a[0]은 a[0][] 
  printf("a[1] : %x \n", a[1]);
  printf("a[2] : %x \n", a[2]);
  printf("a    : %x \n", a);     // a는 큰 숫자가 나타날 것임.  // a의 이름 = a[0]의 이름
  
  return 0;
  
}
```
  * ![image](https://user-images.githubusercontent.com/49339278/128665735-53f3e13e-4b4f-496a-85f2-c9a2b2fe48bc.png)

  * ![image](https://user-images.githubusercontent.com/49339278/128667528-3f73fee9-cc64-4a93-b810-93a8bf40cdd9.png)


* 2차원 배열 이름의 특성 이해 (2단계)
```c
// two_array1.c
#include <stdio.h>
int main(void)
{
  int a[3][2] = {1, 2, 3, 4, 5, 6};   // int a [y][x] (기억해두기) // 2차원 data
  
  printf("a : %x \n", a);  // a의 주소 = a[0]의 주소
  printf("a+1 : %x \n", a+1); // a+1의 주소 = a[1]의 주소
  printf("a+2 : %x \n", a+2); // a+2의 주소 = a[2]의 주소 (표기하는 방식이 달라도 같은 값이 나온다.)
  
  return 0;
  
}  
```

* 2차원 배열 이름의 특성 이해
  * 결론 1
    * ![image](https://user-images.githubusercontent.com/49339278/128667812-2bef1c4b-b278-4c4e-97e1-81b04eb98b36.png)

  * 결론 2
    * 2차원 배열 이상의 포인터 타입 구성
      * 가리키는 대상의 자료형
      * 포인터 연산 시 증가하는 바이트의 크기
      * ![image](https://user-images.githubusercontent.com/49339278/128668883-0a46f941-6983-4092-9d40-f02cc0971ff6.png)


* 2차원 배열 이름에 일치하는 포인터 선언
```c
int arr[2][4];
int (*pArr)[4];   // int : int형 변수를 나타냄  
                  // pArr : 포인터
                  // 참고 : p_ : 포인터 변수
                  // n_ , m_ : 정수 변수
                  // f_ , d_ : 실수 변수
                  // c_ : 문자 변수
                  // s_ : 문자열 변수
                  // [4] : 4칸씩 건너뛴다.
                  // 결론 : 1. pArr 변수 선언. 2. pArr 배열 선언 3. 배열 요소는 포인터이다.
```

* 매개 변수로 선언되는 포인터의 또 다른 표현
  * ![image](https://user-images.githubusercontent.com/49339278/128668468-92e75f51-b52c-4265-a520-872349504793.png)
  * C 언어에서는 '배열 = 배열' 형태로 바로 대입해주는 기능은 없다. 그래서 포인터 형식으로 사용해야 한다.
    * C#, Java는 있다.
    * 문자열도 복사 명령을 통해 대입시킨다.

```c
int main(void)
{
  int arr1[2][4] = {1, 2, 3, 4, 5, 6, 7, 8};
  int (*ptr1)[4] = arr1;      // OK. (*ptr1 자체에 arr1의 첫번째 element를 가져다온다는 의미)
  int ptr2[][4] = arr1;       // ERROR.
}
```
* int(*pArr)[4]과 int *pArr[4]의 차이점
* ![image](https://user-images.githubusercontent.com/49339278/128668837-384253f1-6bb6-4f0e-9429-5c7342d1a8a8.png)

* 다양한 형태의 배열 요소 접근 방법
```c
// two_array2.c
#include <stdio.h>
int main(void)
{
  int a[3][2] = { {1, 2}, {3, 4}, {5, 6} };
  
  printf("a[0]  : %d \n", a[0]);
  printf("*(a+0): %d \n", *(a+0));
  
  printf("a[1]  : %d \n", a[1]);
  printf("*(a+1): %d \n", *(a+1));
  
  printf("a[2]  : %d \n", a[2]);
  printf("*(a+2): %d \n", *(a+2));
  
  printf("%d, %d \n", a[1][0], (*(a+1))[0]);
  printf("%d, %d \n", a[1][1], *(a[1]+2));
  printf("%d, %d \n", a[2][1], *(*(a+2)+1));
  
  return 0;
}
```

* 문제 1 : scanf 함수를 이용하여 문자열(영문, 숫자 포함)을 입력 후 해당 문자열을
한 글자씩 공백을 입력한 후, getch() 함수를 이용하여 숫자 0부터 9까지 키를 누르면 해당
위치의 문자를 출력하시오. 
  * 문자 배열을 사용하고, str[i] index를 사용하면 된다.
  * 전자의 부분은 포인터를 사용한다.

```c
//pointer_myway.c
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int CharToInt(int a)
{
	int ret;		// 분류 값
	ret = a - 0x30;

// switch (a)
//	{
//	case 0x30: ret = 0;
//	case 0x31: ret = 1;
//	case 0x32: ret = 2;
//	case 0x33: ret = 3;
//	case 0x34: ret = 4;
//	case 0x35: ret = 5;
//	case 0x36: ret = 6;
//	case 0x37: ret = 7;
//	case 0x38: ret = 8;
//	case 0x39: ret = 9;
//
//	}   /ctrl + k,c (블록 주석처리)

	return ret;
}

const int num = 100;		// 입력할 최대 글자 수
int pointer(void)
{
	int i, j, k;
	char str[num];
	char c;
	char paste[num * 2]; // 복사 배열

	printf("영문과 숫자를 포함하여 아무 글이나 작성하세요: ");
	scanf("%s", str);		// 배열은 &연산자 안하기

	for (i = 0; i < num; i++)
	{
		
		paste[2* i] = str[i];		// 포인터
		paste[2*i + 1] = ' ';		// "" : 문자열, '' : 문자
	} 


	while (1)
	{
		c = getch();
		if (CharToInt(c) >= 0 && CharToInt(c) <= 9)
		{
			printf("%c", paste[CharToInt(c)]);
			continue;
		}
		break;
	}
	//switch (CharToInt(c))
 //{
 //	case 0: printf("%c", paste[CharToInt(c)]); break;	// %c로 변환
	//	case 1:	printf("%c", paste[CharToInt(c)]);	break;
	//	case 2: printf("%c", paste[CharToInt(c)]); break;
	//	case 3: printf("%c", paste[CharToInt(c)]); break;
	//	case 4: printf("%c", paste[CharToInt(c)]); break;
	//	case 5: printf("%c", paste[CharToInt(c)]);	break;
	//	case 6: printf("%c", paste[CharToInt(c)]); break;
	//	case 7: printf("%c", paste[CharToInt(c)]);	break;
	//	case 8: printf("%c", paste[CharToInt(c)]);	break;
	//	case 9: printf("%c", paste[CharToInt(c)]);	break; 
	//}
	return 0;
}

int main()
{
	pointer();

}
```

```c
//pointer_teacheradvise.c
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

// 프로그래밍의 상당 부분은 '문자열 처리'이다!
// 문자열의 길이를 어떻게 아는가? 함수를 만들어 보자!

// function define (습관화 하기)
//		Prototype  :  int str_len(char *str)	// 포인터 (문자열의 포인터를 매개변수로 받는다.)
// 문자열 str을 받아서 해당 문자열의 길이를 되돌려 줌
// 전제 : 문자열 끝에는 null이 붙어 있다.
int str_len(char* str)		// 문자열 == 문자 배열
{
	int ret = 0;	
//	while (*(str + ret++)); return ret;
	
	while (1)
	{
		if (*(str + ret) != 0) ret++;	// str[ret], 전제를 이용한 방법
		else break;		
	}
	return ret;
}

int solution1()
{
	//문1) scanf 함수를 이용하여 문자열을 입력 후
	//     해당 문자열을 한 글자씩 공백을 삽입하여 출력하시오.
	//     > 12345 ==> 1_2_3_4_5
	// 
	//문2) scanf 함수를 이용하여 문자열을 입력한 후
	//     getch() 함수를 이용하여 숫자 키를 누르면
	//     해당 위치의 문자를 출력하시오.

	char buf[100];		// buffer : 버퍼 (임시 저장용, 배열, 포인터)
	int i, j, k;

	printf("문자열을 입력하세요: "); scanf("%s", buf);	// 배열은 &연산자 쓰는 것 아니다.
	printf("입력문자역 [%s] 의 길이는 %d 입니다. \n", buf, j = str_len(buf));		// 효율적

	for (i = 0; i < j; i++)		// for문 안에 함수를 넣을 수는 있지만, 바람직하지 않다. (복잡한 계산이 들어간 함수일 경우, 처리속도가 느려질 수 있다.)
	{
		printf("%c_", buf[i]);
	}



	while (1)
	{
		k = getch() - 0x30;	// 0 ~ 9 숫자키 (ASCII 0x30 ~ 0x39) 입력
		if (k >= 0 && k <= 9)
		{
			printf("%c", buf[k]);
			continue;		// 순환
		}
		break;
	}


	return 0;
}

int main()
{

	solution1();
}

```
