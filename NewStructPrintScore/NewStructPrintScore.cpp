#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <time.h>
#include <string.h>

// 20210812 미션
// 위의 구조체를 이용하여 사용자 정의 자료형을 선언하고,
// 10명의 학생에 대한 데이터를 입력한 후 정렬하여 출력하시오.

//struct student {
//	int kor;
//	int eng;
//	char name[10];
//};
//
//typedef struct student STU;


const int nArr = 10;

int kor[] = { 67, 70, 77, 65, 68, 72, 79, 55, 85, 61 };
int eng[] = { 70, 75, 80, 60, 65, 55, 80, 95, 67, 84 };
const char* name[nArr] = {"홍길동", "홍길이", "홍길삼", "홍길사", "홍길오", 
						"맹일", "맹이", "맹삼", "맹사", "맹오"};

typedef struct {
	int kor;
	int eng;
	char name[10];
	double tot;
	double avg;
} STU;


STU student[nArr];
void totalswap(void* a, void* b, int op)
{

	switch (op)
	{
	case 1:  // char 
	{
		char temp = *(char*)a;		// 강제 형 변환 추가
		*(char*)a = *(char*)b;
		*(char*)b = temp;
	}
	case 4: // int (float, char* : 4byte)
	{
		int temp = *(int*)a;
		*(int*)a = *(int*)b;
		*(int*)b = temp;
	}
	case 8:  // double
	{
		double temp = *(double*)a;
		*(double*)a = *(double*)b;
		*(double*)b = temp;
	}
	case sizeof(STU):	// STU (사용하기 전 선언되어야 한다.)
		STU temp = *(STU*)a;
		*(STU*)a = *(STU*)b;
		*(STU*)b = temp;
	}
}

void sort(double* a, int op)
{
	int i, j, k;
	for (i = 0; i < nArr; i++)
	{
		for (j = 0; j < nArr; j++)
		{
			if (a[i] > a[j])
			{
				totalswap(a + i, a + j, sizeof(a));
				totalswap(student + i, student + j, sizeof(student));
				// 문자열의 배열 == *
			}
		}
	}
}
// 학생 수는 10명이니, 구조체 배열을 선언해보자.

void sortSTU(STU* a, int op)
{
	int i, j, k;
	for (i = 0; i < nArr; i++)
	{
		for (j = 0; j < nArr; j++)
		{
			if ((a+i)->avg > (a+j)->avg) // 포인터 값
			{
				totalswap(a + i, a + j, sizeof(STU));
			}
		}
	}
}
int sortTest()
{
	double f_kor = 0.3, f_eng = 0.7;	// 가중치
	double tot[nArr];
	//double *tot  = (double *)malloc(sizeof(double)*nArr);


	for (int i = 0; i < nArr; i++)
	{
		//student[i].kor = kor[i];
		//student[i].eng = eng[i];
		strcpy(student[i].name, name[i]);  // 문자열(널 포함 0)은 대입 연산자를 사용할 수 없다. 그래서 strcpy 사용
			// strcpy는 크기에 제한이 없다. 하지만 오류가 발생할 수 있으므로, strncpy 함수를 사용하기도 한다.
			// strncpy의 n : 복사할 문자 수
			// size_t는? 변수의 type으로, long이라고 생각하면 된다.
 
			// strcpy는 '\0'까지 복사된다.
			// strncpy는 '\0'이 복사가 되지 않는다.
 
 
        // 예시
		//		char *a = "Good morning";
		//		char buf[10];
		//		
		//		strncpy(buf, a, 4);  // null 없음
		//		buf[4] = 0;  // null (반드시 필요한 과정)
		//		printf("%s", buf);  // Good??
 
		tot[i] = (student[i].kor = kor[i]) + (student[i].eng = eng[i]);
		student[i].avg = (student[i].kor = kor[i]) * f_kor + (student[i].eng = eng[i]) * f_eng;
	}


	printf("Original : \n");
	printf("이름 : "); for (int i = 0; i < nArr; i++) printf("%7s ", student[i].name); printf("\n\n");
	printf("국어 : "); for (int i = 0; i < nArr; i++) printf("%7d ", student[i].kor); printf("\n\n");
	printf("영어 : "); for (int i = 0; i < nArr; i++) printf("%7d ", student[i].eng); printf("\n\n");
	printf("합계 : "); for (int i = 0; i < nArr; i++) printf("%7.2f ", tot[i]); printf("\n\n");
	printf("평균 : "); for (int i = 0; i < nArr; i++) printf("%7.2f ", student[i].avg); printf("\n\n");

	sortSTU(student, nArr);		// 정렬

	printf("Sorted : \n");
	printf("이름 : "); for (int i = 0; i < nArr; i++) printf("%7s ", student[i].name); printf("\n\n");
	printf("국어 : "); for (int i = 0; i < nArr; i++) printf("%7d ", student[i].kor); printf("\n\n");
	printf("영어 : "); for (int i = 0; i < nArr; i++) printf("%7d ", student[i].eng); printf("\n\n");
	printf("합계 : "); for (int i = 0; i < nArr; i++) printf("%7.2f ", tot[i]); printf("\n\n");
	printf("평균 : "); for (int i = 0; i < nArr; i++) printf("%7.2f ", student[i].avg); printf("\n\n");

	return 0;
}


