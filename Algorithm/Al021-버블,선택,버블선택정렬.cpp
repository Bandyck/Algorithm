#include "stdafx.h"
#include "Stopwatch.h"
#include <time.h>
#include <iostream>
using namespace std;

void BubbleSort(int *List);
void SelectionSort(int *List);
void SelBubbleSort(int * List);
int main()
{
	int i = 0, j = 0;
	Stopwatch SW;
	int nList[100000] = { 0 };
	srand((unsigned)time(NULL));
	
	for (i = 0; i < 100000; ++i)
		nList[i] = (((int)rand() << 15) | rand()) % 100000;

	/* 버블 정렬 */
	SW.start();
	BubbleSort(nList);
	SW.end();
	cout << "버블 정렬 시간측정 결과입니다." << endl;
	cout << SW.getElapsedTime() << " s" << endl;

	for (i = 0; i < 100000; ++i)
		nList[i] = (((int)rand() << 15) | rand()) % 100000;

	/* 선택 정렬 */
	SW.start();
	SelectionSort(nList);
	SW.end();
	cout << "선택 정렬 시간측정 결과입니다." << endl;
	cout << SW.getElapsedTime() << " s" << endl;

	for (i = 0; i < 100000; ++i)
		nList[i] = (((int)rand() << 15) | rand()) % 100000;

	/* 선택로 알려진 버블정렬 */
	SW.start();
	SelBubbleSort(nList);
	SW.end();
	cout << "선택로 알려진 버블정렬 시간측정 결과입니다." << endl;
	cout << SW.getElapsedTime() << " s" << endl;
		
	return 0;
}
void BubbleSort(int * List)
{
	int i = 0, j = 0, tmp = 0;

	for (i = 99999; i >0; --i)
		for(j=0;j<i;++j)
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

	for (i = 0; i <99999; ++i)
		for (j = i+1; j<100000; ++j)
			if (List[j] > List[i])
			{
				tmp = List[i];
				List[i] = List[j];
				List[j] = tmp;
			}
}