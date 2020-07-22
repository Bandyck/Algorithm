#include "stdafx.h"
#include <iostream>
#include <conio.h>
using namespace std;

void Heap(int * List, int left, int right);
void HeapSort(int * List, int STP, int END);
const int SIZE = 12;
int main()
{
	int nList[SIZE] = { 10, 4, 8, 5, 12, 2, 6, 11, 3, 9, 7, 11 };
	int STP = 0;
	int END = SIZE;
	int h = 0;
	Heap(nList, 0, SIZE);
	//HeapSort(nList, STP, END);
}
void Heap(int * List, int leftP, int rightP)
{
	for (int k = 0; k < SIZE; ++k)
	{
		cout << List[k] << " ";
	}
	cout << endl;
	int root = List[leftP];
	int i = 1;
	int j;
	while (1)
	{
		int parent = List[(i - 1) / 2];
		int child = List[i];
		while (1)
		{
			j = (i - 1) / 2;
			cout << "i : " << i << "  parent : " << parent << " child : " << child << endl;
			if (child > parent)
			{
				List[(i - 1) / 2] = child;
				List[i] = parent;
			}
			else
			{
				break;
			}
			parent = List[(j - 1) / 2];
			child = List[j];
		}
		for (int k = 0; k <= i; ++k)
		{
			cout << List[k] << " ";
		}
		cout << endl;
		getch();
		++i;
	}
	
}
void HeapSort(int * List, int STP, int END)
{
	do
	{
		Heap(List, STP, END);
		int tmp = 0;
		tmp = List[END];
		List[END] = List[0];
		List[0] = tmp;
		if (END == 1)
			break;
		END--;
	} while (1);
}