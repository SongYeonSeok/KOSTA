# 3. C언어의 분기문 / 반복문
- 알고리즘 구현하는 가장 핵심적인 명령어
- 종류는 많지 않다. 하지만 연습이 중요
- 유행에 따르는 것보다 기초가 최고다. 뭐든지 안되면 기초로 돌아가보자.
- C언어는 free format이므로, 자유롭게 한 줄에 모든 코드를 작성해도 되고, 여유롭게 해도 된다. 하지만, 코드리뷰 등 코드를 봐야할 경우가 많으므로 '클린 코드'를 위해 시각적으로 잘 알아볼 수 있도록 노력해야 한다.

## 7장. 다양한 형태의 반복문
- 뺑뺑이는 컴퓨터에게!

* 반복문의 기능 : 특정 영역을 특정 조건이 만족하는(수행 조건) 동안에 반복 실행하기 위한 문장
* 세 가지 형태의 반복문 : while, do-while(사용 x), for
  * while문에 의한 반복
  	- while문의 기본 원리와 의미
  	    - 반복 조건이 거짓일 때 반복문을 빠져나갈 수 있다.
  	```c
	while(반복 조건) 	    // 반복 조건 : 조건식이 들어감. 
	    			// 반복 조건이 참(true, 1, !0)일 때 반복문 구간 실행
	{	                // 다른 언어에서는 'true'만 인정한다(이렇게 생각해두기). 
				// 그래서 C언어가 다른 언어에 비해 유연한 면이 있다.
	        반복 내용
        // "반복의 조건"이 만족되는 동안
        // "반복 내용"을 반복 실행하라.
	}
	```
        
	<pre><code>
        // example.c
        while(i<10)
        {
            printf("Hello World!\n");
            i++;
            
            // i<10이 만족되는 동안
            // printf()와 i++를 반복 실행하라.
        }
        </code></pre>
    
    * while문의 중괄호
        - 반복하고자 하는 영역이 둘 이상의 문장으로 구성되는 경우에 필수
        - 단일 문장일 경우, 생략은 가능하다. 단, 시각적으로 불편하지 않는다는 경우에 한해서이다.
        ```c
        while (i < 10)
        {
            printf("Hello World!\n"),i++;       // 콤마(,) ≒ 세미콜론(;) but, 문장의 끝은 아니다.
                                                // 문장 자체로는 단일 문장으로 인식되기 때문에
                                                // 중괄호가 생략이 될 수 있었던 것 (컴파일러가 속아 넘어간 것)
                                                // 사용하면 욕먹는다. (절대 권장하지 않음)
        }    
        ```
    
    - 무한 루프(반복)
        - 반복의 조건으로 true가 오면 발생
        ```c
        while(1)    // 반복의 조건 대신 0이 아닌 정수를 넣는다.
        {
            printf("Hello World!\n");              
            i++;
        }
        ```
        - 무한루프의 예시
            - 의도하지 않게 무한루프가 발생할 수도 있다. 조심해야 한다.
            - 만약 의도하고 사용했다면 좋은 것이고, 그렇지 않을 때 벗어나려면, ctrl + C 사용!
            
        ```c
        // example2.c
        #include <stdio.h>
        #include <conio.h>
        
        int main()
        {
            char name[20];
            int age, height;
            
            while(1) //무한 루프, 프로그래머는 의도한 대로 나갈 수 있도록 주의
            {
                printf("당신의 이름은 무엇입니까?");
                scanf("%s", name);
                
                printf("당신의 키를 cm단위로 입력하세요. \n 당신의 나이도 입력해주세요.");
                scanf("%s", &height, &age);
                
                printf("안녕하세요. \n %s 씨\n", name);
                printf("반갑습니다.\n");
                printf("저는    %5d 살이에요.\n", age);
                printf("제 키는  %d cm이에요.\n", height);
                printf("제 키는 %.2f m이에요.\n", (float)height / 100.0);
                
                // 무한 루프
            }
            
            getch();
            return 0;
            
        }
        ```
        
        ```c
        // example3.c
        #include <stdio.h>
        #include <conio.h>
        
        int main()
        {
            char name[20];
            int age, height;
            int index = 2;  // while문 수행 횟수 정의
            
            while(index > 0)    // 2 >0으로 항상 true여서 무한 루프가 된다.
            {
                printf("당신의 이름은 무엇입니까?");
                scanf("%s", name);
                
                printf("당신의 키를 cm단위로 입력하세요. \n 당신의 나이도 입력해주세요.");
                scanf("%s", &height, &age);
                
                printf("안녕하세요. \n %s 씨\n", name);
                printf("반갑습니다.\n");
                printf("저는    %5d 살이에요.\n", age);
                printf("제 키는  %d cm이에요.\n", height);
                printf("제 키는 %.2f m이에요.\n", (float)height / 100.0);
                

            }
            
            getch();
            return 0;
        }    
        ```
        
    - 무한 루프에 빠지지 않으려면? 다음을 확인해야 한다.
        1. **index 지정**
        2. **수행 조건**
        3. **증감**
        - 이러한 것들을 묶어 놓은 것이 for문이다.

        ```c
        // 성공적인 예시
        #include <stdio.h>
        #include <conio.h>
        
        int main()
        {
            char name[20];  
            int age, height;
            int index = 2;  // while 문의 수행 횟수를 정의

            while (index > 0) 
            {
                printf("당신의 이름은 무엇입니까?");
                scanf("%s", name);

                printf("당신의 키를 cm단위로 입력하세요. \n 당신의 나이도 입력해주세요.");
                scanf("%d %d", &height, &age);

                printf("안녕하세요. \n %s 씨\n", name);
                printf("반갑습니다.\n");
                printf("저는    %5d 살이에요.\n", age);
                printf("제 키는 %d  cm이에요.\n", height);
                printf("제 키는 %.2f m이에요.\n", (float)height / 100.0);

                index--;
            }

            getch();
            return 0;

        }

        ```
        
    - while문의 중첩
        - while문 안에 while문을 포함시킨다는 뜻
        - 반복 구조 내에서 또 하나의 반복 구조 형성
        
        ```c
        #include <stdio.h>
        
        int main()
        {
            int i = 0, j = 0;
            int num = 0;
            
            while (i<10)		// 외부 루프
            {
                while (j<10)	// 내부 루프
                {
                    num++;
                    j++;
                }
                i++;
                j=0;
            }
        }
        
        ```
        
    - while문의 순서도
        - ![image](https://user-images.githubusercontent.com/49339278/128297813-b0278045-aad4-4376-9b3c-b2862acc900a.png)

        
  * do - while문에 의한 반복 (while문의 한 part!, 실제로 잘 쓰이지 않음)
    - do ~ while문과 while문의 차이점
        - do ~ while문은 일단 한 번 실행하고 나서 조건 검사를 진행
            - ![image](https://user-images.githubusercontent.com/49339278/128297880-0f96b2fe-f022-4149-8885-a88b3639f102.png)

        - do ~ while문의 순서도
            - ![image](https://user-images.githubusercontent.com/49339278/128297903-0978c283-0c15-42c7-adbb-c62c472a8e29.png)

  * for문에 의한 반복 (가장 많이 사용됨)
    - 기본 원리와 의미
        - 초기, 조건문, 증감문 모두를 기본적으로 포함
        - 가장 많이 사용되는 반복문
        - ![image](https://user-images.githubusercontent.com/49339278/128298011-95d63c27-16a4-49d5-883d-0d562de1762f.png)
        
        - while문과 for문 차이
            - ![image](https://user-images.githubusercontent.com/49339278/128298110-4cca562d-17b4-4bf2-8e97-a1c84596bb5f.png)
            - while문 : 선 비교, 후 실행 (A형 인간)
            - for문: 선 실행, 후 비교(B형 or O형 인간)

    - while문 처럼 인덱스, 수행조건, 증감을 일일이 지정할 필요 없이 반복 조건에 한 곳에 지정 가능하다.
    ```c
    #include <stdio.h>
    #include <conio.h>

    int main()
    {// ctrl + c
        char name[20];  
        int age, height;
 
        for (int index = 0;index < 2; index++) // index  수행조건    증감
        {
            printf("당신의 이름은 무엇입니까?");
            scanf("%s", name);

            printf("당신의 키를 cm단위로 입력하세요. \n 당신의 나이도 입력해주세요.");
            scanf("%d %d", &height, &age);

            printf("안녕하세요. \n %s 씨\n", name);
            printf("반갑습니다.\n");
            printf("저는    %5d 살이에요.\n", age);
            printf("제 키는 %d  cm이에요.\n", height);
            printf("제 키는 %.2f m이에요.\n", (float)height / 100.0);

        }

        getch();
        return 0;

    }
    ```
    
    ```c
    // 2단 - 1
    #include <stdio.h>
    #include <conio.h>

    int main()	// C/C++는 필수적으로 작성해야 한다.
    {
	    int dan = 2;	// 구구단의 2단
	    int nDan = 9;	// xx단 : 9

	    for (int idx = 1; idx <= nDan; idx += 1)	// ++는 1씩 증가
    //  for (int idx = 1; idx < nDan + 1; idx++)	// 위와 같은 방식(위의 방식이 편리할 때가 많다.)
    // 		
							// 프로그래머는 한 가지 방법이 아니라 여러 가지 방법을 사용하도록 해보자.
	    {
		    // 임계 조건 : nDan은 9로 주어졌으므로, 결과도 nDan까지 나올 수 있도록 해야 한다.
		    printf("%d x %d = %2d\n", dan, idx, dan * idx);	// 2 x 2 = 4	dan x idx = (dan * idx)
			    					// 결과값이 2자리수이기 때문에, 큰 자릿수로 바꿔야 한다. %2d로 지정
	    }
        
        getch();        // 오류가 발생할 경우, 프로젝트 -> 속성 -> C/C++ -> sdl속성 아니오 지정
        return 0;
    }
    ```
    
    ```c
    
    // 2단 - 2
    #include <stdio.h>
    #include <conio.h>
    
    int main()
    {
        int dan = 1;
        int nDan = 9;
        
        for (int idx = 1; idx <= nDan; idx++)
        {
            printf("%d x %d = %2d       ", dan, idx, dan * idx);
            printf("%d x %d = %2d       ", dan+1, idx, (dan+1) * idx);
            printf("%d x %d = %2d       ", dan+2, idx, (dan+2) * idx);
            printf("%d x %d = %2d       ", dan+3, idx, (dan+3) * idx);
            printf("%d x %d = %2d\n", dan+4, idx, (dan+4) * idx);
        }
        
        printf("\n");
        dan = 6;
        for (int idx = 1; idx <= nDan; idx++)
        {
            printf("%d x %d = %2d       ", dan, idx, dan * idx);
            printf("%d x %d = %2d       ", dan+1, idx, (dan+1) * idx);
            printf("%d x %d = %2d       ", dan+2, idx, (dan+2) * idx);
            printf("%d x %d = %2d\n", dan+3, idx, (dan+3) * idx);
        }
        getch();
        return 0;
    }
    ```
    
    ```c
    // 2단 - 3 (for문 중첩)
    #include <stdio.h>
    #include <conio.h>
    
    int main()
    {
        int dan, nDan = 9;
        
        for (dan = 2; dan < 10; dan += 4)
        {
            for (int idx = 1; idx <= nDan ; idx++)
            {
                printf("%d x %d = %2d       ", dan, idx, dan * idx);
                printf("%d x %d = %2d       ", dan+1, idx, (dan+1) * idx);
                printf("%d x %d = %2d       ", dan+2, idx, (dan+2) * idx);
                printf("%d x %d = %2d\n", dan+3, idx, (dan+3) * idx);
            }
            printf("\n\n\n");
        }
        getch();
        return 0;
    }
    ```
    
    * 프로그래밍할 때 중요한 것
        - ** 중복되는 것을 최소화! **
        - 결과물은 같더라도, 코드는 모두 다르다! 코드 구조가 같더라도, 변수의 이름은 같을 수가 없다. 따라서 자신이 편한 방식과 효율적인 코드 방식을 사용해야 한다.
        - 상수, 설정값들을 위에 정의시켜 놓고, 초기갑과 여러 설정값들을 미리 설정하고, 그 외의 구간에 숫자를 입력하지 않도록 하자.(권장! 잘하면 프로그래머로서 좋다.)
            * 이유 1 : 디버깅할 때 굉장히 유리하다. (값을 수정할 때 변수 하나만 변경하면 다 변경이 가능하니까, 수정 및 작업 시간이 줄어든다.)
            * 이유 2 : 코딩 시에 유연성 증가
            * 따라서 가급적 상수를 많이 사용하지 않도록 하자.
        
    ```c
    // 2단 4열 구구단
    #include <stdio.h>
    #include <conio.h>
    
    int main()
    {
        int i, j, k;        // 이렇게 먼저 자료형을 선언하는 방식을 사용하는 것이 좋다.
        int dan = 2;        // 구구단의 2단 ~ 9단
        int nDan = 9;       // xx단 : 9
        
        for (dan = 2; dan < 10; dan += 4)
        {
            for (int idx = 1; idx <= nDan; idx++)
            {
                for (i = 0; i < 4; i++)
                    /* i<4도 반복 조건이지만, 탈출 조건도 가능하다. (초기값과 종료값을 주의하자.)
                    4와 같은 상수를 반복문에 안 쓰는 것이 유연성을 높이는 길이다.
                    4는 가로 방향 열 수를 의미
                    */
                {
                    printf("%d x %d = %2d       ", dan+i, idx, (dan+i) * idx);
                }
                printf("\n");
            }
            printf("\n\n\n");
        }
        getch();
        return 0;
    }
    ```
    
    ```c
    // 3단 3열 구구단
    #include <stdio.h>
    #include <conio.h>
    
    int main()
    {
        int i, j, k;
        int dan, nDan = 9;          // nDan : xx단 (9)
        int hDan = 3;               // hDan : 가로 방향 열의 개수
        
        for (dan = 1; dan <= nDan; dan += hDan)
        {
            for (int idx = 1; idx <= nDan; idx++)
            {
                for (i = 0; i < hDan; i++)
                {
                    printf("%2d x %2d = %3d     ", dan+i, idx, (dan+i) * idx);
                }
                printf("\n");
            }
            printf("\n\n\n");
        }
        getch();
        return 0;
    }
    ```
    
    ```c
    // 구구단.c
    #include <stdio.h>
    #include <conio.h>
   
    int main(void)
    {
        for(int i = 1; i <= 9; i++)
        {
            for(int j = 1; j <=9; j++)
            {
                printf("%d x %d = %2d\n", i, j, i * j);
            }
            printf("\n");   // 구분점
        }
        
        getch();
        return 0;
    }
    ```
    
    * 반복 과정의 이해
        - ![image](https://user-images.githubusercontent.com/49339278/128298182-505318c3-2699-429e-8cd1-7c3a9d4e98df.png)
        
    - 비주얼 스튜디오 
       
## 8장. 조건에 따른 흐름의 분기 (= if - else문)
* 조건문이 먼저인가? 반복문이 먼저인가? 이것은 사람마다 다르므로, 편한 거를 사용하면 된다.
- c언어의 조건문 유형
    - if ~ else
    - switch
    - 삼항 연산자(조건 연산자)

* 상황에 따른 프로그램의 유연성 부여
    - ![image](https://user-images.githubusercontent.com/49339278/128298779-f2345aaa-23fb-497b-b8dd-1fcbda79c001.png)

* if문에 의한 조건적 실행
    - 조건이 만족되는 경우에 한해서 실행
    - for문과 다르게, 실행의 조건에 따라 1번만 수행된다.
    ```c
    if (실행의 조건)
    {
        실행하고자 하는 내용 // '실행의 조건'이 만족되는 경우 '실행하고자 하는 내용'을 실행한다.
                             // 만족되지 않으면 건너뛴다.
    }
    ```

* if ~ else에 대해서
    - 단점, 불필요한 연산을 하게 된다.
    ```c
    if (조건 )    // "조건"이 만족되는 경우 "이거" 실행, 만족되지 않으면 "저거" 실행
    {
        조건 만족 시 실행 ; "이거"
    }
    else
    {
        조건 불만족 시 실행 ; "저거"
    }
    ```
    
* if, else if, else
    - 무분별하게 사용하면 lost(불필요한 지연과 연산)이 많다. 꼭 필요한 경우가 아니면 사용하지 말자.
    - if ~ else문은 하나의 문장이다.
    - if ~ else문의 중첩된 형태에 지나지 않는다.
    - ![image](https://user-images.githubusercontent.com/49339278/128300701-89857bf3-80d6-4778-99a9-06c582f9c416.png)

* switch문
    - 조건문의 n은 꼭 반드시 정수 값이어야만 한다는 뜻이다. (int, long, char 가능, float, double, 문자열 불가능)
    - if ~ else문에 비해서는 제한적이다. 그런데도 switch문을 사용해야 하는 경우가 종종 있다.
    - ![image](https://user-images.githubusercontent.com/49339278/128301100-68e13d1e-a54b-4804-b97e-1817c2260a46.png)

* switch문에서 break문의 의미
    - ![image](https://user-images.githubusercontent.com/49339278/128302559-d749bd30-ccd5-4261-a064-1f5c82c569e2.png)

* 조건 연산자(삼항 연산자)
    - if~else 문을 간결히 표현하는 데 사용될 수 있다.
    - 조건? A : B
        - 조건이 true인 경우 A를 반환
        - 조건이 false인 경우 B를 반환
    - X = (y<0)? 10:20;
        - 'y<0'이 true면 10이 반환되어 x에 대입
        - 'y<0'이 false면 20이 반환되어 x에 대입
    - x = (y>0)? a*b : a/b;
        - 'y>0'이 true면 a*b 연산결과를 x에 대입
        - 'y>0'이 false면 a/b 연산결과를 x에 대입
        
* break : 반복문을 빠져 나올 때 사용 (무한 루프에서 사용). 일종의 반복문 탈출 (많이 쓰임)
	* 참고 : break문은 while문과 switch문에서 사용 가능하다.
* continue : 다음 번 반복으로 넘어갈 때 사용 (무한 루프에서 사용). 나머지 루프를 건너뛰고 다시 루프 반복한다.
    - ![image](https://user-images.githubusercontent.com/49339278/128301329-27edc021-a838-440b-b15d-79b91eda66c1.png)

* switch vs if ~ else
    1. 분기의 경우, 수가 많아지면 가급적 switch문 사용한다.
        - ![image](https://user-images.githubusercontent.com/49339278/128302625-62bd3d96-47cf-4589-b65c-abe382236980.png)

    2. switch문에서는 비교 연산이 올 수 없다.
        - ![image](https://user-images.githubusercontent.com/49339278/128302707-f2480649-fe0e-4d46-bbcb-e5227e3a5dc1.png)
        
* GOTO label 문 (사용하지 말기)
    * 프로그램의 흐름을 복잡하게 한다.
    * C 프로그래밍은 절차적인 프로그래밍으로, 주의해서 사용하거나 가급적 사용하지 말자. (에러가 발생하였을 때, 비상상황에서 사용)
    * 잘못 사용하게 되면, 중구난방인 상태가 올 수 있다.
    * ![image](https://user-images.githubusercontent.com/49339278/128302758-f83574e9-6f2c-4535-9c6d-d66915076fd4.png)


* 새로운 컴퓨터 언어가 개발되는 이유 : 새로운 흥미 유발 + 새로운 시장 창출 목적
    - 많이 띄울려고 노력하고 있다. 그렇게 해야 새로운 시장이 창출이 가능하다.
    - 새로운 언어를 만들 때 가장 많이 참조되는 언어가 C언어이다.
    
* 실습 문제
    1. if문을 이용해서 숫자 키를 누르면 해당하는 영어 단어을 출력하는 프로그램을 작성하여라.
        - 만일 숫자 키 외의 키를 누르면 프로그램을 종료하세요.
        - 0을 누르면 프로그램을 종료하세요.
        - ![image](https://user-images.githubusercontent.com/49339278/128302998-982e4e24-e855-44a2-99a1-9b049fa00b93.png)
        ```c
        #include <stdio.h>
        #include <conio.h>
        
        int main()
        {
            int num;    // 입력되는 숫자
            
            while (1)
            {
                printf("숫자를 입력하세요: ");
                scanf("%d"
                // scanf_s("%d", &num);     // visual studio에서 scanf가 사용 안될 때 사용
                if (num == 1)       {printf(">1 : One\n");    break;}
                else if (num == 2)  {printf(">2 : Two\n");    break;}
                else if (num == 3)  {printf(">3 : Three\n");  break;}
                else if (num == 4)  {printf(">4 : Four\n");   break;}
                else if (num == 5)  {printf(">5 : Five\n");   break;}
                else if (num == 6)  {printf(">6 : Six\n");    break;}
                else if (num == 7)  {printf(">7 : Seven\n");  break;}
                else if (num == 8)  {printf(">8 : Eight\n");  break;}
                else if (num == 9)  {printf(">9 : Nine\n");   break;}
                else break;
            }
            /* if-else문에서 들여쓰기는 시각적 목적으로 사용하는데, 들여쓰기 하지 않더라도 구조만
               간단하다면 들여쓰기 하지 않아도 된다.*/
        }
        ```
        
        * 참고 (scanf, scanf_s의 차이점)
            - 비쥬얼 스튜디오를 사용하게 되면 SDL로 인해 scanf()사용할 때 오류가 발생한다.
            - 해결방법 1 : 프로젝트 -> 속성 -> C/C++ -> SDL 아니오 설정
            - 해결방법 2 : scanf 대신 scanf_s 사용
            - 해결방법 3 : #include <stdio.h>와 함께 #define_CRT_SCURE_NO_WARNINGS를 작성하면 된다.
            
        * scanf_s 사용 방법
            1. 문자 1개를 입력받을 때
            2. 문자열 입력받을 때
            3. 정수 숫자 입력받을 
        
    2. 1번 문제는 switch ~ case 문을 이용해서 작성하여라.
        	
		```c
		
       	 #include <stdio.h>
		#include <conio.h>
	
		int main()
		{
			int num;	// 입력받을 숫자
		
			printf("숫자를 입력하세요: ");
			scanf("%d", &num);
			// scanf_s("%d", &num);		// scanf 안될 때 사용한다.
		
			switch(num)
			{
			case 1 : printf(">1 : One\n");		break;
			case 2 : printf(">2 : Two\n");		break;
			case 3 : printf(">3 : Three\n");	break;
			case 4 : printf(">4 : Four\n");		break;
			case 5 : printf(">5 : Five\n");		break;
			case 6 : printf(">6 : Six\n");		break;
			case 7 : printf(">7 : Seven\n");	break;
			case 8 : printf(">8 : Eight\n");	break;
			case 9 : printf(">9 : Nine\n");		break;
			default : break;
			}
		
		getch();
		return 0;
		
		}
        	```
        
        
