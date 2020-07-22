#include "stdafx.h"
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>

typedef struct Tree {
	int data;
	struct Tree *left;
	struct Tree *right;
}Tree;
Tree *Add(Tree **t, const int x);
void Remove(Tree *t, const int x);
Tree *Search(Tree *t, const int x);
void PrintTree(const Tree *t);
int main()
{
	int menu;
	int x;
	Tree *tree = NULL;
	while (1)
	{
		puts("=================================================================");
		printf("(1) ����     (2) ����     (3) �˻�     (4) ���     (0) ���� : ");
		scanf("%d", &menu);
		switch (menu)	
		{
		case 1:
			printf("Ʈ���� ������ ���ڸ� �Է��ϼ���. : ");
			scanf("%d", &x);
			Add(&tree, x);
			break;
		case 2:
			printf("Ʈ������ ������ ���ڸ� �Է��ϼ���. : ");
			scanf("%d", &x);
			Remove(tree, x);
			break;
		case 3:
			printf("Ʈ������ �˻��� ���ڸ� �Է��ϼ���. : ");
			scanf("%d", &x);
			Search(tree, x);
			break;
		case 4:
			PrintTree(tree);
			break;
		case 0:
			return 0;
		default:
			puts("�߸��� ���� �Է��ϼ̽��ϴ�.");
			system("pause");
			break;
		}
	}
}
Tree *Add(Tree **t, const int x)
{
	if (*t == NULL)
	{
		*t = (Tree*)malloc(sizeof(Tree));
		(*t)->data = x;
		(*t)->left = NULL;
		(*t)->right = NULL;
	}									
	else if ((*t)->data == x)										
		puts("�̹� Ʈ���� ��ϵǾ� �ִ� ���Դϴ�.");				
	else if ((*t)->data > x)
		(*t)->left = Add(&((*t)->left), x);
	else
		(*t)->right = Add(&((*t)->right), x);
	return (*t);
}
void Remove(Tree *t, const int x)
{
	if (Search(t, x) == NULL)
		return;
	else
	{
		Tree *tmp = t;
		if (x < t->data)
		{
			tmp = t->left;
			//printf("%d", tmp->data);
			//getch();
			if (tmp->data == x)
			{
				if (tmp->left == NULL && tmp->right == NULL)
				{
					t->left = NULL;
					free(tmp);
					return;
				}
				else if(tmp->left != NULL && tmp->right == NULL)
				{
					t->left = tmp->left;
					free(tmp);
					return;
				}
				else if(tmp->left == NULL && tmp->right != NULL)
				{
					t->right = tmp->right;
					free(tmp);
					return;
				}
				else
				{

				}
			}
		}
	}
}
Tree *Search(Tree *t, const int x)
{
	if (t == NULL)
	{
		puts("Ʈ���� �ش� ���� �������� �ʽ��ϴ�.");
		return NULL;
	}
	else if (t->data == x)
	{
		printf("%d�� Ʈ�� ���� �����մϴ�.\n", x);
		return t;
	}
	else if (t->data > x) return Search(t->left, x);
	else return Search(t->right, x);
}
void PrintTree(const Tree *t)
{
	if (t != NULL)
	{
		PrintTree(t->left);
		printf("%d\n", t->data);
		PrintTree(t->right);
	}
	//else
	//	puts("Ʈ���� �ƹ� �����͵� �������� �ʽ��ϴ�.");
}