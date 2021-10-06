- IoT = Internet of Things
- Internet of net = Network : 송신자 + 수신자
- 프로그래밍을 하는 데 있어서의 통신은 통신 공학과 수학적 계산은 크게 필요가 없다. 
  - 다루는 것
  1. TCP
  2. UDP
  3. RS-232C

  - TCP, UDP = 이더넷
  - LAN Cable`s LAN = Local Area Network(근거리 통신망)
  - WAN = Wide Area Network(원거리 통신망)
  - AP = Access Point(= 무선 라우터)
    - AP의 구성요소 : 무선 LAN(WIFI), 유선 LAN(이더넷)

  - 송신자 <-> 사업자 <-> 수신자 (그 사이에 통신사가 있음)

- ![image](https://user-images.githubusercontent.com/49339278/136124009-d84da82f-bac6-4617-87cd-4f867970b7b4.png)
- Packet : protocol과 연관된 것으로, 통신 단위이다.
- LTE : Long Term Evolution, 긴 패킷이다.

- ![image](https://user-images.githubusercontent.com/49339278/136126832-14cecaeb-970f-48e5-b970-4fcc913d039f.png)
- ![image](https://user-images.githubusercontent.com/49339278/136128164-5f5e44de-0361-44ad-a817-42656926b8b9.png)

- ![image](https://user-images.githubusercontent.com/49339278/136128359-3c9ad448-aa38-4f77-bf2f-fdbf8e0cf040.png)
- IoT 핵심 : LAN
- ![image](https://user-images.githubusercontent.com/49339278/136130502-d536d721-9aeb-4df8-8e13-f973521adc80.png)

- TCP/IPv4(인터넷 프로토콜 버전4) 속성 중 서브넷 마스크는 관용적으로 255.255.255.0을 사용한다.
- DNS : Domain Name Server, 도메인 서버
- 도메인(ex : github.com, korea.com, google.com), 문자열로 이루어진다.
- ![image](https://user-images.githubusercontent.com/49339278/136133950-ba994728-5be5-4c79-850f-1daaeac679fe.png)


- ![image](https://user-images.githubusercontent.com/49339278/136134155-a3509ffe-0085-46ff-b2ae-600af87d06bc.png)
- ![image](https://user-images.githubusercontent.com/49339278/136134778-d1809b09-d68a-4f58-86d7-e9b816375949.png)
- ![image](https://user-images.githubusercontent.com/49339278/136135080-628e8844-3f02-4905-aab2-ebc2290cf5f3.png)
- ![image](https://user-images.githubusercontent.com/49339278/136135253-10828c53-6221-4f27-8930-ec603173c374.png)
- ![image](https://user-images.githubusercontent.com/49339278/136135951-ac0c7710-0156-4b4f-8eec-a8ac7b712bcd.png)


- TCP, UDP = 이더넷
  - ![image](https://user-images.githubusercontent.com/49339278/136136261-143f54f0-beed-43ca-b97b-e3cc9d035892.png)
  - ![image](https://user-images.githubusercontent.com/49339278/136136327-c491faf1-a53d-44bf-95f1-ef5e8a5fc1b6.png)
    - TCP : 수신 확인
    - UDP : 방송용

- 스스로 공부해야 겠다.

## Windows Socket API : 이더넷 커뮤니케이션 통신 라이브러리
- 보통 C/C++으로 구성되지만, 강의에서는 C#으로 할 예정
- OSI 7계층
  7. Application
  6. ㄹ
  5. ㄹ
  4. ㄹ
  3. 4
  2. 3
  1. Media - physical
- Socket : 

- ![image](https://user-images.githubusercontent.com/49339278/136144996-faac5419-a9d5-439b-9f83-8254d16b689b.png)
  - Address related Data Structures and Functions : 주소 관련된 함수
- ![image](https://user-images.githubusercontent.com/49339278/136145429-28c92c01-0683-488f-889f-f417986e1dfe.png)
  - C#에서는 using을 사용할 예정
  - C/C++에서 사용
- ![image](https://user-images.githubusercontent.com/49339278/136145494-b5756213-6440-45a1-a875-5ca8903e813e.png)
- ![image](https://user-images.githubusercontent.com/49339278/136145528-b523c9a8-abc9-486d-845e-2db584a595e9.png)
- ![image](https://user-images.githubusercontent.com/49339278/136145919-e92ed1ce-2db1-49cd-88e3-0f19c0df7c11.png)
- ![image](https://user-images.githubusercontent.com/49339278/136145927-a53d0f96-ce5e-4925-8039-b8d0ca9c7fab.png)
- ![image](https://user-images.githubusercontent.com/49339278/136145959-e83c00ad-a6c5-42b0-b1b0-233a257ab14c.png)
- ![image](https://user-images.githubusercontent.com/49339278/136146472-73d2b279-9a66-429b-9087-0d652264fc53.png)
  - 일종의 Listener
- ![image](https://user-images.githubusercontent.com/49339278/136146721-8b126946-8236-4fd5-8968-e210db10f361.png)

- Blocking Mode / non Bloking Mode
- ![image](https://user-images.githubusercontent.com/49339278/136147496-0e3547d5-deac-42e8-bce5-081f13e97f42.png)
- ![image](https://user-images.githubusercontent.com/49339278/136147906-c5dd064a-3744-4866-8c98-5f1bc4ad7da4.png)
- listen accept : blocking method

- ![image](https://user-images.githubusercontent.com/49339278/136148035-07289294-6275-4473-bab6-a3b3ee1751a2.png)
- ![image](https://user-images.githubusercontent.com/49339278/136149105-ba27b359-1aae-4ffd-b28b-f607b9609364.png)




