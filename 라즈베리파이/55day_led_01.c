// led_01.c

#include <stdio.h>
#include <wiringPi.h>

#define PORT_NUM 15   // 연결된 포트 번호

// 헤더 파일을 실행하게 되면, reference 목록이 나온다.
int main()
{
    int port = PORT_NUM;
    wiringPiSetup();        // setup
    
    // define pin how to use it
    pinMode(port, OUTPUT);      // pin num : wPI num, use : OUTPUT
    
    // signal iteration
    for(int i=0;i<10;i++)
    {
        digitalWrite(port, HIGH);       // digital value : 1(HIGH) / 0 (LOW)
        delay(1000);                    // 밀리초 단위, 잠깐 쉬어가는 것
        digitalWrite(port, LOW);
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
