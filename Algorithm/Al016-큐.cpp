#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;
typedef struct IntQ {
	int *FPQue;         // Queue의 초기 주소값
	int counter;       // Queue의 현재 개수
	int QueSize;      // Queue의 전체 사이즈
	int start;		 // Queue의 맨 앞 위치
	int end;		// Queue의 맨 뒤 위치
}IntQ;
void Initialize(IntQ *q, int QueSize);
int Size(IntQ *q);
int Capacity(IntQ *q);
int EnQue(IntQ *q, int x);
int DeQue(IntQ *q, int x);
int Peek(IntQ *q, int *x);
int Search(IntQ *q, int x);
void PrintQueue(IntQ *q);
void Clear(IntQ *q);
void Exit(IntQ *q);
int main()
{
	int Qsize = 0;
	IntQ q;
	printf("생성하고자 하는 큐의 개수를 입력하세요.\n");
	scanf("%d", &Qsize);
	system("cls");
	Initialize(&q, Qsize);
	while (1)
	{
		system("cls");
		int menu, x;
		x = 0;
		int tmp = 0;
		printf("현재 데이터 수 : %d / %d\n", Size(&q), Capacity(&q));
		printf("(1)인큐   (2)디큐   (3)피크   (4)검색   (5)전체 출력   (9)전체 비우기   (0)종료\n");
		scanf("%d", &menu);
		if (menu == 0)
			break;
		switch (menu)
		{
		case 1:
			printf("데이터 : ");
			scanf("%d", &x);
			if (EnQue(&q, x) == -1)
			{
				puts("오류 : 인큐에 실패하셨습니다.");
				Sleep(1000);
			}
			break;
		case 2:
			tmp = DeQue(&q, x);
			if (tmp == -1)
			{
				puts("오류 : 디큐에 실패하셨습니다.");
				Sleep(1000);
			}
			else
			{
				printf("디큐 데이터는 %d입니다.\n", tmp);
				getch();
			}
			break;
		case 3:
			if (Peek(&q, &x) == -1)
			{
				puts("오류 : 피크에 실패하셨습니다.");
				Sleep(1000);
			}
			else
			{
				printf("피크 데이터는 %d입니다.\n", x);
				getch();
			}
			break;
		case 4:
			printf("찾고자 하는 데이터를 입력하세요. : ");
			scanf("%d", &x);
			tmp = Search(&q, x);
			if (tmp == -1)
			{
				puts("오류 : 검색에 실패하셨습니다.");
				Sleep(1000);
			}
			else
			{
				printf("찾고자 하는 데이터는 %d번째에 있습니다.", tmp);
				getch();
			}
			break;
		case 5:
			PrintQueue(&q);
			getch();
			break;
		case 9:
			Clear(&q);
			puts("큐 전체를 비웠습니다.\n");
			Sleep(1000);
			break;
		case 0:
			Exit(&q);
			Exit(0);
			break;
		default:
			break;
		}
	}
}
void Initialize(IntQ *q, int QueSize)
{
	q->counter = 0;
	q->start = 0;
	q->end = 0;
	q->FPQue = (int *)calloc(QueSize, sizeof(IntQ));
	q->QueSize = QueSize;
}
int Size(IntQ *q)
{
	return q->counter;
}
int Capacity(IntQ *q)
{
	return q->QueSize;
}
int EnQue(IntQ *q, int x)
{
	if (q->counter == q->QueSize)
		return -1;
	q->counter++;
	q->FPQue[q->end] = x;
	q->end++;
	if (q->end == q->QueSize)
		q->end = 0;
	return 0;
}
int DeQue(IntQ *q, int x)
{
	if (q->counter == 0)
	{
		x = -1;
		return x;
	}
	q->counter--;
	x = q->FPQue[q->start];
	q->FPQue[q->start] = 0;
	q->start++;
	if (q->start == q->QueSize)
		q->start = 0;
	return x;
}
int Peek(IntQ *q, int *x)
{
	if (q->counter == 0)
		return -1;
	*x = q->FPQue[q->start];
	return 0;
}
int Search(IntQ *q, int x)
{
	int i = 0;
	for (i = q->start; i < q->start+q->counter; ++i)
	{
		if (q->FPQue[i % q->QueSize] == x)
			return i % q->QueSize;
	}
	return -1;
}
void PrintQueue(IntQ *q)
{
	int i = 0;
	for (i = q->start; i < q->start+q->counter; ++i)
	{
		printf("%d번째 데이터는 %d입니다.\n", i%q->QueSize, q->FPQue[i%q->QueSize]);
	}
}
void Clear(IntQ *q)
{
	q->counter = 0;
	q->start = 0;
	q->end = 0;
}
void Exit(IntQ *q)
{
	free(q);
}