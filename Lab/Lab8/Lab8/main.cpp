#include "BST.h"



int main(void)
{
	Node n1("Sam");
	BST Tree;
	Tree.insert("t");
	Tree.insert("v");
	Tree.insert("e");
	Tree.insert("c");
	Tree.insert("s");
	Tree.insert("d");
	Tree.insert("a");
	Tree.insert("b");
	Tree.inOrderTraversal(Tree.getRoot());







	/*cout << n1.getName() << endl;
	n1.setName("JAke");
	cout << n1.getName() << endl;*/
	cout << n1;
	return 0; 
}