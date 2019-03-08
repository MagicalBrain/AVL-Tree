#pragma once
#include <iostream>

using namespace std;

#define TRUE 1
#define FALSE 0

#define OK 1
#define ERROR 0
//#define OVERFLOW -1

typedef int Status;

#define KeyType int

struct AvlNode
{
	KeyType data;
	AvlNode *left, *right;
	int height;
};


struct AvlTree
{
	AvlNode *root;
};

//初始化函数
void InitAvlTree(AvlTree &T)
{
	T.root = NULL;
}

//查找元素函数
bool find(KeyType x, AvlTree T)
{
	AvlNode *t = T.root;

	while (t != NULL && t->data != x)
	{
		if (t->data > x)
			t = t->left;
		else
			t = t->right;
	}
	if (t == NULL)
		return FALSE;
	else
		return TRUE;
}


//insert0
void insert0(KeyType x,AvlNode* t)
{
	if (t == NULL)
		t = (AvlNode*)malloc(sizeof(AvlNode));
	else if (x < t->data)
	{
		insert0(x, t->left);
		if (t->left->height - t->right->height == 2)
			if (x < t->left->data)
				LL(t);
			else
				LR(t);
	}
}


//insert函数的实现
void insert(KeyType x,AvlTree &T)
{
	insert0(x, T.root);
}