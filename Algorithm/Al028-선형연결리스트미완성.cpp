#include "stdafx.h"
#include <string>
#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct classmate
{
	int no;
	string name;
	struct classmate* pNext;
}classmate;
typedef struct classlist
{
	classmate *head;
	classmate *tail;
};
void Initialize(classlist *list);
void classmateAdd(classlist *list, int a, string b);
void InsertFirst(classlist *list, int a, string b);
void InsertFront(classlist *list, int a, string b);
void InsertRear(classlist *list, int a, string b);
void classmateRemove(classlist *list, int a);
void Printcl(const classlist *list);
int main()
{
	classlist cl;
	Initialize(&cl);
	while (1)
	{
		int menu, mateno;
		string matename;
		puts("\t\t\t\t�޴� ����");
		puts("====================================================================");
		printf("1. �л� �߰�     2. �л� ����     3. ��ü ���     0 : ����     : ");
		scanf("%d", &menu);
		if (menu == 0) break;
		switch (menu)
		{
		case 1:
			printf("��ȣ : ");
			cin >> mateno;
			printf("�̸� : ");
			cin >> matename;
			classmateAdd(&cl, mateno, matename);
			break;
		case 2:
			printf("��ȣ : ");
			cin >> mateno;
			classmateRemove(&cl, mateno);
			break;
		case 3:
			Printcl(&cl);
			break;
		}
		
	}
}
void Initialize(classlist *list)
{
	list->head = NULL;
	list->tail = NULL;
}
void classmateAdd(classlist *list, int a, string b)
{

}
void InsertFirst(classlist *list, int a, string b)
{
	classmate *ptr;
	ptr = (classmate *)calloc(1, sizeof(classmate));
	list->head = ptr;
	list->tail = ptr;
	ptr->no = a;
	ptr->name = b;
	ptr->pNext = NULL;
}
void InsertFront(classlist *list, int a, string b)
{
	classmate * ptr;
	ptr = (classmate *)calloc(1, sizeof(classmate));
	ptr->pNext = list->head;
	list->head = ptr;
	list->tail = ptr;
	ptr->no = a;
	ptr->name = b;
}
void InsertRear(classlist *list, int a, string b)
{
	classmate * ptr = list->tail;
	ptr = (classmate *)calloc(1, sizeof(classmate));
	list->tail->pNext = ptr;
	list->tail = ptr;
	ptr->no = a;
	ptr->name = b;
	ptr->pNext = NULL;
}
void classmateRemove(classlist *list, int a)
{
	// ��������� �� ��ġ �Ǵ�
	// ���� �� ��� ����
	// �� �� ��� ����
	// ���� ��� ����
}
void Printcl(const classlist *list)
{
	classmate *ptr = list->head;
	while (ptr != NULL)
	{
		cout << "��ȣ : " << ptr->no << " �̸� : " << ptr->name << endl;
		ptr = ptr->pNext;
	}
}