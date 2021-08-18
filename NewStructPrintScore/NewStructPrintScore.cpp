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

//void sort(double* a, int op)
//{
//	int i, j, k;
//	for (i = 0; i < nArr; i++)
//	{
//		for (j = 0; j < nArr; j++)
//		{
//			if (a[i] < a[j])
//			{
//				totalswap(a + i, a + j, 8);
//				totalswap(student + i, student + j, 18);
//				// 문자열의 배열 == *
//			}
//		}
//	}
//}
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
//int sortTest()
//{
//	double f_kor = 0.3, f_eng = 0.7;	// 가중치
//	double tot[nArr];
//	int i, j, k;
//
//
//	for (int i = 0; i < nArr; i++)
//	{
//		//student[i].kor = kor[i];
//		//student[i].eng = eng[i];
//		strcpy(student[i].name, name[i]);
//		tot[i] = (student[i].kor = kor[i]) * f_kor + (student[i].eng = eng[i]) * f_eng;
//		// tot[i] = student.kor[i] * f_kor + student.eng[i] * f_eng;
//	}
//
//
//	printf("Original : \n");
//	printf("이름 : "); for (int i = 0; i < nArr; i++) printf("%7s ", student[i].name); printf("\n\n");
//	printf("국어 : "); for (int i = 0; i < nArr; i++) printf("%7d ", student[i].kor); printf("\n\n");
//	printf("영어 : "); for (int i = 0; i < nArr; i++) printf("%7d ", student[i].eng); printf("\n\n");
//	printf("합계 : "); for (int i = 0; i < nArr; i++) printf("%7.2f ", tot[i]); printf("\n\n");
//
//	sort(tot, nArr);		// 정렬
//
//	printf("Sorted : \n");
//	printf("이름 : "); for (int i = 0; i < nArr; i++) printf("%7s ", student[i].name); printf("\n\n");
//	printf("국어 : "); for (int i = 0; i < nArr; i++) printf("%7d ", student[i].kor); printf("\n\n");
//	printf("영어 : "); for (int i = 0; i < nArr; i++) printf("%7d ", student[i].eng); printf("\n\n");
//	printf("합계 : "); for (int i = 0; i < nArr; i++) printf("%7.2f ", tot[i]); printf("\n\n");
//
//	return 0;
//}


int sortTestEx() // 구조체를 이용한 성적 처리 - 파일 입출력
{
	int n = 10;
	double f_kor = 0.3, f_eng = 0.7;	// 가중치
	double tot[nArr], avg[nArr];
	int i, j, k;

	FILE* fin = fopen("C:\\Users\\KOSTA\\table1.txt", "r");
	FILE* fout = fopen("C:\\Users\\KOSTA\\table1.rpt", "w+b");
	for (i = 0; i < nArr; i++)	fscanf(fin, "%s", student[i].name); // Debugging
	for (i = 0; i < nArr; i++)	fscanf(fin, "%d", &student[i].kor);
	for (i = 0; i < nArr; i++)	fscanf(fin, "%d", &student[i].eng);
	for (i = 0; i < nArr; i++)
	{
		student[i].tot = student[i].kor + student[i].eng;
		student[i].avg = student[i].tot/2;
	}

	fprintf(fout, "Original : \n"); fprintf(fout,"%-7s %-7s %-7s %-7s %-7s\n", "  이름", "  국어", "  영어", "  총점", "  평균");
	for (int i = 0; i < n; i++)
	{
		fprintf(fout,"%7s %7d %7d %7.2f %7.2f\n", student[i].name,
		student[i].kor, student[i].eng, student[i].tot, student[i].avg);
	}

	sortSTU(student, nArr);		// 정렬

	fprintf(fout,"\n\nSorted : \n");
	for (int i = 0; i < n; i++)
	{
		fprintf(fout,"%7s %7d %7d %7.2f %7.2f\n", student[i].name,
			student[i].kor, student[i].eng, student[i].tot, student[i].avg);
	}

	return 0;
}


/*void StreamTest()
{
	int m, i, j;
	float d;
	char buf[1024];

	// cmd -> echo "입력할 내용" > "저장 파일명.저장 파일확장자"
	FILE* fin = fopen("C:\\Users\\KOSTA\\table1.txt", "r");  
	FILE* fout = fopen("C:\\Users\\KOSTA\\tabler.txt", "a+b");
					// r : read, w : write(overwrite), a : append(추가)
					// 만약 파일이 존재하지 않으면 -1 반환. 즉 오류 반환
	if (fin != NULL)
	{
		// CRLF의 white space 제거해야 함.
		fscanf(fin, "%s %d %d", buf[j], &m[j], &i[j]); // 데이터 입력 -> 구조체로 load -> swap, sorting -> 출력
		fprintf(fout, "이름 : %s \n 국어 :%d\n 영어: %d\n", buf, m, i); // 출력
		printf("이름 : %s \n 국어 :%d\n 영어: %d\n", buf, m, i);
		//while (1)
		//{
		//	//fgets(buf, 1024, stdin);				// 파일 입력
		//	//										// stdin : 이미 존재하고 있는 파일
		//	//if (strlen(buf) < 3) break;				// enter 자체도 \n이므로 문자열 길이가 0이 아니다.
		//	//fputs("==== 입력문자열 ====>", stdout);		// stdout : 이미 존재하고 있는 파일 -> 언제든 사용이 가능하다는 것
		//	
		//	if (fgets(buf, 1024, fin) == NULL) break;
		//	fputs(buf, stdout);
		//	//fputs(buf, fout0);
		//	//fputs(buf, fout1);
		//	//fputs(buf, fout2);
		//	// 차이점
		//	// aa.o1은 메모장을 실행하면 Windows(CRLF) 형식으로 나온다.
		//	// aa.02는 메모장을 실행하면 Linux(LF) 형식으로 나온다. binary 모드로 출력하였을 때,
		//	// 즉, CR이 사라짐

		//	// fscanf( , , , , )
		//	// fprintf( , , , , )
		//}
		
	}
	else printf("입력 파일이 존재하지 않습니다.\n");
}*/

int main()
{
	//sortTest();
	//StreamTest();
	sortTestEx();
}