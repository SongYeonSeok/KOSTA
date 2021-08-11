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

* 포인터와 배열을 통해서 얻을 수 있는 중대한 결론 : 기억하기 [] == ```*```
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
  * 배열 기반의 문자열 변수
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
    char str1[5] = "abcd";
    char *str2 = "ABCD";
    
    printf("%s \n", str1);
    printf("%s \n", str2);
    
    str1[0] = 'x';
    // str2[0] = 'x'; // error
    
    printf("%s \n", str1);
    printf("%s \n", str2);
    
    return 0;
  }
  ```

* 포인터 배열 : 배열의 요소로 포인터를 지니는 배열
```c
int* arr1[10];   // int* : 배열 요소 자료형, arr1 : 배열 이름, [10] : 배열 길이
double* arr2[20];
char* arr3[30];
```
![image](https://user-images.githubusercontent.com/49339278/128835743-bf0341d8-e819-4aed-bd2a-ff8b444a0b72.png)

![image](https://user-images.githubusercontent.com/49339278/128835981-e58787f6-5cbe-4446-bc29-e4b255aaf963.png)


## 15장. 포인터와 함수에 대한 이해
* 기본적인 인자의 전달 방식
  * 값의 복사에 의한 전달
  * ![image](https://user-images.githubusercontent.com/49339278/128949727-c2504541-8353-45fc-9298-091cf1a92568.png)

* 배열의 함수 인자 전달 방식
  * 배열 이름(배열 주소, 포인터)에 의한 전달
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
    
    printf("%d \n", sizeof(arr) );  // 20 출력
    printf("%d \n", sizeof(pArr) ); // 4 출력
    return 0;
  }
  ```
  
* ```int *pArr vs int pArr[]```
  * 둘 다 같은 의미를 지닌다.
  * 선언 "int pArr[]"은 함수의 매개 변수 선언 시에만 사용 가능

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
  
  * Call-By-Value에 의한 swap
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


* scanf 함수 호출 시 &를 붙이는 이유
  * case 1
  ```c
  int main(void)
  {
    int val;
    scanf("%d", &val);
  ```
  * case 2
    int main(void)
    {
      char str[100];
      printf("문자열 입력 : ");
      scanf("%s", str);

* 포인터가 가리키는 변수의 상수화
  ```c
  int a = 10;
  const int* p = &a;
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

## 16장. 포인터의 
