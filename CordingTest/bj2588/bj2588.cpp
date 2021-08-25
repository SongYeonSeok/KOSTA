#include <stdio.h>

int main(void)
{
    int a, b;        // (1), (2)
    int c = 0, d = 0, e = 0;     // (3), (4), (5)
    scanf("%d %d\n", &a, &b);

    c = a * (b % 10);
    d = a * ((b % 100)/10);
    e = a * (b / 100);
    printf("%d\n%d\n%d\n%d", c, d, e, a*b);

}