#include"stdafx.h"
//#include <stdlib.h>
//#include <iostream>
//#include <Windows.h>
//void gotoxy(int x, int y)					// 좌표 찍는 함수 선언
//{
//	COORD pos = { x,y };
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
//}
//using namespace std;
//void View();
//int x = 0;
//typedef struct IntStack {
//	int max;
//	int ptr;
//	int *stk;
//}IntStack;
//IntStack AStack;
//IntStack BStack;
//IntStack CStack;
//int InitializeStack(IntStack *s, int max);
//int Push(IntStack *s, int x);
//int Pop(IntStack *s, int *x);
//int PeekStack(const IntStack *s, int *x);
//void PrintStack(const IntStack *s);
//void Hanoi(int orbis, IntStack & a, IntStack & b);	// 원반 확인, 출발 스택, 도착 스택
//int main()
//{
//	int NUM = 2;
//	InitializeStack(&AStack, NUM);
//	InitializeStack(&BStack, NUM);
//	InitializeStack(&CStack, NUM);
//	int i = 0;
//
//	for (i = NUM; i >=0; --i)
//	{
//		Push(&AStack, i);
//	}
//	View();
//	Hanoi(1, AStack, BStack);
//	View();
//	Hanoi(2, AStack, CStack);
//	View();
//	Hanoi(1, BStack, CStack);
//	View();
//}
//void View()
//{
//	cout << "=================================================" << endl;
//	PrintStack(&AStack);
//	PrintStack(&BStack);
//	PrintStack(&CStack);
//	cout << "A" << "\t\t\t" << "B" << "\t\t\t" << "C" << endl << endl;
//}
//int InitializeStack(IntStack *s, int max)
//{
//	s->ptr = 0;
//	if ((s->stk = (int *)calloc(max, sizeof(int))) == NULL)
//	{
//		s->max = 0;
//		return -1;
//	}
//	s->max = max;
//	return 0;
//}
//int Push(IntStack *s, int x)
//{
//	if (s->ptr >= s->max)
//		return -1;
//	s->stk[s->ptr++] = x;
//	return 0;
//}
//int Pop(IntStack *s, int *x)
//{
//	if (s->ptr <= 0)
//		return -1;
//	s->ptr--;
//	*x = s->stk[s->ptr];
//}
//int PeekStack(const IntStack *s, int *x)
//{
//	if (s->ptr <= 0)
//		return -1;
//	*x = s->stk[s->ptr - 1];
//	return 0;
//}
//void Hanoi(int orbis, IntStack & a, IntStack & b)
//{
//	PeekStack(&a, &x);
//	if (orbis == x)
//	{
//		Pop(&a, &x);
//		Push(&b, x);
//	}
//}
//void PrintStack(const IntStack *s)
//{
//	int i;
//	for (i = 0; i < s->ptr; ++i)
//		printf("%d\n", s->stk[i]);
//}