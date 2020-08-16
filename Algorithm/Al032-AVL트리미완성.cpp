#include "stdafx.h"
//#include <iostream>
//#include <queue>
//#include <string>
//using namespace std;
//class leaf
//{
//public:
//	unsigned short num;
//	std::string name;
//	leaf * left;
//	leaf * right;
//
//	leaf()
//	{
//		left = right = nullptr;
//	}
//	leaf(unsigned short _num, std::string _name) : leaf()
//	{
//		this->num = _num;
//		this->name = _name;
//	}
//	leaf(unsigned short _num, std::string _name, leaf * _left, leaf * _right) : leaf(_num, _name)
//	{
//		this->left = _left;
//		this->right = _right;
//	}
//};
//class TreeClass
//{
//public:
//	leaf * top;
//	leaf * search(unsigned short num);
//	bool Insert(leaf * leaf);
//	bool Insert(unsigned short num, std::string name);
//	bool remove(leaf * leaf);
//	bool remove(unsigned short num);
//	void print(leaf * leaf);
//	void printBfs(leaf * leaf);
//	TreeClass();
//	~TreeClass();
//};
//bool TreeClass::Insert(leaf * le)
//{
//	if (top == nullptr)
//	{
//		top = le;
//		return true;
//	}
//
//	leaf * search = top;
//	while (1)
//	{
//		if (search->num > le->num)
//		{
//			if (search->left == nullptr)
//			{
//				search->left = le;
//				return true;
//			}
//			else
//				search = search->left;
//		}
//		else if (search->num < le->num)
//		{
//			if (search->right == nullptr)
//			{
//				search->right = le;
//				return true;
//			}
//			else
//				search = search->right;
//		}
//		else
//			break;
//	}
//	return false;
//}
//bool TreeClass::Insert(unsigned short num, std::string name)
//{
//	leaf * le = new leaf(num, name);
//	return this->Insert(le);
//}
//bool TreeClass::remove(leaf * leaf)
//{
//	return this->remove(leaf->num);
//}
//bool TreeClass::remove(unsigned short num)
//{
//	leaf * search = top;
//	leaf * prev = nullptr;
//	while (search->left != nullptr || search->right != nullptr)
//	{
//		if (num < search->num)
//		{
//			if (search->left == nullptr)
//				return false;
//			prev = search;
//			search = search->left;
//		}
//		else if (num > search->num)
//		{
//			if (search->right == nullptr)
//				return false;
//			prev = search;
//			search = search->right;
//		}
//		else
//			break;
//	}
//	if (search->num != num)
//		return false;
//	if (search->left == nullptr && search->right == nullptr)
//	{
//		if (search == top)
//			top = nullptr;
//		else
//		{
//			if (prev->right == search)
//				prev->right = nullptr;
//			else
//				prev->left = nullptr;
//		}
//	}
//	else if (search->left != nullptr && search->right != nullptr)
//	{
//		leaf * upPlacePrev = search;
//		leaf * upPlace = search->left;
//		while (upPlace->right != nullptr)
//		{
//			upPlacePrev = upPlace;
//			upPlace = upPlace->right;
//		}
//		if (upPlacePrev != search)
//		{
//			if (upPlace->left != nullptr)
//				upPlacePrev->right = upPlace->left;
//			else
//				upPlacePrev->right = nullptr;
//		}
//		if (top == search)
//			top = upPlace;
//		else
//		{
//			if (prev->left == search)
//				prev->left = upPlace;
//			else
//				prev->right = upPlace;
//		}
//		if (search->left != upPlace)
//			upPlace->left = search->left;
//		upPlace->right = search->right;
//	}
//	else if (search->left != nullptr)
//	{
//		if (search == top)
//		{
//			top = search->left;
//		}
//		else
//		{
//			if (prev->left == search)
//				prev->left = search->left;
//			else
//				prev->right = search->left;
//		}
//	}
//	else if (search->right != nullptr)
//	{
//		if (search == top)
//		{
//			top = search->right;
//		}
//		else
//		{
//			if (prev->left == search)
//				prev->left = search->right;
//			else
//				prev->right = search->right;
//		}
//	}
//	delete search;
//	return true;
//}
//void TreeClass::print(leaf * leaf)
//{
//	if (leaf == nullptr)
//		return;
//	print(leaf->left);
//	std::cout << "번호 : " << leaf->num << "  이름 : " << leaf->name << "\n";
//	print(leaf->right);
//}
//void TreeClass::printBfs(leaf * top)
//{
//	if (top == nullptr)
//		return;
//	std::queue<leaf *> bfs;
//	bfs.push(top);
//	leaf * temp;
//	int cnt = 1;
//	while (bfs.size() > 0)
//	{
//		int size = bfs.size();
//		for (size_t i = 0; i < size; i++)
//		{
//			std::cout << "번호 : " << bfs.front()->num << "\t";
//			if (bfs.front()->left != nullptr)
//				bfs.push(bfs.front()->left);
//			if (bfs.front()->right != nullptr)
//				bfs.push(bfs.front()->right);
//			bfs.pop();
//		}
//		std::cout << "\n";
//	}
//}
//leaf * TreeClass::search(unsigned short num)
//{
//	leaf * search = top;
//	while (search != nullptr)
//	{
//		if (num < search->num)
//			search = search->left;
//		else if (num > search->num)
//			search = search->right;
//		else
//			break;
//	}
//	return search;
//}
//TreeClass::TreeClass()
//{
//	top = nullptr;
//}
//TreeClass::~TreeClass()
//{
//}
//int main()
//{
//	TreeClass tc;
//	size_t menu = 1;
//	while (menu)
//	{
//		cout << "1. 삽입 2. 삭제 3. 검색 4. 출력 0. 종료\n";
//		cin >> menu;
//		switch (menu)
//		{
//		case 1:
//		{
//			unsigned short num = 0;
//			string name;
//			cout << "삽입하는 데이터를 입력하세요.\n";
//			cout << "번호 : ";
//			cin >> num;
//			cout << "이름 : ";
//			cin >> name;
//			tc.Insert(num, name);
//		}
//		break;
//		case 2:
//		{
//			unsigned short num = 0;
//			cout << "삭제할 번호를 입력하세요.\n";
//			cout << "번호 : ";
//			cin >> num;
//			tc.remove(num);
//		}
//		break;
//		case 3:
//		{
//			leaf * search;
//			unsigned short num = 0;
//			cout << "검색할 번호를 입력하세요.\n";
//			cout << "번호 : ";
//			cin >> num;
//			search = tc.search(num);
//			if (search == nullptr)
//			{
//				cout << "검색에 실패하였습니다.\n";
//			}
//			else
//			{
//				cout << "번호 : " << search->num << "  이름 : " << search->name << "\n";
//			}
//		}
//		break;
//		case 4:
//		{
//			tc.print(tc.top);
//		}
//		break;
//		case 5:
//			tc.printBfs(tc.top);
//			break;
//		default:
//			break;
//		}
//	}
//	return 0;
//}