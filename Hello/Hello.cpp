#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main()
{// ctrl + c (무한루프 빠져나갈 때
    char name[20];  // 문자열 변수 지정할 때, Array값을 가지고 얼마나 넣을지 미리 데이터 공간 지정하기
    int age, height;
    //int index = 2;  // while 문의 수행 횟수를 정의

    //while (index > 0) 
    //for(index 수행조건  증감)
    for (int index = 0; index < 2; index++) //index  수행조건    증감
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

        //index--;
    }



    getch();
    return 0;

}
