#include "stdafx.h"
#include <iostream>
using namespace std;

int med3(int a, int b, int c);
int main()
{
	int a, b, c = 0;

	cin >> a >> b >> c;
	cout << med3(a, b, c);

    return 0;
}
int med3(int a, int b, int c)
{
	if (a >= b)
	{
		if (a > b)
		{
			if (b >= c)
			{
				if (b > c)
					return b;
				else
					return b;
			}
			else
			{
				if (a >= c)
				{
					if (a > c)
						return c;
					else
						return c;
				}
				else
					return a;
			}
		}
		else
		{
			if (b >= c)
			{
				if (b > c)
					return b;
				else return b;
			}
			else
				return a;
		}
	}
	else
	{
		if (a >= c)
		{
			if (a > c)
				return a;
			else
				return a;
		}
		else
		{
			if (b >= c)
			{
				if (b > c)
					return c;
				else
					return c;
			}
			else
				return b;
		}
	}
}