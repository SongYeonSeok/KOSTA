- Analogy -> Digital(0, 1) => converter 필요
  - 이를 ADC 컨버터라고 한다.

-------------------------------------------
- 초음파 센서 정리
  - 부제 : 초음파 센서를 이용한 거리 측정 Application.

- 초음파 거리 센서 사용
  - 센서의 모델명 : HC-SRO4
    - ![image](https://user-images.githubusercontent.com/49339278/139357583-fae03097-c621-4485-a19e-0823602aac6d.png)
      - Vcc : 전원공급 5V
      - Trig : 초음파 발신
        ```c
        // 10us 트리거 = 측정 시작 신호
        // [Trigger 신호 발생]
        digitalWrite(Trig, HIGH);
        delayMicroseconds(10);    // ms초 delay
        digitalWrite(Trig, LOW);  
        ```
        
      - Echo : 초음파 수신
        ```c
        // [Echo 신호 측정]
        // 대기가 필요하다.
        
        // Echo Start
        while(1)
        {
          if(digitalRead(Echo) == HIGH) break;    // HIGH일 때까지 무한루프
        }
        Ts = micros();    // 현재 시간(현재 클럭)
        
        // Echo Stop
        while(1)
        {
          if(digitalRead(Echo) == LOW) break;
        }
        Tr = micros();    // 현재 시간(현재 클럭)
        Td = Tr - Ts;     // 거리 측정을 위한 시간
        ```
        
      - GND : 접지
      
      1. Trig 단에 트리거 신호
      2. Echo 감시
      3. Echo Start ~ Echo Stop간의 시간 구하기
  - 생각보다 측정 정밀도가 높음 (5cm ~ 4m)
  - 사람이 듣고 이해할 수 있는 가청 주파수(20m ~ 20km)가 아닌 초음파 영역을 통해 거리 측정
  - 음파의 속도 : 340m/s
  - trigger =>(t = 1 sec) / 2

- 초음파 센서의 원리
  - ![image](https://user-images.githubusercontent.com/49339278/139355509-8c31bb41-82bf-4a94-8f44-453ba159f1c6.png)
  - ![image](https://user-images.githubusercontent.com/49339278/139355585-6dd8af94-75ff-40bf-a627-fde70203867b.png)

- 초음파 센서의 Timing Diagram
  - ![image](https://user-images.githubusercontent.com/49339278/139360233-ea6b8680-05f2-4cce-aac2-9358b1d855a3.png)


- 초음파 트리거 신호의 수신에 걸린 시간 (Tr - Ts) = Td (sec 단위)
  - Tr : Trigger Receive
  - Ts : Trigger Start (수신)

- Td = 10 msec = 0.01 sec
- (초)음파의 속도 = 340m/sec (공기 매질 기준)
- 실제 거리 Dist = 340m * Td/2 (이유 : 소리의 왕복이므로) 
                 = 340 * 0.01/2 = 1.7 (m) 
                 
                 
---------------------------------------------

- 어제까지 한 것 : digitalwrite


-----------------------
- 프로그램을 만들어 보자
  - 초음파 센서 회로 구성
    - Vcc : 무조건 5V (+)
    - GND : GND에 연결 (-)
    - Trig : GPIO16(wPi 27)에 연결(+)
    - Echo : GPIO20(wPi 28)에 연결(-)
    - 센서 자체에 회로가 구성되어 있으므로 저항은 필요 없다.

  - 

-----------------------
