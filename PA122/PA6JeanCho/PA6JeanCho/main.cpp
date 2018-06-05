#include "BSTnode.h"
#include "BST.h"
/*
CPTS 122 PA6
This program read MorseTabel.txt and save char alphabet and its corresponding morse code string into binary search tree node.
Furthermore it can search Morse string for specific alphabet.
It can read in Convert.txt and convert english text to morse coed text
*/
int main(void)
{
	BST tree;
	string str1;
	

	tree.print(); //print BST inorder
	
	cout << endl;
	cout << "Converting file Convert.txt.." << endl << endl;
	tree.convert();
	return 0;
}