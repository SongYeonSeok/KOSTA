// tcp.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wiringPi.h>
#include <unistd.h>
#include <netinet/in.h>

#define MAX_BUF		1024

int port = 9000;
char* SIP = "192.168.2.64";		// 주소		// 192.168.2.100
char* insa = "안녕하세요. 여기는 라즈베리파이입니다.\r\n";
int main(int argc, char *argv[])
{
	// 1. 소켓을 구성해서 정보를 넣어주는 것
	// 소켓 = integer
	int sock;
	struct sockaddr_in server;
	char buf[1024];
	
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
				
		memset(buf, 0, sizeof(buf));		// read 전에 진행
		read(sock, buf, MAX_BUF);			// NULL('\0') 덧붙이지 않음.
		printf("server > %s\n", buf);		// linux에서 출력하기 위해선, \r\n할 필요 없이 \n만 하면 된다.
		//scanf("%s", buf);	// 공백문자열을 입력할 수 없음
		fgets(buf, MAX_BUF, stdin);			// 파일로부터 입력받는다. 한 줄씩 읽는다. (그런데 파일이 아니기 때문에, stdin(키보드)으로 설정)
		if(buf[0] == 'q')	break;
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
