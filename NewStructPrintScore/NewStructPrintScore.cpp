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

int main()
{
	int k;
	printf(
		"	1.sortTest();\n"
		"	2.StreamTest();\n"
		"	3.sortTestEx();\n"
		"	0. Exit\n\n"
		"======================"
		"	Select Menu : ");

	scanf("%d", &k);

	switch (k)
	{
		// sortTest();    // 1
		// StreamTest();  // 2
		// sortTestEx();  // 3
	case 1:	sortTest();		break;
	case 2: StreamTest();	break;
	case 3:	sortTestEx();	break;
	case 4: case 5: case 6: case 7: case 8: case 9:
	default:	break;
	}
}