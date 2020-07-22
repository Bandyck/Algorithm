#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <conio.h>
using namespace std;
char Operator[] = { '(',')','+','-','*','/','.' };
char Num[] = { '0','1','2','3','4','5','6','7','8','9' };
typedef struct CharStack {
	int max;
	int ptr;
	char *stk;
}CharStack;
typedef struct StringQueue {
	int max;
	int num;
	int front;
	int rear;
	string *que;
}StringQueue;
typedef struct DoubleStack {
	int max;
	int ptr;
	double *stk;
}doubleStack;
int InitializeStack(CharStack *s, int max);
int InitializedStack(DoubleStack *s, int max);
int Push(CharStack *s, char x);
int dPush(DoubleStack *s, double x);
int Pop(CharStack *s, char *x);
int dPop(DoubleStack *s, double *x);
int PeekStack(const CharStack *s, char *x);
int InitializeQueue(StringQueue *q, int max);
int Enque(StringQueue *q, string x);
int Deque(StringQueue *q, string *x);
int PeekQueue(const StringQueue *q, string *x);
int OperatorTrigger(char);
int NumTrigger(char x);
void PrintStack(const CharStack *s);
void PrintQueue(const StringQueue *q);
int main()
{
	char Ex[] = "(2*-6-3-2-1*2)";
	int i = 0;
	char sx = 0;
	string qx;
	double dsx = 0;
	CharStack OperatorStack;
	StringQueue PostFix;
	doubleStack Operand;
	string Numstr;

	InitializeStack(&OperatorStack, strlen(Ex));
	InitializeQueue(&PostFix, strlen(Ex));
	InitializedStack(&Operand, strlen(Ex));

	if (OperatorTrigger(Ex[i]) != -1)
	{
		switch (OperatorTrigger(Ex[i]))
		{
		case 0:
			Push(&OperatorStack, Ex[i]);
			break;
		case 3:
			Numstr = Ex[i];
			break;
		default:
			return 0;
		}
	}
	else
	{
		if (NumTrigger(Ex[i]) != -1)
		{
			Numstr = Ex[i];
		}
		else
			return 0;
	}

	for (i = 1; i < strlen(Ex); ++i)
	{
		if (OperatorTrigger(Ex[i]) != -1)
		{
			switch (OperatorTrigger(Ex[i]))
			{
			case 0:
				Push(&OperatorStack, Ex[i]);
				break;
			case 4:
				Push(&OperatorStack, Ex[i]);
				break;
			case 5:
				Push(&OperatorStack, Ex[i]);
				break;
			case 6:
				Numstr += Ex[i];
				break;
			case 2:
				while (1)
				{
					PeekStack(&OperatorStack, &sx);
					if (sx == Operator[4] || sx == Operator[5])
					{
						Pop(&OperatorStack, &sx);
						string tmp;
						tmp += sx;
						Enque(&PostFix, tmp);
					}
					else
					{
						Push(&OperatorStack, Ex[i]);
						break;
					}
				}
				break;
			case 3:
				if (Ex[i - 1] == Operator[0] || Ex[i - 1] == Operator[2] || Ex[i - 1] == Operator[4] || Ex[i - 1] == Operator[5])
				{
					Numstr += Ex[i];
					break;
				}
				while (1)
				{
					PeekStack(&OperatorStack, &sx);
					if (sx == Operator[4] || sx == Operator[5])
					{
						Pop(&OperatorStack, &sx);
						string tmp;
						tmp += sx;
						Enque(&PostFix, tmp);
					}
					else
					{
						Push(&OperatorStack, Ex[i]);
						break;
					}
				}
				break;
			case 1:
				while (1)
				{
					PeekStack(&OperatorStack, &sx);
					if (sx == Operator[0])
					{
						Pop(&OperatorStack, &sx);
						break;
					}
					else
					{
						Pop(&OperatorStack, &sx);
						string tmp;
						tmp += sx;
						Enque(&PostFix, tmp);
					}
				}
				break;
			default:
				return 0;
			}
		}
		else
		{
			if (NumTrigger(Ex[i]) != -1)
			{
				while (1)
				{
					string tmp;
					tmp = Ex[i];
					Numstr += tmp;
					if (NumTrigger(Ex[i + 1]) == -1)
					{
						if (Ex[i + 1] != Operator[6])
						{
							Enque(&PostFix, Numstr);
							Numstr = "";
							break;
						}
						else
							break;
					}
					else
						break;
				}
			}
			else
				return 0;
		}
	}
	PrintQueue(&PostFix);
	getch();
	for (i = 0; i < PostFix.num + PostFix.front; ++i)
	{
		Deque(&PostFix, &qx);
		if (OperatorTrigger(qx[0]) == -1)
		{
			dPush(&Operand, stod(qx));
		}
		else
		{
			switch (OperatorTrigger(qx[0]))
			{
				double tmp1, tmp2;
			case 2:
				dPop(&Operand, &dsx);
				tmp1 = dsx;
				dPop(&Operand, &dsx);
				tmp2 = dsx;
				dPush(&Operand, tmp1 + tmp2);
				break;
			case 3:
				dPop(&Operand, &dsx);
				tmp1 = dsx;
				dPop(&Operand, &dsx);
				tmp2 = dsx;
				dPush(&Operand, tmp1 - tmp2);
				break;
			case 4:
				dPop(&Operand, &dsx);
				tmp1 = dsx;
				dPop(&Operand, &dsx);
				tmp2 = dsx;
				dPush(&Operand, tmp1*tmp2);
				break;
			case 5:
				dPop(&Operand, &dsx);
				tmp1 = dsx;
				dPop(&Operand, &dsx);
				tmp2 = dsx;
				dPush(&Operand, tmp1 / tmp2);
				break;
			default:
				break;
			}
		}
	}
	dPop(&Operand, &dsx);
	cout << dsx << endl;

	return 0;
}
int InitializeStack(CharStack *s, int max)
{
	s->ptr = 0;
	if ((s->stk = (char *)calloc(max, sizeof(char))) == NULL)
	{
		s->max = 0;
		return -1;
	}
	s->max = max;
	return 0;
}
int Push(CharStack *s, char x)
{
	if (s->ptr >= s->max)
		return -1;
	s->stk[s->ptr++] = x;
	return 0;
}
int Pop(CharStack *s, char *x)
{
	if (s->ptr <= 0)
		return -1;
	s->ptr--;
	*x = s->stk[s->ptr];
}
int PeekStack(const CharStack *s, char *x)
{
	if (s->ptr <= 0)
		return -1;
	*x = s->stk[s->ptr - 1];
	return 0;
}
int InitializeQueue(StringQueue *q, int max)
{
	q->num = q->front = q->rear = 0;
	if ((q->que = (string *)calloc(max, sizeof(string))) == NULL)
	{
		q->max = 0;
		return -1;
	}
	q->max = max;
	return 0;
}
int Enque(StringQueue *q, string x)
{
	if (q->num >= q->max)
		return -1;
	else
	{
		q->num++;
		q->que[q->rear++] = x;
		if (q->rear == q->max)
			q->rear = 0;
		return 0;
	}
}
int Deque(StringQueue *q, string *x)
{
	if (q->num <= 0)
		return -1;
	else
	{
		q->num--;
		*x = q->que[q->front++];
		if (q->front == q->max)
			q->front = 0;
		return 0;
	}
}
int PeekQueue(const StringQueue *q, string *x)
{
	if (q->num <= 0)
		return -1;
	*x = q->que[q->front];
	return 0;
}
int OperatorTrigger(char x)
{
	for (int i = 0; i < strlen(Operator); ++i)
		if (x == Operator[i])
			return i;
	return -1;
}
int NumTrigger(char x)
{
	for (int i = 0; i < strlen(Num); ++i)
		if (x == Num[i])
			return i;
	return -1;
}
void PrintStack(const CharStack *s)
{
	int i;
	for (i = 0; i < s->ptr; ++i)
		printf("%d\n", s->stk[i]);
}
void PrintQueue(const StringQueue *q)
{
	int i;
	for (i = 0; i < q->num; ++i)
		cout << q->que[i + q->front] << endl;
}
int InitializedStack(DoubleStack *s, int max)
{
	{
		s->ptr = 0;
		if ((s->stk = (double *)calloc(max, sizeof(double))) == NULL)
		{
			s->max = 0;
			return -1;
		}
		s->max = max;
		return 0;
	}
}
int dPush(DoubleStack *s, double x)
{
	if (s->ptr >= s->max)
		return -1;
	s->stk[s->ptr++] = x;
	return 0;
}
int dPop(DoubleStack *s, double *x)
{
	if (s->ptr <= 0)
		return -1;
	s->ptr--;
	*x = s->stk[s->ptr];
}