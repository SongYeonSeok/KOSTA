1. client(sensor) -> DB
2. Server(LED) <- PC (cmd)

- 상수를 최소화시키는 것이 좋다.(ini/Registry) (유연성 상승)

- Monitoring Protocol
  - ![image](https://user-images.githubusercontent.com/49339278/140688308-16734de2-57fb-4712-a44a-4a09580266de.png

-----
### tcp.c
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <unistd.h>
#include <netinet/in.h>


extern int fd;
extern int ReadRegAll(double* ax, double* ay, double* az, double* gx, double* gy, double* gz, double* tm);


#define MAX_BUF		1024

int port = 9000;
char* SIP = "192.168.2.100";		// 주소		// 192.168.2.100
char* insa = "안녕하세요. 여기는 라즈베리파이입니다.\r\n";
int main(int argc, char *argv[])
{
	// 1. 소켓을 구성해서 정보를 넣어주는 것
	// 소켓 = integer
	int sock;
	struct sockaddr_in server;
	char buf[MAX_BUF];
	double ax, ay, az, gx, gy, gz, tm;
	
	mpu_init();
	fd = wiringPiI2CSetup(0x68);
	
	strcpy(buf, insa);
	
	if(argc > 1)
	{
		strcpy(buf, argv[1]);		// 문자열 복사함수(null까지 복사해줌)
		// strcpy : 문자열 복사 함수, null까지 복사해줌
		// strncpy : 문자열 복사 함수, null은 복사해주지 않는다. 대신, 크기를 지정해주어야 한다.
	}
	
	// domain 	: AF_INET(address family)
	// type 	: SOCK_STREAM(연결형, TCP)
	// protocol	: 0 또는 IPPROTO_TCP	 (TCP, UDP 상관없이 0으로 설정해도 상관 없음)
	sock = socket(AF_INET, SOCK_STREAM, 0);
	server.sin_family = AF_INET;
	server.sin_port = htons(port);		// small -> Big Endian
	server.sin_addr.s_addr = inet_addr(SIP);	// IP string -> Big Endian IP
	
	// 2. 연결
	connect(sock, (struct sockaddr *)&server, sizeof(server));		// middle 파라미터엔 구조체 형변환이 필요하다!
	printf("%s\n", buf);
	// casting을 하는 이유 : 안해도 상관없지만, sockaddr 구조체의 sa_data 배열에 세부적으로 데이터를 입력해주어야 한다.
	// [0] : port_H / [1] : port_L / [2] : port_IP_A / [3] : port_IP_B / [4] : port_IP_C / [5] : port_IP_D
	// 일일이 입력하는 것보다 구조체로 형변환하는 것이 훨씬 편하다.
	
	// 3. hand shake
	while(1)
	{
		write(sock, buf, strlen(buf));		// strlen : 문자열 길이 
		printf("%s...", buf);
		memset(buf, 0, sizeof(buf));		// read 전에 진행
		read(sock, buf, MAX_BUF);			// NULL('\0') 덧붙이지 않음.
		printf("server > %s\n", buf);		// linux에서 출력하기 위해선, \r\n할 필요 없이 \n만 하면 된다.
		//scanf("%s", buf);	// 공백문자열을 입력할 수 없음
		//fgets(buf, MAX_BUF, stdin);			// 파일로부터 입력받는다. 한 줄씩 읽는다. (그런데 파일이 아니기 때문에, stdin(키보드)으로 설정)
		
		ax = ay = az = gx = gy = gz = tm = 0;
		ReadRegAll(&ax, &ay, &az, &gx, &gy, &gz, &tm);
		sprintf(buf, "%5.2f,%5.2f,%5.2f,%5.2f,%5.2f,%5.2f,%5.2f\n\r",ax,ay,az,gx,gy,gz,tm);
		//if(buf[0] == 'q')	break;
		delay(2000);
	}
	
	
	// utf-8 => 윈도우(ansi) (need converting)
	// 1. 클라이언트(C / linux) ->
	// 2. 서버(C#) -> utf-8 -> ansi형으로 바꿀 수 있도록 변환해준다.
	/* ReadProcess() ==> 수정 필요!
	 * 방법 1
	   ... byte[] aa = Encoding.Convert(Encoding.UTF8, Encoding.Default, bArr, 0, n);	// 뒤에 꼬리가 남는 오류를 해결해줄 수 있다.
	   AddText(Encoding.Default.GetString(aa, 0, aa.Length), 1);
	 * 방법 2 (c style)
	   ... bArr[n] = 0; 
	   byte[] aa = Encoding.Convert(Encoding.UTF8, Encoding.Default, bArr);	// 뒤에 꼬리가 남는 오류를 해결해줄 수 있다.
	   AddText(Encoding.Default.GetString(aa, 0, aa.Length), 1);

	   * 
	   pmnuSendClientText_Click() ==> 수정 필요!
	   byte[] bArr = Encoding.Default.GetBytes(str);
	   byte[] cArr = Encoding.Convert(Encoding.Default, Encoding.UTF8, bArr);
	   sock.Send(cArr);
	   * 
	   pmnuSendServerText_Click() ==> 수정 필요!
	   byte[] cArr = Encoding.Convert(Encoding.Default, Encoding.UTF8, bArr);
	   tcp[GetTcpIndex()].Client.Send(cArr);
	   * try ~ catch 사용하자
	 */
	
	// 4. 종료
	close(sock);
	
	return 0;
}

```
-----

-----
### xiro1.c
```c
#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>

#define	DEVICE_ADDRESS	0X68

// Register Address
#define PWR_MGMT_1    0x6B
#define SMPLRT_DIV    0x19
#define CONFIG        0x1A
#define GYRO_CONFIG   0x1B
#define INT_ENABLE    0x38

#define ACCEL_XOUT_H  0x3B
#define ACCEL_YOUT_H  0x3D
#define ACCEL_ZOUT_H  0x3F

#define	TEMPERTURE	  0x41

#define GYRO_XOUT_H   0x43
#define GYRO_YOUT_H   0x45
#define GYRO_ZOUT_H   0x47

// LED 
#define	RED		27
#define	YELLOW	28
#define	GREEN	29


int fd;

int ReadReg(int addr)		// addr : address
{
	short data_h, data_l, data;	
	data_h = wiringPiI2CReadReg8(fd, addr);		// 16bit data의 상위 8bit data
	data_l = wiringPiI2CReadReg8(fd, addr + 1);	// 16bit data의 하위 8bit data
	//int data = data_h * 256 + data_l;		// 문제 발생 가능성 높음 
	data = (data_h << 8) | data_l;		// 비트 연산 
	return data;
}

void mpu_init()
{
	/*
	PWR_MGMT_1	= 1;
	SMPLRT_DIV	= 7;
	CONFIG		= 1;
	GYRO_CONFIG	= 24;
	INT_ENABLE	= 1;
	*/
	wiringPiI2CWriteReg8(fd, PWR_MGMT_1 , 0x01);
	wiringPiI2CWriteReg8(fd, SMPLRT_DIV, 0x07);
	wiringPiI2CWriteReg8(fd, CONFIG, 0x01);
	wiringPiI2CWriteReg8(fd, GYRO_CONFIG, 0x24);
	wiringPiI2CWriteReg8(fd, INT_ENABLE, 0x01);
}


int ReadRegAll(double* ax, double* ay, double* az, double* gx, double* gy, double* gz, double* tm)
{
	*ax = ReadReg(ACCEL_XOUT_H)/16384.0;
	*ay = ReadReg(ACCEL_YOUT_H)/16384.0;
	*az = ReadReg(ACCEL_ZOUT_H)/16384.0;
		
	*tm = ReadReg(TEMPERTURE) / 340.0 + 36.53;
	
	*gx = ReadReg(GYRO_XOUT_H)/131;
	*gy = ReadReg(GYRO_YOUT_H)/131;
	*gz = ReadReg(GYRO_ZOUT_H)/131;
	return 1;
}

```
-----

-----
### xiro.c
```c
#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>

#define	DEVICE_ADDRESS	0X68

// Register Address
#define PWR_MGMT_1    0x6B
#define SMPLRT_DIV    0x19
#define CONFIG        0x1A
#define GYRO_CONFIG   0x1B
#define INT_ENABLE    0x38

#define ACCEL_XOUT_H  0x3B
#define ACCEL_YOUT_H  0x3D
#define ACCEL_ZOUT_H  0x3F

#define	TEMPERTURE	  0x41

#define GYRO_XOUT_H   0x43
#define GYRO_YOUT_H   0x45
#define GYRO_ZOUT_H   0x47

// LED 
#define	RED		27
#define	YELLOW	28
#define	GREEN	29


extern int fd;
extern int ReadRegAll(double* ax, double* ay, double* az, double* gx, double* gy, double* gz, double* tm);

int main(void)
{
	// gx = 도 / 초 단위의 자이로 x 축 데이터
	// gy = 도 / 초 단위의 자이로 y 축 데이터
	// gz = 도 / 초 단위의 자이로 z 축 데이터
	// ax = 가속도계 x축 데이터 (g)
	// ay = 가속도계 y축 데이터 (g)
	// az = 가속도계 z축 데이터 (g)
	double ax = 0, ay = 0, az = 0, gx = 0, gy = 0, gz = 0, tm = 0;
	fd = wiringPiI2CSetup(DEVICE_ADDRESS);
	
	mpu_init();
	wiringPiSetup();
	
	while(1)
	{
		ReadRegAll(&ax, &ay, &az, &gx, &gy, &gz, &tm);
		
		printf("Acc-X : %.3f Acc-Y : %.3f Acc-Z : %.3f ...", ax, ay, az);
		printf("G-X : %.3f G-Y : %.3f G-Z : %.3f ...", gx, gy, gz);
		printf("Temp : %.3f\n", tm);

		delay(1500);
	}
}

```
-----
- 오늘 사용한 리눅스 터미널 명령어
  1. ```$gcc -o xiro xiro.c xiro1.c -lwiringPi```
  2. ```$gcc -o tcp tcp.c xiro1.c -lwiringPi```
