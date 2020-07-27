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
		cout << "1. 삽입\t2. 삭제\t3. 검색\t4. 출력\t0. 종료" << endl;
		cin >> menu;
		switch (menu)
		{
		case 0:
			exit(0);
			break;
		case 1:
		{
			cout << "삽입할 데이터를 입력하십시오. : ";
			cin >> num;
			hashkey = num % KEY;
			HASHADD(hash[hashkey], num);
		}
			break;
		case 2:
		{
			cout << "삭제할 데이터를 입력하십시오. : ";
			cin >> num;
			hashkey = num % KEY;
			HASHREMOVE(hash[hashkey], num);
		}
			break;
		case 3:
		{
			cout << "검색할 데이터를 입력하십시오. : ";
			cin >> num;
			hashkey = num % KEY;
			HASHSEARCH(hash[hashkey], num);
		}
			break;
		case 4:
			HASHPRINT(hash);
			break;
		default:
			puts("다시 입력하십시오.");
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
	puts("삭제할 데이터가 존재하지 않습니다.");
}
void HASHSEARCH(vector<int> & hash, int num)
{
	vector<int>::iterator it;
	for (it = hash.begin(); it != hash.end(); it++)
	{
		if (*it == num)
		{
			puts("데이터가 존재합니다.");
			return;
		}
	}
	puts("데이터가 존재하지 않습니다");
}
void HASHPRINT(vector<vector<int>> hash)
{
	vector<int>::iterator it;
	for (int i = 0; i < KEY; ++i)
	{
		if (hash[i].size() != 0)
		{
			cout << i << "번째 KEY를 가진 데이터들입니다." << endl;
			for (it = hash[i].begin(); it != hash[i].end(); it++)
			{
				cout << *it << " -> ";
			}
			cout << endl;
		}
	}
}