int sortTestEx() // 구조체를 이용한 성적 처리 - 파일 입출력
{
	int n = 10;
	double f_kor = 0.3, f_eng = 0.7;	// 가중치
	//double tot[nArr], avg[nArr];
	int i, j, k;

	//****************************************************************************
	//****************************************************************************
	//****************************************************************************
	int num;   // file에서 read
	STU *students;  // malloc 으로 메모리 확보
	//****************************************************************************
	//****************************************************************************
	//****************************************************************************



	FILE* fin = fopen("C:\\Users\\KOSTA\\table1.txt", "r");
	FILE* fout = fopen("C:\\Users\\KOSTA\\table1.rpt", "w+b");
	fscanf(fin, "%d", &num);
	students = (STU *)malloc(sizeof(STU)*num);
	for (i = 0; i < nArr; i++)	fscanf(fin, "%s", students[i].name); // Debugging
	for (i = 0; i < nArr; i++)	fscanf(fin, "%d", &students[i].kor);
	for (i = 0; i < nArr; i++)	fscanf(fin, "%d", &students[i].eng);
	for (i = 0; i < nArr; i++)
	{
		students[i].tot = students[i].kor + students[i].eng;
		students[i].avg = students[i].tot/2;
	}

	fprintf(fout, "Original : \n"); fprintf(fout,"%-7s %-7s %-7s %-7s %-7s\n", "  이름", "  국어", "  영어", "  총점", "  평균");
	for (int i = 0; i < n; i++)
	{
		fprintf(fout,"%7s %7d %7d %7.2f %7.2f\n", students[i].name,
		students[i].kor, students[i].eng, students[i].tot, students[i].avg);
	}

	sortSTU(students, nArr);		// 정렬

	fprintf(fout,"\n\nSorted : \n");
	for (int i = 0; i < n; i++)
	{
		fprintf(fout,"%7s %7d %7d %7.2f %7.2f\n", (students+i)->name,
			(students+i)->kor, (students+i)->eng, (students+i)->tot, (students+i)->avg);
	}

	fclose(fin);   // 파일을 열었다면 닫아야 한다는 생각을 가질 수 있도록 하자.
	fclose(fout);
	// 한 방에 닫기 위해서는?
	// fcloseall();  // 현재 열려 있는 모든 파일을 닫으라는 뜻

	return 0;
}


