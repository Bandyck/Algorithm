#include "stdafx.h"
#include <iostream>
using namespace std;

//int GaussSum(int);
//int GaussAtoBSum(int a, int b);
//int GaussIntegerSum(int a, int b);
//int main()
//{
//	int n = 0;
//	int a, b = 0;
//
//	cout << "1부터 n까지의 합" << endl;
//	cout << "n을 입력하세요" << endl;
//	cin >> n;
//	
//	cout << GaussSum(n) << endl << endl; // 1부터 n까지의 합
//
//	cout << "a, b를 포함하여 그 사이의 모든 정수의 합" << endl;
//	cout << "a와 b를 입력하세요" << endl;
//	cin >> a >> b;
//
//	cout << GaussAtoBSum(a, b) << endl;
//	
//	return 0;
//}
//int GaussSum(int n)
//{
//	int sum = 0;
//
//	sum = (n + 1)*n / 2;
//
//	return sum;
//}
//int GaussAtoBSum(int a, int b)
//{
//	if (a >= b)
//		return GaussSum(a) - GaussSum(b-1);
//	else
//		return GaussSum(b) - GaussSum(a-1);
//}
