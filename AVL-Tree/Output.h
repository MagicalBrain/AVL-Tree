#pragma once
#include <iostream>
#include <fstream>
#include "AvlTree.h"

using namespace std;

/*
一下是从CMD调用graphviz来进行二叉树可视化的操作：
dot -Tpng 二叉树.dot -o 二叉树.png
*/


void fprint_tree0(AvlNode* t, ofstream* Tree)
{
	if (t != NULL)
	{
		*Tree << t->data << ";" << endl;
		if (t->left != NULL)
			* Tree << t->data << "->" << t->left->data << ";" << endl;
		if (t->right != NULL)
			* Tree << t->data << "->" << t->right->data << ";" << endl;

		fprint_tree0(t->left, Tree);

		fprint_tree0(t->right, Tree);
	}
}

void fprint_tree(AvlNode* t, char str[]) {
	ofstream Tree;
	Tree.open(str);
	Tree << "digraph G{" << endl;

	fprint_tree0(t, &Tree);
	Tree << "}" << endl;
	Tree.close();
}