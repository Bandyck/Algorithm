#include "stdafx.h"
#include <iostream>
using namespace std;

/*
	Q. 다음 2 2 1차 방정식을 크래이머의 공식을 사용해 풀이하는 프로그램을 작성하라.
		ax + by = e
		cx + dy = f

		x = ( ed - bf ) / ( ad - bc )
		y = ( af - ec ) / ( ad - bc )

		a, b, c, d, e, f 값을 입력받아 결과를 출력하라.
		ad-bc = 0 이면 "해가 없음"을 출력하라.
*/

int main()
{
	double a, b, c, d, e, f, x, y = 0.0;

	cout << "첫 번째 1차 방정식을 입력하세요." << endl;
	cout << "ax + by = e의 형태로 a, b, e를 차례로 입력 : ";
	cin >> a >> b >> e;
	cout << endl;

	cout << "두 번째 1차 방정식을 입력하세요." << endl;
	cout << "cx + dy = f의 형태로 c, d, f를 차례로 입력 : ";
	cin >> c >> d >> f;
	cout << endl;

	if (a*d - b*c == 0)
		cout << "해가 없음" << endl;
	else
	{
		x = (e*d - b*f) / (a*d - b*c);
		y = (a*f - e*c) / (a*d - b*c);
		cout << "x : " << x << " y : " << y << endl;
	}

	return 0;
}