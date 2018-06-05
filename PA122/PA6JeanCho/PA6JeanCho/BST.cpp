#include "BST.h"

BST::BST(Node *pNewRoot)
{
	this->pRoot = pNewRoot;
	this->mInput.open("MorseTable.txt", ios::in);
	this->mInput2.open("Convert.txt", ios::in);
	this->loadMorseTable();
	mInput.close();
}

BST::~BST()
{
	cout << "Inside BST destructor, closing files..." << endl;
	if (mInput.is_open())
	{
		mInput.close();
	}
	if (mInput2.is_open())
	{
		mInput2.close();
	}
	cout << "File closed" << endl;
}
// public

void BST::loadMorseTable()//load morse table as a nodes of BST, insert in order
{
	Node *n = nullptr;
	char alphabet;
	string line;
	while (!mInput.eof())
	{
		mInput >> line;
		alphabet = line[0];
		mInput >> line;
		this->insert(this->pRoot,alphabet, line);
	}
}

void BST::convert()
{
	string line="";
	string converted="";
	cout << "This is a test of the cpts 122 Morse code conversion tool." << endl;
	while (!mInput2.eof())
	{
		mInput2 >> line;
		
		for (int i = 0; line[i] != NULL; i++)
		{
			if (line[i] == '\n')
			{
				converted += "\n";
			}
			else
			{
				converted += search(line[i]);
				converted += " ";//space for each character
			}
		}
		converted += "  ";//double space, eventually 1+2 =3 space for each Morse string
	}
	cout << converted << endl;
	cout << "Conversion Complete" << endl << endl;
}

//ifstream& operator >> (ifstream& lhs, Node &rhs)
//{
//	string input, morse;// sAlpha = "", copyline;
//	char alphabet;
//	
//	lhs >> input;
//	alphabet = input[0];
//	rhs.setAlpha(alphabet);
//	lhs >> input;
//	rhs.setData(input);
//	//lhs >> input;//flush the empty line
//	return lhs;
//}

bool BST::insert(char alpha, const string &newData)
{
	bool success = false;

	success = insert((this->pRoot),alpha,newData); // private

	return success;
}
//based on the size of aplphabet
bool BST::insert(Node *&pTree, char alpha, const string &newData)
{
	bool success = false;

	if (pTree == nullptr) // base case?
	{
		Node *pMem = nullptr;

		pMem = new Node(alpha, newData);

		if (pMem != nullptr)
		{
			success = true;
			pTree = pMem;
		}
	}
	else if (alpha > (pTree)->getAlpha())// recursive step
	{
		// go down right subtree
		success = insert(((pTree)->getRight()), alpha, newData);
	}
	else if (alpha < (pTree)->getAlpha())// left subtree
	{
		success = insert(((pTree)->getLeft()), alpha, newData);
	}
	else // duplicate
	{
		cout << "dup" << endl;
	}

	return success;
}

void BST::print()
{
	print(this->pRoot);
}

void BST::print(Node *pTree)
{
	// algorithm: 1. go as far left as possible 
	// 2. process the node (print)
	// 3. go as far right as possible
	if (pTree != nullptr)
	{
		print(pTree->getLeft());
		cout <<pTree->getAlpha()<<" : " << pTree->getData() << endl;
		print(pTree->getRight());
	}
}

string BST::search(char alpha)
{
	string morse;
	morse = search(this->pRoot, alpha);
	return morse;
	
}

string BST::search(Node *pTree,char alpha)//recursive function that returns data
{
	char ss = pTree->getAlpha();
	string target = "";
	if (pTree != nullptr)
	{
		if (pTree->getAlpha() == alpha)//return if found
		{
			target = pTree->getData();
		}
		else if (alpha > (pTree)->getAlpha())// recursive step
		{
			// go down right subtree
			target = search(pTree->getRight(), alpha);

		}
		else if (alpha < (pTree)->getAlpha())// left subtree
		{
			target = search(pTree->getLeft(), alpha);
		}
		
		
	}
	/*else
	{
		cout << "Failed to find target" << endl;
		return "/failtofind/";
	}*/
	return target;
}