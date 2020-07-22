#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include "Stopwatch.h"
#include <random>
#include <conio.h>
#include <string>
using namespace std;

void radixSort(int *List, int n);
int main()
{
	int i = 0, j = 0;
	Stopwatch SW;
	int nList[100000] = { 0 };

	srand((unsigned)time(NULL));

	for (i = 0; i < 100000; ++i)
		nList[i] = 1000 + rand() % 9000;

	/* 지수 정렬*/
	SW.start();
	radixSort(nList, 100000);
	SW.end();
	cout << "지수 정렬 시간측정 결과입니다." << endl;
	cout << SW.getElapsedTime() << " s" << endl;
	cout << endl;

	return 0;
}
void radixSort(int *List, int n)
{
	int i, j;
	string *stringList = NULL;
	stringList = new string[n];
	for (i = 0; i < n; ++i)
	{
		stringList[i] = to_string(List[i]);
	}
	for (int k = 0; k < 20; ++k)
	{
		cout << stringList[k] << ' ';
	}
	cout << endl << endl;
	for (j = 0; j < 20; ++j)
	{
		string tmp;
		for (i = 0; i < 4; ++i)
		{
			if (*(stringList[j].begin() + i) > *(stringList[j+1].begin() + i))
			{
				tmp = stringList[j];
				stringList[j] = stringList[j + 1];
				stringList[j + 1] = tmp;
				break;
			}
			else if (*(stringList[j].begin() + i) < *(stringList[j+1].begin() + i))
			{
				//tmp = stringList[j+1];
				//stringList[j+1] = stringList[j];
				//stringList[j] = tmp;
				break;
			}
		}
	}
	for (int k = 0; k < 20; ++k)
	{
		cout << stringList[k] << ' ';
	}
	getch();
}