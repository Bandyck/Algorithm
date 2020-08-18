#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
#define I 3000
#define NUM_NODE 8
void Dijkstra(int start, int end);
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
int main()
{
	int start, end;
	cout << "출발 노드 입력 : ";
	cin >> start;
	cout << "목적 노드 입력 : ";
	cin >> end;
	Dijkstra(start, end);
	return 0;
}
void Dijkstra(int start, int end)
{
	int i;
	int VertexCost[NUM_NODE][2];
	for (i = 0; i < NUM_NODE; i++)
	{
		VertexCost[]
	}
	vector<vector<int>> v;
	v.assign(7, vector<int>(0));
	vector<int>::iterator vit;
	vector<int> v1;
	vector<int> v2;
	vector<int> v3;
	vector<int> v4;
	vector<int> v5;
	vector<int> v6;
	vector<int> v7;
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);
	v.push_back(v5);
	v.push_back(v6);
	v.push_back(v7);

	int i;
	for (i = 0; i < NUM_NODE; i++)
	{
		if (aEdgeCost[start - 1][i] != 0 && aEdgeCost[start - 1][i] != I)
			v1.push_back(aEdgeCost[start - 1][i]);
	}
	for (vit = v1.begin(); vit != v1.end(); vit++)
		cout << *vit << ' ';
	cout << endl;
}