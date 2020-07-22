#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include "Stopwatch.h"
#include <random>
#include <conio.h>
using namespace std;

void BubbleSort(int *List);
void SelectionSort(int *List);
void SelBubbleSort(int * List);
void InsertionSort(int * List);
//void InsertionPrintSort(int * List);
void ShellSort(int *List);
void Shell364Sort(int *List);
void Shell4Sort(int *List);
void Shell1Sort(int *List);
void ShellPrintSort(int *List);
void QuickSort(int *nList, int n, int m, int f);
void Mergesort(int *nList);
int main()
{
	int i = 0, j = 0;
	Stopwatch SW;
	int nList[100000] = { 0 };

	/*  랜덤 1번째 방법 */
	srand((unsigned)time(NULL));

	for (i = 0; i < 100000; ++i)
		nList[i] = (((int)rand() << 15) | rand()) % 100000;

	/*	랜덤 2번째 방법 */
	//random_device rd;
	//mt19937_64 gen(rd());
	//uniform_int_distribution<int> dis(0, 100000);
	//int icase;
	//for (int i = 0; i < 100000; i++)
	//{
	//	icase = dis(gen);
	//	nList[i] = icase;
	//}

	///* 버블 정렬 */
	//SW.start();
	//BubbleSort(nList);
	//SW.end();
	//cout << "버블 정렬 시간측정 결과입니다." << endl;
	//cout << SW.getElapsedTime() << " s" << endl;

	//for (i = 0; i < 100000; ++i)
	//	nList[i] = (((int)rand() << 15) | rand()) % 100000;

	///* 선택 정렬 */
	//SW.start();
	//SelectionSort(nList);
	//SW.end();
	//cout << "선택 정렬 시간측정 결과입니다." << endl;
	//cout << SW.getElapsedTime() << " s" << endl;

	//for (i = 0; i < 100000; ++i)
	//	nList[i] = (((int)rand() << 15) | rand()) % 100000;

	///* 선택로 알려진 버블정렬 */
	//SW.start();
	//SelBubbleSort(nList);
	//SW.end();
	//cout << "선택로 알려진 버블정렬 시간측정 결과입니다." << endl;
	//cout << SW.getElapsedTime() << " s" << endl;

	/////* 단순 삽입 정렬 */
	//SW.start();
	//InsertionSort(nList);
	//SW.end();
	//cout << "단순 삽입 정렬 시간측정 결과입니다." << endl;
	//cout << SW.getElapsedTime() << " s" << endl;
	////InsertionPrintSort(nList);


	///* 셸 정렬 */
	//SW.start();
	//ShellSort(nList);
	//SW.end();
	//cout << "셸 정렬 시간측정 결과입니다." << endl;
	//cout << "h : {9841, 3280, 1093, 364, 121, 40, 13, 4, 1}" << endl;
	//cout << SW.getElapsedTime() << " s" << endl;

	//srand((unsigned)time(NULL));
	//for (i = 0; i < 100000; ++i)
	//	nList[i] = (((int)rand() << 15) | rand()) % 100000;

	//SW.start();
	//Shell364Sort(nList);
	//SW.end();
	//cout << "셸 정렬 시간측정 결과입니다." << endl;
	//cout << "h : {364, 121, 40, 13, 4, 1}" << endl;
	//cout << SW.getElapsedTime() << " s" << endl;

	//srand((unsigned)time(NULL));
	//for (i = 0; i < 100000; ++i)
	//	nList[i] = (((int)rand() << 15) | rand()) % 100000;

	//SW.start();
	//Shell4Sort(nList);
	//SW.end();
	//cout << "셸 정렬 시간측정 결과입니다." << endl;
	//cout << "h : {4, 1}" << endl;
	//cout << SW.getElapsedTime() << " s" << endl;

	//srand((unsigned)time(NULL));
	//for (i = 0; i < 100000; ++i)
	//	nList[i] = (((int)rand() << 15) | rand()) % 100000;

	//SW.start();
	//Shell1Sort(nList);
	//SW.end();
	//cout << "셸 정렬 시간측정 결과입니다." << endl;
	//cout << "h : {1}" << endl;
	//cout << SW.getElapsedTime() << " s" << endl;

	//ShellPrintSort(nList);

	///* 퀵 정렬*/
	//SW.start();
	//QuickSort(nList, 0, 99999, -1);
	//SW.end();
	//cout << "퀵 정렬 시간측정 결과입니다." << endl;
	//cout << SW.getElapsedTime() << " s" << endl;

	for (int k = 0; k < 100; ++k)
		cout << nList[k] << " ";
	return 0;
}
void BubbleSort(int * List)
{
	int i = 0, j = 0, tmp = 0;

	for (i = 99999; i >0; --i)
		for (j = 0; j<i; ++j)
			if (List[j] > List[j + 1])
			{
				tmp = List[j];
				List[j] = List[j + 1];
				List[j + 1] = tmp;
			}
}
void SelectionSort(int * List)
{
	int i = 0, j = 0, MinIndex = 0, tmp = 0;

	for (i = 0; i < 99999; ++i)
	{
		MinIndex = i;
		for (j = i + 1; j < 100000; ++j)
			if (List[MinIndex] > List[j])
				MinIndex = j;

		if (MinIndex != i)
		{
			tmp = List[MinIndex];
			List[MinIndex] = List[i];
			List[i] = tmp;
		}
	}
}
void SelBubbleSort(int * List)
{
	int i = 0, j = 0, tmp = 0;

	for (i = 0; i < 99999; ++i)
		for (j = i + 1; j < 100000; ++j)
			if (List[j] > List[i])
			{
				tmp = List[i];
				List[i] = List[j];
				List[j] = tmp;
			}
}
void InsertionSort(int * List)
{
	int i = 0, j = 0;
	for (i = 1; i < 100000; ++i)
	{
		int tmp = List[i];
		for (j = i; List[j - 1] > tmp && (j - 1) >= 0; --j)
			List[j] = List[j - 1];
		List[j] = tmp;
	}
}
//void InsertionPrintSort(int * List)
//{
//	int i = 0, j = 0, k=0;
//	cout << "정렬 전 List입니다" << endl;
//	for (k = 0; k < 10; ++k)
//	{
//		cout << List[k] << " ";
//	}
//	cout << endl << endl;
//	for (i = 1; i < 10; ++i)
//	{
//		int tmp = List[i];
//		cout << i << "번 정렬 전 List입니다.   ";
//		cout << "현재 저장되어 있는 tmp는 " << tmp << endl;
//		for (k = 0; k < 10; ++k)
//		{
//			if (k == i)
//				cout << "[ " << List[k] << " ] ";
//			cout << List[k] << " ";
//		}
//			
//		cout << endl;
//		for (j = i; List[j - 1] > tmp && (j - 1) >= 0; --j)
//			List[j] = List[j - 1];
//		List[j] = tmp;
//		cout << i << "번 정렬 후 List입니다" << endl;
//		for (k = 0; k < 10; ++k)
//		{
//			if (k == j)
//				cout << "[ " << List[k] << " ] ";
//			cout << List[k] << " ";
//		}
//		cout << endl << endl;
//	}
//}
void ShellSort(int *List)
{
	int i, j, h;

	for (int h : {9841, 3280, 1093, 364, 121, 40, 13, 4, 1})
		for (i = h; i < 100000; ++i)
		{
			int tmp = List[i];
			for (j = i - h; j >= 0 && List[j] > tmp; j = j - h)
				List[j + h] = List[j];
			List[j + h] = tmp;
		}
}
void Shell364Sort(int *List)
{
	int i, j, h;

	for (int h : {364, 121, 40, 13, 4, 1})
		for (i = h; i < 100000; ++i)
		{
			int tmp = List[i];
			for (j = i - h; j >= 0 && List[j] > tmp; j = j - h)
				List[j + h] = List[j];
			List[j + h] = tmp;
		}
}
void Shell4Sort(int *List)
{
	int i, j, h;

	for (int h : {4, 1})
		for (i = h; i < 100000; ++i)
		{
			int tmp = List[i];
			for (j = i - h; j >= 0 && List[j] > tmp; j = j - h)
				List[j + h] = List[j];
			List[j + h] = tmp;
		}
}
void Shell1Sort(int *List)
{
	int i, j, h;

	for (int h : {1})
		for (i = h; i < 100000; ++i)
		{
			int tmp = List[i];
			for (j = i - h; j >= 0 && List[j] > tmp; j = j - h)
				List[j + h] = List[j];
			List[j + h] = tmp;
		}
}
void ShellPrintSort(int *List)
{
	int i, j = 10000000, h;	// 10000000은 i가 돌고 j가 들어 가기 전 값을 의미합니다. 구분하기 위해 그냥 넣은 값입니다.
	int k = 0;
	for (int h : {9841, 3280, 1093, 364, 121, 40, 13, 4, 1})
		for (i = h; i < 100000; ++i)
		{
			int tmp = List[i];
			j = 10000000;
			printf("h : %6d, i : %6d, j : %8d, tmp : %6d\n", h, i, j, tmp);
			printf("============================================================================\n");
			for (k = i - h; k < 100000; k = k + h)
				printf("%5d  ", List[k]);
			putchar('\n');
			putchar('\n');
			for (j = i - h; j >= 0 && List[j] > tmp; j = j - h)
			{
				printf("h : %6d, i : %6d, j : %8d, tmp : %6d\n", h, i, j, tmp);
				printf("============================================================================\n");
				for (k = i - h; k < 100000; k = k + h)
					printf("%5d  ", List[k]);
				putchar('\n');
				putchar('\n');
				List[j + h] = List[j];
			}
			List[j + h] = tmp;
			printf("h : %6d, i : %6d, j : %8d, tmp : %6d\n", h, i, j, tmp);
			printf("============================================================================\n");
			for (k = i - h; k < 100000; k = k + h)
				printf("%5d  ", List[k]);
			putchar('\n');
			putchar('\n');
			getch();
		}
}
void QuickSort(int *nList, int n, int m, int f)
{
	int tmp1 = n;
	int tmp2 = m;
	if (n == m)
		return;
	while (n != m)
	{
		if (f == -1)
		{
			int tmp = nList[n];
			for (int i = m; i>n; --i)
			{
				if (tmp>nList[i])
				{
					nList[n] = nList[i];
					nList[i] = tmp;
					f *= -1;
					m = n + f;
					n = i;
					break;
				}
				if (i == n + 1)
					m = m + f;
			}
		}
		else
		{
			int tmp = nList[n];
			for (int i = m; i<n; ++i)
			{
				if (tmp<nList[i])
				{
					nList[n] = nList[i];
					nList[i] = tmp;
					f *= -1;
					m = n + f;
					n = i;
					break;
				}
				if (i == n - 1)
					m = m + f;
			}
		}
	}
	if (tmp1<n - 1)
		QuickSort(nList, tmp1, n - 1, -1);
	if (n + 1<tmp2)
		QuickSort(nList, n + 1, tmp2, -1);
}
void Mergesort(int *nList)
{

}