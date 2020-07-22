#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;
typedef struct IntQ {
	int *FPQue;         // Queue�� �ʱ� �ּҰ�
	int counter;       // Queue�� ���� ����
	int QueSize;      // Queue�� ��ü ������
	int start;		 // Queue�� �� �� ��ġ
	int end;		// Queue�� �� �� ��ġ
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
	printf("�����ϰ��� �ϴ� ť�� ������ �Է��ϼ���.\n");
	scanf("%d", &Qsize);
	system("cls");
	Initialize(&q, Qsize);
	while (1)
	{
		system("cls");
		int menu, x;
		x = 0;
		int tmp = 0;
		printf("���� ������ �� : %d / %d\n", Size(&q), Capacity(&q));
		printf("(1)��ť   (2)��ť   (3)��ũ   (4)�˻�   (5)��ü ���   (9)��ü ����   (0)����\n");
		scanf("%d", &menu);
		if (menu == 0)
			break;
		switch (menu)
		{
		case 1:
			printf("������ : ");
			scanf("%d", &x);
			if (EnQue(&q, x) == -1)
			{
				puts("���� : ��ť�� �����ϼ̽��ϴ�.");
				Sleep(1000);
			}
			break;
		case 2:
			tmp = DeQue(&q, x);
			if (tmp == -1)
			{
				puts("���� : ��ť�� �����ϼ̽��ϴ�.");
				Sleep(1000);
			}
			else
			{
				printf("��ť �����ʹ� %d�Դϴ�.\n", tmp);
				getch();
			}
			break;
		case 3:
			if (Peek(&q, &x) == -1)
			{
				puts("���� : ��ũ�� �����ϼ̽��ϴ�.");
				Sleep(1000);
			}
			else
			{
				printf("��ũ �����ʹ� %d�Դϴ�.\n", x);
				getch();
			}
			break;
		case 4:
			printf("ã���� �ϴ� �����͸� �Է��ϼ���. : ");
			scanf("%d", &x);
			tmp = Search(&q, x);
			if (tmp == -1)
			{
				puts("���� : �˻��� �����ϼ̽��ϴ�.");
				Sleep(1000);
			}
			else
			{
				printf("ã���� �ϴ� �����ʹ� %d��°�� �ֽ��ϴ�.", tmp);
				getch();
			}
			break;
		case 5:
			PrintQueue(&q);
			getch();
			break;
		case 9:
			Clear(&q);
			puts("ť ��ü�� ������ϴ�.\n");
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
		printf("%d��° �����ʹ� %d�Դϴ�.\n", i%q->QueSize, q->FPQue[i%q->QueSize]);
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