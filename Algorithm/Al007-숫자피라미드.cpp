#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int n = 0;
	int i = 0, j = 0;

	cin >> n;

	for (i = 0; i < n ; ++i)
	{
		for (j = 0; j < 2*n-1; ++j)
		{
			if (i > j)
			{
				cout.width(2);
				cout << ' ';
			}
			else
			{
				if (j >= 2 * n - 1 - i)
				{
					cout.width(2);
					cout << ' ';
				}
				else
				{
					cout.width(2);
					cout << i + 1;
				}
			}
		}
		cout << endl;
	}
	for (i = n+1; i < 2 * n; ++i)
	{
		for (j = 0; j < 2 * n - 1; ++j)
		{
			if (2 * n - 1 - i > j)
			{
				cout.width(2);
				cout << ' ';
			}
			else
			{
				if (j >= i)
				{
					cout << ' ';
				}
				else
				{
					cout.width(2);
					cout << 2 * n - i;
				}
					
			}
		}
		cout << endl;
	}

	return 0;
}