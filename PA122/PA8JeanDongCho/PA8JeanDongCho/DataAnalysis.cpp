#include "DataAnalysis.h"

DA::DA()
{

}
DA::~DA()
{
	cout << "DA's destructor" << endl;
	if (mCsvStream.is_open())
	{
		mCsvStream.close();
	}
	cout << "All file clcosed" << endl;

}
void DA::runAnalysis()
{
	openFile();
	readAll();
	displaytrends();
}
void DA::openFile()
{
	mCsvStream.open("data.csv", ios::in);
}
void DA::splitLine(string line,string &data, int &unit, string &transaction)
{
	string token = "";

	stringstream ss(line);
	
	getline(ss, token, ',');
	unit = stoi(token);
	getline(ss, token, ',');
	data = token;
	getline(ss, token);
	transaction = token;

}
void DA::readAll()
{
	string line;
	string data;
	int unit;
	string transaction;
	getline(mCsvStream, line);
	while (!mCsvStream.eof())
	{
		getline(mCsvStream, line);
		if (line.size() > 2)
		{
			splitLine(line, data, unit, transaction);
			insertCompare(data, unit, transaction);

		}
		
		
		

		
	}
	cout << "-----TREE PURCHASED-----" << endl;
	mTreePurchased.inOrderTraversal();
	cout << endl<<endl;
	cout << "-----TREE SOLD-----" << endl;

	mTreeSold.inOrderTraversal();
	cout << endl << endl;

	
}
void DA::insertCompare(string data, int unit, string transaction)
{
	if (transaction == "Purchased")
	{
		mTreePurchased.insert(data, unit);
	}
	else
	{
		mTreeSold.insert(data, unit);
	}
}
void DA::displaytrends()
{
	Tnode* largest = new Tnode();
	Tnode* smallest = new Tnode();

	cout << "Purchased Item" << endl;
	mTreePurchased.findLargest(*largest);
	cout << "<Largest> " << endl;
	cout << "Data : " << largest->getData() << endl;
	cout << "Unit : " << largest->getUnits() << endl;
	cout << endl;
	mTreePurchased.findSmallest(*smallest);
	cout << "<Smallest> " << endl;
	cout << "Data : " << smallest->getData() << endl;
	cout << "Unit : " << smallest->getUnits() << endl;
	cout << endl;
	cout << endl;

	cout << "Sold Item" << endl;
	mTreeSold.findLargest(*largest);
	cout << "<Largest> " << endl;
	cout << "Data : " << largest->getData() << endl;
	cout << "Unit : " << largest->getUnits() << endl;
	cout << endl;

	mTreeSold.findSmallest(*smallest);
	cout << "<Smallest> " << endl;
	cout << "Data : " << smallest->getData() << endl;
	cout << "Unit : " << smallest->getUnits() << endl;
	cout << endl;
	cout << endl;




}