#pragma once
#include <iostream>
#include <fstream>
#include <string>

#include "BSTnode.h"

using std::cin;
using std::cout;
using std::endl;

using std::ifstream;
using std::ofstream;
using std::fstream;
using std::ios;
using std::getline;
using std::stringstream;
using std::string;

class BST
{
public:
	const BST(Node *pNewRoot = nullptr);
	~BST();
	//make postorder destroying tee private function
	bool insert(char alpha, const string &newData);
	void loadMorseTable();
	string search(char alpha);
	void print();//print
	void convert();
private:
	Node *pRoot;
	ifstream mInput;
	ifstream mInput2;


	bool insert(Node *&pTree, char alpha, const string &newData);
	void print(Node *pTree);
	string search(Node *pTree, char alpha);

};
//ifstream& operator >> (ifstream& lhs, Node &rhs);