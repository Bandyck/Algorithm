#include "stdafx.h"
#include <iostream>
#include <conio.h>
using namespace std;
const int SIZE = 8;
void QuickSort(int *nList, int n, int m, int f);
int main()
{																										
	int List[SIZE] = { 168,170,160,175,165,170,155,150 };												
	//													 = Quick(NowIndex,MaxIndex,flag)				
	//{ [168], 170, 160, 175, 165, 170, 155, [150] }	 = Quick(0, SIZE-1, -1)						
	//{ 150, [170], 160, 175, 165, 170, 155, [168] }	 = Quick(1, SIZE-1, 1)							
	//{ 150, [168], 160, 175, 165, 170, [155], 170 }	 = Quick(1, SIZE-2, -1)						
	//{ 150, 155, [160], 175, 165, 170, [168], 170 }	 = Quick(SIZE-2, 2, 1) 									
	//{ 150, 155, 160, [175], 165, 170, [168], 170 }	 = Quick(SIZE-2, 3, 1)									
	//{ 150, 155, 160, [168], 165, [170], 175, 170 }	 = Quick(3, SIZE-3, -1)									
	//{ 150, 155, 160, [168], [165], 170, 175, 170 }	 = Quick(3, SIZE-4, -1)									
	//{ 150, 155, 160, 165, [168], 170, 175, 170 }		 = Quick(4, SIZE-4, 1)										
	//{ [150], 155, 160, [165]} {168} { 170, 175, 170 }	 = Quick(0,  										
	//{ [150], 155, [160], 165} {168} { 170, 175, 170 }	 = Quick(										
	//{ [150], [155], 160, 165} {168} { 170, 175, 170 }	 = Quick(										
	//{ [150], 155, 160, 165} {168} { 170, 175, 170 }		 =Quick(									
	//{150} {[155], 160, [165]} {168} { 170, 175, 170 }	 =Quick(										
	//{150} {[155], [160], 165} {168} { 170, 175, 170 }	 =Quick(										
	//{150} {[155], 160, 165} {168} { 170, 175, 170 }		 =Quick(									
	//{150} {155} {[160], [165]} {168} { 170, 175, 170 }	 =Quick(									
	//{150} {155} {[160], 165} {168} { 170, 175, 170 }	 =Quick(
	//{150} {155} {160} {[165]} {168} { 170, 175, 170 }	 =Quick(
	//{150} {155} {160} {165} {168} { [170], 175, [170] }	 =Quick(
	//{150} {155} {160} {165} {168} { [170], [175], 170 }	 =Quick(
	//{150} {155} {160} {165} {168} { [170], 175, 170 }	 =Quick(
	//{150} {155} {160} {165} {168} {170} {[175], [170]}	 =Quick(
	//{150} {155} {160} {165} {168} {170} {170, [175]}	 =Quick(
	//{150} {155} {160} {165} {168} {170} {[170]} {175}	 =Quick(
	//{150} {155} {160} {165} {168} {170} {170} {175}		 =Quick(
	int NowIndex = 0;
	int MaxIndex = SIZE-1;
	int flag = -1;
	QuickSort(List, NowIndex, MaxIndex, flag);
	/*cout << "NowIndex : " << NowIndex << " MaxIndex : " << MaxIndex << " flag : " << flag << endl;
	cout << "======================================================================" << endl;
	for (int i = 0; i < SIZE; ++i)
		cout << List[i] << " ";
	cout << endl << endl;
	if (flag == -1)
	{
		int tmp = List[NowIndex];
		for (int i = MaxIndex; i>NowIndex; --i)
		{
			if (tmp>List[i])
			{
				List[NowIndex] = List[i];
				List[i] = tmp;
				flag *= -1;
				MaxIndex = NowIndex + flag;
				NowIndex = i;
				break;
			}
		}
	}
	cout << "NowIndex : " << NowIndex << " MaxIndex : " << MaxIndex << " flag : " << flag << endl;
	cout << "======================================================================" << endl;
	for (int i = 0; i < SIZE; ++i)
		cout << List[i] << " ";
	cout << endl << endl;
	if (flag == 1)
	{
		int tmp = List[NowIndex];
		for (int i = MaxIndex; i<NowIndex; ++i)
		{
			if (tmp<List[i])
			{
				List[NowIndex] = List[i];
				List[i] = tmp;
				flag *= -1;
				MaxIndex = NowIndex + flag;
				NowIndex = i;
				break;
			}
		}
	}
	cout << "NowIndex : " << NowIndex << " MaxIndex : " << MaxIndex << " flag : " << flag << endl;
	cout << "======================================================================" << endl;
	for (int i = 0; i < SIZE; ++i)
		cout << List[i] << " ";
	cout << endl << endl;
	cout << "NowIndex : " << NowIndex << " MaxIndex : " << MaxIndex << " flag : " << flag << endl;
	cout << "======================================================================" << endl;
	for (int i = 0; i < SIZE; ++i)
		cout << List[i] << " ";
	cout << endl << endl;
	if (flag == -1)
	{
		int tmp = List[NowIndex];
		for (int i = MaxIndex; i>NowIndex; --i)
		{
			if (tmp>List[i])
			{
				List[NowIndex] = List[i];
				List[i] = tmp;
				flag *= -1;
				MaxIndex = NowIndex + flag;
				NowIndex = i;
				break;
			}
		}
	}
	cout << "NowIndex : " << NowIndex << " MaxIndex : " << MaxIndex << " flag : " << flag << endl;
	cout << "======================================================================" << endl;
	for (int i = 0; i < SIZE; ++i)
		cout << List[i] << " ";
	cout << endl << endl;
	if (flag == 1)
	{
		int tmp = List[NowIndex];
		for (int i = MaxIndex; i<NowIndex; ++i)
		{
			if (tmp<List[i])
			{
				List[NowIndex] = List[i];
				List[i] = tmp;
				flag *= -1;
				MaxIndex = NowIndex + flag;
				NowIndex = i;
				break;
			}
		}
	}
	cout << "NowIndex : " << NowIndex << " MaxIndex : " << MaxIndex << " flag : " << flag << endl;
	cout << "======================================================================" << endl;
	for (int i = 0; i < SIZE; ++i)
		cout << List[i] << " ";
	cout << endl << endl;*/
	
	//while (1)
	//{
	//	cout << "NowIndex : " << NowIndex << " MaxIndex : " << MaxIndex << " flag : " << flag << endl;
	//	cout << "======================================================================" << endl;
	//	for (int i = 0; i < SIZE; ++i)
	//		cout << List[i] << " ";
	//	cout << endl << endl;
	//	if (NowIndex == MaxIndex)
	//		break;
	//	if (flag == -1)
	//	{
	//		int tmp = List[NowIndex];
	//		for (int i = MaxIndex; i>NowIndex; --i)
	//		{
	//			if (tmp>List[i])
	//			{
	//				List[NowIndex] = List[i];
	//				List[i] = tmp;
	//				flag *= -1;
	//				MaxIndex = NowIndex + flag;
	//				NowIndex = i;
	//				break;
	//			}
	//		}
	//	}
	//	else
	//	{
	//		int tmp = List[NowIndex];
	//		for (int i = MaxIndex; i<NowIndex; ++i)
	//		{
	//			if (tmp<List[i])
	//			{
	//				List[NowIndex] = List[i];
	//				List[i] = tmp;
	//				flag *= -1;
	//				MaxIndex = NowIndex + flag;
	//				NowIndex = i;
	//				break;
	//			}
	//		}
	//	}
	//	getch();
	//}
	//
	//cout << "나왔다 !" << endl;
	//getch();
	
}
void QuickSort(int *nList, int n, int m, int f)
{
	cout << "처음으로 Sort가 들어갑니다" << endl;
	int tmp1 = n;
	int tmp2 = m;
	cout << "NowIndex : " << n << " MaxIndex : " << m << " flag : " << f << endl;
	cout << "======================================================================" << endl;
	for (int i = 0; i < SIZE; ++i)
		cout << nList[i] << " ";
	cout << endl << endl;
	while (1)
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
				//if (i == n + 1)
				//{
				//	QuickSort(nList, tmp1 + 1, m, -1);
				//	getch();
				//	return;
				//}
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
				//if (i == n - 1)
				//{
				//	QuickSort(nList, n, tmp2-1, -1);
				//	getch();
				//	return;
				//}
			}
		}
		getch();
		cout << "NowIndex : " << n << " MaxIndex : " << m << " flag : " << f << endl;
		cout << "======================================================================" << endl;
		for (int i = 0; i < SIZE; ++i)
			cout << nList[i] << " ";
		cout << endl << endl;
		if (n == m)
		{
			QuickSort(nList, tmp1, n - 1, -1);
			QuickSort(nList, m + 1, tmp2, -1);
		}
	}
	cout << "나왔다 !" << endl;
}