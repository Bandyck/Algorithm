#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include "Stopwatch.h"
#include <random>
#include <conio.h>
using namespace std;

void qSort(int *List, int n);
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

	/* 도수 정렬*/
	SW.start();
	qSort(nList, 99999);
	SW.end();
	cout << "도수 정렬 시간측정 결과입니다." << endl;
	cout << SW.getElapsedTime() << " s" << endl;
	cout << endl;

	return 0;
}
void qSort(int *List, int n)
{
	int max;
	max = List[0];
	int i;
	for (i = 1; i < 99999; ++i)
		if (List[i] > max)
			max = List[i];

	int *countList = (int *)malloc(sizeof(int)*max);
	memset(countList, 0, sizeof(int)*max);

	for (i = 0; i < 99999; ++i)
		countList[List[i]]++;

	int j;
	i = 0;
	j = 0;
	while(1)
	{
		while (countList[j] != 0)
		{
			List[i] = j;
			countList[j]--;
			i++;
			if (i >= 99999)
				break;
		}
		j++;
		if (i >= 99999)
		{
			free(countList);
			break;
		}	
	}
}