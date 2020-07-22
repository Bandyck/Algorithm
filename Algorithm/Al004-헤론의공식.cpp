#include "stdafx.h"
#include <iostream>
using namespace std;
/*
Q. 삼각형의 3개의 점 (x1, y1), (x2, y2), (x3, y3)를 입력하여 면적을 출력하는 프로그램을 작성하세요.
삼각형의 면적을 구하는 공식은...
	  s  = (side1 + side2 + side3) / 2
	면적 =  sqrt(s(s-side1)(s-side2)(s-side3)) 
*/
double TwoDotDistance(double x1, double y1, double x2, double y2);
double HeronFormula(double a, double b, double c);
int main()
{
	double x1, x2, x3, y1, y2, y3;
	double side1, side2, side3;
	double tmparea, area;

	cout << "삼각형의 넓이를 구하고자 하는 세 점을 입력하세요. " << endl;
	cout << "x1, y1 : ";
	cin >> x1 >> y1;
	cout << "x2, y2 : ";
	cin >> x2 >> y2;
	cout << "x3, y3 : ";
	cin >> x3 >> y3;
	
	side1 = TwoDotDistance(x1, y1, x2, y2);
	side2 = TwoDotDistance(x1, y1, x3, y3);
	side3 = TwoDotDistance(x2, y2, x3, y3);

	cout << "삼각형의 넓이는 " << HeronFormula(side1, side2, side3) << endl;

	return 0;
}
double TwoDotDistance(double x1, double y1, double x2, double y2)
{
	return pow(pow((x2 - x1), 2)+ pow((y2 - y1), 2), 0.5);
}
double HeronFormula(double side1, double side2, double side3)
{
	double tmparea, area;

	tmparea = (side1 + side2 + side3) / 2;
	area = pow(tmparea*(tmparea - side1)*(tmparea - side2)*(tmparea - side3), 0.5);

	return area;
}