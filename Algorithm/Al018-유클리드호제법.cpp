#include "stdafx.h"
#include <iostream>
using namespace std;
int gcd(int x, int y)
{
	if (y == 0)
		return x;
	else
		return gcd(y, x%y);
}
int main()
{
	int x, y;
	cout << "두 정수의 최대공약수를 구합니다." << endl;
	cout << "정수를 입력하세요 : ";
	cin >> x;
	cout << "정수를 입력하세요 : ";
	cin >> y;
	cout << "최대공약수는 " << gcd(x, y) << "입니다. " << endl;

	return 0;
}