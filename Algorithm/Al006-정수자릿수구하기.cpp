#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int nInput = 0, counter = 0;

	cout << "�ڸ����� �˰��� �ϴ� ���� �Է��ϼ���. : ";
	cin >> nInput;
	while (1)
	{
		if (nInput != 0)
		{
			counter++;
			nInput /= 10;
		}
		else
			break;
	}
	cout << "�ڸ����� " << counter << " �Դϴ�" << endl;
}