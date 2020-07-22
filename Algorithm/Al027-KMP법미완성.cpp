#include "stdafx.h"
#include <string.h>
#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

int main()
{
	string text;
	string find;
	cout << "원래의 text를 입력하세요 : ";
	cin >> text;
	cout << "찾고자 하는 text를 입력하세요 : ";
	cin >> find;

	int strindex;
	int textpoint;
	int findpoint;
	int len1 = text.size();
	int len2 = find.size();
	int counter;
	findpoint = len2 - 1;
	textpoint = len2 - 1;
	strindex = len2 - 1;
	cout << "findpoint : " << findpoint << "   textpoint : " << textpoint << "   strindex : " << strindex << endl;
	getch();
	while (1)
	{
		counter = len2;
		if (text[textpoint] == find[findpoint])
		{
			textpoint--;
			findpoint--;
			strindex--;
			counter--;
		}
		else
		{
			findpoint--;
			counter--;
		}
		if (counter == 0)
		{
			textpoint += len2;
		}
		cout << "findpoint : " << findpoint << "   textpoint : " << textpoint << "   strindex : " << strindex << endl;
		if (strindex == 0)
		{
			for (int i = textpoint; i < textpoint + len2; ++i)
				text[i] = '*';
			break;
		}
		getch();
	}


	cout << endl << endl;
	cout << "나왔습니다 !" << endl;
	cout << text << endl;
	getch();
	
	return 0;
}