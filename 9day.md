# 7강. C 표준함수
* 호환성이 높아서 임의의 플랫폼에서도 사용이 가능하다.
  * 그 이유는 OS마다 제공하는 컴파일러가 다르기 때문에, 호환성 여부를 확인해 보아야 한다. 
  * C언어는 이식성이 굉장히 높아서, 따로 손을 쓰지 않아도 사용 기능하다.
## 24. 문자와 문자열 처리 함수

* 입출력의 이해
  * 파일, 콘솔, 소켓 입출력
* 스트림에 대한 이해
  * 데이터를 송수신 하기 위한 일종의 다리
  * ![image](https://user-images.githubusercontent.com/49339278/129317904-f42b2fbd-adbb-47ca-a430-8b59fff90b48.png)

* 표준 입출력 스트림 = File의 개념
  * 프로그램 실행 시 자동으로 생성 및 소멸
  * 모니터와 키보드를 그 대상으로 함
  * 
  | 이름 | 스트림의 종류 | 입출력 장치 |
  |:----:|:----:|:----:|
  | stdin | 표준 입력 스트림 | 키보드 |
  | stdout | 표준 출력 스트림 | 모니터 |
  | stderr | 표준 에러 스트림 | 모니터 |

* 문자 출력 함수
```c
#include <stdio.h>

int putchar(int c);
int fpuct(int c, FILE* stream);     // fprintf (앞의 f = file) 사용하면 된다.
// 에러가 발생하는 경우 EOF 리턴
```

* 문자 입력 함수
```c
#include <stdio.h>

int getchar(void)
int fgetc(FILE* stream);            // fscanf (앞의 f = file) 사용하면 된다.
// 에러가 발생하거나 파일의 끝에 도달하는 경우 EOF 리턴
```

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
int fputs(const char* s, FILE* stream);
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

* 입출력 사이에 존재하는 버퍼의 이해
  * 여분의 임시 메모리적 특징을 지닌다.
  * 성능 향상이 목적이다.
  * 모아서 보내고... 모아서 받고...

















* 문자열의 길이를 반환하는 strlen 함수
  ```c
  #include <stdio.h>
  size_t strlen(const char *s)
  // 성공 시 0, 실패 시 EOF 리턴
  ```
  
  
