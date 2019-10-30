#pragma once
#include <iostream>
#include <fstream>
#include "AvlTree.h"

using namespace std;

/*
һ���Ǵ�CMD����graphviz�����ж��������ӻ��Ĳ�����
dot -Tpng ������.dot -o ������.png
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