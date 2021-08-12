#include <stdio.h>     // C++ 전용 헤더 파일

int main()
{
    /* char, short int, long, float, double 변수를 선언하고
    해당 data type의 byte 수를 출력하시오.  */
    
    int age = 10;
    float pi = 3.141592;
    double dr2 = 1.414;

    printf("age = %d     sizeof(age) = %d\n", age, sizeof(age)); //sizeof의 값: 4 byte
    printf("pi = %.6f     sizeof(pi) = %d\n", pi, sizeof(pi)); //sizeof의 값(무조건 정수): 4 byte
    printf("dr2 = %.3f     sizeof(dr2) = %d\n", dr2, sizeof(dr2)); //sizeof의 값: 8 byte(가변적인 형태의 data type에 대한 사이즈를 알아낼 때 유용)
                                                                   // double도 %f 사용

}
