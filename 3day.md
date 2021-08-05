# 3. C언어의 분기문 / 반복문
- 알고리즘 구현하는 가장 핵심적인 명령어
- 종류는 많지 않다. 하지만 연습이 중요

## 7장. 다양한 형태의 반복문
- 뺑뺑이는 컴퓨터에게!

* 반복문의 기능 : 특정 영역을 특정 조건이 만족하는 동안에 반복 실행하기 위한 문장
* 세 가지 형태의 반복문
  * while문에 의한 반복
  	- while문의 기본 원리와 의미
  	    - 반복 조건이 거짓일 때 반복문을 빠져나갈 수 다.
  	    <pre>
		<code>
		while(반복 조건)    // 반복 조건 : 조건식이 들어감. 반복 조건이 참(true, 1, !0)일 때 반복문 구간 실행
		{                   // 다른 언어에서는 'true'만 인정한다(이렇게 생각해두기). 그래서 C언어가 다른 언어에 비해 유연한 면이 있다.
	        반복 내용
            // "반복의 조건"이 만족되는 동안
            // "반복 내용"을 반복 실행하라.
		}
		</code>
		</pre>
        
        <pre>
        <code>
        // example.c
        while(i<10)
        {
            printf("Hello World!\n");
            i++;
            
            // i<10이 만족되는 동안
            // printf()와 i++를 반복 실행하라.
        }
        </code>
        </pre>
    
    - while문의 중괄호
        - 반복하고자 하는 영역이 둘 이상의 문장으로 구성되는 경우에 필수
        <pre>
        <code>
        while (i < 10)
        {
            printf("Hello World!\n");
            i++;
        }    
        </code>
        </pre>
    
    - 무한 루프(반복)
        - 반복의 조건으로 true가 오면 발생
        <pre>
        <code>
        while(1)    // 반복의 조건 대신 0이 아닌 정수를 넣는다.
        {
            printf("Hello World!\n");
            i++;
        }
        </code>
        </pre>
        - 무한루프의 예시
            - 의도하지 않게 무한루프가 발생할 수도 있다. 조심해야 한다.
            - 만약 의도하고 사용했다면 좋은 것이고, 그렇지 않을 때 벗어나려면, ctrl + C 사용!
            - 코드 작성 후에, 
        <pre>
        <code>
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
        </code>
        </pre>
        
        <pre>
        <code>
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
        </code>
        </pre>
        
    - 무한 루프에 빠지지 않으려면? 다음을 확인해야 한다.
        1. **index 지정**
        2. **수행 조건**
        3. **증감**
        - 이러한 것들을 묶어 놓은 것이 for문이다.

        <pre>
        <code>
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

        </code>
        </pre>
        
    - while문의 중첩
        - while문 안에 while문을 포함시킨다는 뜻
        - 반복 구조 내에서 또 하나의 반복 구조 형성
        
        <pre>
        <code>
        #include <stdio.h>
        
        int main()
        {
            int i = 0, j = 0;
            int num = 0;
            
            while (i<10)
            {
                while (j<10)
                {
                    num++;
                    j++;
                }
                i++;
                j=0;
            }
        }
        
        </code>
        </pre>
        
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
    <pre>
    <code>
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
    </code>
    </pre>
    
    <pre>
    <code>
    // 2단 
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
    </code>
    </pre>
 
 
    <pre>
    <code>
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
    </code>
    </pre>
    
    * 반복 과정의 이해
        - ![image](https://user-images.githubusercontent.com/49339278/128298182-505318c3-2699-429e-8cd1-7c3a9d4e98df.png)
        
       
       
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
    <pre>
    <code>
    if (실행의 조건)
    {
        실행하고자 하는 내용 // '실행의 조건'이 만족되는 경우 '실행하고자 하는 내용'을 실행한다.
                             // 만족되지 않으면 건너뛴다.
    }
    </code>
    </pre>

* if ~ else에 대해서
    - 단점, 불필요한 연산을 하게 된다.
    <pre>
    <code>
    if (조건 )    // "조건"이 만족되는 경우 "이거" 실행, 만족되지 않으면 "저거" 실행
    {
        조건 만족 시 실행 ; "이거"
    }
    else
    {
        조건 불만족 시 실행 ; "저거"
    }
    </code>
    </pre>
    
* if, else if, else
    - 무분별하게 사용하면 lost(불필요한 지연과 연산)이 많다. 꼭 필요한 경우가 아니면 사용하지 말자.
    - if ~ else문은 하나의 문장이다.
    - if ~ else문의 중첩된 형태에 지나지 않는다.
    - ![image](https://user-images.githubusercontent.com/49339278/128300701-89857bf3-80d6-4778-99a9-06c582f9c416.png)

* switch문
    - 조건문의 n은 꼭 반드시 정수 값이어야만 한다는 뜻이다. (int, long, char 가능, float, double, 문자열 불가능)
    - if ~ else문에 비해서는 제한적이다. 그런데도 switch문을 사용해야 하는 경우가 종종 있다.
    - ![image](https://user-images.githubusercontent.com/49339278/128301100-68e13d1e-a54b-4804-b97e-1817c2260a46.png)

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
        
* break : 반복문을 빠져 나올 때 사용 (무한 루프에서 사용)
* continue : 다음 번 반복으로 넘어갈 때 사용 (무한 루프에서 사용)
    - ![image](https://user-images.githubusercontent.com/49339278/128301329-27edc021-a838-440b-b15d-79b91eda66c1.png)
