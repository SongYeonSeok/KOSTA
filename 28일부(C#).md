# C\# 프로그래밍

* Intro
  - MFC = 윈도우 프로그래밍을 염두로 만든 프레임워크. 하지만 C/C++로부터 시작하여서, 초심자에게 진입장벽이 존재한다는 점이 있다.
  - SUN -> Java 만듬 (현재 Oracle꺼)
    - Java = C/C++ - Pointer
    - 대한민국은 Java공화국이다. 대부분의 회사에서 다 Java를 쓰기 때문
    - 인기가 많은 이유 = 무료 ㅎㅎ + Runtime Library가 필요
    - Java는 UNIX 베이스에서 개발된 언어이므로 리눅스 환경에서도 사용 가능하고, 윈도우, 맥 등에서도 사용이 가능하다.

  - Java의 인기에 배아픈 Microsoft가 만든 것이 C#이다. (실제)
    - 그래서 C#이 Java와 거의 같다.
    - C#은 Runtime 모듈이 거의 필요가 겂다. 즉, C#을 위한 .NET FrameWork이란 환경이 필요하다.(현재 7버전 출시)
    - C#의 단점은 .NET Framework가 지원이 되어야만 사용이 가능하다. 그래서 아직 리눅스 환경에서는 완벽하게 작동되지는 않는다.
    - C#의 단점에 비해 장점이 매우 많다.
      - 개발 환경이 기존 java보다 좋다. java를 개발하기 위해서는 eclipse를 사용해야만 했고, Visual Studio보다 기능이 좋지는 않다고 한다.
        - (자존심 때문인지는 모르겠지만... visual studio에서 java를 사용할 수 없다. (하지만 visual studio code를 개발해 냈고, 이것으로 java, JS, html를 사용한다.)
        - Java != Javascript (하지만 C/C++에서부터 파생된 언어인 것은 공통점이다.) 

* C# 개요
  * C# : 형식 안정 객체 지향 언어로, 기존 언어들의 생산성을 개선하여 성능을 향상시킨다.
  * 초기 : Windows에서만 지원 -> 현재 : Windows, Linux, mac, android, etc... 등 지원 가능하지만, Windows 전용임은 틀림없다.
  * C#에서도 포인터라는 개념은 없어졌다.

  * 닷넷 플랫폼 + 클래스 라이브러리 => 닷넷 프레임워크(Runtime 환경)
    * .NET Framework가 개발된 이후에 런타임 환경이라고 잘 부르지 않는다. 그 이유는 런타임 환경보다 기능이 많기 때문.
    * 응용프로그램 프레임워크 : 윈도 폼, WPF, 윈도10 유니버셜 응용프로그램
    * 웹 응용프로그램 프레임워크 : 실버라이트
    * 웹 서버 프레임워크 : ASP.NET, ASP.NET MVC
    * 웹 서비스 프레임워크 : WCF
    * GUI 개발 (윈도 폼, WPF)
    * 웹 개발 (ASP.NET, ASP.NET MVC)
    * 게임 개발(**유니티** 등장 -> C# 영향력 커짐)
    * IoT 개발

    * 컴퓨터 구성요소 (.NET Framework는 App를 비집고 들어가서 App와 OS 사이에 위치한다.
    
      | User-사용자 (App) |
      |:---:|
      | OS(Windows) |
      | BIOS |
      | Hardware|
 
  * .NET Framework 버전별 기능
    * .NET 2.0부터 본격적으로 현재의 틀, 64비트 플랫폼을 지원한다.
    * .NET 3.5부터 윈도우 10 지원
    * .NET 4.5
      * 64비트 플랫폼에서 2GB보다 큰 배열 지원 => integer를 넘어서는 long long인 64비트를 지원한다는 의미
        * 2GB = 31bit (int와 비슷)
      * 콘솔에서 유니코드(UTF-16) 인코딩 지원
        * UTF-8보다 범위가 더 넓다. (utf-8 : 1 ~ 3byte / utf-16 : 1 ~ 4byte)

* 프로그래밍 기초
  * 기본 자료형 -> GetType()
    * 참고 : C#에서의 char은 C/C++의 char과 달리 문자에서는 2byte이다! (주의)
    * 즉, C#에서 char은 문자라는 것을 강조한다. 그리고 C/C++과 달리 C#에서의 char은 문자열만 처리한다.
      * 변수간의 제약사항이 C/C++보다 더 타이트해졌다.
    
    | 자료형 | 설명 |
    |:---:|:---:|
    | int| 정수(4byte)|
    |long|정수(8byte)|
    |float|실수(4byte)|
    |double|실수(8byte)|
    |char|문자(c#에서는 2byte)|
    |string|문자열|
    |bool|불|

  * Var 키워드 : 초기화할 때 자료형을 자동으로 지정. 선언과 동시에 초기화
    * 비정형 데이터이다. (이유 : 똑같은 var타입인 변수인데, 지정한 숫자 형태에 따라 자료형을 지동으로 지정할 수 있다.)
    * 중요한 것 : 선언과 동시에 초기화, 초기화할 때 자료형을 자동으로 지정한다는 것. -> 잘못하면 오류가 발생할 수도 있다.
    * 그래서 Var 키워드보다 자료형을 지정하는 것을 추천 (Var : 간편함, 관리하는 데는 불편)
      * <pre>자료형[] 이름 = {자료, 자료}</pre>

  ```C#
  Static void Main(string[] args)
  {
      var number = 20;
  }
  ```

  * 자료형 변환 메서드
  
  | 자료형 변환 | 방법 (parsing) |
  |:--:|:---|
  | 문자열 -> 숫자 | int.Parse(), double.Parse()|
  |다른 자료형 -> 문자열 | ToString() |
  | 문자열 -> 불 | bool.Parse()|
  
  ```C#
  // example.cs
  int.Parse("123")  // => 숫자 123됨
  int.Parse("3.14") // => 실수 3.14됨
  ```
  
  * C#의 복합 대입 연산자, 증감 연산자, 삼항 연산자, 조건문, 반복문 -> C, Java와 동일하다.
    * C#에서 반복문 추가된 것 : for, foreach(배열 처리할 때 유용)

  * 키 입력 메서드 : ReadKey()

* 클래스
  * 클래스 - C++의 클래스와 동일
  ```C#
  //Test(클래스) test(인스턴스) = new(New 키워드) Test() (생성자)
  
  class Test
  {
      public string name = "default;
      public int number = 1000;
  }
  ```
    * C#은 인스턴트를 생성할 때 값을 초기화할 수 있는 기능이 있다.
    * 다만 C++과 다르게 C#에서 클래스 안에서는 public, private, protected를 하나의 멤버변수마다 일일이 다 지정해 주어야 한다.

  ```C#
  Ramdom random = new Random();
  List <>list = new list<>();
  Math.abs(5);
  
  ```
  
  * 메서드의 기본 형태 (class의 멤버변수)
    ```C#
    //[접근 제한자] [반환형] [메서드 이름] ([매개변수])
    //{
    //          [메서드 코드]
    //}
    ```
    * 클래스 이름으로 곧바로 사용하는 변수와 메서드 -> 클래스 변수클래스 메서드 (static 키워드)

  * 생성자
    ```
    Public [클래스 이름] ([매개 변수])
    {
    
    }
    ```
    * 이름은 클래스 이름과 같게
    * 인스턴스 변수를 초기화...
    * (후에 필기)

  * 소멸자 

  * C#의 자료형 (class)
    * 값 : int/float 등 기본 자료형 : 변수 자체에 객체의 값이 들어감
    * 참조 : 클래스로 만들어진 인스턴스 : 객체의 메모리 위치를 나타내는 참조가 들어감

  * 객체 지향 언어
  * is / as
  * 이름 재사용
  * 상속과 오버라이딩 제한 (가급적 쓰지 않는 것이 좋다.)
    * virtual : 가상함수 (필요한 경우를 제외하고 가급적 사용하지 않는 것을 권장)

* 클래스 심화
  * 제네릭 <> : 클래스 내부의 자료형에 별칭을 저장하는 기능 (매크로 + 오버로드)
    ```C#
    class Test<T>
    {
      public T Value;
      public Wanted(T value)
      {
        this.Value = value;
      }
      
    class Program
    {
      static void Main(string[] args)
      {
        // 제네릭을 사용해 변수 Value의 자료형을 원하는 자료형으로 지정
        Test<string> testString = new Test<string>("String");
        Test<int> testInt = new Test<int>("Int");
        
        Console.WriteLine(testString.Value);
        Console.WriteLine(testInt.Value);
      }
    }
    }
    ```

  * out 키워드 (포인터 대신 사용)
    * C#은 메서드를 호출 후 반환시 하나의 값만 반환
    * 값을 여러 개 반환하고 싶은 경우 사용
    * 매개변수로 넣은 변수에 값을 넣어줌

    * 값 : 변수 자체에 객체의 값이 들어감
    * 참조 : 객체의 메모리 위치를 나타내는 참조가 들어감
    * Out 참조
      * 객체의 메모리 위치를 나타내는 참조가 들어감
      * 참조할 변수를 초기화 할 필요가 없다는 점에서 참조와 차이가 있다.

  * 구조체 (C#에서는 구조체가 쉽지 않다.)
    * 상속 불가능
    * 매개변수 없는 생성자 선언X(자동으로 생성)
    * 선언과 동시에 멤버변수를 초기화할 수 없음
    * 값 복사가 이루어짐

    ```C#
    struct Test
      {
        public int x;
        public int y;
        public string test = "test";  // 오류 발생 : 선언과 동시에 초기화 불가능 (클래스가 아니므로)
        public Test(); // 오류 발생
      }
    ```

* 예외 처리 (세상엔 악질 사용자가 많으므로... 돌발 상황에 예측을 하여 대비를 할 수 있어야 한다.)
  * 예외 처리 : 프로그램이 실행되는 동안 발생하는 오류를 예외라고 하는데, 이러한 예외에 대처하는 방법을 의미한다.
  * 이때 사용하는 것이 try ~ catch를 사용해서 예외 처리를 진행한다.

  * 예외 객체 : exception, 모든 예외를 처리할 수 있음
  * 예외 강제 발생 : throw 키워드를 사용하여 무조건적으로 예외를 발생시키는 것
  
  ```C#
  class Program
  {
    static void Main(string[] args)
    {
      Console.Write("숫자 입력 : ");
      string test = Console.ReadLine();
      
      Console.WriteLine(int.Parse(test));   // 문자 입력 시 예외 발생
    }
  }
  ```

  ```C#
    class Program
  {
    static void Main(string[] args)
    {
      Console.Write("숫자 입력 : ");
      string test = Console.ReadLine();
      
      // try ~ catch문
      try
      {
        // try : Main, 예외 발생
        Console.WriteLine(int.Parse(test));
      }
      catch(Exception exception)  // 예외 객체 exception
      {
        // catch : 오류 발생시 동작
        Console.WriteLine("예외 발생!!");
        Console.WriteLine(exception.GetType());
      }
      finally
      {
        // finally : 종료할 때 에러 여부와 상관없이 무조건 수행
        Console.WriteLine("프로그램 종료");
      }
    }
  }
  ```

* 델리게이트와 람다
  * 델리게이트 
    * 메서드를 참조하는 변수
    * C++의 함수 포인터와 비슷 -> 함수의 별명이라고 생각하면 된다.
      * ```(*func)() = sub``` -> 함수
    * 메서드를 대신해서 호출(메서드의 대리인)
    * [접근 제한자] delegate [반환형] [델리게이트 이름]([매개변수]);
    * 델리게이트를 사용할 때 invoke 호출자를 사용해야 한다.

    * 사용처 : 쓰레드(Thread)를 다룰 때가 있다. 하나의 thread에서 다른 form에 변수를 넣는다던지 access할 때 direct로 허용이 불가능한데, 이 때 사용
      * 즉, 네트워크 프로그래밍을 진행할 때
      
      ```C#
      class Program
      {
        public delegate int mydelegate(int a, int b);
        
        public static int plus(int a, int b) {return a+b;}
        public static int minus(int a, int b) {return a-b;}
        
        static void Main(string[] args)
        {
          mydelegate calculate;
          
          calculate = new mydelegte(plus);
          Console.WriteLine(calculate(11, 3));
          
          calculate = new mydelegate(minus);
          Console.WriteLine(calculate(11, 3));
        }
      }
      ```

  * 무명 델리게이트와 람다
    * 무명 델리게이트 : 무명 메서드를 참조

    * 람다
      * 델리게이트를 짧게 쓰는 방식
      * 매개변수의 자료형을 지정할 필요가 없다.

  * 일반화 델리게이트
  * 콜백 메서드
    * 델리게이트를 사용하여 구현
  
  * 델리게이트 체인

* Linq
  * Linq (Database Style로 DB관리 가능, 배열 객체 조작)
    * 조건에 맞는 데이터 추출
    * C# 객체의 집합 쉽게 관리가 가능하다.
    * SQL 서버와 함께 연동하여 DB관리 가능
    * 하지만 DB를 다룬다면 SQL과 비슷하게 해야 한다고 생각하지만, 다른 점이 있기 때문에 잘 사용하지 않는 것으로 보인다.
    
    ```C#
    class Program
    {
      static void Main(string[] args)
      {
        List<int> num = new List<int>() {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};  // 리스트 제네릭으로 구성되어 있다.
        
        // 밑은 SQL문과 유사하다.
        var output = from item in num
                    where item > 5
                    orderby item descending
                    select item;
                    
        // 위를 SQL문으로 바꾼다면
        // select * from num where item > 5 orderby item desc
        
        foreach(var item in output)
        {
          Console.WriteLine(item);
        }
      }
    }
    ```
    
    ```
    // 결과
    10
    9
    8
    7
    6
    계속하려면 아무 키나 누르십시오 . . .
    ```
    
  * 익명 객체
  * 클래스 활용
    * C#은 무조건 클래스이다. 클래스에서 시작하여 클래스로 끝나기 때문. 그 이유는 Program 클래스로 시작하기 때문
    * 프로그램 진입점 : Class Program -> static void Main(string[] args) (class -> main)

* C#은 Form 기반이다.  

# C/# 객체지향
* 
    
    
    
