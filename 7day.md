# 05. 포인터
* 포인터 : 주소를 data값으로 하는 변수.

## 13강 포인터의 이해
* 포인터와 포인터 변수
  * 메모리의 주소 값을 저장하기 위한 변수
  * "포인터"를 흔히 "포인터 변수"라고 한다.
  * 주소 값과 포인터는 다른 것이다.
  * ![image](https://user-images.githubusercontent.com/49339278/128832978-ef6ddb34-e979-4385-89fa-364a32951c3f.png)


* 그림을 통한 포인터의 이해
  * 컴퓨터의 주소 체계에 따라 크기가 결정
    * 증감은 자료형 data 오차범위 ex) int형 -> -4 ~ +4
  * **32비트 시스템 기반 : 4바이트**
    * 즉, 포인터 = 4byte
  * ![image](https://user-images.githubusercontent.com/49339278/128833006-cc35322c-18ce-420f-818f-98ca443fed5f.png)


* 포인터 타입과 선언
  * 포인터 선언 시 사용되는 연산자 : ```*```
  * A형 포인터(```*A```) = A형 변수의 주소 값을 저장
  ```c
  int main(void)
  {
    int *a     // a라는 이름의 int형 포인터
    char *b;   // b라는 이름의 char형 포인터
    double *c; // c라는 이름의 double형 포인터
  ```

* 주소 관련 연산자
  * & 연산자 : 변수의 주소 값 반환
  * ```*```연산자 : 포인터가 가리키는 메모리 참조
  ```c
  int main(void)
  {
    int a = 2005;
    int *pA = &a;
    printf("%d", a);  // 직접 접근
    printf("%d", *pA); // 간접 접근
  
  ```
    * ![image](https://user-images.githubusercontent.com/49339278/128833587-fc4785d4-9764-44ba-98e3-5ed3b97360bf.png)

```c
// pointer1.c
#include <stdio.h>

int main(void)
{
  int a = 2005;
  int* pA = &a;  // &a : a 변수의 위치
  
  printf("pA : %d \n", pA);
  printf("&a : %d \n", &a);
  
  (*pA)++;   // a++와 같은 의미를 지닌다.
  
  printf("a   : %d \n", a);
  printf("*pA : %d \n", *pA);
  
  return 0;
}
```

* 포인터에 다양한 타입이 존재하는 이유 : 포인터 타입은 참조할 메모리의 크기 정보를 제공
```c
#include <stdio.h>

int main(void)
{
  int a = 10;
  int *pA = &a;
  double e = 3.14;
  double *pE = &e;
  
  printf("%d %f, *pA, *pE);
  return 0;
}
```

```c
// 오류1.c
#include <stdio.h>

int main(void)
{
  int *pA;  // pA는 쓰레기 값으로 초기화 됨 
  *pA = 10; // 입력하는 것 자체만으로 오류가 발생할 수도 있다.
  return 0;
}
```

```c
// 오류2.c
#include <stdio.h>

int main(void)
{
  int* pA = 100;  // 100이 어디에 있음? (정확한 값을 입력해야 한다.
  *pA = 10;
  return 0;
}

```

## 14. 포인터와 배열! 함께 이해하기
* 배열의 이름의 정체 : 배열 이름은 첫 번째 요소의 주소 값을 나타낸다.
* int a[5] = {0, 1, 2, 3, 4}
  * ![image](https://user-images.githubusercontent.com/49339278/128834336-76f02398-4d2e-4e66-9a91-866cb699ddb8.png)

```c
//pointer_array1.c
#include <stdio.h>

int main(void)
{
  int a[5] = {0, 1, 2, 3, 4};
  double *b = {1.1, 2.2, 3.3, 4.4, 5.5};
  
  printf("%d, %d \n", a[0], a[1]);
  printf("%d 번지, %d 번지 \n", &a[0], &a[1]);
  printf("%d 번지, %d 번지 \n", a, a+1);
  
  printf("배열 이름 : %d \n", a);
  
  return 0;
}
```

* 배열 이름과 포인터 비교
  | 비교 조건 \ 비교 대상 | 포인터 | 배열 이름 |
  |:-----:|:--------:|:----:|
  | 이름이 존재하는가 | 물론 있다.| 당연히 있다.|
  | 무엇을 나타내는가 | 메모리의 주소 | 메모리의 주소 |
  | 변수인가 상수인가 | 변수 | 상수 |
  
  ```c
  int main(void)
  {
   ```int a[5] = {0, 1, 2, 3, 4};```
   ```nt b = 10;```
   a = &b;  // a는 상수이므로 오류, a가 변수였다면 ok
  }
  ```
  
* 배열 이름의 타입
  * 배열 이름도 포인터이므로 타입이 존재!
  * 배열 이름이 가리키는 배열 요소에 의해 결정
    * int arr1[10] -> int*
    * double arr2[20] -> double*
    
* 배열 이름의 활용 : 배열 이름을 포인터처럼, 포인터를 배열 이름처럼 활용하는 것이 가능하다!
  ```c
  // pointer_array2.c
  #include <stdio.h>
  
  int main(void)
  {
    int arr[3] = {0, 1, 2};
    int *ptr;
    
    ptr = arr;
    
    printf("%d, %d, %d \n", ptr[0], ptr[1], ptr[2]);
    return 0;
  }
  ```
  ![image](https://user-images.githubusercontent.com/49339278/128836903-fcb4253e-bd63-43fb-a47c-dd70a6a15a2d.png)

* 포인터 연산 
  * 포인터가 지니는 값을 증가 혹은 감소시키는 연산을 의미한다.
  ```c
  ptr1++;
  ptr1 += 3;
  --ptr1;
  ptr2 = ptr1 + 2;
  ```
  
  * 포인터가 가리키는 대상의 자료형에 따라서 증가 및 감소되는 값이 차이를 지닌다.
  ```c
  // pointer_op.c
  #include <stdio.h>
  
  int main(void)
  {
    int* ptr1 = 0;        // int* ptr1 = NULL; 과 같은 문장
    char* ptr2 = 0;       // char* ptr2 = NULL; 과 같은 문장
    double* ptr3 = 0;     // double* ptr3 = NULL; 과 같은 문장
    
    printf("%d 번지, %d 번지, %d 번지 \n", ptr1++, ptr2++, ptr3++);
    printf("%d 번지, %d 번지, %d 번지 \n", ptr1, ptr2, ptr3);
    
    return 0;
  }
  ```
  
* 포인터 연산을 통한 배열 요소의 접근
  ```c
  // pointer_array3.c
  #include <stdio.h>
  
  int main(void)
  {
    int arr[5] = { 1, 2, 3, 4, 5};
    
    int *pArr = arr;
    printf("%d \n", *pArr);
    
    printf("%d \n", *(++pArr));
    printf("%d \n", *(++pArr));
    
    printf("%d \n", *(pArr+1));
    printf("%d \n", *(pArr+2));
    
    return 0;
  }
  ```
  
  ![image](https://user-images.githubusercontent.com/49339278/128837619-f25b359c-63f4-4a6f-832b-fa1046b0b8a7.png)

* 포인터와 배열을 통해서 얻을 수 있는 중대한 결론 : 기억하기 [] == ```*``` (단, arr이 포인터이거나 '배열 이름인 경우.]

* ```arr[i] == *(arr+i)```

```c
// two_same.c
#include <stdio.h>

int main(void)
{
  int arr[2] = {1, 2};
  int *pArr = arr;
  
  printf("%d, %d \n", arr[0], *(arr+1));
  printf("%d, %d \n", pArr[0], *(pArr+1));
  
  return 0;
}
```

* 문자열 표현 방식의 이해
  * 배열 기반의 문자열 변수 ```a[0] == *a == *(a+0)```
  * 포인터 기반의 문자열 상수
  ```c
  char str1[5] = "abcd";
  char *str2 = "ABCD";
  ```
  ![image](https://user-images.githubusercontent.com/49339278/128949506-c2c129a4-ccf3-412c-b8c7-4889806fd28c.png)

  ```c
  // str_prn.c
  #include <stdio.h>
  
  int main()
  {
    char str1[5] = "abcd";  // 문자열을 이용해서 배열을 초기화
    char *str2 = "ABCD";    // 포터 str2 선언하고 문자열의 "ABCD"의 주소로 초기화
    
    printf("%s \n", str1);
    printf("%s \n", str2);
    
    str1[0] = 'x';
    // str2[0] = 'x'; // error
    
    printf("%s \n", str1);
    printf("%s \n", str2);
    
    return 0;
  }
  ```
  
  | 비교 조건 | 비교 대상 | 
  |:-----:|:--------:|
  | 0005 | |
  | 0006 | abcd |
  | 0007 | |
  | 0008 | |    
  | 0009 | ABCD |
  | 0010 | |
  | 0011 | |
  | str1(0012) | a |
  | 0013 | b |
  | 0014 | c |
  | 0015 | d | 
  | 0016 | 0 |
  | str2(0017) | 0009|
  | 0018 | 0  |
  | 0019 | 0 |
  | 0020 | 0 |
  | 0021 | 0 |
  
* 포인터 배열 : 배열의 요소로 포인터를 지니는 배열 (2차원 배열과 마찬가지)
```c
int* arr1[10];   // int* : 배열 요소 자료형, arr1 : 배열 이름, [10] : 배열 길이
double* arr2[20];
char* arr3[30];
```
![image](https://user-images.githubusercontent.com/49339278/128835743-bf0341d8-e819-4aed-bd2a-ff8b444a0b72.png)

![image](https://user-images.githubusercontent.com/49339278/128835981-e58787f6-5cbe-4446-bc29-e4b255aaf963.png)

* C언어의 변수와 연산자의 keyword가 40여개뿐이라서 제약조건이 작아 유연성이 높다.

## 15장. 포인터와 함수에 대한 이해
* 기본적인 인자의 전달 방식
  * 값의 복사에 의한 전달 (Call-by-Value, 가장 일반적)
  * ![image](https://user-images.githubusercontent.com/49339278/128949727-c2504541-8353-45fc-9298-091cf1a92568.png)
  * ![image](https://user-images.githubusercontent.com/49339278/128963885-f5da9e4f-6ec8-4357-b1ba-9f95004b0209.png)
  * 스택(Stack) 영역을 통해서 인수를 전달하거나 결과를 전달하거나 다른 역할을 수행한다.

* 배열의 함수 인자 전달 방식
  * 배열 이름(배열 **주소, 포인터**)에 (참조 ; reference에) 의한 전달 (Call-by-Reference)
  * ![image](https://user-images.githubusercontent.com/49339278/128949753-04f09cfd-b0f1-49dd-b5b8-8c364afa8af5.png)

* 배열 이름, 포인터의 sizeof 연산
  * 배열 이름 : 배열 전체 크기를 바이트 단위로 반환
  * 포인터 : 포인터의 크기(4)를 바이트 단위로 반환
  ```c
  #include <stdio.h>
  
  int main(void)
  {
    int arr[5];
    int* pArr = arr;
    
    printf("%d \n", sizeof(arr) );  // 20 출력 (4 * 5)
    printf("%d \n", sizeof(pArr) ); // 4 출력
    return 0;
  }
  ```
  
* ```int *pArr vs int pArr[]```
  * 둘 다 같은 의미를 지닌다.
  * 선언 "int pArr[]"은 함수의 매개 변수 선언 시에만 사용 가능
  * ```*``` = 포인터 = 배열

```c
int function(int pArr[])
{
  int a = 10;
  pArr = &a;     // pArr이 다른 값을 지니게 되는 순간
  return *pArr;
}
```

* Call-By-Value
  * 값의 복사에 의한 함수의 호출
  * 가장 일반적인 함수 호출 형태
  ```c
  #include <stdio.h>
  
  int add(int a, int b);
  
  int main(void)
  {
    int val1=10;
    int val2=20;
    
    printf(" 결 과 : ", add(val1, val2));
    
    return 0;
  }
  
  int add(int a, int b)
  {
    return a+b;
  }
  ```
  
  * Call-By-Value에 의한 swap (결과 안나옴)
  ```c
  int main(void)
  {
    int val1 = 10, val2 = 20;
    swap(val1, val2);
    
    printf("val1: %d \n", val1);
    printf("val2: %d \n", val2);
    return 0;
    
  }
  
  void swap(int a, int b)
  {
    int temp = a;
    a = b;
    b = temp;
    
    printf("a : %d \n", a);
    printf("b : %d \n", b);
  }
  ```
  ![image](https://user-images.githubusercontent.com/49339278/128950206-883eecb7-ba0f-467e-838d-0f73be401d24.png)

* Call-By-Value와 Call-By-Reference
  * call-by-reference : 참조(참조를 가능케 하는 주소 값)을 인자로 전달하는 형태의 함수 호출
  * ![image](https://user-images.githubusercontent.com/49339278/128950268-93509cca-d478-45b3-9942-c2ec1f0bf6ec.png)
    * call-by-reference에 의한 swap
    ```c
    int main(void)
    {
      int val1 = 10; val2 = 20;
      printf("Before val1 : %d \n", val1);
      printf("Before val2 : %d \n", val2);
      swap(&val1, &val2);  // val1, val2 주소 전달
      
      printf("After val1 : %d \n", val1);
      printf("After val2 : %d \n", val2);
      return 0;
    }
    
    void swap(int* a, int* b)
    {
      int temp = *a;
      *a = *b;
      *b = temp;
    }
    ```
    ![image](https://user-images.githubusercontent.com/49339278/128950408-5b11c3c6-f356-417b-8d66-e97ae6a62675.png)


* scanf 함수 호출 시 &를 붙이는 이유 : 주소를 전달하기 위해서
  * scanf함수에서 keyboard에서 입력된 값을 원하는 형태대로 변환한 다음, 
  이 변수에 값을 써 넣어서 반환해라는 것
  * case 1
  ```c
  int main(void)
  {
    int val;
    int *p = &val;
    scanf("%d", &val);  // scanf("%d, p); -> & 붙이지 않아도 된다. p가 주소값이기 때문
  ```
  * 입력된 것이 배열이라고 했을 때, 배열명 자체가 주소이므로 &를 붙이지 않아도 된다.
  * case 2
    int main(void)
    {
      char str[100];
      printf("문자열 입력 : ");
      scanf("%s", str);

* 포인터가 가리키는 변수의 상수화 (const 즐겨 쓰지 말자.)
  ```c
  int a = 10;
  const int* p = &a;  // p를 상수로 선언 => 초기화 이후 변경이 불가
  *p = 30;   // error
  a = 30;    // ok
  ```
  ![image](https://user-images.githubusercontent.com/49339278/128950526-ed7fc912-5c9c-4103-b396-94b95b8ba3eb.png)

* 포인터 상수화
  ```c
  int a = 10;
  int b = 20;
  int *const p = &a;
  p = &b;    // Error
  *p = 30;   // ok
  ```
  ![image](https://user-images.githubusercontent.com/49339278/128950587-ccf689c0-2120-4682-948b-55a183d3a450.png)

* const 키워드를 사용하는 이유
  * 컴파일 시 잘못된 연산에 대한 에러 메시지
  * 프로그램을 안정적으로 구성
  ```c
  #include <stdio.h>
  float PI = 3.14;
  
  int main(void)
  {
    float rad;
    PI = 3.07;  // 분명히 실수!
    
    scanf("%f, &rad);
    printf("%원의 넓이는 %f \n", rad*rad*PI)'
    return 0;
  }
  ```
  
    ```c
  #include <stdio.h>
  const float PI = 3.14;
  
  int main(void)
  {
    float rad;
    PI = 3.07;  // Complier Error 발생
    
    scanf("%f, &rad);
    printf("%원의 넓이는 %f \n", rad*rad*PI)'
    return 0;
  }
  ```
  
* 문제 1
  * 키보드에서 5개의 정수를 입력받아서 그 중 가장 작은 수를 찾아서 출력하시오. 
  * (단, 배열과 함수를 이용해서 구성할 것. 함수는 배열을 매개변수로 받아서 그 중
  * 가장 작은 수를 되돌려 주는 함수이다.)

## 16장. 포인터의 포인터
* 포인터의 포인터
  * 더블 포인터라고 한다.
  * 싱글 포인터의 주소 값을 저장하는 용도의 포인터
  ```c
  int main(void)
  {
    double val = 3.14;
    double *ptr1 = &val;   // 싱글 포인터
    double **ptr2 = &ptr1; // 더블 포인터
  }
  ```
  ![image](https://user-images.githubusercontent.com/49339278/128966000-dd0c9c7e-3b73-4c7c-8bdd-2f26e1715d9b.png)
  ![image](https://user-images.githubusercontent.com/49339278/128966016-df0014d7-d2ea-4061-9170-09532da13944.png)

* 더블 포인터에 의한 Call-by-Reference
  - 다음 그림이 제시하는 프로그램의 구성을 통한 이해
    * ![image](https://user-images.githubusercontent.com/49339278/128971664-75f73827-268b-4cde-883c-9063cde533a8.png)

* 구현 사례 1 : 효과 없는 swap 함수의 호출
```c
// ptr_swap1.c
#include <stdio.h>

void pswap(int* p1, int* p2);

int main(void)
{
  int A = 10, B = 20;
  int *pA, *pB;
  pA = *pA, pB = *pB;
  
  pswap(pA, pB);
  
  // 함수 호출 후
  printf("pA가 가리키는 변수 : %d \n", *pA);
  printf("pB가 가리키는 변수 : %d \n", *pB);
  
  return 0;
}

void pswap(int *p1, int *p2)
{
  int *temp = p1;
  p1 = p2;
  p2 = temp;
}
```
![image](https://user-images.githubusercontent.com/49339278/128971891-3b83fde9-6a06-475d-adee-644ee57757c1.png)

* 구현 사례 2 : 더블 포인터 입장에서의 swap
```c
// ptr_swap2.c
#include <stdio.h>

void pswap(int **p1, int **p2);

int main(void)
{
  int A = 10, B = 20;
  int *pA, *pB;
  pA = &A, pB = &B;
  
  pswap(&pA, &pB);
  
  // 함수 호출 후
  printf("pA가 가리키는 변수 : %d \n", *pA);
  printf("pB가 가리키는 변수 : %d \n", *pB);
  
  return 0;
}

void pswap(int **p1, int **p2)
{
  int* temp;
  temp = *p1;
  *p1 = *p2;
  *p2 = temp;
}

```
![image](https://user-images.githubusercontent.com/49339278/128972094-16853669-0d53-4d29-91bb-2dd63dbb6eaa.png)

* 포인터 배열과 포인터 타입
  * 1차원 배열의 경우 배열이름이 가리키는 대상을 통해서 타입이 결정된다.
  * 포인터 배열이라고 하더라도 마찬가지이다.
  
  ```c
  int* arr1[10];
  double* arr2[20];
  char* arr3[30];
  ```
## 17. 함수 포인터와 void 포인터
* void 포인터 : type이 없는 포인터를 말한다.
* pointer : (함수, 상수, 변수의) 주소를 가리키는 변수

* 함수 포인터의 이해 (굳이 쓸 일은 없을 것이다.)
  ![image](https://user-images.githubusercontent.com/49339278/128966123-ab2229a2-68f4-47d4-a0b8-106ec14c2ad2.png)

* 함수 이름의 포인터 타입을 결정짓는 요소
  * SDK와 연결된다고 생각하기
  - 리턴 타입 + 매개 변수 타입
  ```c
  int fct1 (int a)
  {
    a++;
    return a;
  }
  
  // int (*fPtr1) (int);  // int : 선언
  // == fPtrl(10) = fct1;
  ```
  
  ```c
  double fct2(double a, double b)
  {
    double add = a+b;
    return add;
  }
  
  // double (*fPtr2) (double, double);
  
  ``` 
  
* void형 포인터란 무엇인가? (= 무소속 포인트. 사용할 때는 casting)
  * 원래 void는 정해지지 않은 데이터 타입어서 포인터를 사용할 수 없는데, void 포인터는 임시적인 용도로 사용된다. 실제로 사용할 때 casting(강제형변환)을 사용한다.
  * 자료형에 대한 정보가 제외된, 주소 정보를 담을 수 있는 형태의 변수
  * 포인터 연산과, 메모리 참조와 관련된 일에 활용할 수 없다.
  
  ```c
  // rightway.c
  int main(void)
  {
    char c = 'a';
    int n = 10;
    void* vp;  // void 포인터 선언
    vp = &c;
    vp = &n;
    ...

  ```
  
  ```c
  // wrongway.c
  
  int main(void)
  {
    int n = 10;
    void* vp = &n;
    *vp = 20;    // error
    vp++;        // error
  ```
  
  ```c
  // main_age.c
  #include <stdio.h>
  
  int main(int argc, char **argv)
  {
    int i = 0;
    printf("전달된 문자열의 수 : %d \n", argc);
    
    for (i=0;i<argc;i++)
      printf("%d번째 문자열 : %s \n", i+1, argv[i]);
      
    return 0;
  }
  ```
  
  * VoidTest 예제 
  * ![image](https://user-images.githubusercontent.com/49339278/128972864-db9d2d24-e5ae-46b0-9a96-cb991fd3e85e.png)

* Reference의 이해
* ![image](https://user-images.githubusercontent.com/49339278/128972885-b1d3ac73-af18-4a0c-836a-64de7ca73354.png)

* reference 관련 예제와 reference의 선언
* ![image](https://user-images.githubusercontent.com/49339278/128972960-193764d6-ae5f-43fd-b547-822d2f29d623.png)

* reference의 선언 가능 범위
* ![image](https://user-images.githubusercontent.com/49339278/128972994-d563ea0b-e6bd-4127-9011-cba345e896a1.png)

* 포인터 변수 대상의 reference 선언
* ![image](https://user-images.githubusercontent.com/49339278/128973061-1e01d3e7-e9a2-4a69-9d08-4dd8aefe6931.png)

* Call-by-value & Call-by-reference
* ![image](https://user-images.githubusercontent.com/49339278/128973086-f963cb7c-70ee-4d01-9c42-07fa8ce35ff1.png)

* Call-by-address? Call-by-reference!!
* ![image](https://user-images.githubusercontent.com/49339278/128973122-6bd5ab2f-ef64-4330-964e-dedbab5b84a9.png)

* reference를 이용한 Call-by-reference
* ![image](https://user-images.githubusercontent.com/49339278/128973174-c70e3c9d-f6a4-4414-bce7-519ea031d310.png)

* const reference
* ![image](https://user-images.githubusercontent.com/49339278/128973205-b1abf658-341f-4810-a46b-0f6ccf23524f.png)

* 반환형이 참조이고 반환도 참조로 받는 경우
* ![image](https://user-images.githubusercontent.com/49339278/128973237-8486f1b0-1591-416d-8381-4333adad5017.png)

* 반환형은 참조이되 반환은 변수로 받는 경우
* ![image](https://user-images.githubusercontent.com/49339278/128973397-300c2ff4-352f-4a03-97de-d58d773cbc4c.png)

* 참조를 대상으로 값을 반환하는 경우
* ![image](https://user-images.githubusercontent.com/49339278/128973467-9b86c692-c145-4349-a9fc-f3d6c2ccdaa8.png)

* 잘못된 참조의 반환
* ![image](https://user-images.githubusercontent.com/49339278/128973485-dce3fe94-0a6b-45ec-9259-0c3f797eadd0.png)

* const reference의 또 다른 특징
* ![image](https://user-images.githubusercontent.com/49339278/128973513-dc790989-5c7d-41b1-94c9-d4abfd953c14.png)

* reference의 상수 참조
* ![image](https://user-images.githubusercontent.com/49339278/128973535-cf07c1f5-52a1-49f4-ad78-e5bf431d5141.png)

# 6. 구조체(Struct*ure*)와 사용자 정의 자료형
* 구조체의 정의 : 하나 이상의 기본 자료형을 기반으로 사용자 정의 자료형을 만들 수 있는 문법 요소
```c
struct point  // point(점)라는 이름의 구조체 선언, struct : 키워드
{
  int x;   // 구조체 멤버 int x
  int y;   // 구조체 멤버 int y
}
```

* 구조체 변수의 선언
```c
struct point {    // data type
  int x;
  int y;
};

int main(void)
{
  struct point p1, p2, p3;
  ...
  return 0;
}
```
 * ![image](https://user-images.githubusercontent.com/49339278/128988195-2c38d23a-9206-4839-bce1-fc7c0028f0cb.png)

* 구조체 변수의 접근(access)
```c
struct point {
  int x;
  int y;
};

int main(void)
{
  struct point p1;
  p1.x = 10;      // p1의 멤버 x에 10을 대입
  p1.y = 20;      // p1의 멤버 y에 20을 대입
  ...
  return 0;
}
```

* 구조체 변수의 초기화
  * 배열 초기화 문법과 일치
  ```c
  struct person {
    char name[20];
    char phone[20];
    int age;
  };
  
  int main(void)
  {
    struct person p ={"Free Lec", "02-3142-6702", 20};
    ...
    return 0;
  }
  ```
  ![image](https://user-images.githubusercontent.com/49339278/128989363-f41ef931-ef30-4f7e-9d74-3f600d5c1ccf.png)

* 구조체 배열의 선언
```c
struct person {
  char name[20];
  char phone[20];
  int age;
};

int main(void)
{
  struct person pArray[10];
  ...
  return 0;
}
```
![image](https://user-images.githubusercontent.com/49339278/128990010-1e344ed5-69c6-470a-876b-978c76d38682.png)

* 구조체 배열 요소의 접근
  * 초기화 수준에서 값을 넣어주지 않는다면, strcpy()함수를 사용하여 배열 요소에 접근하여야 한다.
  * 즉, name = "홍길동"와 같이 값을 입력할 수 없다.
```c
pArray[1].age = 10;                   // 두 번째 요소의 age에 접근
strcpy(pArray[1].name, "홍길동");     // 두 번째 요소의 name에 접근
strcpy(pArray[1].phone, "333-3333");  // 두 번째 요소의 phone에 접근
```
![image](https://user-images.githubusercontent.com/49339278/128990439-6093411c-8c6a-4bb2-8a49-6e84daecdf52.png)

  * strcpy : #include <string.h>의 string-copy로, 문자열 복사 함수이다.
    * strcpy(char* dest, char* syc)
  * 저수준 함수 = Low Level Function -> C언어의 함수 대부분이 함수 내에서 모두 처리하는 저수준 함수이다.

* 구조체와 포인터
  * 모든 data type에 포인터가 적용이 될 수가 있다. 심지어 void까지도 적용이 가능하다. 심지어 function도 가능
  * 따라서, 구조체에도 포인터를 사용할 수 있다.
  1. 첫째 : 구조체 포인터를 선언하여 구조체 변수를 가리키는 경우
  2. 둘째 : 구조체의 멤버로 포인터 변수가 선언되는 경우

* 구조체와 배열 그리고 포인터 사용례
```c
struct person {
  char name[20];
  char phone[20];
};

int main()
{
  struct person man = {"Thomas", "354-00xx"};   // 초기화 과정
  struct person * pMan;
  pMan = &man;
  
  // 구조체 변수를 이용한 출력
  printf("name : %s\n", man.name);
  printf("phone : %s\n", man.phone);
  
  // 구조체 포인터를 이용한 출력1 : 
  printf("name : %s\n", (*pMan).name);
  printf("phone : %s\n", (*pMan).phone);
  
  // 구조체 포인터를 이용한 출력2 : ->
  printf("name : %s\n", pMan->name);
  printf("phone : %s\n", pMan->phone);
  return 0;
}
```

```c
// struct_example.c
// FILE
#include <stdio.h>

struct perInfo {
  char addr[30];
  char tel[20];
};

struct person {
  char name[20];
  char pID[20];
  struct perInfo* info;
};

int main()
{
  struct perInfo info = {"Korea Seoul", "333-4444");
  struct person man = {"Mr.Lee", "820204-xxxx512");
  
  man
}
```

* ppt 보고 정리하기

* 구조체의 byte 수 : 모른다. 그 안에 있는 멤머 종류와 바이트 수에 따라 다르게 설정된다.
  * ex)
  ```c
  struct person {
    char name[20];
    char pID[20];
    struct person* fmd;
  };   // 20 + 20 + 4 = 44 따라서 44byte이다.
  ```
* char : 1 / int : 4 / double : 8 / pointer : 4
