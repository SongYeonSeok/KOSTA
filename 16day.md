## Chapter 08-1. 객체 포인터의 참조관계
* C언어라는 것은 객체가 아니었다. 진짜 말 그대로 Language였다.

* 객체의 주소 값을 저장하는 객체 포인터 변수
  * C++에서 AAA형 포인터 변수는 AAA 객체 또는 AAA를 직접 혹은 간접적으로 상속하는 모든 객체를 가리킬 수 있다.(객체의 주소 값을 저장할 수 있다.)
  * SDK = Software Development Kit -> 라이브러리라는 뜻(고급형 그래픽 인터페이스에 같이 적용되는 경우가 있음)
  * ![image](https://user-images.githubusercontent.com/49339278/131077944-dfe4b19e-6022-4ddf-8f2f-3637a2147d5b.png)

## Chapter 08-2. 가상함수(Virtual Function)
* ![image](https://user-images.githubusercontent.com/49339278/131078469-918d104d-0989-4bf6-bc12-6636786a7ef6.png)

* 기초 클래스의 포인터로 객체를 참조하면...
  * C++ 컴파일러는 포인터 연산의 가능성 여부를 파악할 때, **포인터의 자료형을 기준으로 판단하지, 실제 가리키는 객체의 자료형을 기준으로 판단하지 않는다.**\
  * ![image](https://user-images.githubusercontent.com/49339278/131078648-3178e70e-e369-4b98-9623-f3b9852847d1.png)
  * 불필요하게 어렵게 쓰지 말 것! (프로그램은 가능하면 알기 쉽고 간편하게 작성하는 것이 중요하다.)

* 함수의 오버라이딩과 포인터 형
  * ![image](https://user-images.githubusercontent.com/49339278/131081031-36825436-6c79-4069-8cf5-9f26451fad86.png)
  * 함수를 호출할 때 사용이 된 포인터의 형에 따라서 호출되는 함수가 결정된다. 포인터의 형에 정의된 함수가 호출된다.

* 가상함수(Virtual Function)
  * H/W, Interface
  * 오버라이드를 염두에 둔 함수이다. (덮어쓰는 것)
    * 오버로드와 오버라이딩은 서로 다른 것들이다.
  * 현 상황에서의 EmployeeManager 클래스는 모든 객체를 Employee 객체로 간주한다. 따라서 호출하는 함수도 Employee 객체의 멤버함수이다. 바로 이러한 문제의 해결책이 위의 예제에 있다.
  * ![image](https://user-images.githubusercontent.com/49339278/131081623-7a194241-1a58-4218-a39b-550e72bf8a68.png)
  * 새롭게 선언해서 사용할 것

* 순수 가상함수와 추상 클래스
  * 몸체가 정의되지 않은 함수를 가리켜 순수 가상함수라고 하며, 하나 이상의 순수 가상 함수를 멤버로 두어서 객체생성이 불가능한 클래스를 가리켜 추상 클래스라고 한다.
  * 오버라이딩의 관계를 목적으로 정의된 함수들! 따라서 몸체부분의 정의는 의미가 없다!
  * ![image](https://user-images.githubusercontent.com/49339278/131082465-3f3ef847-9b4e-4ae3-a038-9b9ef45eb9de.png)
  * 따라서 반드시 새롭게 정의할 것! 
  * 이와 같은 클래스를 추상 클래스라고 한다.
  * 추상 클래스는 SDK 선언 후 출력이 안된다. 즉, 상속 전용이라는 뜻이다.
  * 추상 클래스는 객체 선언이 불가능하다. 오직 상속만 가능하다.

* 다형성(Polymorphism)
  * 지금까지 공부한 가상함수와 관련한 내용을 가리켜, 다형성"이라고 한다!
  * 다형성은 동질 이상의 의미를 갖는데, **모습은 같은데 형태는 다르다. 문장은 같은데 결과는 다르다.**
  * ptr->Simplefunc 함수의 호출이 다형성의 예
  * 예시는 좋지 않은 예시이다. 이런 경우를 회피하는 것을 권장
  * ![image](https://user-images.githubusercontent.com/49339278/131083206-f58313cd-d7fd-4613-8eb5-53700cc150f4.png)

## Chapter 08-3 가상소멸자와 참조자의 참조 가능성
* 가상 소멸자(Virtual Destructor)
  * 소멸자를 가상으로 선언함으로써 각각의 생성자 내에서 할당한 메모리 공간을 효율적으로 해제할 수 있다.
  * ![image](https://user-images.githubusercontent.com/49339278/131083574-21e76080-86ec-4f2d-ab33-766872801366.png)

* 참조자의 참조 가능성(할 수는 있지만 안하는 것이 좋다.)
* ![image](https://user-images.githubusercontent.com/49339278/131083795-d9d95299-a746-423d-a19d-050ec51f8a6b.png)


## Chapter 11-1. 연산자의 오버로딩
* 흔히 생각하는 +, -, ```*```, /의 오버로딩을 말한다. 즉, 수식을 새롭게 정의해 주는 것이다.


* Operator+라는 이름의 함수
  * ![image](https://user-images.githubusercontent.com/49339278/131085169-7c86e884-2485-4928-9274-d38af75b34fa.png)
  * ![image](https://user-images.githubusercontent.com/49339278/131085085-f253fd2b-a4db-40fc-9022-4052c3ae3762.png)
  * 왼쪽에 있는 요소가 기준

* 연산자를 오버로딩하는 두 가지 방법
  * ![image](https://user-images.githubusercontent.com/49339278/131093159-4be1184f-b5a6-40cb-bba9-59fe4c507e33.png)
  * ![image](https://user-images.githubusercontent.com/49339278/131093353-761ef920-e8d2-496a-b697-6859eecdfdd0.png)

* 오버로딩이 불가능한 연산자의 종류
  * 
