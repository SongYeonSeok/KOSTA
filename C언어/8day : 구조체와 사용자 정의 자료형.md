* C -> C++ -> C# -> DB & ORM 순서로 진도 나갈 것
  * C는 이번 주에 끝날 예정
  * 다음주는 MFC에 기반한 프로그래밍 공부 예정
  * C/C++ + MFC (Microsoft Foundation Class)

* Programming != Coding
  * Programming : 창작의 영역 -> 알고리즘, 생각이 들어가는 것이다.
  * Coding : 기능의 영역 -> 배운다면 누구나 할 수 있는 것
  * 우리는 코더가 아닌 프로그래머가 되어야 한다.
  * 프로그래밍은 텍스트가 아닌 손으로(typing) 공부하는 것이다.

* IoT 개념 반영한 S/W 개발

* VS와 Github 연동하기
1. github의 code에 git주소 복사
2. VS의 리포지토리 복제 클릭
3. 리포지토리 위치에 git 주소 붙이기, 경로 지정 (기존 폴더 지정할 수 없다.) -> respos 생성 및 복제
4. Local Directory 생성됨 (그러면 기존에 있던 것은? -> PC에서 복사해서 넣으면 된다.)

## 23장. 구조체와 사용자 정의 자료형
* 참고 : C언어의 예약어는 대문자 없다.


* call-by-value -> call-by-reference로 변경
* 배열 = * = 구조체

* 함수의 인자로 전달되는 구조체 변수
  * 구조체 변수의 인자 전달 방식은 기본 자료형 변수의 인자 전달 방식과 동일

* 구조체 변수의 연산
  * 허용되는 대표적인 연산은 대입 연산(=)이며, 이외의 사칙 연산들은 적용이 불가능하다.

* 구조체 변수의 리턴 방식 : 기존 자료형 변수의 리턴 방식과 동일하다.
  * 포인터가 원칙이다. 이는 다른 것들도 할 수는 있지만 포인터로 하는 것이 좋다는 말이다.
