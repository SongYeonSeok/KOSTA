- 이번주 금요일(11/5) 공강
- 이번주까지 라즈베리파이 수업함
- 이후 파이널 프로젝트 시작. (11/8 ~ )
  - 2 ~ 3시 10분까지 (1시간) 별도의 팀 구성을 위한 회의
- 11월 27일(?) 특강 (컨설팅)

------
- Read & Write (명령어)
  - 중요한 키 : digital (0(off)과 1(on))
    - 디지털에서의 1과 0은 일반적인 값이 아닌 상태값이다. 1 : On, 0 : Off
    - data => 1bit / 4bit ... (8bit가 일반적으로 사용된다.)
  - 직렬 vs 병렬
    - 직렬 : 하나의 선(bit)으로 0과 1로 파형이 구성되어 있는 것
    - 병렬 : 여러개의 선(bit)로 0과 1로 파형이 동시에 표현되어 있는 것. (보통 1byte = 8bit => 8개의 선을 사용)

- 라즈베리파이에서의 센서 접속 방식
  1. GPIO : 출력/입력할 때 하나의 포트 자체에서 신호(digits bit)를 내보내준다/입력한다.
    - 실습 방식이 여기에 해당. wPi 방식도 있음
  2. SPI : 병렬 처리, wired 방식 (bus, memory도 병렬 처리된다.)
  3. UART : 
  4. I2C : device address 개념이 들어감(직렬 신호)
    - ADC(아날로그 디지털 컨버터 : 8bit = ADC) (ex : 마이크)
      - Analog => 전기적 값, 연속적인 신호 (ex : 비트 수 높으면 좋다.)
      - Digital => 0과 1
      - 직렬을 하는 이유 : 병렬은 메모리를 많이 차지한다. -> 확장성 줄어들음
      - USB의 S : 직렬(serial) => 대부분의 저장장치가 여기에 해당

-------------
# ADC 모듈과 I2C 통신
- I2C 인터페이스 : IC들 간의 데이터 통신을 목적으로 하는 통신 방식으로, 2개의 신호선(SDA, SCL)만을 사용하여 통신토록 정의한 것이다. 회로가 간단하고, 저비용, 저잡음 등의 장점이 있다. 송/수신측은 하나의 master와 다수의 slave로 구성된다.
- ADC 3가지 센서
  - ![image](https://user-images.githubusercontent.com/49339278/139608520-600b9be5-1b1d-41d0-8dee-9af608caf331.png)
  - SCL / SDA => Data , I2C 인터페이스의 제어
  - I2C는 라즈베리 파이 포트 번호에서 핀 번호 3번과 5번이 여기에 해당한다.
    - SDA(Serial data) : wPi 8, GPIO2, 3
    - SCL(Serial clock) : wPi 5, GPIO3, 5

  - 특징 : SCL / SDA pin을 이용한 I2C 인터페이스 사용
  - 총 4개의 아날로그 채널이 들어있다. (Ain0 ~ Ain3)
  - A0, A1, A3 채널은 내부 테스트 센서 제공
    - (온도, 조도, 가변저항)
    - 점퍼들이 연결되어 있으면, 내부 테스트 센서를 사용할 수 있다. (A0, A1, A3는 내부 점퍼들에 의해 연결됨)8
  - 참고 : vdd => 5v / vcc => 3.3v 가능


```linux
$ i2cdetext
$ sudo raspi-config -> Interface Options -> I2C 사용 설정
$ 12cdetect -y 1 => 48이 뜨면 setup이 잘 된것 => 구성 완료된 것!
```

- ADC를 사용하기 위해서는 새로운 헤더파일이 필요하다. ```#include <wiringPiI2C.h>```
```linux
$ cd work
$ ls -al
```

- 4개의 채널 address가 있다.
  - 00(0) / 01(1) / 10(2) / 11(3)
  - 0 : 조도
  - 1 : 온도 (고장)
  - 2 : 없음(volume) (open == 아무것도 연결되어 있지 않다는 것)
  - 3 : 가변 저항


- 과제
  - Volumn 회로(가변저항)를 조절하여 그 값에 따라 LED의 밝기가 조절되도록 구현하라.
  - 가변 저항 값 읽기 : wiringPi2CRead
  - LED 밝기 제어 : PwmWrite
  - 58day_i2c.c 파일 참고!
