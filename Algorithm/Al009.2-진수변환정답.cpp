#include "stdafx.h"
#include <iostream>
using namespace std;
#include <string>
#include <math.h>
//
//int main()
//{
//	int InputNtt = 0;
//	int ResultNtt = 0;
//	string InputNum;
//	int sum = 0, sumtmp = 0;
//	int i = 0, j = 0, tmp = 0;
//
//	cout << "몇 진수의 수인가 : ";
//	cin >> InputNtt;
//	cout << "수 입력 : ";
//	cin >> InputNum;
//	cout << "몇 진수로 변환을? : ";
//	cin >> ResultNtt;
//
//	for (i = 0; i < InputNum.size(); ++i)
//	{
//		if ((int)InputNum[i] >= 65)
//			sum += ((int)InputNum[i] - 55) * pow(InputNtt, InputNum.size() - 1 - i);
//		else
//			sum += ((int)InputNum[i] - 48) * pow(InputNtt, InputNum.size() - 1 - i);
//	}
//
//	sumtmp = sum;
//	i = 0;
//	while (sumtmp!=0)
//	{
//		sumtmp /= ResultNtt;
//		i++;
//	}
//	
//	int *pt = new int[i]; 
//	char *ResultNttArray = new char[_msize(pt) / sizeof(pt[0])];
//
//	i = 0;
//	while (sum != 0)
//	{
//		pt[i] = sum % ResultNtt;
//		sum /= ResultNtt;
//		i++;
//	}
//	for (j = 0; j < _msize(pt) / sizeof(pt[0]) / 2; ++j)
//	{
//		tmp = pt[j];
//		pt[j] = pt[i - 1 - j];
//		pt[i - 1 - j] = tmp;
//	}
//	for (j = 0; j < _msize(pt) / sizeof(pt[0]); ++j)
//	{
//		if (pt[j] >= 10)
//			ResultNttArray[j] = char(pt[j]) + 55;
//		else ResultNttArray[j] = char(pt[j]) + 48;
//	}
//	for (j = 0; j<_msize(pt) / sizeof(pt[0]); ++j)
//	{
//		cout << ResultNttArray[j];
//	}
//	cout << endl;
//
//	delete[] pt;
//	delete[] ResultNttArray;
//
//	return 0;
//}