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
		printf("(1) 삽입     (2) 삭제     (3) 검색     (4) 출력     (0) 종료 : ");
		scanf("%d", &menu);
		switch (menu)	
		{
		case 1:
			printf("트리에 삽입할 숫자를 입력하세요. : ");
			scanf("%d", &x);
			Add(&tree, x);
			break;
		case 2:
			printf("트리에서 삭제할 숫자를 입력하세요. : ");
			scanf("%d", &x);
			Remove(tree, x);
			break;
		case 3:
			printf("트리에서 검색할 숫자를 입력하세요. : ");
			scanf("%d", &x);
			Search(tree, x);
			break;
		case 4:
			PrintTree(tree);
			break;
		case 0:
			return 0;
		default:
			puts("잘못된 값을 입력하셨습니다.");
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
		puts("이미 트리에 등록되어 있는 값입니다.");				
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
		puts("트리에 해당 값이 존재하지 않습니다.");
		return NULL;
	}
	else if (t->data == x)
	{
		printf("%d은 트리 내에 존재합니다.\n", x);
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
	//	puts("트리에 아무 데이터도 존재하지 않습니다.");
}