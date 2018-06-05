#pragma once
#include "BST.h"
#include <sstream>
using std::ifstream;
using std::ofstream;
using std::fstream;
using std::ios;
using std::getline;
using std::stringstream;
using std::string;
class DA
{
public:
	DA();
	~DA();
	void runAnalysis();
private:
	BST mTreeSold;
	BST mTreePurchased;
	ifstream mCsvStream;

	void openFile();
	void splitLine(string line,string &data, int &unit, string &transaction);
	void readAll();
	void insertCompare(string data, int unit, string transaction);
	void displaytrends();
};