## Chapter 07-1. 상속(Inheritance)
* parent => child, derived (간단, 단순, 기본) -> 복잡, 다기능
* 문제의 제시를 위한 시나리오의 도입
  * PermanentWorker는 정규직을 표현해 놓은 클래스이다.
    ```c++
    class PermanentWorker
    {
    private:
      char name[100];
        int salary; // 매달 지불해야 하는 급여액
    public:
      PermanentWorker(char*name, int money) : salery(money) //이니셜라이저 생성, char 배열형태
      {
        strcpy(this-> name, name); // 배열이므로 C의 strcpy 함수를 사용할 수밖에 없음
      }
      int GetPay() const
      {
        return salary;
      }
      void ShowSalaryInfo() const
      {
        cout<<"name: "<<name<endl;
        cout<<"salary: "<<GetPay()<<endl<<endl;
      }
    };
    ```
  * 프로그램 전체 기능의 처리를, 프로그램의 흐름을 담당하는 클래스를 가리켜 컨트롤 클래스라고 한다.
  * EmployeeHandler의 경우 컨트롤 클래스에 해당한다.
    ```c++
    class EmployeeHandler
    {
    private:
      PermanentWorker* empList[50]; // 포인터는 그 데이터의 주소를 말함
      int empNum;
    public:
      EmployHandler() : empNum(0)
      {  }
      void AddEmployee(PermanentWorker* emp)
      {
        empList[empNum++]=emp;  // 신규 직원 등록시
      }
      void ShowAllSalaryInfo() const
      {
        for (int i = 0;i<empNum;i++)
          empList[i]->ShowSalaryInfo();  // 전체 급여정보 출력
      }
      void ShowTotalSalary() const
      {
        int sum = 0;
        for (int i = 0; i < empNum; i++)  // 급여 합계정보 출력
          sum+=empList[i]->Getpay();
        cout<<"salary sum: "<<sum<<endl;
      } 
      ~EmployeeHandler()  
      {
        for(int i=0;i<empNum;i++)
          delete empList[i];
      }
      
    }
    ```
    * 신규 직원 등록시, 전체 급여정보 출력, 급여 합계 정보 출력 등

* 문제의 제시
  * 프로그램에 추가할 직급의 형태
    * 영업직(Sales) : 조금 특화된 형태의 고용직. 인센티브 개념이 도입
    * 임시직(Temporary) : 학생들을 대상으로 하는 임시고용 형태, 흔히 아르바이트라고 한다.

  * 확장 이후의 급여지급 방식
    * 고용직 급여 : 연봉제! 따라서 매달의 급여가 정해져 있다.
    * 영업직 급여 : '기본급여 + 인센티브'의 형태
    * 임시직 급여 : '시간당 급여 * 일한 시간'의 형태
  
  * 이 문제는 영업직과 임시직에 해당하는 클래스의 추가로 끝나지 않는다. 
컨트롤 클래스인 EmployeeHandler클래스의 대대적인 변경으로 이어진다.

  * 좋은 코드는 요구사항의 변경 및 기능의 추가에 따른 변경이 최소화되어야 한다. 그리고 이를 위한 해결책으로 상속이 사용된다. 
  
