#include "list.h"

list::list(int newsize )
{
	mSize = newsize;
	mMaxsize = 100;
	mTop = new node[100];
	this->mInput.open("classList.csv", ios::in);
	this->mMasterIn.open("master.txt", ios::in);
}

list::~list()
{
	delete[]mTop;
	if (mInput.is_open())
	{
		mInput.close();
	}
	if (mMasterIn.is_open())
	{
		mMasterIn.close();
	}
	if (mMasterOut.is_open())
	{
		mMasterOut.close();
	}
	cout << "All file closed" << endl;
}
void list::loadClassList()
{
	this->loadList(mInput);
}
void list::loadMasterList()
{
	if (mMasterIn.peek()!=mMasterIn.eof())
	{
		//this->loadList(mMasterIn);
		string line;
		string name;

		int num;


		//getline(mMasterIn, line);

		while (!mMasterIn.eof())
		{
			string token;
			node* tnode = new node(0, 0, "", "", 0, "", "");

			getline(mMasterIn, token, ',');//Round number
			num = stoi(token);
			tnode->setRnum(num);

			getline(mMasterIn, token, ',');//Id Num
			num = stoi(token);
			tnode->setIDnum(num);

			getline(mMasterIn, token, ',');//Firt Name
			name = token;
			//getline(mMasterIn, token, ',');//Last Name
			//name += token;
			tnode->setName(name);

			getline(mMasterIn, token, ',');//Mail
			tnode->setMail(token);

			getline(mMasterIn, token, ',');//Unit
			if (token == "AU")
			{
				tnode->setUnits(0);
			}
			else
			{
				num = stoi(token);
				tnode->setUnits(num);
			}
			getline(mMasterIn, token, ',');//Program
			tnode->setProgram(token);

			getline(mMasterIn, token,',');//Level
			tnode->setLevel(token);


			getline(mMasterIn, token);//Absence
			tnode->setAbsence(token);

			if (mSize > 1)
			{
				if (mTop[mSize - 1].getRnum() < tnode->getRnum())//when importing, igonore same node
				{
					this->push(*tnode);

				}
			}
			else
			{
				this->push(*tnode);
			}
			


		}

	}
	else
	{
		cout << "master.txt is empty" << endl;
	}
}

void list::markAbsence()
{
	this->printList();
	int check = 0;
	cout << "Type record number you want to mark" << endl;
	cin >> check;
	if (check >= 1 && check < mSize+1)
	{
		mTop[check - 1].markAbsence();
		cout << "Name : " << mTop[check - 1].getName() << endl;
		cout << "Data of absence" << endl;
		
		cout << "Dates : " << mTop[check - 1].getAbsence() << endl;
	}
	else
	{
		cout << "Data not found" << endl;
	}
}

void list::loadList(ifstream &Input)
{
	
	string line;
	string name;
	
	int num;
	
	
	getline(Input, line);//load header
	
	while (!Input.eof())
	{
			string token;
			node* tnode = new node(0, 0, "", "", 0, "", "");

			getline(Input, token, ',');//Round number
			num = stoi(token);
			tnode->setRnum(num);

			getline(Input, token, ',');//Id Num
			num = stoi(token);
			tnode->setIDnum(num);

			getline(Input, token, ',');//Firt Name
			name = token;
			getline(Input, token, ',');//Last Name
			name += token;
			tnode->setName(name);
			
			getline(Input, token, ',');//Mail
			tnode->setMail(token);

			getline(Input, token, ',');//Unit
			if (token == "AU")
			{
				tnode->setUnits(0);
			}
			else
			{
				num = stoi(token);
				tnode->setUnits(num);
			}
			getline(Input, token, ',');//Program
			tnode->setProgram(token);

			getline(Input, token);//Level
			tnode->setLevel(token);

			if ( mTop[mSize - 1].getRnum() < tnode->getRnum())//when importing, igonore same node
			{
				this->push(*tnode);

			}

	
	}
}
bool list::push(node &newItem)
{
	bool check = false;
	if (this->mSize < 100)
	{
		this->mTop[mSize] = newItem;
		mSize++;
		check =true;

	}

	return check;
}

bool list::isEmpty()
{
	bool check = true;
	if (mTop != nullptr)
	{
		check = false;
	}
	return check;
}

bool list::pop()
{
	bool check = false;
	if (!isEmpty())
	{
		mSize--;
		check = true;
	}
	return check;
}

