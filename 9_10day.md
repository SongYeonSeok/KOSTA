# 7강. C 표준함수
* string(문자열, char*) 처리
* 호환성이 높아서 임의의 플랫폼에서도 사용이 가능하다.
  * 그 이유는 OS마다 제공하는 컴파일러가 다르기 때문에, 호환성 여부를 확인해 보아야 한다. 
  * C언어는 이식성이 굉장히 높아서, 따로 손을 쓰지 않아도 사용 기능하다.

## 24. 문자와 문자열 처리 함수

* 입출력의 이해
  * 파일, 콘솔, 소켓 입출력
    * 파일이 입력과 출력의 원형이다.
    * 콘솔은 특수 파일이라고 이해하면 된다. 실제로 특수 파일이다.
* 스트림에 대한 이해
  * 데이터를 송수신 하기 위한 일종의 다리 (데이터의 흐름이라고 생각하면 편하다)
  * ![image](https://user-images.githubusercontent.com/49339278/129317904-f42b2fbd-adbb-47ca-a430-8b59fff90b48.png)

* 표준 입출력 스트림 = File의 개념
  * 프로그램 실행 시 자동으로 생성 및 소멸
  * 모니터와 키보드를 그 대상으로 함
  * 이것들은 특수한 type이다.
  
  | 이름 | 스트림의 종류 | 입출력 장치 |
  |:----:|:----:|:----:|
  | stdin | 표준 입력 스트림 | 키보드 |
  | stdout | 표준 출력 스트림 | 모니터 |
  | stderr | 표준 에러 스트림 | 모니터 |

* 문자 출력 함수
```c
#include <stdio.h>

int putchar(int c);
int fputc(int c, FILE* stream);     // fprintf (앞의 f = file) 사용하면 된다.
// 에러가 발생하는 경우 EOF 리턴
```
  * sprintf도 있다. 이것은 string buf로, 메모리 공간에 출력한다는 뜻이다.

* 문자 입력 함수
```c
#include <stdio.h>

int getchar(void)
int fgetc(FILE* stream);            // fscanf (앞의 f = file) 사용하면 된다.
// 에러가 발생하거나 파일의 끝에 도달하는 경우 EOF 리턴
```

* scanf : program down 가능성이 높아서 scanf를 주의 깊게 설계해야 한다. 사용자가 무엇을 입력할 지 모르기 때문에 가급적 사용하지 말아라고 권장하는 것임. 그리고 white space를 인식하지 못한다.

* EOF에 대한 이해
  * file을 읽을 때, 끝에 도달했다는 read 함수의 **return 값**이다.
  * fgetc, getchar 함수가 파일의 끝에 도달하는 경우 반환
  * End-Of-File의 약자로서, 파일의 끝을 표현하기 위한 상수
  (-1의 값을 지닌다.)
    * 꼭 그렇지는 않다.
  * 콘솔의 경우 Ctrl-Z가 파일의 EOF를 의미
    * 그 의미는 

* 문자 단위 입출력 함수의 필요성
  * 용도에 맞는 적절한 함수를 제공함으로써 성능 향상을 도모

```c
// char_IO.c
#include <stdio.h>

int main()
{
  char ch = 0;
  
  while(ch != 'q')
  {
    ch = getchar();
    putchar(ch);
  }
  
  return 0;
}
```

```c
// Ctrl_Z.c
#include <stdio.h>

int main()
{
  char ch = 0;
  
  while(ch != EOF)
  {
    ch = getchar();
    putchar(ch);
  }
  printf("program 종료 \n");
  
  return 0;

```

* 문자열 출력 함수
```c
#include <stdio.h>

int puts (const char* s);
int fputs(const char* s, FILE* stream);  // FILE : 새로운 data type
```

* 문자열 입력 함수
```c
#include <stdio.h>

char* gets(char* s);
char* fgets(char* s, int n, FILE* stream);
```

```c
// puts_fputs.c
#include <stdio.h>

int main()
{
  fputs("fputs 함수에 의한 출력, ", stdout);
  fputs("I Love Linux ", stdout);
  
  fputs("\n", stdout);  // 한 줄 건너뛰기 위해서
  puts("puts 함수에 의한 출력,");
  puts("I Love Linux ");
  
  return 0;
}

```

```c
// fputs.c
#include <stdio.h>

int main()
{
  char str[10];
  
  fputs("문자열을 입력 하세요 : ", stdout);
  fgets(str, sizeof(str), stdin);
  
  fputs("입력된 문자열 : ", stdout);
  fputs(str, stdout);
  
  return 0;
}

```

* cmd -> echo "내용" > "파일이름" -> 파일 생성
* cmd -> dir : 디렉토리 확인
* cmd -> dir 파일명* : 디렉토리에서 '파일명' 글자가 있는 모든 파일을 보여준다.
* cmd -> type 파일명 : 내용물 출력(파일명에 경로를 같이 붙이면 어느 디렉토리이든지 출력이 가능)
* cmd -> cd .. : 상위 디렉토리로 바꾸라는 의미
* cmd -> . : current

* 입출력 사이에 존재하는 버퍼의 이해
  * 여분의 임시 메모리적 특징을 지닌다.
  * 성능 향상이 목적이다.
  * 모아서 보내고... 모아서 받고...
![image](https://user-images.githubusercontent.com/49339278/129839871-922b7c63-e343-4e89-9f8c-fc37ccbf085e.png)

* 버퍼를 비우는 작업을 하는 fflush 함수
```c
#include <stdio.h>

int fflush(FILE * stream);

// 성공 시 0, 실패 시 EOR 리턴
```![image](https://user-images.githubusercontent.com/49339278/129839964-0c566312-751f-4a48-a659-6af7a5ce0423.png)

```c
// fflush.c
#include <stdio.h>

int main(void)
{
  char perID[7];  // 6 + null 문자 = 7
  char name[10];
  
  fputs("주민번호 앞 6자리 입력하세요 : ", stdout);
  fgets(perID, sizeof(perID), stdin);
  
  fflush(stdin); // 입력 버퍼를 비운다.
  
  fpust("이름을 입력하세요 : ", stdout);
  fgets(name, sizeof(name), stdin);
  
  printf("주민번호 앞자리 : %s\n", perID);
  printf("이           름 : %s\n", name);
  
  return 0;
}
```

* 문자열의 길이를 반환하는 strlen 함수
  ```c
  #include <stdio.h>
  
  size_t strlen(const char* s)
  // 성공 시 0, 실패 시 EOF 리턴
  ```

* string != datatype -> 대입 연산자, 연산자, 비교연산자 등을 사용할 수 있도록 함

* 문자열을 복사하는 함수
  ```c
  #include <string.h>
  
  char* strcpy(char* dest, const char* src);
  char* strncpy(char* dest, const char* stc, size_t n);
  // 리턴 시 복사된 문자열의 포인터 리턴
  ```
* 복사 참조
```c
// strlen.c
#include <stdio.h>
#include <string.h>

int main(void)
{
  char str[100];
  
  while(1)
  {
    fgets(str, sizeof(str), stdin);
    printf("문자열의 길이 : %d \n", strlen(str));
  }
  
  return 0;
}

```

* 문자열을 추가(결합)하는 함수 (문자열의 연산자를 수행한다.)
```c
#include <string.h>

char* strcat(char* dest, const char* src);
char* strncat(char* dest, const char* src, size_t n);
// 리턴 시 추가된 문자열의 포인터 리턴
```
![image](https://user-images.githubusercontent.com/49339278/129840457-53c64b7f-1e43-40f5-a22e-429ff69c3187.png)

* 문자열(널 포함 0)은 대입 연산자를 사용할 수 없다. 그래서 strcpy 사용
  * strcpy는 크기에 제한이 없다. 하지만 오류가 발생할 수 있으므로, strncpy 함수를 사용하기도 한다.
  * strncpy의 n : 복사할 문자 수
  * size_t는? 변수의 type으로, long이라고 생각하면 된다.
  * strcpy는 '\0'까지 복사된다.
  * strncpy는 '\0'이 복사가 되지 않는다.
```c
//예시
				char *a = "Good morning";
				char buf[10];
				
				strncpy(buf, a, 4);  // null 없음
				buf[4] = 0;  // null (반드시 필요한 과정)
				printf("%s", buf);  // Good??
```

```c
// strcat.c
#include <stdio.h>
#include <string.h>

int main(void)
{
  char str1[30] = "Your favorite language is "; // null 문자 포함 27문자
  char str2[10];
  
  fputs("What is your favorite computer language ? : ", stdout);
  fgets(str2, sizeof(str2), stdin);
  
  strcat(str1, str2);
  printf("생성된 문자열 : %s \n", str1);
  return 0;
}
```

* 문자열을 비교하는 함수 (조건문에서 많이 사용할 수 있다.)
```c
#include <string.h>
int strcmp(const char* s1, const char* s2);   // cmp == compare
int strncmp(const char* s1, const char* s2, size_t n);
// 리턴 시 추가된 문자열의 포인터 리턴
```

| 리턴 값 | 의미 |
|:-----:|:----|
| 0보다 큰 값(양수) | str1이 str2 보다 큰 경우 |
| 0 | str1과 str2가 완전히 같은 경우 |
| 0보다 작은 값(음수) | str1이 str2 보다 작은 경우 |

```c
// strcamp.c
#include <stdio.h>
#include <string.h>

char* str1 = "ABC";
char* str2 = "ABD";

int main(void)
{
  int result;
  result = strcmp(str1, str2);
  
  if(result > 0)       puts("str1이 str2보다 큽니다.");
  else if (result <0)  puts("str2이 str1보다 큽니다.");
  else                 puts("두 문자열이 정확히 같습니다.");
  
  return 0;
}
```

* 문자열을 숫자로 변환하는 함수들
```c
#include <stdlib.h>

int atoi(char* ptr); // 문자형을 int형 데이터로 변환, a to i로 읽기(ascii to integer)
long atol(char* ptr); // 문자열을 long형 데이터로 변환, a to l로 읽기(ascii to long)
double atof(char* str);  // 문자열을 double형 데이터로 변환, a to f로 읽기(ascii to float)
                         // return 값은 double형이다.
``` 
  * 데이터 파싱 작업에서 많이 사용한다. 특히 데이터베이스에서 데이터를 가져오는 작업에서 빈번하게 사용된다.

* 대소문자의 변환을 처리하는 함수들
```c
#include <ctypes.h>

int toupper(int c);  // 소문자를 대문자로 (to upper)
int tolower(int c);  // 대문자를 소문자로 (to lower)
```

## 25. 파일 입, 출력
* 파일의 OPEN
  * 데이터를 주고 받을 수 잇는 스트림의 생성
  * filename에 full path를 작성해야 한다. 그렇지 않으면 작업하고 있는 디렉토리에 파일이 있지 않는 경우에 null 포인터를 리턴하게 된다. 생략하면 current directory에 있는 파일만 생성 가능하다.
  ```c
  #include <stdio.h>
  FILE* fopen(const char* filename, const char* mode)
  /*
  성공 시 해당 파일의 파일 포인터, 실패 시 NULL 포인터 리턴
  */
  ```

* 파일 OPEN mode
  * 파일 접근 모드 + 데이터 입출력 모드

  * 파일 접근 모드
    * 개방한 파일의 사용 용도 확인
    * r, w, a, r+, w+, a+
      * r : read, w : overwrite, a : append(추가 - 기존의 파일 없으면 새로 만들어 기록해 나감.)
      * r+ :  w+, a+ 는 텍스트 모드나 2진 모드와 같은 데이터 입출력 모드를 덧붙이기 위해서이다.
        * 하지만 a+t는 a와 같아서 의미가 없다.
        * 보통 a+b를 선호한다. 그 이유는 바이트 단위로 적용해서 쓸 수 있다. 단, a+b로 쓴다면, \r\n을 같이 붙여 줘서 출력문으로 만들어 주어야 우리가 보는 일반적인 출력문으로 볼 수 있다.

    * 로그 파일 : 운영 체제나 다른 소프트웨어가 실행 중에 발생하는 이벤트나 각기 다른 사용자의 통신 소프트웨어 간의 메시지를 기록한 파일

  * 데이터 입, 출력 모드

    | 모드 | 의미 |
    |:---:|:-----|
    | t | 텍스트 모드(text mode), CRLF, 기본값 |
    | b | 2진 모드(binary mode), 옵션 |

* CR & LF : 개행문자, white space
  * CR(Carriage Return)은 특수문자 '\r'로 표시
  * LF(Line Feed ; 줄바꿈 문자)는 특수문자 '\n'로 표시

![image](https://user-images.githubusercontent.com/49339278/129866858-178d02f7-6e88-4591-80bc-37cbd079338f.png)


* 텍스트 모드와 2진 모드의 차이점
![image](https://user-images.githubusercontent.com/49339278/129867047-b296b7ca-8dd1-483c-8867-8710a2dbf80b.png)


* 파일 개방 모드의 완성
![image](https://user-images.githubusercontent.com/49339278/129867107-876abd6d-07dc-43f4-b2fb-87b3a5edf8a6.png)


* FILE 구조체의 포인터 (stdio.h 파일에 있다.)
  * fopen 함수의 리턴 타입 (int, double 형이 아닌 FILE 구조체를 써야 한다!)
  * 흔히 파일 포인터라고 불린다.
  * 개방한 파일에 대한 여러 가지 정보를 지니는 변수를 가리키는 포인터

* FILE 구조체 포인터의 용도
  * 데이터 입출력 함수의 호출
  * 위치 정보의 참조
  * 파일의 끝 확인
 
* 파일의 종결(CLOSE)
  * 스트림의 종결을 의미함. 프로그램이 끝날 때 종결하는 것이 원칙이다. 즉, 다 썼으면 닫으라는 것.
  ```c
  #include <stdio.h>
  int fclose(FILE * stream)
  // 종료가 오류 없이 제대로 이뤄지면 0을 리턴
  ```
  
  * console도 특수파일이기 때문에, 파일 함수를 사용할 수 있다.
  * 키보드/모니터는 특수 file이다. 그리고 ```FILE *stream``` 대신에 stdin / stdout를 쓰게 되면 콘솔 입출력이 된다.
  | 기능 \ 스트림 | 키보드/모니터 | 선택(키보드/모니터, 파일) |
  |:-----:|:------|:------|
  | 문자 출력 | ```int putchar(int c)``` | ```int fputc(int c, FILE* stream)``` |
  | 문자 입력 | ```int getchar(void)``` | ```int fgetc(FILE* stream)``` |
  | 문자열 출력 | ```int puts(const char* s)``` | ```int fputs(const char* s, FILE* stream)``` |
  | 문자열 입력 | ```char* gets(char* s)``` | ```char* fgets(char* s, int n, FILE* stream)``` |
  | 형식 지정 출력 | ```int printf(const* format, ...)``` | ```int fprintf(FILE* stream, const char* format, ...)```|
  | 형식 지정 출력 | ```int scanf(const char* format, ...)```|```int fscanf(FILE* stream, const char* format, ...)```|

* 파일 위치 지시자 (Random Access - 임의의 위치를 지시할 수 있다.)
  * FILE 구조체 변수의 멤버로서 존재
  * READ & WRITE에 대한 위치 정보가 된다.
  * 입출력 함수의 호출에 의해 이동
  * 순차적인 입력 및 출력이 가능한 이유
  * ![image](https://user-images.githubusercontent.com/49339278/129998238-6312f9aa-8482-4a7e-bcf2-2ddfc6b920c2.png)

* feof 함수를 사용하여 파일의 끝을 확인
  * FILE 구조체 변수를 참조하는 방법
  ```c
  #include <stdio.h>
  int feof(FILE * stream);
  // 파일의 끝에 도달한 경우 0이 아닌 값을 리턴
  ```
  
* Random Access
  * 특정 위치 임의 접근 방식의 입출력
  * DataBase에서 쓰인다.
  ```c
  #include <stdio.h>
  int fseek(FILE * stream, long offset, int wherefrom);
  // 성공 시 0을, 실패 시 0이 아닌 값을 리턴한다.
  ```
  
  | 만약에 whereform이 | 파일 위치 지시자를 offset 만큼 이동하기 전에 |
  |:----:|:-----|
  | SEEK_SET(0) 이라면 | 파일의 맨 앞으로 이동한다.|
  | SEEK_CUR(1) 이라면 | 이동하지 않는다. |
  | SEEK_END(2) 이라면 | 파일의 끝으로 이동한다. |
  
* fseek 함수의 사용 예 (작성하기)

## 26. 메모리 관리와 동적 할당
* C <-> C++ => C#
* 메모리 관리라는 것은 C언어에서 가장 중요한 것이다.
* 근본적으로 메모리 관리를 왜 하는가? -> C 언어는 메모리 자체를 굉장히 작은 사이즈로, 소규모 기계에서도 사용할 수 있도록 Optimize(압축)하는 특징이 있음. 대규모 사이즈에서도 넉넉한 용량이 남아서 H/W 환경에 능동적으로 대응할 수 있다.
* 메모리 관리 = 배열 처리

* 하드웨어 개발용 등 단일용도용 프로세서에서는 Assembly, C언어가 많이 사용된다.

* 스택, 힙, 그리고 데이터 영역
  * 프로그램의 실행을 위해 기본적으로 할당하는 메모리 공간
  * 컴파일 타임에 함수에서 요구하는 스택의 크기 결정되어야 함.
  * ![image](https://user-images.githubusercontent.com/49339278/129999826-db4ae085-7b1b-4702-bf58-9af9fa2399eb.png)
    * 데이터 영역은 컴파일러가 정해준 것이므로 미리 계산되어 필요한 데이터 공간을 미리 확보해 둔다.
    * 힙, 스택은 가변 영역으로, 프로그램 영역이다.
    
```c
#include <stdio.h>

void fct1(int);
void fct2(int);

int a = 10, b = 20;

int main(void)
{
  int m = 123;
  
  fct1(m);
  fct2(m);
  return 0;
}

void fct1(int c)
{
  int d = 30;
}

void fct2(int e)
{
  int f = 40;
}

```

* ![image](https://user-images.githubusercontent.com/49339278/130165175-e36e817b-e572-4d70-a13b-bc81edab8608.png)

* 배열의 선언
  * 배열의 길이 선언은 상수!
  * 컴파일 타임에 요구되는 메모리 공간의 크기를 결정지어야 하므로

```c
// probArray.c 의 일부

void function(int i)
{
  int array[i]; // 공간의 크기를 어떻게 아는가??
}
```

```c
void function(void)
{
  int i = 10;
  int array[i]; // 상수가 아니기 때문에 배제를 한다. 단, 이렇게 해나갈 수 있는 방법을 알려준다. 이것을 동적 할당이라고 한다.
}
```

* 참고 : file 입출력은 실제로 빠르다고 생각하지만, CPU의 속도와 비교했을 때 굉장히 입출력 속도가 느리다. 특히 hdd, DAT, DVD, USB, SSD도 CPU 속도에 비해서 매우 느린것은 마찬가지이다.
* 그래서 file 입출력을 가능한 줄이는 것이 처리 속도를 높이는 길이다!


* 메모리 동적 할당 (동적 배열)
  * 런 타임에 메모리 공간의 크기를 결정지어서 할당 (힙 영역에 할당)
  ```c
  #include <stdlib.h>
  void* malloc(size_t size)
  // 성공 시 할당된 메모리의 첫 번째 주소 리턴, 실패 시 NULL 포인터 리턴
  ```
    * malloc 말록 : memory + alloc(allocation) = 메모리 할당
  * 동적 할당된 메모리 공간의 소멸
  ```c
  #include <stdlib.h>
  void free(void* ptr)
  ```
  * malloc로 할당된 메모리를 소멸시켜 준다. 할당된 메모리를 소멸이 되지 않아서 오류가 발생할 수도 있으니, malloc을 사용했다면 반드시 free를 사용하여 동적 할당된 메모리 공간을 소멸시켜야 한다.
  
* malloc 함수의 활용 : 반환 값이 void ```*``` 이다.
* void pointer는 포인터 연산이나, 포인터에 들어가 잇는 value를 참조하는 것이 안된다고 했다.
  * 하려면 data type으로 casting해야 한다.
* ![image](https://user-images.githubusercontent.com/49339278/130002957-6d1a3a44-b031-48c2-9209-d13d5f4bdd94.png)
* 위의 그림은 이것과 같다.
  * ```int i[x]; // x = sizeof(int)```
  * 기억하기 : ```[] == *```

## 27. 매크로와 전처리기
* 전처리기(pre-processor)에 의한 전처리
  * 컴파일러에 대한 지시자
  * ![image](https://user-images.githubusercontent.com/49339278/130003571-44bc5fb6-49d0-46db-adfe-b6b2fc27e937.png)

* ```#define```으로 시작하는 전처리기 지시자
  * 컴파일러에 의해 처리되는 것이 아니다.
  * 전처리기에 단순 치환 작업을 요청할 때 사용되는 지시자
  * ```#define``` 자체도 header파일에 넣어서 ```#include <헤더파일.h>```처럼 사용하기도 한다.
  ```c
  #define PI 3.1415  // #define : 전처리기 지시자
                     // PI : 매크로
                     // 3.1415 : 대체 리스트
                     
  const int num = 10;
  // 사실 이것은 다음과 같다.
  // #define num 10
  
  ```
  
  ```c
  // Preproc.c
  // 전처리기에 의한 매크로 처리 (= 치환 작업)
  #include <stdio.h>
  
  #define string "C++ Compatible C"
  #define cal (3*4)+(12/4)
  
  #define ONE 1
  #define TWO ONE+ONE
  #define THREE TWO+ONE
  
  int main(void)
  {
    printf("string : %s \n", string);
    printf("cal : %d \n', cal);
    printf("One=%d, Two=%d, Three=%d \n", ONE, TWO, THREE);
    
    return 0;
  }
  ```
  
* 매크로 함수란?
  * 매크로를 기반으로 정의되는 함수
  * 함수가 아니라 매크로다! 다만, 함수의 특성을 지닐 뿐이다.
  * 잘 쓰면 편하지만, 대신에 설계를 잘 해야 한다.

* 두 인수 중 큰 수를 반환하는 함수 MAX
```c
int MAX(int x, int y)
{
  if (x>y) return x;
  return y; // 프로그램 흐름 상 else를 붙이지 않아도 된다.
  
  // 이러한 프로그램의 특성은 삼항 연산자로 바꿀 수 있다.
  return (x>y)? x: y; //
  
  // 이것을 매크로 함수로 만들 수 있다. // 장점 : 자료형에 독립적이다.
  #define MAX(x>y) return (x>y)? x:y 
}
```


  ```c
  #define SQUARE(x) x*x
  // #define : 전처리기 지시자
  // SQUARE(x) : 매크로, x : 매크로 함수 전달 인자
  // x*x : 대체 리스트
  ```

* 매크로 함수의 장점
  * **자료형에 독립적이다.**
  * 실행 속도가 향상된다.

* 매크로 함수의 단점
  * 구현이 어렵다.
  * 디버깅이 어렵다.

* 매크로 함수가 되기 위한 조건
  * **함수의 크기가 작아야 한다.**(작을 필요는 없지만, 단순해야 한다.)
  * 그렇지 않을 경우 실행 파일의 크기가 커지게 된다.

* ##를 이용한 토큰의 결합 
* ![image](https://user-images.githubusercontent.com/49339278/130011431-ba3904de-58f5-4da3-a928-605ffb635c8e.png)

## 28. 모듈화 프로그래밍
* 함수, 기능(루프)
* 단위 s/w, 전체가 아니다. 나눌 수 있는 부분이다.

* 모듈(module)이란 무엇인가?
  * 프로그램을 구성하는 구성 요소의 일부
  * 관련된 데이터와 함수들이 묶여서 모듈을 형성한다.
  * 파일 단위로 나뉘는 것이 보통

* 모듈화 프로그래밍
  * 기능별로 파일을 나눠가며 프로그래밍하는 것
    * 여러 사람이 작업을 나눠서 수행 가능하다.
    * 시차로 나눠서 우선순위를 부여할 수도 있다.
  
  * **유지 보수성이 좋아진다.**

* 파일의 분할 및 컴파일
  * 파일을 나눌지라도 완전히 독립되는 것은 아니다.
  * **파일이 나뉘어도 상호 참조가 발생할 수 있는데, 이는 전역 변수 및 전역 함수로 제한된다.**
  * ![image](https://user-images.githubusercontent.com/49339278/130011573-f360618b-fffe-4d0e-8aeb-597b45adea17.png)
    * 전역변수 : 이하의 함수에서 사용 가능한데, 다른 .cpp 파일에서도 사용하기를 원한다면, ```extern```라고 키워드를 사용해서 명시적 선언을 하면 된다. (extern : 변수 뿐만 아니라 함수에도 적용이 가능함.)

* 외부 접근 금지
  * static 키워드에 의한 접근의 제한
  * ![image](https://user-images.githubusercontent.com/49339278/130011660-e259db3e-1b6a-4c44-bc12-7516c77262ab.png)

* 링크에 대한 이해
  * 링크라는 이름이 의미하는 것처럼 연결에 관련된 작업을 한다.
  * 선언된 함수의 정의를 찾아서 연결시켜 주는 작업 (여기서 말하는 연결이라는 용어는 다양한 의미로 사용)

* 헤더 파일의 포함이 지니는 의미
  * 전처리기에 의해 하나의 파일을 다른 하나의 파일에 포함시키는 작업
  * 그림 추가

* 헤더 파일 포함 방법
```c
#include <abc.h>             // 표준 디렉토리에서 abc.h를 찾아서 포함(시스템 헤더파일, vs gcc 헤더 디렉토리일 때 사용) 
#include "c:/include/abc.h"  // c:\include에서 abc.h를 찾아서 포함 (직접 만든 것)
``` 

```c
#include "plus.h"   // 현재 작업 디렉토리에 존재하는 plus.h를 포함하라는 의미

#include "c:/header/lib/plus.h"  // c:/header/lib에 존재하는 plus.h 포함
```

* 헤더 파일의 정의 방법 및 유용성
  * 함수 및 변수의 extern 선언의 간략화
  * 파일 변경 최소화!
  * ![image](https://user-images.githubusercontent.com/49339278/130014251-54840cd7-0457-4bc3-9d2b-33c7a6d100d4.png)


* #if, #elif # else #endif 기반 조건부 컴파일
```c
#if CONDITION1
  expression1
  
#elif CONDITION2  // else if
  expression2
  
#else
  expression3
  
#endif  // 최초의 if에 대한 종결, 가장 가까운 위치에 있는 if문에 종속됨
```

* 헤더 파일 포함 관계에서 발생하는 문제
  * 하나의 헤더 파일을 두 번 이상 포함!
  * 이는 중복해서 함수가 정의되거나, 변수가 선언되는 문제점
  * 조건부 컴파일로 문제 해결!
  * ![image](https://user-images.githubusercontent.com/49339278/130014158-15020eb3-5403-4962-8679-d1a767753fd4.png)

* #ifndef, #endif 기반 조건부 컴파일
* ![image](https://user-images.githubusercontent.com/49339278/130014200-574753a6-86f5-4c87-a17b-0c3c1c8e0e8f.png)