void StreamTest()
{
	int m, i, j;
	float d;
	char buf[1024];

	// cmd -> echo "입력할 내용" > "저장 파일명.저장 파일확장자"
	FILE* fin = fopen("C:\\Users\\KOSTA\\aa", "r");  
	FILE* fout = fopen("C:\\Users\\KOSTA\\aa.re", "a+b");
					// r : read, w : write(overwrite), a : append(추가)
					// 만약 파일이 존재하지 않으면 -1 반환. 즉 오류 반환
	if (fin != NULL)
	{
		// CRLF의 white space 제거해야 함.
		fscanf(fin, "%d %f %s", &m, &d, buf); // 데이터 입력 -> 구조체로 load -> swap, sorting -> 출력
		fprintf(fout, "정수 : %d \n 실수 :%f\n 인사: %s\n", m, d, buf); // 출력
		printf("정수 : % d \n 실수 : % f\n 인사 : % s\n", m, d, buf);
		while (1)
		{
			//fgets(buf, 1024, stdin);				// 파일 입력
			//										// stdin : 이미 존재하고 있는 파일
			//if (strlen(buf) < 3) break;				// enter 자체도 \n이므로 문자열 길이가 0이 아니다.
			//fputs("==== 입력문자열 ====>", stdout);		// stdout : 이미 존재하고 있는 파일 -> 언제든 사용이 가능하다는 것
			
			if (fgets(buf, 1024, fin) == NULL) break;
			fputs(buf, stdout);
			//fputs(buf, fout0);
			//fputs(buf, fout1);
			//fputs(buf, fout2);
			// 차이점
			// aa.o1은 메모장을 실행하면 Windows(CRLF) 형식으로 나온다.
			// aa.02는 메모장을 실행하면 Linux(LF) 형식으로 나온다. binary 모드로 출력하였을 때,
			// 즉, CR이 사라짐

			// fscanf( , , , , )
			// fprintf( , , , , )
		}
		
	}
	else printf("입력 파일이 존재하지 않습니다.\n");
}

#define KBD_BUF_SIZE 20
#define MAX(x,y) (x>y)? x:y
#define MIN(x,y) (x<y)? x:y

int GetInt()
{
	// 호출이 되면 무조건 키보드에서 값을 입력받아서 int형으로 반환하는 것
	char buf[KBD_BUF_SIZE];
	fgets(buf, KBD_BUF_SIZE, stdin);    // stdin : Keyboard until [Enter]
	return(atoi(buf));
}

double GetDouble()
{
	char buf[KBD_BUF_SIZE];
	fgets(buf, KBD_BUF_SIZE, stdin); 
	return(atof(buf));
}

