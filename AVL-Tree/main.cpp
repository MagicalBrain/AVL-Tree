#include <iostream>
#include "AvlTree.h"

using namespace std;



int main()
{
	int in[] = { 1,2,3,4,5,6,7,8,9,0 };
	AvlTree T;
	T.root = NULL;
	
	//AvlNode *t = T.root;

	for (int i = 0; i < 10; i++)
	{
		insert(in[i], T);
	}

	int num = 1;
	cout << "Find " << num << " is " << (find(num, T) ? "true" : "false") << endl;

	return 0;
}