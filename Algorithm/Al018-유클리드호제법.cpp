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
	cout << "�� ������ �ִ������� ���մϴ�." << endl;
	cout << "������ �Է��ϼ��� : ";
	cin >> x;
	cout << "������ �Է��ϼ��� : ";
	cin >> y;
	cout << "�ִ������� " << gcd(x, y) << "�Դϴ�. " << endl;

	return 0;
}