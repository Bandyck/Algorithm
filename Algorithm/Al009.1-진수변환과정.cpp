#include "stdafx.h"
#include <iostream>
using namespace std;
#include <string>
#include <math.h>

int main()
{
	int InputNtt = 0;
	string InputNum;

	cout << "몇 진수의 수인가 : ";
	cin >> InputNtt;
	cout << "수 입력 : ";
	cin >> InputNum;

	// 길이 확인하고
	cout << InputNum.size() << endl << endl;

	// string으로 받아서 확인
	int i = 0;
	for (i = 0; i < InputNum.size(); ++i)
	{
		cout << InputNum[i] << '\t';
	}
	cout << endl;
	cout << endl;

	// 각각을 짤라서 아스키코드를 숫자로 변환
	for (i = 0; i < InputNum.size(); ++i)
	{
		cout << (int)InputNum[i] << '\t';
	}

	cout << endl;
	cout << endl;

	// 각각을 짤라서 아스키코드를 숫자로 변환
	// 영어는 55를 빼고, 숫자는 48을 빼고
	for (i = 0; i < InputNum.size(); ++i)
	{
		if ((int)InputNum[i] >= 65)
			cout << (int)InputNum[i] - 55 << '\t';
		else
			cout << (int)InputNum[i] - 48 << '\t';
	}
	cout << endl;
	cout << endl;

	int sum = 0;

	// 각 수를 짤라서 10진법으로 고치고
	for (i = 0; i < InputNum.size(); ++i)
	{
		if ((int)InputNum[i] >= 65)
			cout << ((int)InputNum[i] - 55) * pow(InputNtt, InputNum.size() - 1 - i) << '\t';
		else
			cout << ((int)InputNum[i] - 48) * pow(InputNtt, InputNum.size() - 1 - i) << '\t';
	}

	cout << endl;
	cout << endl;

	// 더해서 10진수로 변환된 값.

	for (i = 0; i < InputNum.size(); ++i)
	{
		if ((int)InputNum[i] >= 65)
			sum += ((int)InputNum[i] - 55) * pow(InputNtt, InputNum.size() - 1 - i);
		else
			sum += ((int)InputNum[i] - 48) * pow(InputNtt, InputNum.size() - 1 - i);
	}

	cout << sum << endl;
	cout << endl;
	cout << endl;

	int ResultNtt = 0;

	cout << "몇 진수로 변환을? : ";
	cin >> ResultNtt;

	int *pt = new int;

	// 진수로 나누고 하나씩 넣기. 배열의 크기가 얼마나 될 지 모르니까 동적 할당.
	i = 0;
	while (sum != 0)
	{
		*(pt+i) = sum % ResultNtt;
		sum /= ResultNtt;
		i++;
	}

	// 배열의 크기가 i이므로 for문을 쓰기 위해 j 하나 더 추가.
	// 다시 배열을 역순으로 바꾸기 위해 tmp 하나 더 변수 추가하고 역순으로 바꾸고 출력해봄
	int j = 0;
	int tmp = 0;

	for (j = 0; j < i / 2; ++j)
	{
		tmp = *(pt+j);
		*(pt + j) = *(pt + i - 1 - j);
		*(pt + i - 1 - j) = tmp;
	}
	for (j = 0; j<i; ++j)
	{
		cout << pt[j] << '\t';
	}

	cout << endl;
	cout << endl;

	// 마지막 받을 결과 배열 선언
	char *ResultNttArray = new char;

	// 아스키 코드로 변환
	for (j = 0; j < i; ++j)
	{
		if (pt[j] >= 10)
			*(ResultNttArray+j) = char(pt[j]) + 55;
		else *(ResultNttArray+j) = char(pt[j]) + 48;
	}

	// 출력
	for (j = 0; j<i; ++j)
	{
		cout << *(ResultNttArray+j);
	}

	cout << endl;

	//delete[] pt;
	//delete[] ResultNttArray;

	// delete 안하면 정답이 나오는데 delete 하면 오류(heap corruption detected) 걸려서 내일 우재씨에게 물어보기

	return 0;
}