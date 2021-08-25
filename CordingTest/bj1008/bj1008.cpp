// 백준 1008번 C 언어 풀이

#include <stdio.h>

int main(void)
{
	int a, b;
	double c;
	scanf("%d %d", &a, &b);

	c = (double) a / b;
	printf("%.25f", c);

	return 0;
}