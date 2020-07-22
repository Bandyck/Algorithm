#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int nInput = 0, counter = 0;

	cout << "자릿수를 알고자 하는 수를 입력하세요. : ";
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
	cout << "자릿수는 " << counter << " 입니다" << endl;
}