#include <stdio.h>
#include <conio.h>
int main()
{
    int num;    // 입력되는 숫자

//  scanf_s("%d : ", &num);     // scanf 안될 때 사용
 

    /* scanf와 scanf_s의 차이점
    비주얼 스튜디오를 사용하게 되면 SDL로 인해 scanf() 사용 시 오류가
    발생한다. 
    해결방법 1 : 프로젝트 -> 속성 -> C/C++ -> SDL 아니오
    해결방법 2 : scanf 대신 scanf_s 사용
    해결방법 3 : #include <stdio.h>와 함께
    #define_CRT_SCURE_NO_WARNINGS 를 작성하면 된다.
    
    scanf_s() 사용 방법
    1. 문자 1개를 입력받을 때
    2. 문자열 입력을 받을 때
    3. 정수 숫자 입력 받을 때
    */
    while (1)
    {
        printf("숫자를 입력하세요: ");
        scanf("%d", &num);  // 숫자를 입력하지 않으면 컴퓨터가 빈정상해서 인식하지 않는다.
        if (num == 1) 
        {
            printf(">1 : One\n"); 
            break;
            }
        else if (num == 2)
        {
            printf(">2 : two\n");
            break;
        }
        else if (num == 3)
        {
            printf(">3 : three\n");
            break;
        }
        else if (num == 4)
        {
            printf(">4 : four\n");
            break;
        }
        else if (num == 5)
        {
            printf(">5 : five\n");
            break;
        }
        else if (num == 6) 
        {
            printf(">6 : six\n");
            break;
        }
        else if (num == 7) 
        {
            printf(">7 : seven\n");
            break;
        }
        else if (num == 8) 
        {
            printf(">8 : eight\n");
            break;
        }
        else if (num == 9)
        {
            printf(">9 :nine\n");
            break;
        }
        else break;
    }
    printf("\n\n");

//  int num;
    printf("숫자를 입력하세요: ");
    scanf("%d", &num);
//  scanf_s("%d : ", &num);     // scanf 안될 때 사용

    switch (num)
    {
    case 1: printf("1 : On\n");     break;
    case 2: printf("2 : Two\n");    break;
    case 3: printf("3 : Three\n");  break;
    case 4: printf("4 : Four\n");   break;
    case 5: printf("5 : Five\n");   break;
    case 6: printf("6 : Six\n");    break;
    case 7: printf("7 : Seven\n");  break;
    case 8: printf("8 : Eight\n");  break;
    case 9: printf("9 : Nine\n");   break;
    default: break;
    }
    //printf("프로그램을 종료하려면 아무 키나 누르세요...");
   
    //getch(); // console 은 PC, Windows 전용이다. mac는 X
    return 0;
}