* ![image](https://user-images.githubusercontent.com/49339278/129133000-b544e7c8-56cc-416c-b823-d50e1eda30c3.png)
* 이 방식은, stack의 깊이가 길어질수록 stack의 사용량이 누적되는 것인데, 컴파일러가 많이 만들어진 stack를 꽉 채워가서 stack overflow라는 에러 메세지가 발생할 가능성이 높아진다. 
* 이 stack overflow가 발생하면, logic 분석으로 해석이 안되고 시스템적인 분석으로 들어가야 한다.

* 잘 구현된 프로그램은 처리되어야 할 데이터의 부류가 적절히 나뉘어진다.
* 부류를 적절히 나누면 데이터를 처리하는 과정이 수월해진다.

* 중첩된 구조체 : 구조체의 멤버로 구조체 변수가 오는 경우
* ![image](https://user-images.githubusercontent.com/49339278/129133914-e9f4a927-d4e5-4bae-bb5a-15ef4f7a6f9f.png)

* 중첩된 구조체 변수의 초기화 방식
  * case 1
  * ![image](https://user-images.githubusercontent.com/49339278/129134055-9051d8e1-cf98-4fb1-876d-6df805cd9807.png)
  * 두 방법 어느 것을 써도 상관은 없는데, case 2를 사용하여 그룹별로 지정하는 것이 신상에 좋다. 따라서 case 2 방법을 사용하는 것을 권장한다.

  * case 2
  * ![image](https://user-images.githubusercontent.com/49339278/129134072-ea46038a-3d57-48f9-9a55-8563dbe30079.png)
  * 마찬가지로 case 2를 사용하는 것을 권장한다.

* 위의 예제와 같이, 계속 struct, struct ... 를 작성해야 하니 번거롭다. 그래서 나온 것이 typedef 키워드가 나왔다. (물론, typedef이 struct때문에 나온 것은 아니다.)

* typedef 키워드의 이해
```typedef int INT;```
  * typedef : 이름을 지어 주자 -> To : complier -> 해석하고 읽기가 편해지는 점이 있다.
  * int : 기본 자료형 int에 대해
  * INT; : INT라는 이름을~~ 끝.

  * typedef가 많이 쓰이는 곳 : struct
  * 가독성을 높이기 위해서 사용

* typedef의 적용
* ![image](https://user-images.githubusercontent.com/49339278/129135012-a47eec0d-445f-4bb0-ba3e-f791b0b36a8f.png)
* 후자를 많이 쓴다. 단, 구조체에 자료 정의를 다른 사람이 만든 헤더 파일에 들어가 있다면, 전자를 많이 쓴다.

* 구조체 이름의 생략
* ![image](https://user-images.githubusercontent.com/49339278/129135339-65e72939-b2ff-4f21-9499-7adbc2935f79.png)
* 두 가지가 다 허용이 된다. 하지만 서로 같지 않다. 전자는 구조체를 선언할 때, 구조체 자체에 data라는 이름을 부여했는데, 후자는 구조체 자체에 이름을 부여하지 않았다.
* 전자와 후자는 Data로 써도 무방. but 전자는 'struct Data ...' 라고 뜨면서 이렇게 써도 된다는 것이다. 즉, 두 가지 명칭을 쓸 수 있다는 것. 후자는 명칭이 없어서 한 가지의 명칭(아래의 Data)만 쓸 수 있다.

* 공용체(union)의 특성 : 하나의 메모리 공간을 둘 이상의 변수가 공유하는 형태
  * union - 공용체는 'c' 언어에만 사용이 가능하고, 다른 언어에서는 사용이 불가능하다.
* ![image](https://user-images.githubusercontent.com/49339278/129151081-831a85e1-6afe-4c4d-bb7b-8458a98e4ff3.png)
* 앞부분만 제외하고 모두 같다.
  * struct(구조체)는 변수마다 메모리 공간을 할당한다.
  * union(공용체)는 하나의 메모리 공간에 둘 이상의 변수가 공유하는 형태이다. 주로 통신 영역에서 고속 처리를 위해서 쓸 때에 사용하는 경향이 있다. (무조건 쓰는 것은 아님)
    * 통신 영역 : 빠르게 처리하는 것이 핵심!
    * 통신 영역은 byte 단위로 데이터를 통신하도록 만들어져 있다.

* 열거형(Enum)의 정의와 의미 ; Enumeric
* enum color{RED = 1, GREEN = 3, BLUE = 5};
  * enum color : color라는 이름의 자료형 선언
  * RED = 1, GREEN = 3, BLUE = 5 : 상수 RED(1), GREEN(3), BLUE(5)의 선언
  ```c
  enum color c    // 열거형 color의 변수 c를 선언
      c = RED;    // c에 RED 대입
      c = GREEN;  // c에 GREEN 대입
      c = BLUE;   // c에 BLUE 대입
  ```
  
  * enum week{Sun = 1, MON = 2, TUE = 3, WEN = 4, THU = 5, FRI = 6, SAT = 7}
    * 정수에 부여된 값 대로 값을 부여 받음 (정수값 지정하는 것은 프로그래머의 마음대로!)
  
  * 할당되는 상수의 값
  ```c
  enum color {RED, GREEN, BLUE};
  enum color {RED, GREEN=100, BLUE};
  ```

* 프로그래밍을 할 때, 변수든지 값을 지정하든지 간에... 일관성 있게 형식대로 변수를 부여하든, 값을 부여해야 나중에 다시 보거나 코드 리뷰하기 쉽다.

* 열거형을 사용하는 이유
  1. 특정 정수 값에 의미를 부여할 수 있다.
  2. 따라서 프로그램의 가독성을 높이는 데 한 몫을 한다.


# C 언어에 대한 전반적인 문법 지식은 완료함.
