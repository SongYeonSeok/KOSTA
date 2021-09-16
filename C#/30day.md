* C#의 배열선언 != C/C++ 배열 선언
  * ```C/C++ : char str[] = "";```
  * ```C# : char[] str = "";```
  * 느낌상으로는 C#은 포인터 자리에 []이 온 것과 같다고 생각하면 편할 수 있다.
  
* 문자열에서 n진법으로 변경을 위해선?
  * C#에서는 문자열에서 n진법으로 바로 바꾸는 것이 쉽지 않다.
  * 그 이유는 C#는 문자열에서 숫자 direct로 변경하는 것을 허용하지 않기 때문
  * C#에서의 변경 과정은 문자열 -> 바이트 -> 숫자 구성 -> n진법 변환
  
* C#의 문자열 처리 법 2가지 존재
  1. ```string str = string.Format("{0} {1}", ○, ●);```
  2. ```string str = $"출력 형식 지정 {변수 입력}";``` -> 마치 python의 f-string과 비슷하다.
    * $ 표기법 더 공부해보기
    * https://docs.microsoft.com/ko-kr/dotnet/csharp/tutorials/string-interpolation
    * $ : 보간 문자열 지시자
  
* enum은 C/C++보다 C#이 빡세졌다.

* Encoding 클래스 : 문자 인코딩을 나타낸다. 
  * 참고 : class, struct, enum을 객체, object라고 부른다.
  * 속성 종류
    * ASCII : ASCII(7비트)
    * Defalut : ANSI(운영체제 기본값)
      * GetBytes : 문자열의 모든 문자를 바이트 시퀀스로 인코딩함
      * GetString : 지정된 바이트 배열의 모든 바이트를 문자열로 디코딩함
    * Unicode
    * UTF8
    
* foreach : 제약 조건이 여러개가 있어서 많이 사용하는 경우도 있고, 그렇지 않은 경우도 있다.
  * 주로 배열이나 컬렉션에 주로 사용된다. 컬랙션의 각 요소를 하나씩 꺼내와서 foreach 루프 내의 블럭을 실행할 때 사용된다.
  ```C#
  foreach (데이터타입 변수 in 배열)
  {
      ...
  }
  ```

  ```C#
  static void Main(string[] args)
  {
      stirng[] array = new string[] { "AB", "CD", "EF" };
      
      // foreach 루프
      foreach (string s in array)
      {
          Console.WriteLine(s);
      }
  }
  ```
  
  * for과 foreach의 차이점
    * C#에서 for, foreach 비교하는 것은 성능적 측면과 가독성 측면을 고려한다.
      * 성능적 측면 : for가 경우에 따라 약간 빠른 경우가 있다. (대부분의 경우 성능 차이는 크지 않다.)
      * 가독성 측면 : foreach는 for보다 훨씬 간결한 코드를 제공한다는 장점이 있다.
      * foreach가 for에 비해 유리한 점
        * 루프에서 가장 많이 사용되는 C# Array의 경우, foreach가 내부적인 최적화를 거쳐 for 루프와 동일한 성능이다.
        * 따라서 foreach를 사용할 것을 권장한다.
        
      * foreach의 단점 : count의 개념이 없다. -> 문자열의 줄바꿈을 구현하기 위해 count를 사용해야 할 경우, 따로 지정해주어야 한다.
      
      * 결과 : 경우에 따라서 foreach, for을 적절하게 사용하자.
      
        ```C#
        static void Main(string[] args)
        {
            // 3차 배열 선언
            string[,,] arr = new string[,,] {
                { {"1", "2"}, {"11", "22"} },
                { {"3", "4"}, {"33", "44"} }
            };
            
            // for 루프 : 3번 루프를 만들어 올림
            for (int i=0;i < arr.GetLength(0); i++)
            {
                for (int j=0; j < arr.GetLength(1); j++)
                {
                    for (int k=0; k < arr.GetLength(2); k++)
                    {
                        Debug.WriteLine(arr[i, j, k]);
                    }
                }
            }
            
            
            // foreach 루프 : 한번에 3차 배열 모두 처리
            foreach (vars in arr)
            {
                Debug.WriteLine(s);
            }
            
            
        }
        
        ```
    
* Windows Form에서 파일 읽고 저장하기
  * 파일 읽기 : openFileDialog 사용 -> StreamReader 클래스 사용, ReadToEnd(), Close() 사용
  * 파일 저장 : saveFileDialog 사용 -> StreamWriter 클래스 사용, Write(), Close() 사용

* C#에서 경로 지정 -> C#의 Path static class 사용하기
  * GetToken 메소드 만들어보기
