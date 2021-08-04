* printf 함수는 서식 지정이 가능하다. 
  - printf의 f은 "formatted"를 의미한다.
  - 서식 지정 : 출력의 형태를 지정한다는 의미 (ex; 문자열 안에 숫자 삽입)
  - 서식 지정의 예
  <pre>
  <code>
  #include <stdio.h>
  //#include <stadafx.h>
  
  int main(void)
  {
      int age = 12;
      printf("10진수로 %d살이고 16진수로 %x살 입니다.", age, age);
      return 0;
  
  }
  </code>
  </pre>
