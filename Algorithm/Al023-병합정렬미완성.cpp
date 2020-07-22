#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
#include <conio.h>
using namespace std;

const int SIZE = 12;
int tmp[SIZE];
int j = 0;
void Mergesort(int *List, int n, int m);
int main()
{
	int nList[SIZE] = { 6, 5, 4, 8, 3, 7, 9, 0, 1, 5, 2, 3 };
	int Stp = 0;
	int Enp = SIZE-1;
	Mergesort(nList, Stp, Enp);
	for (int i = 0; i < SIZE; ++i)
		cout << nList[i] << " ";
	cout << endl;
}
void Mergesort(int *List, int n, int m)
{
	cout << "ÇöÀçÀÇ n : " << n << " m : " << m << endl;
	cout << "======================================" << endl;
	int i = 0;
	int min = 0, max = 0;
	getch();
	int middle = (n + m) / 2;
	if (m - n  >=1)
	{
		Mergesort(List, n, middle);
		Mergesort(List, middle + 1, m);
	}
	if (m - n == 1)
	{
		min = List[n];
		max = List[m];
		if (max < List[n])
			max = List[n];
		if (min > List[m])
			min = List[m];
	}
}