#include "stdafx.h"
#include <iostream>
#include <vector>
#include <conio.h>
using namespace std;
const int KEY = 5;
void HASHADD(vector<int> & hash, int num);
void HASHREMOVE(vector<int> & hash, int num);
void HASHSEARCH(vector<int> & hash, int num);
void HASHPRINT(vector<vector<int>> hash);
int main()
{
	vector<vector<int>> hash;
	vector<int> vec1;
	vector<int> vec2;
	vector<int> vec3;
	vector<int> vec4;
	vector<int> vec5;
	hash.push_back(vec1);
	hash.push_back(vec2);
	hash.push_back(vec3);
	hash.push_back(vec4);
	hash.push_back(vec5);
	int menu;
	while (1)
	{
		int num;
		int hashkey;
		cout << "1. ����\t2. ����\t3. �˻�\t4. ���\t0. ����" << endl;
		cin >> menu;
		switch (menu)
		{
		case 0:
			exit(0);
			break;
		case 1:
		{
			cout << "������ �����͸� �Է��Ͻʽÿ�. : ";
			cin >> num;
			hashkey = num % KEY;
			HASHADD(hash[hashkey], num);
		}
			break;
		case 2:
		{
			cout << "������ �����͸� �Է��Ͻʽÿ�. : ";
			cin >> num;
			hashkey = num % KEY;
			HASHREMOVE(hash[hashkey], num);
		}
			break;
		case 3:
		{
			cout << "�˻��� �����͸� �Է��Ͻʽÿ�. : ";
			cin >> num;
			hashkey = num % KEY;
			HASHSEARCH(hash[hashkey], num);
		}
			break;
		case 4:
			HASHPRINT(hash);
			break;
		default:
			puts("�ٽ� �Է��Ͻʽÿ�.");
			break;
		}
	}
}
void HASHADD(vector<int> & hash, int num)
{
	hash.push_back(num);
}
void HASHREMOVE(vector<int> & hash, int num)
{
	vector<int>::iterator it;
	for (it = hash.begin(); it != hash.end(); it++)
	{
		if (*it == num)
		{
			hash.erase(it);
			return;
		}
	}
	puts("������ �����Ͱ� �������� �ʽ��ϴ�.");
}
void HASHSEARCH(vector<int> & hash, int num)
{
	vector<int>::iterator it;
	for (it = hash.begin(); it != hash.end(); it++)
	{
		if (*it == num)
		{
			puts("�����Ͱ� �����մϴ�.");
			return;
		}
	}
	puts("�����Ͱ� �������� �ʽ��ϴ�");
}
void HASHPRINT(vector<vector<int>> hash)
{
	vector<int>::iterator it;
	for (int i = 0; i < KEY; ++i)
	{
		if (hash[i].size() != 0)
		{
			cout << i << "��° KEY�� ���� �����͵��Դϴ�." << endl;
			for (it = hash[i].begin(); it != hash[i].end(); it++)
			{
				cout << *it << " -> ";
			}
			cout << endl;
		}
	}
}