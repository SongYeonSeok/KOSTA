// led_01.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wiringPi.h>

#define PORT_NUM 15   // 연결된 포트 번호

// .. $ ledtest 15
// ==> argc == 2, *v[0] == ledtest, *v[1] == wPi번호(15)

void Usage()
{
    printf("\n\nUsage :  ledtest  < wPi_Num >\n\n");
}


// 헤더 파일을 실행하게 되면, reference 목록이 나온다.
int main(int argc, char **argv)     // argc : 입력 개수, argv : 입력 문자열
{
    if (argc < 2)
    {
        Usage();
        return 0;
    }
    
    int port = atoi(argv[1]);
    wiringPiSetup();        // setup
    
    // define pin how to use it
    pinMode(port, OUTPUT);      // pin num : wPI num, use : OUTPUT
    
    // signal iteration
    for(int i=0;i<10;i++)
    {
        digitalWrite(port, HIGH);       // digital value : 1(HIGH) / 0 (LOW)
        delay(1000);                    // 밀리초 단위, 잠깐 쉬어가는 것
        digitalWrite(port, LOW);        // 1 : light on / 0 : light off
        delay(1000);
    }
}

/*
< raspberry terminal >
$ cd work
$ ls -al
$ gcc -o ledtest led_01.c -lwiringPi
$ ledtest
*/

/*
< raspberry terminal - 20211028 ver >
$ cd wirj
$ ls -al
$ gcc -o ledtest led_01.c -lwiringPi
$ ledtest 15

*/
