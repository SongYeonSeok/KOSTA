- 하나의 라즈베리파이에 2개의 I2C를 사용할 수 없다.
- I2C : Inter Integrated Circuit
  - IC들 간의 데이터 통신을 목적으로 하는 통신 방식
  - SDL, SCL

- start 및 stop 조건
  - 비 통신 시 DAT, SCL에 High 신호 유지(아이들 상태)
  - 통신을 위해선 반드시 시작 조건으로 개시
  - 두 조건사이의 전송 데이터 바이트 수는 제한 없음
- Start 조건 : master가 slave에게 통신 개시의 의미 상태, SCL(High 상태) / SDA(High-to-low) 천이
- Stop 조건 : master가 slave에게 통신 종료의 의미 상태, SCL(High 상태) / SDA(Low-to-High) 천이

- wiringPiI2C 라이브러리 함수 : I2C 통신을 위한 함수들을 정의, I2C 통신을 위한 슬레이브 주소를 지정하여 초기화하는 함수
- ```wiringPiI2CSetup(0x48);``` => 포인터가 아니다. Device Handle이다.
- ADC : 아날로그 신호를 가지고 오는 것. 즉, 아날로그 신호 -> 디지털 신호 변환
- read = I2C 디바이스로부터 데이터를 갖는다는 의미

- ADC/DAC(YL-40) 모듈 : 3개의 아날로그 센서(조도, 온도, 가변저항) 장착
  
  | 채널 | 내정디바이스 | 점퍼선 | 
  |:----:|:----:|:----:|
  | AIN0 |조도 센서|P5|
  | AIN1 | 온도 센서|P4|
  | AIN2 | -| -|
  | AIN3 | 가변 저항| P6|
  
  
- I2C 활성화 한 후에 I2C 모듈의 주소를 확인한 후에 사용한다.

---------------------------------------------------------------------
[C언어로 하는 DHT11 모듈 프로그래밍](https://blog.daum.net/ejleep1/442)

--------------------------------------------------------------------
- DHT11 모듈(온습도 센서) : 하이브리드 모듈의 한 종류. (신호 처리를 위한 여러 부품이 들어 있다는 것)
  - type 1 : normal한 상태(원본 그대로) (우리가 가지고 있는 것)
  - type 2 : hybrid한 상태(핀이 추가로 부착되어 있다.)
  - 1-wired
  - 5 개의 byte로 이루어져 있다.

|byte 4 | byte 3|byte2 |byte 1 |byte 0|
|:-:|:-:|:-:|:-:|:-:|
|RH integral | RH decimal | T integral | T decimal | checksum|
|습도 | 습도 | 온도 | 온도 | |

- 구성 요소
  - ![image](https://user-images.githubusercontent.com/49339278/139771500-6402386c-0638-42b7-8eb4-db7b8e44f052.png)
  - vcc(+) = 3.3v
  - Signal => gpid 선을 연결
  - Not used
  - Ground(-)
  
- 파장
  - ![image](https://user-images.githubusercontent.com/49339278/139771750-f239d8b8-18e9-4434-ae3e-bc60177fb1ce.png)
  - ![image](https://user-images.githubusercontent.com/49339278/139781197-a1343a80-4cff-4e52-82e1-3ca3c0f233d4.png)

1. send start signal
```c
// Send Start Signal 함수를 만들어서 모듈화시키는 것을 추천!
pinMode(P_DHT_DAT, OUTPUT);

// 1wire init- to HIGH
digitalWrite(P_DHT_DAT, HIGH);delay(1);

// MCU sends out start signal & low signal for at least 18ms
// to let DHT11 detect the signal
digitalWrite(P_DHT_DAT, LOW);delay(18);

// MCU pulls up voltage and waits for DHT response(20 ~ 40 ms)
digitalWrite(P_DHT_DAT, HIGH);
```

2. Response signal
```c
// 1-wired IO(Input/Output)
pinMode(P_DHT_DAT, INPUT);  // 제어 신호를 보내는 핀과 받는 핀번호가 같다.

// check : high -> low
while(digitalRead(P_DHT_DAT) == HIGH);  // wait

// 2) DHT sends out reaponse signal & keeps it for 80us
// check : low -> high
while(digitalRead(P_DHT_DAT) == LOW);   // wait

// DHT pulls up voltage & keeps it for 80us
// check : high -> low
while(digitalRead(P_DHT_DAT) == HIGH);    // wait
```

3. 데이터 비트 수신 (파형 해석 - bit 단위로, 병렬 형태)
```c
for(bit = 0;bit<MAX_BIT;bit++)      // MAX_BIT = 40 (이유 : 5byte가 있으니, bit로 나타내면 40이 나온다.)
{
  // Start to transmit 1-bit data (50us)
  while(digitalRead(P_DHT_DAT) == LOW);
  // 26 ~ 28us voltage-length means data "0"
  // 70us voltage-length means 1-bit data "1"
  
  // 파형의 길이를 측정
  st = micros();
  while(digitalRead(P_DHT_DAT) == HIGH) delayMicroseconds(1);
  en = micros();
  
  // get a bit data
  dht11Res[bit/8] <<= 1;  // bit shift;   // 한 bit를 왼쪽으로 shift하라. 
                          // 0 ~ 7 : [0] / 8 ~ 15 : [1] / 16 ~ 23 : [2] / 24 ~ 32 : [3] / 30 ~ 39 : [4]
                          // RH : [0], [1]
                          // T  : [2], [3]
  duration = en - st;
  
  // printf(" %d \n", duration);
  if(duration > THRESHOLD)    // us, threshold
  {
    dht11Res[bit/8] |= 1;     // bit value 1    // 해당하는 비트에 1을 넣음 ('|' : bit OR)
  }
  else
  {
    dth11Res[bit/8] |= 0;     // bit value 0    // 의미 없는 작업
  }
}
```

- 참고 (bit 구성에 대한 이해)
  - 83 : ![image](https://user-images.githubusercontent.com/49339278/139778239-70e2f0c3-3ec5-4e69-b116-665bdbb1c59e.png)
  - C0 : ![image](https://user-images.githubusercontent.com/49339278/139778337-0c3a949d-cfc0-494e-92d9-bf28a530c1fe.png)
  - 01 : ![image](https://user-images.githubusercontent.com/49339278/139778426-985ab872-c1de-44d6-b882-eadab550f7b7.png)
  - 10 == ```01 <<= 1``` : ![image](https://user-images.githubusercontent.com/49339278/139778482-8b2f00d4-10bb-44f0-b2e8-e0f55808aa56.png)

4. Checksum : 데이터를 다 더한다. (선택)
- 마지막 데이터에 checksum이 들어간다.
- 마지막 데이터가 checksum과 같으면 PASS, 그렇지 않으면 ERROR 발생
```c
checksum = 0;
for(i =0;i<4;i++)
{
  checksum += dht11Res[i];
}
if(checksum == dht11Res[4]) PASS;
else                        ERROR;
```


--------------------------------------------------------------------------------
- 설계의 단계

| U/I = Human(고수준)|User Interface(= Front-end)|
|:---:|:----|
|Back-End|SW Programming, User와 가까움, DB과 접근되는 부분을 말한다.|
|System|SW Programming, Back-End보다 low 수준, H/W의 Interface에 중점|
|H/W(저수준)|Device를 다루는 수준, S/W 단계가 아니다.|
---------------------------------------------------------------------------------
