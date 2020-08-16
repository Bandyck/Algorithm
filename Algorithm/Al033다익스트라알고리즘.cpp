#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
#define I 3000
#define NUM_NODE 8
int main()
{
	int start, end;
	int aEdgeCost[NUM_NODE][NUM_NODE] =
	{
		{ 0, 2, I, I, I, 3, I, I },	//	NODE1
		{ 2, 0, 4, 1, I, I, I, I },	//	NODE2
		{ I, 4, 0, I, 3, I, I, I },	//	NODE3
		{ I, 1, I, 0, 3, I, 2, I },	//	NODE4
		{ I, I, 3, 3, 0, I, I, 4 },	//	NODE5
		{ 3, I, I, I, I, 0, 6, I },	//	NODE6
		{ I, I, I, 2, I, 6, 0, 4 },	//	NODE7
		{ I, I, I, I, 4, I, 4, 0 },	//	NODE8
	};

	cout << "출발 노드 입력 : ";
	cin >> start;
	cout << "목적 노드 입력 : ";
	cin >> end;
	int LeastCost[NUM_NODE];

			
}