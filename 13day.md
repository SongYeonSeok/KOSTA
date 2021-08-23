## chapter 02-1. chapter 02의 시작에 앞서
* 인터넷의 모든 정보가 맞는 것은 결코 아니다.

* C언어의 복습을 유도하는 확인학습 문제 1
* < 문제 1 > 키워드 const의 의미
  * 변수 같은 상수이다. 배열 선언할 때 상수가 필요한데, const를 이용해서 지정하면 배열의 크기를 한 곳에서 변경이 가능하다.
  * 초기화 이후 변경이 불가능
  * ```const int num = 10;```  // 변수 num을 상수화!
  * ```const int *ptr1 = &val1;``` // 포인터 ptr을 이용해서 val1의 값을 변경할 수 없음
  * ```int *const prt2=&val2;``` // 포인터 ptr2가 상수화 됨
  * ```const int *const ptr3=&vale2;```  // 포인터 ptr3가 상수화되었으며, ptr3을 이용해서 (더 기록하기)

* < 문제 2 > 실행중인 프로그램의 메모리 공간
  * ![image](https://user-images.githubusercontent.com/49339278/130378075-00e16303-2a34-4a7c-89a7-dfc61b48ee87.png)

  |종류|설명|
  |:----|:----|
  |데이터 | 전역변수가 저장되는 영역|
  |스택|지역변수 및 매개변수가 저장되는 영역|
  |힙| malloc 함수호출에 의해 프로그램이 실행되는 과정에서 동적으로 할당이 이뤄지는 영역|
  |malloc & free|malloc 함수호출에 의해 할당된 메모리 공간은 free 함수호출을 통해서 소멸하지 않으면 해체되지 않는다.|
  
## chapter 02.2 새로운 자료형 bool
* 참 : true, 거짓 : false
* true : 1, 참, 1바이트 데이터
* falue : 0, 거짓, 1바이트 데이터
* true != int, false != int (1과 0은 정수 1과 0이 아니다!)
* 그러나 정수가 와야 할 위치에 오게 되면, 각각 1과 0으로 변환이 된다.

* 속도가 빠르게 하려면 메모리 자원을 늘려야 하고, 속도가 느리게 하려면 메모리 자원이 줄어들게 만들어야 한다.

```c++
int num1 = true           // num1에는 1이 저장된다.
int num2 = false;         //num2에는 0이 저장된다.
int num3 = true+false;    //num3 = 1+0
```
* c#으로 올라가면서 true, false 적용하는 것이 엄격하게 변한다.
  * c/c++은 while(1) 사용이 가능했지만, c#부터는 while(true)만 가능하게 되었다. 좀 더 변수 type 호환성 문제가 조금 더 엄격해졌음

* 자료형 bool

* Reference의 이해
  * ![image](https://user-images.githubusercontent.com/49339278/130379677-f74abfe7-5e00-4481-b62c-a498c1212d9d.png)
  * reference는 기존에 선언된 변수에 붙이는 '별칭'이다. 그리고 이렇게 reference가 만들어지면 이는 변수의 이름과 사실상 차이가 없다.
  * reference = 변수의 별명!
  *  ```*``` : 포인터 변수의 주소 = Array
  *  잘못 사용하면 혼동을 불러 올 수도 있다는 것을 알아야 한다

* reference 관련 예제와 reference의 선언
* ![image](https://user-images.githubusercontent.com/49339278/130379930-ccd39b98-e1dd-4666-92dc-2e9007cac345.png)

* reference의 선언 가능 범위
```c++
int &ref = 20;  // X, 상수 대상으로의 reference 선언은 불가능하다.
int &ref; // X, reference는 생성과 동시에 누군가를 참조해야 한다.
int &ref=NULL;  // X 포인터처럼 NULL로 초기화하는 것도 불가능하다.
```
  * 정리하면, reference는 선언과 동시에 누군가를 참조해야 하는데, 그 참조의 대상은 기본적으로 변수가 되어야 한다. 그리고 참조자는 참조의 대상을 변경할 수 없다.
  * ![image](https://user-images.githubusercontent.com/49339278/130381219-dd1997bd-6f95-4391-9d66-4ad9e16e91db.png)
  * (추가)
    * ```arr[0] = *(arr+0)```
    * ```arr[1] = *(arr+1)```
    * ```arr[2] = *(arr+2)```

* 포인터 변수 대상의 reference 선언
* ![image](https://user-images.githubusercontent.com/49339278/130381422-49ffb28d-71cf-4965-891b-542c251c0c6d.png)
* ![image](https://user-images.githubusercontent.com/49339278/130381997-9e02742a-7d31-4c07-953a-125cee6fac01.png)
* 동일한 범주의 변수명이 여러개가 있다고 되어 있는 것이다. 컴파일러에게 그렇게 선언한 것
* ```*(&num1) == num1```
* 변수는 물리적 주소의 이름표를 붙인 것. 그래서 변수 이름에 따라서 프로그램을 짤 수 있는 것
* 하나의 물리적 주소에는 하나의 변수가 할당되어야 한다.

* Call-by-value & Call-by-reference
```c++
void SwapByValue(int num1, int num2)
{
  int temp=num1;
  num1=num2;
  num2=temp;
   // call-by-value
}
```
  * 값을 전달하면서 호출하게 되는 함수이므로 이 함수는 **Call-by-value**이다. 이 경우 함수 외에 선언된 변수에는 접근이 불가능하다.

```c++
void SwapByRef(int* ptr1, int* ptr2)
{
  int temp = *ptr1;
  *ptr1 = *ptr2;
  *ptr2 = temp;
  //call-by-reference
}
```
  * 값은 값이되, 주소 값을 전달하면서 호출하게 되는 함수이므로 이 함수는 **Call-by-reference**이다. 이 경우 인가로 전달된 주소의 메모리 공간에 접근이 가능하다.

* ![image](https://user-images.githubusercontent.com/49339278/130382691-5a2b6218-49f5-48ff-a9f0-c73efc4a8bc5.png)

* reference를 이용한 Call-by-reference
* ![image](https://user-images.githubusercontent.com/49339278/130382943-02027144-0f9c-4db4-8a0c-fffa95039844.png)
* ![image](https://user-images.githubusercontent.com/49339278/130383194-0a475869-638b-4de6-8bbf-4e187a38a5d2.png)

  * reference 규칙에 위배되는 것 처럼 보이지만, 함수가 호출되면서 val1, val2로 의해 &ref1, &ref2의 초기화가 동시에 이루어진다. (별명이라고 생각하면 된다)
  * 참고 reference는 변수의 별명이라고 하는데, 이는 변수 값과 다르다고 생각해야 한다. '

* const reference
* ![image](https://user-images.githubusercontent.com/49339278/130395681-d3409c88-ce7a-4e16-bdb5-4ed82233a7a3.png)
* const는 초기화 이후 변경불가! (이것만 기억해 두기)

* 반환형이 참조이고 반환도 참조로 받는 경우
* ![image](https://user-images.githubusercontent.com/49339278/130395777-13c05656-9df8-4d31-ae8b-0a4f18c1f88d.png)
* 이렇게 해야 할 이유는 없다. &num2 = num1과 같은 거라고 보면 되고, 실제로도 같다.

* 반환형은 참조이되 반환은 변수로 받는 경우
* ![image](https://user-images.githubusercontent.com/49339278/130396470-bd1ebd17-b690-4fe0-99e3-51fb7d0a9d0a.png)

* 참조를 대상으로 값을 반환하는 경우
* ![image](https://user-images.githubusercontent.com/49339278/130396805-8f78b360-3b2a-4099-b558-29c9b78173a1.png)

* 잘못된 참조의 반환
* ![image](https://user-images.githubusercontent.com/49339278/130397432-9fccfea9-6c6c-406e-b40d-646e8d72fe23.png)
* reference는 변수의 별명, 여러 개의 별명을 붙일 수도 있다.
* int num = 20; : stack에 쌓임 -> 일시적 -> 소멸됨

* const reference의 또 다른 특징
* ![image](https://user-images.githubusercontent.com/49339278/130397575-658f9a6d-426a-43df-a42e-e9683ccba53a.png)
* 상당히 귀찮은 작업!

* 어떻게 reference가 상수를 참조합니까?
* ![image](https://user-images.githubusercontent.com/49339278/130397929-067697c1-0579-48f4-9e1c-b7090e0f3b59.png)
* 꼭 필요한 경우를 제외하고 이렇게 할 필요가 없다.

* new & delete
* ![image](https://user-images.githubusercontent.com/49339278/130397955-3ea9094f-f193-484c-bed8-46f698c4c3c8.png)
* new는 malloc과 비슷한 의미라고 생각하면 된다. 그 이유는 메모리 공간 신규 생성이기 때문이다.
* delete는 매모리 공간을 해제하는 방법이다. free를 대신하는 방법이다.
* new 연산자로 할당된 메모리 공간은 반드시 delete 함수 호출을 통해서 소멸해야 한다!
* 이후에 공부하는 객체의 생성 및 소멸 과정에서 호출하게 되는 new & delete 연산자의 연산자 연산특성은 malloc & free와 큰 차이가 있다.
* 개념적으로 비슷하다는 것이지, 구조상으로는 다른 것들이다. (malloc는 힙 영역에 생김)

* malloc도 사용 가능하다. 고전적인 방법들은 모두 사용이 가능하다. 하지만 new를 통해서 새롭게 변수 뿐만 아니라 배열 등 다양한 형태의 변수 타입들을 생성을 해줄 수 가 있다

* 포인터를 사용하지 않고 힙에 접근하기
* ![image](https://user-images.githubusercontent.com/49339278/130400232-6825820e-7080-467a-9533-5d5b2d359288.png)
* ![image](https://user-images.githubusercontent.com/49339278/130400618-5b49c4bb-1a1e-4142-a854-8614f39eae96.png)

* C++의 표준헤더 : c를 더하고 .를 빼라.
* ```#include <stdio.h> -> #include <cstdio>```
* ```#include <stdlib.h> -> #include <cstdlib>```
* ```#include <math.h> -> #include <cmath>```
* ```#include <string.h> -> #include <cstring>```
* 이렇듯 C 언어에 대응하는 c++ 헤더파일 이름의 정의에는 일정한 규칙이 적용되어 있다.
* ![image](https://user-images.githubusercontent.com/49339278/130401251-e0aeb65e-49c9-4864-a618-25892ca6b1b8.png)
* 함수의 오버로드 -> 컴파일러가 자동적으로 데이터 타입을 확인해서 컴파일함 -> C언어보다 확장되어 더 유연하다. (가급적이라면 c++ 표준형태의 헤더 파일로 바꾸어서 사용하면 유리한 점이 있으니 사용하자)

## chapter 03-1. C++에서의 구조체
* class가 무엇인가?
  * c 언어에서는 struct를 배웠다. class는 struct와 똑같이 생겼다. 그런데 거기에 데이터 타입뿐만 아니라 함수까지 포함할 수 있다는 점이 다르다. struct의 요소를 부를 때 구조체 멤버라고 부르는데, class에서는 그 안에 있는 속성들은 똑같이 사용하고 있다. 똑같이 멤버라고 부른다. 또 다른 말은 property라고 부른다.'
  * class 안에 있는 함수를 method라고 부른다.

* c++에서의 구조체
  * 구조체의 등장배경
    * 연관 있는 데이터를 하나로 묶으면 프로그램의 구현 및 관리가 용이하다.
    * 구조체는 연관 있는 데이터를 하나로 묶는 문법적 장치이다.
![image](https://user-images.githubusercontent.com/49339278/130402725-407791e1-7e44-4b2a-aafb-97474b514b64.png)

  * 연관있는 데이터들은 생성 및 소멸의 시점이 일치하고, 이동 및 전달의 시점 및 방법이 일치하기 때문에 하나의 자료형으로 묶어서 관리하는 것이 용이하다.

* C++에서의 구조체 변수 선언
* ![image](https://user-images.githubusercontent.com/49339278/130402854-4117dea7-b61e-41ef-9edc-2db8921eb86a.png)

* 구조체 안에 함수 삽입하기
* ![image](https://user-images.githubusercontent.com/49339278/130403060-628329b1-3314-46b7-9fa9-cbddae52b6af.png)
  * c++에서는 구조체 안에 함수를 삽입하는 것이 가능하다.
  * 따라서 C++에서는 구조체가 아닌, 클래스라 한다.
  * namespace // 큰 모듈 -> 정적 변수

* 사이 추가

* 구조체 안에 enum 상수의 선언
* ![image](https://user-images.githubusercontent.com/49339278/130403686-53ccbe02-56d4-402d-b17b-32afbbd76802.png)

* 함수는 외부로 뺄 수 있다.
* ![image](https://user-images.githubusercontent.com/49339278/130403771-c520c679-3c08-492d-9d24-6baef369ef52.png)
* 가능하지만 관등성명(?) 즉, 소속을 앞에 붙어주어야 한다.

## chapter 03-2. class와 객체(object)
* 클래스와 구조체의 유일한 차이점
* ![image](https://user-images.githubusercontent.com/49339278/130405865-522cf879-bd00-4a5a-ac12-ff8fba0b35e7.png)

* 접근제어 지시자

| 종류 | 내용 |
|:---:|:----|
|public|어디서든 접근허용|
|protected|상속관계에 놓여있을 때, 유도 클래스에서의 접근 허용|
|private|클래스 내(클래스 내에 정의된 함수)에서만 접근 허용|
* ![image](https://user-images.githubusercontent.com/49339278/130406402-a76e02a5-f789-409e-b086-627e16638200.png)

* 용어 정리 : 객체(Object)(= class), 멤버변수, 멤버함수
* ![image](https://user-images.githubusercontent.com/49339278/130407556-b79522ab-c1d4-4d99-b304-0447e16ecb34.png)
* c++에서는 객체를 class라고 이해해도 무방하다.(표현 방법에 따라 광범위하게 표현할 수 있다.) -> C++는 대표적인 객체지향 프로그래밍 언어(OOP)
  * OOP : Object-Oriented Programming
  * OOM : 객체지향 방법(Object-Oriented Method)

* C++에서의 파일 분할
* ![image](https://user-images.githubusercontent.com/49339278/130408309-fcea766f-1383-46ec-99bf-19f875e5a9a1.png)
  * 클래스의 선언은 일반적으로 헤더 파일에 삽입한다. 객체생성문 및 멤버의 접근문장을 컴파일하기 위해서 필요하다.
  * 클래스의 이름을 떼서 Car.h로 헤더 파일의 이름을 정의하기도 한다.
  * 단, 인라인 함수는 컴파일 과정에서 함수의 호출문을 대체해야 하기 때문에 헤더파일에 함께 정의되어야 한다.
  * Car 클래스의 멤버함수의 몸체는 다른 코드의 컴파일 과정에서 필요한 게 아니다. 링크의 과정을 통해서 하나의 바이너 (추후 기록하기)

## chapter 03-3. 객체지향 프로그래밍 시작
* 객체지향 프로그래밍의 이해 (OOP)
  * 객체에 대한 간단한 정의
    * 사전적 의미 : 물건 또는 대상
    * 객체지향 프로그래밍, 객체 중심의 프로그래밍
    * class를 바탕으로 하는 프로그래밍 언어

  * 객체지향 프로그래밍에서는 나, 과일장수, 사과라는 객체를 등장시켜서 두 개의 사과구매라는 행위를 실체화한다.
  * 객체지향 프로그래밍은 현실에 존재하는 사물과 대상, 그리고 그에 따른 행동을 있는 그대로 실체화시키는 형태의 프로그래밍이다.
* ![image](https://user-images.githubusercontent.com/49339278/130408608-945449e3-e9f4-4e86-909a-2e0d38a0e29a.png)

* 한국에서는 spring 프레임워크만 잘해도 밥 먹고 산다고 한다.
* C++ / MFC , ASP/JSP/C# .NET

* '과일장수'(= 객체)의 정의와 멤버변수의 상수화
* ![image](https://user-images.githubusercontent.com/49339278/130409800-b77dd066-e029-4d78-a11e-62e511e50535.png)

* '나(me)'를 표현하는 클래스의 정의와 객체 생성
* ![image](https://user-images.githubusercontent.com/49339278/130410531-7eceb440-3f9b-419b-a89e-d5fd4dabf464.png)
* ![image](https://user-images.githubusercontent.com/49339278/130411006-6f8b6437-09ef-4edd-bc3c-a7bb4e05f831.png)

* ![image](https://user-images.githubusercontent.com/49339278/130411836-db822e9e-911d-422a-a602-039674e9f8df.png)
