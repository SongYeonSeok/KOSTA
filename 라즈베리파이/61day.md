--------------------------
# 계획
- 11/8 ~ 12/17 : Final Project (11/9로 조정 가능 높음)
- 실제로는 12/14 ~ 12/15일 종강 (휴일이 2일 남았는데, 마지막에 활용할 것이기 때문)
- 마지막 날 오후에 발표할 예정. 그리고 수료 (원칙상으로는 12/17로 정함)

- 프로젝트 기간 중, 11/9일부터 프로젝트 시작
- 매주 금요일날, 주간 보고서를 작성하기(구글 클래스룸에 양식 첨부 예정)
- 다음주는 2 ~ 3일 정도는(목요일 까지) 프로젝트 계획을 세우고, 프로젝트에 대한 세부 사항까지 구성한다.
- 12/3일에 중간 발표를 진행한다.
- 12/6 ~ 12/9 : 수정, 보완 개발
- 12/10 : 보고서 제출

--------------------------
- 오늘부터 다음주까지 할 것
1. GSAT + SSAFY
2. 코테 (C++ / Python)
3. 카카오브레인 서비스 백엔드
  - 포트폴리오 작성하여 제출하기
  - HackerRank / 프로그래머스 / 백준 등으로 준비
4. SSAFY 자소서
5. KT ALIVE 자소서
--------------------------
- [라즈베리파이 소켓 프로그래밍 자료](http://cms3.koreatech.ac.kr/sites/joo/IFC415/IFC415_14.pdf)

- IoT 디바이스 목적 : 디바이스를 활용하여 산업 현장 등에 응용할 수 있도록 하는 것
- PC와 라즈베리파이의 통신
  - 라즈베리파이의 소켓 프로그래밍 지식이 필요하다.
    - TCP/IP 프로그래밍
      - Server와 Client간의 통신
      - TCP/IP 계층
      - 소켓 프로그래밍은 low level 단계의 과정을 다루기 때문에 비교적 어렵다.
      - TCP 방식에서 연결 대기부터 Socket 닫기(연결 끊기) 과정에서 쓰레드를 사용한다.
      - PC : 개인용, single user
      - windows -> event driven
      - Process 1과 Process 2가 연관되어 있을 때, 스레드가 연결되어야 작동이 된다.
        - DDE
      - 하나의 프로그램 내에서 두 개의 프로세스를 돌려주는, 공통된 전역 변수를 사용
    - Unix에서는 쓰레드를 사용하지 않는다. 사용하는 것이 크게 의미가 없기 때문이다.
      - Linux에서는 파일에 의해 움직이는 운영체제이다. 
    - TCP 방식에서 수신측과 송신측 간의 통신을 **Hand Shake**라고도 표현한다.

  - UDP 방식 (신경 안써도 된다.)
    - 승인 여부에 관계가 없다.
    - Port 방식
    - 개인/소규모로 프로젝트를 진행할 때 사용해도 관계가 없다.
    - 외부에서 많은 양의 데이터가 지속적으로 들어오게 된다면, 연결이 뻗어버리는 현상이 발생한다.
      - 이러한 해킹 방식을 DDos라고 한다. (보안의 취약한 부분)
    - 데이터에 대해 크게 신뢰를 두지 않아도 될 때 사용함. (UDP 방식의 비신뢰성 특징)

  - 소켓 프로그래밍(C 언어 and linux)
    - ```socket()``` : 소켓 생성 함수
    ```
    #include <sys/socket.h>
    #include <sys/types.h>
    
    int socket(int domain, int type, int protocol);
      // domain   : AF_INET(address family) or PF_INET(protocol family), ...
      // type     : SOCK_STREAM(연결형, TCP) / SOCK_DGRAM(비연결형, UDP)
      // protocol : 0 or IPPROTO_TCP / IPPROTO_UDP
    ```
    
      - TCP 소켓 예제 : ```sock = socket(AF_INET, SOCK_STREAM, 0);```
      - UDP 소켓 예제 : ```sock = socket(AF_INET, SOCK_DGRAM, 0);```

    - 주소 정보를 위한 구조체
      - ```sockaddr``` 구조체 : 소켓 주소를 표현하는 **범용의 구조체**
        ```c
        struct sockaddr {
            sa_family sa_family;    // 소켓의 프로토콜 주소체계
            char sa_data[14];       // 해당 주소체계에서 사용하는 주소 정보
        }
        ```
      - ```sockaddr_in``` 구조체 : **IPv4 주소체계**에서 사용하는 소켓 주소 표현 구조체
        ```c
        struct sockaddr_in {
            sin_family_t sin_family;      // IPv4 주소 체계, AF_INET
            uint16_t sin_port;            // 포트 번호, 16bit, Big Endian
            struct in_addr sin_addr;      // IPv4 IP 주소 구조체, 32bit, Big Endian
            char sin_zero[8];             // sockaddr과 같은 크기 위해, 항상 0
        }
        
        struct in_addr {
            uint32_t s_addr;              // IPv4 IP 주소, 32bit, Big Endian
        }
        ```
      - Big Endian vs Small Endian
        - 소켓 프로그래밍에서 사용되는 용어 -> Big Endian을 사용한다.(이정도만 기억)
        - RISK 서버를 다룰 때 사용되는 용어(sun spark, hp 서버 등)
        - 차이 : 데이터 표현 방식(그래서 변환 함수가 필요하다고 생각하면 된다.)
          - Big Endian : 9000(dec) => 0x2328 /  0010 0011 0010 1000_2

      - 서버 사용 예
        ```c
        struct sockaddr_in server_address;
        
        memset(&server_address, 0, sizeof(server_addresss));
        server_address.sin_family       = AF_INET;
        server_address.sin_port         = htons(PORT);
        server_address.sin_addr.s_addr  = INADDR_ANY;
        
        // htons() (host to network short) : Big Endian 방식으로 변환
        // INADDR_ANY : 실행 중인 시스템 IP 주소에 대한 매크로
        ```
      - 클라이언트 사용 예
        ```c
        struct sockaddr_in client_address;
        
        memset(&client_address, 0, sizeof(client_address));
        // 포트 지정하는 방법
        client_address.sin_family       = AF_INET;
        client_address.sin_port         = htons(PORT);
        client_address.sin_addr.s_addr  = inet_addr("192.168.0.40");  // 서버IP
        ```
          - *범용의 소켓 주소 구조체 sockaddr로 형변환*하여 사용함 => ```(struct sockaddr *)&server_addr```


      - 서버
        - ```bind()``` : 통신을 위해 소켓 기술자와 소켓주소 구조체를 연결한다.
          ```c
          #include <sys/socket.h>
          int bind(int sockfd, struct sockaddr *myaddr, int addrlen);
            // sockfd   : socket()이 생성한 소켓 기술자
            // *myaddr  : 소켓 번호와 연결할 소켓 주소 구조체 포인터
            // addrlen  : 소켓 주소 구조체 크기
            // 리턴값    : 정상 0, 에러 -1
          ```
          - 예시 : ```bind(sockfd, (struct sockaddr *)&server_address, sizeof(server_address));``` // 구조체를 sockaddr 범용 구조체로 형변환
      
        - ```listen()```
          - 클라이언트로부터의 가용한 연결요청 대기큐의 크기 설정
          - 대기큐에서의 요청순서에 따라 서비스. 병해처리 아님

          ```c
          int listen(int sockfd, int n)
              // sockfd   : socket()이 생성한 소켓 기술자
              // n        : 대기큐의 길이, 클라이언트 연결 요청 최대 수
              // 리턴값    : 성공했을 경우 0, 실패했을 경우 -1을 리턴
          ```
          - 예시) ```listen(sockfd, 2);```
            - 서버가 최대 2개의 ```connect()```요청을 대기시킬 수 있으며, 세번째 이후의 ```connect()```요청은 거절하여 클라이언트가 알게 함
        - ```accept()``` : 클라이언트의 주소정보를 반환하여 통신 채널 생성
          ```c
          int accept(int sockfd, struct sockaddr *addr, int *addrlen)
              // sockfd   : socket()이 생성한 소켓 기술자
              // addr     : 접속을 허가 받은 클라이언트 sockaddr 구조체 포인터
              // addrlen  : 클라이언트의 sockaddr 구조체의 크기를 받을 포인터
              // 리턴값    : 성공시 생성된 클라이언트의 소켓 기술자, 실패시 -1
          ``
        - ```read()``` / ```write()``` : TCP 방식에서의 송수신
          ```c
          int write(sockfd, char *buf, int bufsize)
          int read(sockfd, char *buf, int bufsize)
            // sockfd : 서버의 경우 accept()에 의해 생성된 소켓 기술자
            //          클라이언트의 경우 자신의 소켓 기술자
            // buf    : 송수신할 데이터 버퍼
            // bufsize: 버퍼의 크기
            // 리턴값  : 송수신 문자수, 실패시 -1
          ```
          - UDP 방식에서는 ```sendto()```, ```recvfrom()``` 함수 사용
      - 클라이언트
        - ```connect()``` : 클라이언트 측에서 연결 요청
          - 소켓에 클라이언트의 IP 주소, 포트번호를 자동 할당하고, TCP 방식의 클라이언트가 서버로의 연결을 요청하는 함수
          - 사전에 연결할 서버의 주소 구조체 초기화가 필요하다.
          ```c
          int connect(int sockfd, struct sockaddr *serv_addr, int addrlen);
              // sockfd     : 클라이언트의 소켓
              // serv_addr  : 서버의 주소 정보를 담고 있는 구조체
              // addr_len   : serv_addr 구조체의 길이
          ```
      - ```close()``` : TCP방식에서는 미처리된 패킷들을 모두 처리한 후에 소켓을 닫는다.
        - 예외) 미처리 패킷을 즉시 버리거나, 지정 시간동안 처리하기 위해 ```setsockopt()``` 사용한다.
        - UDP 방식에서는 단순히 소켓을 닫는 작업이다.
        ```c
        close(sockfd);
        ```
        
- 라즈베리파이 (linux)
  - ```#include <unistd.h>```
  - ```#include <netinet/in.h>```
