#include "stdafx.h"
#include <iostream>
using namespace std;
/*
Q. �� ���� �� (x1, y1)�� (x2, y2)�� ��ǥ�� �Է¹޾� �� ���� �մ� ���� ���⸦ ����ϴ� ���α׷��� �ۼ��϶�.
	(y2-y1) / (x2-x1)
*/
double slope(double x1, double y1, double x2, double y2);
int main()
{
	double x1, x2, y1, y2 = 0.0;

	cout << "���⸦ ���ϰ��� �ϴ� �� ���� ��ǥ�� �Է��ϼ���." << endl;
	cout << "x1, y1 : ";
	cin >> x1 >> y1;
	cout << "x2, y2 : ";
	cin >> x2 >> y2;

	if(x1==x2)
		cout << "�� ���� x��ǥ�� �޶�� �մϴ�" << endl;
	else
		cout << "�� ���� �մ� ���� ����� " << slope(x1, y1, x2, y2) << endl;

	return 0;
}
double slope(double x1, double y1, double x2, double y2)
{
	double TwoDotslope = 0.0;

	TwoDotslope = (y2 - y1) / (x2 - x1);
	return TwoDotslope;
}