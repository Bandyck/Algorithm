#include "stdafx.h"
#include <iostream>
using namespace std;
#include <string>
#include <math.h>

int main()
{
	int InputNtt = 0;
	string InputNum;

	cout << "�� ������ ���ΰ� : ";
	cin >> InputNtt;
	cout << "�� �Է� : ";
	cin >> InputNum;

	// ���� Ȯ���ϰ�
	cout << InputNum.size() << endl << endl;

	// string���� �޾Ƽ� Ȯ��
	int i = 0;
	for (i = 0; i < InputNum.size(); ++i)
	{
		cout << InputNum[i] << '\t';
	}
	cout << endl;
	cout << endl;

	// ������ ©�� �ƽ�Ű�ڵ带 ���ڷ� ��ȯ
	for (i = 0; i < InputNum.size(); ++i)
	{
		cout << (int)InputNum[i] << '\t';
	}

	cout << endl;
	cout << endl;

	// ������ ©�� �ƽ�Ű�ڵ带 ���ڷ� ��ȯ
	// ����� 55�� ����, ���ڴ� 48�� ����
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

	// �� ���� ©�� 10�������� ��ġ��
	for (i = 0; i < InputNum.size(); ++i)
	{
		if ((int)InputNum[i] >= 65)
			cout << ((int)InputNum[i] - 55) * pow(InputNtt, InputNum.size() - 1 - i) << '\t';
		else
			cout << ((int)InputNum[i] - 48) * pow(InputNtt, InputNum.size() - 1 - i) << '\t';
	}

	cout << endl;
	cout << endl;

	// ���ؼ� 10������ ��ȯ�� ��.

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

	cout << "�� ������ ��ȯ��? : ";
	cin >> ResultNtt;

	int *pt = new int;

	// ������ ������ �ϳ��� �ֱ�. �迭�� ũ�Ⱑ �󸶳� �� �� �𸣴ϱ� ���� �Ҵ�.
	i = 0;
	while (sum != 0)
	{
		*(pt+i) = sum % ResultNtt;
		sum /= ResultNtt;
		i++;
	}

	// �迭�� ũ�Ⱑ i�̹Ƿ� for���� ���� ���� j �ϳ� �� �߰�.
	// �ٽ� �迭�� �������� �ٲٱ� ���� tmp �ϳ� �� ���� �߰��ϰ� �������� �ٲٰ� ����غ�
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

	// ������ ���� ��� �迭 ����
	char *ResultNttArray = new char;

	// �ƽ�Ű �ڵ�� ��ȯ
	for (j = 0; j < i; ++j)
	{
		if (pt[j] >= 10)
			*(ResultNttArray+j) = char(pt[j]) + 55;
		else *(ResultNttArray+j) = char(pt[j]) + 48;
	}

	// ���
	for (j = 0; j<i; ++j)
	{
		cout << *(ResultNttArray+j);
	}

	cout << endl;

	//delete[] pt;
	//delete[] ResultNttArray;

	// delete ���ϸ� ������ �����µ� delete �ϸ� ����(heap corruption detected) �ɷ��� ���� ���羾���� �����

	return 0;
}