#include <stdio.h>
#include <conio.h>


// Function Test 프로그램
// 기능 : 키보드에서 단일 문자를 입력받고
//	      해당 문자가 대문자0/소문자1/특수2/숫자키3 임을 분류 -> 유형에 대한 특정한 값을 만들어서 값에 따라서 분류를 할 수 있도록
//	----- 함수를 선언하고 호출할 것. -- 함수명 : sub

/* 프로그램을 작성할 때, 누구한테 보여준다고 생각하고 클린하고 작성하고
설명을 위해 가능한 많이 주석을 달아 놓자. 주석을 작성하지 않으면 잊어먹는 경우가 많기 때문에
나중을 위해 친절하고 상세하게 작성해 두자*/

int sub(char a);

int main(void)
{
	int i, j, k;
	char c;

	// 숫자 키인지 아닌지 판별하는 구분 -> 구분하기 위해 ASCII 코드 확인해야 한다. (깃허브에 ASCII 코드 목록 첨부)

	while(1) 
	{
		printf("아무 키나 입력하세요");
		c = getch();			// getch() 함수는 하나의 단일 문자를 돌려 받는 일종의 함수이다.
								// sdl 검사 아니오 체크하기
		if (c == 'z') break;
//		if (sub(c) == 0)
//		{
//			printf(">입력하신 Key ['%c']는 대문자입니다.\n", c);	// A ~ Z 키에 해당하는가?
																	// A ~ Z : 65 ~ 90 (decimal) -> 컴퓨터 : 0x41 ~ 0x5A (hexadecimal)로 인식
//		}
//		else if (sub(c) == 1)
//		{
//			printf(">입력하신 Key ['%c']는 소문자입니다.\n", c);		// a ~ z 키에 해당하는가?
																		// a ~ z : 97 ~ 122 (decimal) -> 컴퓨터 : 0x61 ~ 0x7A (hexadecimal)로 인식
//		}
//		else if (sub(c) == 2)
//		{
//			printf(">입력하신 Key ['%c']는 특수키입니다.\n", c);
//		}
//		else
//		{
//			printf(">입력하신 Key ['%c']는 숫자입니다.\n", c);			// 0 ~ 9번 키에 해당하는가?		
																		// 0 ~ 9 : 48 ~ 57 (decimal) -> 컴퓨터 : 0x30 ~ 0x39 (hexadecimal)로 인식

		// switch문 
		int num = sub(c);
		switch (num)
		{
		case 0:  printf(">입력하신 Key ['%c']는 대문자입니다.\n", c);	break;
		case 1:  printf(">입력하신 Key ['%c']는 소문자입니다.\n", c);	break;
		case 2:  printf(">입력하신 Key ['%c']는 특수키입니다.\n", c);	break;
		case 3:  printf(">입력하신 Key ['%c']는 숫자입니다.\n", c);		break;
		default: break;

		}
	}

}

int sub(char a)		// 입력 값에 대한 키 분류 값 리턴
{
	int ret;		// 분류 값

	if (a >= 0x30 && a <= 0x39) ret = 3;		// 숫자 키 : 3
	else if (a >= 0x41 && a <= 0x5A) ret = 0; 	// 대문자 키 : 0
	else if (a >= 0x61 && a <= 0x7A) ret = 1; 	// 소문자 키 : 1
	else ret = 2;								// 특수문자 키(기타 나머지) : 2

	return ret;
}