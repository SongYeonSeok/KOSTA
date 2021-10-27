#include <stdio.h>

int MAX = 0;
int min = 0, max, pos;

// ..$ test 5000

int main(int argc, char **argv)
{
    char b[10];
    printf("게임의 범위를 입력하세요 (최대 1,000,000) : ");
    scanf("%d", &MAX);
    max = MAX;
    printf("%d부터 %d 사이의 숫자 중 하나를 생각하시고 질문에 Y / N 으로 답하세요.\n", min, MAX);
    printf("준비 되셨으면 [enter]을 눌러 주세요...");
    getch(stdin);
    getch(stdin);       // getc(), stdin -> stdio.h
    int count = 1;
    while(1)
    {
        pos = (min + max) / 2;
        printf("%d번째 질문입니다. 당신의 숫자가 %d보다 큽니까? ", count, pos);
        scanf("%s", b);
        // 한 문장으로 받는 것보다 문자열로 받는 것이 편할 수 있다. (배열이면 &를 붙이지 않아도 된다.)
        // 배열 = 포인터 = 주소
        // b : Y | N
        
        if(b[0] == 'Y')
        {
            if(max - pos == 1)  // 결정값 == max
            {
                printf("당신이 생각한 숫자는 %d이군요.\n", max);
                break;
            }
            min = pos;  count++;
        }
        else
        {
            if(max - pos == 1)  // 결정값 == pos
            {
                printf("당신이 생각한 숫자는 %d이군요.\n", pos);
                break;
            }
            max = pos;  count++;
        }
        if(count > 20)
        {
            printf("당신이 생각한 숫자를 유추할 수 없습니다.\n이제 중지하겠습니다.");
            break;
        }
        
    }
    
    return 0;
}
