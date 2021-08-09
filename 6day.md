```c
// array1.c
#include <stdio.h>

const int num = 5;
int main(void)
{
  double total = 0;
  double val[num];
  
  val[0] = 1.01;
  val[1] = 2.02;
  val[2] = 3.03;
  val[3] = 4.04;
  val[4] = 5.05;
  
  for (int i = 0; i < num; i++)
  {
    total += val[i];
  }
  
  printf("평균 : %f \n", total/5);
  
  return 0;
}
```
