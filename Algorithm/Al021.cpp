#include "stdafx.h"
//#include <iostream>
//#include <conio.h>
//using namespace std;
//const int NUM = 4;
//typedef struct PT
//{
//	bool tmpChess[NUM][NUM];
//	int ta;
//	int tb;
//}PT;
//bool(*QueenTrigger(bool QC[][NUM], int a, int b))[NUM];
//void ChessPrint(bool QC[][NUM]);
//void ChesstmpPrint(bool QC[][NUM]);
//void ChessPTPrint(PT *PICTURE);
//bool(*QueenReset(bool QC[][NUM]))[NUM];
//void QueenCopy(bool QC[][NUM], bool QCC[][NUM]);
//int counter = 0;
//int a = 0, b = 0;
//
//int main()
//{
//	bool QueenChess[NUM][NUM];
//	PT PICTURE[4];
//	int i, j, k = 0;
//	int btmp = 0;
//	QueenReset(QueenChess);
//	QueenReset(PICTURE[0].tmpChess);
//	PICTURE[0].ta = 0;
//	PICTURE[0].tb = 0;
//	for (a = 0; a < NUM; ++a)
//	{
//		btmp = 0;
//		for (b = 0; b < NUM; ++b)
//		{
//			if (QueenChess[a][b] == true)
//			{
//				QueenTrigger(QueenChess, a, b);
//				counter++;
//				//ChessPrint(QueenChess);
//				QueenCopy(QueenChess, PICTURE[counter].tmpChess);
//				PICTURE[counter].ta = a;
//				PICTURE[counter].tb = b;
//				ChessPTPrint(&PICTURE[counter]);
//				btmp++;
//			}
//		}
//		if (btmp == 0)
//			break;
//	}
//	//cout << "여기서부터 else 부분입니다" << endl;
//	//while (1)
//	//{
//	//	if (counter == 4)
//	//	{
//	//		ChessPrint(QueenChess);
//	//		break;
//	//	}
//	//	else
//	//	{
//	//		QueenCopy(PICTURE[counter - 1].tmpChess, QueenChess);
//	//		QueenChess[PICTURE[counter].ta][PICTURE[counter].tb] = false;
//	//		for (a = PICTURE[counter].ta; a < NUM; ++a)
//	//		{
//	//			for (b = PICTURE[counter].tb; b < NUM; ++b)
//	//			{
//	//				if (QueenChess[a][b] == true)
//	//				{
//	//					counter++;
//	//					QueenTrigger(QueenChess, a, b);
//	//					QueenCopy(QueenChess, PICTURE[counter].tmpChess);
//	//					PICTURE[counter].ta = a;
//	//					PICTURE[counter].tb = b;
//	//					ChessPTPrint(&PICTURE[counter]);
//	//				}
//	//			}
//	//		}
//	//	}
//	//	counter--;
//	//	getch();
//	//}
//	
//	//	counter--;
//	//	QueenCopy(PICTURE[counter - 1].tmpChess, QueenChess);
//	//	QueenChess[PICTURE[counter].ta][PICTURE[counter].tb] = false;
//	//	for (a = PICTURE[counter].ta; a < NUM; ++a)
//	//	{
//	//		for (b = PICTURE[counter].tb; b < NUM; ++b)
//	//		{
//	//			if (QueenChess[a][b] == true)
//	//			{
//	//				counter++;
//	//				QueenTrigger(QueenChess, a, b);
//	//				ChessPrint(QueenChess);
//	//				QueenCopy(QueenChess, PICTURE[counter].tmpChess);
//	//				PICTURE[counter].ta = a;
//	//				PICTURE[counter].tb = b;
//	//				ChessPTPrint(&PICTURE[counter]);
//	//			}
//	//		}
//	//	}
//	//}
//	return 0;
//}
//bool(*QueenTrigger(bool QC[][NUM], int a, int b))[NUM]
//{
//	if (QC[a][b] == true)
//	{
//		for (int i = 0; i < NUM; ++i)
//		{
//			QC[i][b] = false;
//			QC[a][i] = false;
//			if ((a + i) < NUM && (b + i) < NUM)
//				QC[a + i][b + i] = false;
//			if ((a - i) >= 0 && (b - i) >= 0)
//				QC[a - i][b - i] = false;
//			if ((a + b - i) >= 0 && (a + b - i) < NUM)
//				QC[i][a + b - i] = false;
//		}
//	}
//	QC[a][b] = true;
//	return QC;
//}
//void ChessPrint(bool QC[][NUM])
//{
//	int i, j;
//
//	for (i = 0; i < NUM; ++i)
//	{
//		for (j = 0; j < NUM; ++j)
//		{
//			if (QC[i][j] == true)
//				cout << " ■ ";
//			else
//				cout << " □ ";
//		}
//		cout << endl;
//	}
//	cout << "a : " << a << endl;
//	cout << "b : " << b << endl;
//	cout << counter << endl;
//	cout << endl << endl << endl;
//}
//void ChesstmpPrint(bool QC[][NUM])
//{
//	int i, j;
//
//	for (i = 0; i < NUM; ++i)
//	{
//		for (j = 0; j < NUM; ++j)
//		{
//			if (QC[i][j] == true)
//				cout << " ■ ";
//			else
//				cout << " □ ";
//		}
//		cout << endl;
//	}
//	cout << counter << "저장한 사진" << endl;
//	cout << endl << endl << endl;
//}
//void ChessPTPrint(PT *PICTURE)
//{
//	int i, j;
//
//	cout << counter << "번째 저장한 사진" << endl;
//	for (i = 0; i < NUM; ++i)
//	{
//		for (j = 0; j < NUM; ++j)
//		{
//			if (PICTURE->tmpChess[i][j] == true)
//				cout << " ■ ";
//			else
//				cout << " □ ";
//		}
//		cout << endl;
//	}
//	cout << "a : " << PICTURE->ta << endl;
//	cout << "b : " << PICTURE->tb << endl;
//	cout << endl << endl << endl;
//}
//bool(*QueenReset(bool QC[][NUM]))[NUM]
//{
//	for (int i = 0; i < NUM; ++i)
//		for (int j = 0; j < NUM; ++j)
//			QC[i][j] = true;
//
//	return QC;
//}
//void QueenCopy(bool QC[][NUM], bool QCC[][NUM])
//{
//	for (int i = 0; i < NUM; ++i)
//		for (int j = 0; j < NUM; ++j)
//			QCC[i][j] = QC[i][j];
//}