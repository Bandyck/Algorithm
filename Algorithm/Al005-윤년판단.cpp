#include "stdafx.h"
#include <iostream>
using namespace std;
/*
	윤년계산.
	4로 나누어 떨어지면서 100으로는 나누어 떨어지지 않거나, 400으로 나누어 떨어지는 해는 윤년이다.
	년도 입력
*/

int main()
{
	int LeapYear = 0;
	bool LeapYearTrigger = false;

	cout << "년도를 입력하세요 : ";
	cin >> LeapYear;

	if (LeapYear % 400 == 0)
		LeapYearTrigger = true;
	else 
	{
		if (LeapYear % 100 == 0)
			LeapYearTrigger = false;
		else
		{
			if (LeapYear % 4 == 0)
				LeapYearTrigger = true;
			else
				LeapYearTrigger = false;
		}
	}
	if (LeapYearTrigger)
		cout << "윤년입니다" << endl;
	else cout << "윤년이 아닙니다" << endl;

	return 0;
}