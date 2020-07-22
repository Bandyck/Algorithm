#include "stdafx.h"
#include <iostream>
using namespace std;
/*
Q. 두 개의 점 (x1, y1)과 (x2, y2)의 좌표를 입력받아 두 선을 잇는 선의 기울기를 출력하는 프로그램을 작성하라.
	(y2-y1) / (x2-x1)
*/
double slope(double x1, double y1, double x2, double y2);
int main()
{
	double x1, x2, y1, y2 = 0.0;

	cout << "기울기를 구하고자 하는 두 점의 좌표를 입력하세요." << endl;
	cout << "x1, y1 : ";
	cin >> x1 >> y1;
	cout << "x2, y2 : ";
	cin >> x2 >> y2;

	if(x1==x2)
		cout << "두 점의 x좌표는 달라야 합니다" << endl;
	else
		cout << "두 점을 잇는 선의 기울기는 " << slope(x1, y1, x2, y2) << endl;

	return 0;
}
double slope(double x1, double y1, double x2, double y2)
{
	double TwoDotslope = 0.0;

	TwoDotslope = (y2 - y1) / (x2 - x1);
	return TwoDotslope;
}