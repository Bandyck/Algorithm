#include "stdafx.h"
#include <iostream>
using namespace std;

void BinSearch(int* SortList, int Key, int Ini, int End);
int main()
{
	int n = 0;
	
	cout << "�Է��� �ڷ��� ������ �Է��ϼ���. : ";
	cin >> n;

	int *nList = new int[sizeof(int)*n];
	int *SortList = new int[sizeof(int)*n];
	int i = 0, j = 0;
	int nTmp = 0;

	for (i = 0; i < n; ++i)
	{
		cout << i + 1 << "��° �ڷ� : ";
		cin >> nList[i];
		SortList[i] = nList[i];
	}
	for (i = n - 1; i > 0; --i)
	{
		for (j = 0; j < i; ++j)
		{
			if (SortList[j] > SortList[j + 1])
			{
				nTmp = SortList[j];
				SortList[j] = SortList[j + 1];
				SortList[j + 1] = nTmp;
			}
		}
	}
	BinSearch(SortList, 30, 0, n - 1);
	//cout << ' '<< '|' <<' ';
	//for (i = 0; i < n; ++i)
	//{
	//	cout.width(2);
	//	cout << i + 1 << ' ';
	//}
	//cout << endl;
	//cout << "---";
	//for (i = 0; i < n; ++i)
	//{
	//	cout << "---";
	//}
	return 0;
}
void BinSearch(int* SortList, int Key, int Ini, int End)
{
	int i = 0;
	if ( SortList[(End+Ini)/2]== Key)
	{
		cout << "�˻� ���� : ���ϰ��� �ϴ� Key�� ��ġ�� SortList[" << (End + Ini) / 2 << "]";
		return;
	}
	else
	{
		if (SortList[(End + Ini) / 2] < Key)
		{
			BinSearch(SortList, Key, (End + Ini) / 2, End);
		}
		else
		{
			BinSearch(SortList, Key, Ini, (End + Ini) / 2);
		}
	}
}