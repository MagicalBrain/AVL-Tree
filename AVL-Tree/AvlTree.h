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


int height(AvlNode* t)
{
	return t == NULL ? -1 : t->height;
}


//4个调整函数的实现
////左高，右旋
void LL(AvlNode * &t)
{
	AvlNode* t1 = t->left;
	t->left = t1->right;
	t1->right = t;
	t->height = (height(t->left) > height(t->right)) ? height(t->left) + 1 : height(t->right) + 1;
	t1->height = (height(t->left) > t->height) ? height(t->left) + 1 : t->height + 1;
	t = t1;
}




void RR(AvlNode * &t)
{
	AvlNode* t1 = t->right;
	t->right = t1->left;
	t1->left = t;
	t->height = (height(t->left) > height(t->right)) ? height(t->left) + 1 : height(t->right) + 1;
	t1->height = (height(t->right) > t->height) ? height(t->right) + 1 : t->height + 1;
	t = t1;
}


////左高右低，先右旋再左旋
void LR(AvlNode * &t)
{
	RR(t->left);
	LL(t);
}

void RL(AvlNode * &t)
{
	LL(t->right);
	RR(t);
}


//insert0
void insert0(KeyType &x,AvlNode* &t)
{
	if (t == NULL)
	{
		t = (AvlNode*)malloc(sizeof(AvlNode));
		t->left = NULL;
		t->right = NULL;
		t->height = 0;
		t->data = x;
	}
	else if (x < t->data)
	{
		insert0(x, t->left);
		if (height(t->left) - height(t->right) == 2)
			if (x < t->left->data)
				LL(t);
			else
				LR(t);
	}
	else if (x > t->data)
	{
		insert0(x, t->right);
		if (height(t->right) - height(t->left) == 2)
			if (x > t->right->data)
				RR(t);
			else
				RL(t);
	}
	t->height = (height(t->left) > height(t->right)) ? height(t->left) + 1 : height(t->right) + 1;
}


//insert函数的实现
void insert(KeyType x,AvlTree &T)
{
	insert0(x, T.root);
}


//remove函数的实现
Status remove(KeyType x,AvlNode *&t)
{
	Status stop = FALSE;
	int subTree;

	if (t == NULL)
		return TRUE;
	if (x < t->data)
	{
		stop = remove(x, t->left);
		subTree = 1;
	}
	else if (x > t->data)
	{
		stop = remove(x, t->right);
		subTree = 2;
	}
	else if (t->left != NULL &&t->right != NULL)
	{
		AvlNode* tmp = t->right;
		while (tmp->left != NULL)
			tmp = tmp->left;
		t->data = tmp->data;
		stop = remove(t->data, t->right);
		subTree = 2;
	}
	else
	{
		AvlNode*oddNode = t;
		t = (t->left != NULL) ? t->left : t->right;
		return FALSE;
	}

	if (stop)
		return TRUE;
	int bf;
	switch (subTree)
	{
	case 1:
		bf = height(t->left) - height(t->right) + 1;
		if (bf == 0)
			return TRUE;
		if (bf == 1)
			return FALSE;
		if (bf == -1)
		{
			int bfr = t->right->left->height - t->right->right->height;
			switch (bfr)
			{
			case 0:
				RR(t);
				return TRUE;
			case -1:
				RR(t);
				return FALSE;
			default:
				RL(t);
				return FALSE;
				//break;
			}
		}
		break;
	case 2:
		bf = height(t->left) - height(t->right) - 1;
		if (bf == 0)
			return TRUE;
		if (bf == -1)
			return FALSE;
		if (bf == 1)
		{
			int bfr = t->right->left->height - t->right->right->height;
			switch (bfr)
			{
			case 0:
				LL(t);
				return TRUE;
			case -1:
				LL(t);
				return FALSE;
			default:
				LR(t);
				return FALSE;
				//break;
			}
		}
		break;
	default:
		break;
	}
}