#include "stdafx.h"
#include <iostream>
using namespace std;

/*
	Q. ���� 2 2 1�� �������� ũ���̸��� ������ ����� Ǯ���ϴ� ���α׷��� �ۼ��϶�.
		ax + by = e
		cx + dy = f

		x = ( ed - bf ) / ( ad - bc )
		y = ( af - ec ) / ( ad - bc )

		a, b, c, d, e, f ���� �Է¹޾� ����� ����϶�.
		ad-bc = 0 �̸� "�ذ� ����"�� ����϶�.
*/

int main()
{
	double a, b, c, d, e, f, x, y = 0.0;

	cout << "ù ��° 1�� �������� �Է��ϼ���." << endl;
	cout << "ax + by = e�� ���·� a, b, e�� ���ʷ� �Է� : ";
	cin >> a >> b >> e;
	cout << endl;

	cout << "�� ��° 1�� �������� �Է��ϼ���." << endl;
	cout << "cx + dy = f�� ���·� c, d, f�� ���ʷ� �Է� : ";
	cin >> c >> d >> f;
	cout << endl;

	if (a*d - b*c == 0)
		cout << "�ذ� ����" << endl;
	else
	{
		x = (e*d - b*f) / (a*d - b*c);
		y = (a*f - e*c) / (a*d - b*c);
		cout << "x : " << x << " y : " << y << endl;
	}

	return 0;
}