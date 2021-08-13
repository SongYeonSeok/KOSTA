// 세 값의 정수를 입력하고 최대값을 구합니다.
#include <stdio.h>

int main(void)
{
	int a, b, c;
	int result;			// 최대값
	
	printf("세 값의 정수를 입력하세요\n");
	scanf("%d %d %d", &a, &b, &c);
	printf("세 값 중 최대값을 출력합니다.\n");

	result = a;
	if (b >= a) result = b;
	if (c >= b) result = c;

	printf("%d", result);
	return 0;
}