* 상속의 방법과 그 결과
* ![image](https://user-images.githubusercontent.com/49339278/130710772-07493b81-b818-4ae0-9df7-bf6d54c9fb69.png)
  * 상속을 시행하면 상위 클래스의 내용들이 하위 클래스에 들어간다는 뜻이다.
  * protect는 상속을 어떻게 하느냐에 따라 드라다.
  * 대학생이라는 class을 선언하기 위해서는 기본적인 클래스를 모든 유저 같은 것을 가져올 수 있는 것을 상속이라고 할 수 있따.
  * 상속의 사용법은 ':' 이니셜라이저로 하는 콜론으로 가져올 수 있다.
  * 특별한 경우가 아닌 이상 public으로 지정한다.
  * 여기서 Person을 상위 클래스, 즉 Parent class, base class라고 부른다. (super class 라는 말은 잘 안쓴다.)
  * UnivStudent을 하위 클래스, drived class(유도 클래스), 자식 클래스라고도 한다. (sub class라는 말은 잘 안씀)

* 상속받은 클래스의 생성자 정의
  * 건물을 지을 때, 기초부터 쌓듯이, 생성자부터 처음 지정한 후에 차근차근 시행한다.
  ```c++
  UnivStudent(char *myname, int myage, char *mymajor)
      : Person(myage, myname)
  {
    strcpy(major, mymajor);
  }
  ```
  * **이니셜라이저를 통해서 유도 클래스는 기초 클래스의 생성자를 명시적으로 호출해야 한다.**
  * 유도 클래스의 생성자는 기초 클래스의 멤버를 초기화할 의무를 갖는다. 단, 기초 클래스의 생성자를 명시적으로 호출해서 초기화해야 한다. 
  ```c++
  int main(void)
  {
    UnivStudent ustdl("Lee", 22, "Computer eng.");
    ustd1.WhoAreYou();
    
    UnivStudent ustd2("Yoon", 21, "Electronic eng.");
    ustd2.WhoAreYou();
    return 0;
  }
  ```
  * 때문에 유도 클래스는 기초 클래스의 생성자 호출을 위한 인자까지 함께 전달받아야 한다.
  * private 멤버는 유도 클래스에서도 접근이 불가능하므로, 생성자의 호출을 통해서 기초 클래스의 멤버를 초기화해야 한다.
    * public으로 해도 사용하는데 지장은 없다. (상속관계에서도 접근 가능여부에 지장을 준다.)

* 유도 클래스의 객체 생성 과정
* ![image](https://user-images.githubusercontent.com/49339278/130712279-b46eb275-b5bf-48ec-aef2-a42427c3c011.png)
  * ![image](https://user-images.githubusercontent.com/49339278/130712506-fe8a59de-5ccf-4c02-8b26-5f4b6aac3e11.png)
  * ![image](https://user-images.githubusercontent.com/49339278/130713161-ea45d8ed-217b-4dd0-bebe-fc3ba83d771b.png)

* case 1
  * ![image](https://user-images.githubusercontent.com/49339278/130713395-220cb14c-4d8a-436a-abf1-4f806277d124.png)

* case 2
  * ![image](https://user-images.githubusercontent.com/49339278/130713411-c38e5951-2556-47d0-8d9f-cd3359ee4eb1.png)


* 유도 클래스 객체의 소멸과정 (=> 생성의 역순)
  * 생성은 기초(처음)부터
  * 파괴는 위에부터
  * 유도 클래스의 소멸자가 실행된 이후에 기초클래스의 소멸자가 실행된다.
  * 스택에 생성된 객체의 소멸순서는 생성순서와 반대이다.
    * FILO(First In Last Out ; 처음에 들어간 것은 나중에 나온다.) <-> LIFO(Last In First Out ; 나중에 들어간 것은 처음에 나온다.)
  * ![image](https://user-images.githubusercontent.com/49339278/130713764-e4d270ac-992b-41b0-b5d6-bda21ec1a91c.png)

* protected로 선언된 멤버가 허용하는 접근의 범위
  * ![image](https://user-images.githubusercontent.com/49339278/130715345-f3d1904c-38be-484c-b8d5-0901758ad761.png)
  * ![image](https://user-images.githubusercontent.com/49339278/130715556-eb6ebbed-533d-47c0-896c-f221ffaa05eb.png)
  * private는 상속을 하던 main이던 함수이던 직접 호출이 불가능하여 컴파일 에러가 발생한다.
  * public는 모든 경우에 직접 호출이 가능하다.
  * protect는 private과 달리 상속관계에서의 접근을 허용하여 컴파일이 가능하다.
  * 이런 것들은 system 모듈(= windows class)에서 많이 볼 수 있는 것들이다. 
    * -> 수정은 할 수가 있지만, 호환성에 문제가 생길 수도 있으므로 함수로 수정하기에는 힘들다. 

* 세 가지 형태의 상속
  * **public 상속** : 접근 제어 권한을 그대로 상속한다! 단, private은 접근 불가로 상속한다. (= 있는 그대로 상속)
    * 실무적으로는 public으로 두는 것이 편리하다.
    ```c++
    class Derived : public Base
    {
     . . . . .
    }
    ```
    * public 이외의 상속 타입은 본 적이 없다고는 한다.
  * protect 상속 : protected보다 접근의 범위가 넓은 범위
    ```c++
    class Derived : protected Base
    {
     . . . . . 
    }
    ```
    * protected보다 접근의 범위가 넓은 멤버는 protected로 상속한다.
    * public는 public대로, protected는 상속을 하는데, 호출은 protected로, 로컬은 public인 경우에 쓸 수 있고,
     외부에서는 쓸 수 없는 형태가 된다. privated는 privated로 상속된다.
  * private 상속 : private 보다 접근의 범위가 넓은 멤버는 protected로 상속한다.
    * 단, private는 접근불가로 상속한다.
    ```c++
    class Derived : private Base
    {
     . . . . .
    }
    ```
    
  * protected 상속과 private 상속
    * ![image](https://user-images.githubusercontent.com/49339278/130716878-ac9c2c57-dbfa-4b6a-9f30-dbe75e2e9194.png)
    * protected 상속에서는 class 내부에선 사용가능
    * private 상속을 하는 것은 무의미할 수 있다. (컴파일러로 이렇게 할 수도 없고, 쓸일이 없기 때문)
      * 만약에 이렇게 된다면, 프로그래머가 실수한 것인게 대부분이고, 1% 미만의 경우는 의도한 것이다.

* 상속의 기본 조건인 IS-A관계의 성립
  * class는 객체라는 것으로, 추상적인 개념이다. 크기를 어떻게 정의하기가 어려운 개념이다.
  * framework에서 사용하는 것들도 객체의 종류 중 하나이다.
  * ~는 ~~ 이다라는 의미
  * class 상속 관계에 적용할 수 있는 부분이다.
  * ![image](https://user-images.githubusercontent.com/49339278/130717340-8b394124-11d6-4b44-8fed-9a188e458bf2.png)

* HAS-A 관계를 상속으로 구성하면
  * ~는 ...를 소유한다.라는 의미
  * 상속 class의 범위에 있는 것이 아니다.
  * ![image](https://user-images.githubusercontent.com/49339278/130717519-0ec52563-f7a1-4937-a2cb-171eadaed5a0.png)

* Manipulators : cout, endl을 사용할 때 포맷을 지정하는 것
  * ```#include <cstdio>```의 printf()문을 사용하면 안해도 된다.

* 8/26 기준 다음주까지 비대면(8/30 ~ 9/3, MFC), 그 후에 9/6부터 대면 수업(9/6 ~ 9/10) 진행 예정
* 내일까지 : c++ 이론 위주
* 다음주 : MFC 과정 진행(윈도우 어플리케이션)
* MFC -> 1주간 주간 프로젝트 진행! (Mini Project) -> 이 기간 동안 강의를 하지 않고 자율적으로 기획 및 제작함
* 9/10 이후로 어떻게 될지는 모른다.
  * 대면으로 mini project -> 1일차 : 계획 -> 계획서 작성 / 2~3.5(3일차 오전)일차 : 개발(계획서에 따라) / 3.5(3일차 오후)~5일차 : 발표자료 제작(PPT), 마지막날 : 발표 실시 및 시연
  * 대면으로 계획잡음, 변수가 있을 시 비대면으로 진행 예정
