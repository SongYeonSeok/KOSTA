#include <stdio.h>
#include <conio.h>

const int num = 10;

int main(void)
{
    int array[num] = { 2, 3, 9, 5, 8, 1, 4, 7, 3, 6 };          // 변수 지정

    for (int i = 0; i < num; i++)
    {
        printf("%d ", array[i]);
    }

    for (int j = 0; j < num; j++)
    {
        for (int k = 0; k < num; k++)
        {
            if (array[j] > array[k])
            {
                int temp = array[j];
                array[j] = array[k];
                array[k] = temp;
            }
                
        }
    }

    printf("\n");
    for (int i = 0; i < num; i++)
    {
        printf("%d ", array[i]);
    }

    getch();
    return 0;

}