#include "stdafx.h"
#include <iostream>
using namespace std;
/*
	������.
	4�� ������ �������鼭 100���δ� ������ �������� �ʰų�, 400���� ������ �������� �ش� �����̴�.
	�⵵ �Է�
*/

int main()
{
	int LeapYear = 0;
	bool LeapYearTrigger = false;

	cout << "�⵵�� �Է��ϼ��� : ";
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
		cout << "�����Դϴ�" << endl;
	else cout << "������ �ƴմϴ�" << endl;

	return 0;
}