void StringParse()   // 문자열을 입력받아서 int, double, 문자열 입력을 수행 (scanf을 사용하지 않고)
{
	while (1)
	{
		int k;
		char b[5];   // buffer
		printf("\n\n\n ====문자열 변환 테스트 + @ ===\n"
			"	1.정수(int)\n"
			"	2.실수(double)\n"
			"	3.문자열(공백포함)\n"
			"	4.매크로 함수 테스트\n"
			"	0.Exit\n"
			"======================\n"
			"	Select Menu : ");
		//scanf("%d", &k);  // 최종 kbd buffer의 [Enter] 키 처리 필요
		/* scanf함수에 입력값을 넣을 때, 입력 값에 항상 enter가 들어감 근데 enter가 남아 있음*/
		//fflush(stdin);  // fflush를 사용해서 입력 키값을 키보드 버퍼를 지워라고 명령을 함. 그런데 잘 안됨
						// 그래서 fflust가 enter를 지우는 역할을 함
						// 원래 fflust는 출력 버퍼용이다. 그래서 어떤 시스템에서는 작동될 수도 있고 아닐 수도 있다.
						// 정확하게 하기 위해서는 fgets 함수에 대해 루프를 돌려주어야 한다.

		// scanf 대신에 fgets를 사용하기를 권장한다.
		fgets(b, 5, stdin);  // 입력 처리

		// 이상하게 두 개가 출력되는 이유 : scanf의 \n 개행문자 때문

		if (*b == '1')  // (k==1), (b[0] == 0x31), (b[0] == '1')
		{
			// 먼저 정수를 문자열로 입력받음
			char buf[KBD_BUF_SIZE];
			printf("정수를 입력하세요 : ");  // prompt message
			// scanf("%s", KB_BUT{SIZE);  // 기본적인 문자열 입력
			//fgets(buf, KBD_BUF_SIZE, stdin);  // 별로 추천되지 않는다. 특수 파일 입출력을 쓸 것임 ; fgets
			//									// enter 키가 눌릴때까지 받아주는 함수이다.
			//									// 
			//int n = atoi(buf);
			printf("변환된 정수값은 %d 입니다.\n\n", GetInt());// stdon : 키보드입력(key board)
		}
		if (*b == '2')	// else를 붙이지 않는 이유는, k==1을 수행하고 나서, 다시 else if (k==2)를 체크하게 됨
					// 그런데 k값이 그대로 바뀌지 않고 유지가 되는데, 이 시점에서 k==2이냐를 비교했을 때,
					// 위의 k == 1값을 그대로 내려와서 k==2문을 쓰지 않고 else로 넘어감

					// 만약 else를 붙이게 된다면, k==1인 경우에 대해 수행한 후, 빠져 나온 다음에 else문을
					// 만나게 되는데, 그러면 당연히 넘어가게 된다. 따라서 else을 붙이는 여부는 실행하냐 아니냐
					// 이다. 모두를 거쳐서 가기위해서는 else문을 쓰면 안된다.
		{
			char buf[KBD_BUF_SIZE];
			printf("실수를 입력하세요 : ");  // prompt message
			// scanf("%s", KB_BUT{SIZE);  // 기본적인 문자열 입력
			//fgets(buf, KBD_BUF_SIZE, stdin);  // 별로 추천되지 않는다. 특수 파일 입출력을 쓸 것임 ; fgets
			//double n = atof(buf);
			printf("변환된 실수값은 %f 입니다.\n\n", GetDouble());// stdon : 키보드입력(key board)
		}
		if (*b == '3')
		{
			char buf[KBD_BUF_SIZE];
			printf("문자열을 입력하세요 : ");  // prompt message
			// scanf("%s", KB_BUT{SIZE);  // 기본적인 문자열 입력
			fgets(buf, KBD_BUF_SIZE, stdin);  // 별로 추천되지 않는다. 특수 파일 입출력을 쓸 것임 ; fgets
			printf("변환된 문자열은 %s 입니다.\n\n", buf);// stdon : 키보드입력(key board)
		}
		if (*b == '4')
		{
			int x, y;
			float x1, y1;
			printf("두 개의 정수를 입력하세요 : ");  // prompt message
			//scanf("%d %d", &x, &y);  // GetInt 함수 생성하기
			x = GetInt();	y = GetInt();
			printf("두 개의 정수 %d와 %d 중 큰 수는 %d입니다.\n\n\n", x, y, MAX(x,y));
			printf("두 개의 실수를 입력하세요 : ");  // prompt message
			//scanf("%f %f", &x1, &y1);  // GetDouble 함수 생성하기
			x1 = GetDouble();	y1 = GetDouble();
			printf("두 개의 실수 %f와 %f 중 큰 수는 %f입니다.\n", x1, y1, MAX(x1, y1));
		}

		if (*b == '0') break;
	}
}


int main()
{
	int k;
	printf("\n\n\n =========================\n"
		"	1.sortTest();\n"
		"	2.StreamTest();\n"
		"	3.sortTestEx();\n"
		"	4.StringParse();\n"  // 문자열 변환 테스트
		"	0.Exit\n\n"
		"======================"
		"	Select Menu : ");

	//scanf("%d", &k);
	k = GetInt();   // scanf의 큰 단점인 \n이 남는 것이 사라짐!
	// 단, fgets는 LF문자가 만날 때까지 받는 함수임. 즉, 한 줄 단위로 읽어들인다는 것으로, 공백 등 기타 여러 문자가
	// 들어갈 수도 잇다. 개행 문자가 나올 때까지 한 줄씩 읽어드리는 특징 가짐
	// enter값이 나와야만 값을 보내준다. 

	while (1)
	{
		// sortTest();    // 1
		// StreamTest();  // 2
		// sortTestEx();  // 3
		// SortingParse();// 4
		if (k == 1) 
		{
			sortTest();
			break;
		}
		else if (k == 2) 
		{ 
			StreamTest();
			break; 
		}
		else if (k == 3) 
		{
			sortTestEx();
			break; 
		}
		else if (k == 4) 
		{
			StringParse();
			break; 
		}
		else
		{
			break;
		}	

	}

}