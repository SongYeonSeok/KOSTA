#include <stdio.h>
#include <conio.h>

const int NUMBER = 5;
int main(void)
{
	double total = 0;
	double val[NUMBER];

	val[0] = 1.01;
	val[1] = 2.02;
	val[2] = 3.03;
	val[3] = 4.04;
	val[4] = 5.05;

	for (int i = 0; i < NUMBER; i++) total += val[i];
	printf("평균 : %.2f \n", total / NUMBER);


	getch();
	return 0;

}