bool list::peek(node &item)
{
	bool check = false;
	if (!isEmpty())
	{
		item = mTop[mSize - 1];
		//cout << "Peek: " << item << endl;
		check = true;
	}
	return check;
}

void list::printList()
{
	//node item;
	//this->peek(item);
	cout << "-------List-------" << endl<<endl;
	if (!isEmpty())
	{
		for (int i = 1; i < mSize+1; i++)
		{
			cout << "Record number : " << mTop[mSize-i].getRnum() << endl;
			cout << "ID : " << mTop[mSize - i].getIDnum() << endl;
			cout << "Name : " << mTop[mSize - i].getName() << endl;
			cout << "Email : " << mTop[mSize - i].getMail() << endl;
			cout << "Unit : " << mTop[mSize - i].getUnit() << endl;
			cout << "Program : " << mTop[mSize - i].getProgram() << endl;
			cout << "Level : " << mTop[mSize - i].getLevel() << endl;
			cout << "Absence : " << mTop[mSize - i].getAbsence() << endl << endl;

		}
	}
}

void list::printMenu()
{
	int choice = 0;
	do {
		cout << "1. Import course list" << endl;
		cout << "2. Load master list" << endl;
		cout << "3. Store master list" << endl;
		cout << "4. Mark absences" << endl;
		cout << "5. BONUS: Edit absences" << endl;
		cout << "6. Generate report" << endl;
		cout << "7. Exit" << endl;
		cout << "Insert : " << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			this->loadClassList();
			this->printList();
			this->mInput.close();
			break;
		case 2:
			this->loadMasterList();
			this->printList();
			this->mMasterIn.close();

			break;
		case 3:
			this->storeMasterList();
			break;
		case 4:
			this->markAbsence();
			break;
		case 5://edit absence; BONUS!!
			editAbsence();
			break;
		case 6:
			report();
			break;
		}
	}while(choice != 7);
}


void list::storeMasterList()
{
	this->mMasterIn.close();

	this->mMasterOut.open("master.txt", ios::out);

	int num = 0;
	if (!mMasterOut.eof())
	{
		for (int i = 0; i < mSize; i++)
		{
			string line = "";
			line +=to_string( mTop[i].getRnum());
			line += ",";
			line += to_string(mTop[i].getIDnum());
			line += ",";
			line += mTop[i].getName();
			line += ",";
			line += mTop[i].getMail();
			line += ",";
			line += to_string(mTop[i].getUnit());
			line += ",";
			line += mTop[i].getProgram();
			line += ",";
			line += mTop[i].getLevel();
			line += ",";
			line += mTop[i].getAbsence();
			if (i == mSize - 1)
			{
				mMasterOut << line;
			}
			else
			{
				mMasterOut << line << endl;
			}
			
		}
		cout << "Complete Storing" << endl<<endl;
	}
	this->mMasterOut.close();
	this->mMasterIn.open("master.txt", ios::in);

}

void list::report()
{
	cout << "Generate Report" << endl;
	cout << "-------List-------" << endl << endl;
	if (!isEmpty())
	{
		for (int i = 1; i < mSize + 1; i++)
		{
			cout << "Record number : " << mTop[mSize - i].getRnum() << endl;
			cout << "ID : " << mTop[mSize - i].getIDnum() << endl;
			cout << "Name : " << mTop[mSize - i].getName() << endl;
			cout << "Email : " << mTop[mSize - i].getMail() << endl;
			cout << "Unit : " << mTop[mSize - i].getUnit() << endl;
			cout << "Program : " << mTop[mSize - i].getProgram() << endl;
			cout << "Level : " << mTop[mSize - i].getLevel() << endl;
			cout << "Absence : " << mTop[mSize - i].peekAbsence() << endl << endl;

		}
	}
}
void list::editAbsence()
{
	string newDate = "";
	this->printList();
	int check = 0;
	cout << "Type record number you want edit absence" << endl;
	cin >> check;
	if (check >= 1 && check < mSize + 1)
	{
		
		cout << "Data of absence" << endl;

		cout << "Dates : " << mTop[check - 1].getAbsence() << endl;
		cout << "Type edited date :" << endl;
		cin >> newDate;
		mTop[check - 1].editAbsence(newDate);
	}
	else
	{
		cout << "Data not found" << endl;
	}

}
