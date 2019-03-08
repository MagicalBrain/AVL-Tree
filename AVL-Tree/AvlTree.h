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

//��ʼ������
void InitAvlTree(AvlTree &T)
{
	T.root = NULL;
}

//����Ԫ�غ���
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


//4������������ʵ��
////��ߣ�����
void LL(AvlNode *t)
{

}

////����ҵͣ�������������
void LR(AvlNode *t)
{

}


void RR(AvlNode *t)
{

}


void RL(AvlNode *t)
{

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
	else if (x > t->data)
	{
		insert0(x, t->right);
		if (t->right->height - t->left->height == 2)
			if (x > t->right->data)
				RR(t);
			else
				RL(t);
	}
	t->height = (t->left->height > t->right->height) ? t->left->height + 1 : t->right->height + 1;
}


//insert������ʵ��
void insert(KeyType x,AvlTree &T)
{
	insert0(x, T.root);
}