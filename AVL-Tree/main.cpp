#include <iostream>
#include "AvlTree.h"
#include "Output.h"

using namespace std;

/*
一下是从CMD调用graphviz来进行二叉树可视化的操作：
dot -Tpng Avl.dot -o Avl.png
*/

int main()
{
	int in[] = { 1,2,3,4,5,6,7,8,9,0 };
	AvlTree T;
	T.root = NULL;

	for (int i = 0; i < 10; i++)
	{
		insert(in[i], T);
	}

	char str[40] = "Avl树状图\\Avl01.dot";
	fprint_tree(T.root, str);

	int num;
	puts("输入要查找的值");
	scanf("%d",&num);
	cout << "Find " << num << " is " << (find(num, T) ? "true" : "false") << endl;

	return 0;
}