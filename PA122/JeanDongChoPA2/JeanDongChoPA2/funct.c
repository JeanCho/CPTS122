#include  "Header.h"

//count the number of certain chracter in the string
int countChar(char* string, char character)
{
	int count = 0;
	for (int i = 0; string[i] != NULL; i++)
	{
		if (string[i] == character)
		{
			count += 1;
		}
	}

	return count;
}

/*Inert data of struct Record in to the front of Node
  Input:Node plist, Struct Record
  Output: Boolean, modified Node
*/
Boolean insertFront(Node **pList, Record pItem)
{
	Node *pMem = NULL, *pCur = NULL;
	int success = 0;

	// heap memory - up to programmer to manage
	pCur = *pList;
	pMem = (Node *)malloc(sizeof(Node)); // 104 bytes

										 // did malloc () fail? Null ptr
	if (pMem != NULL)
	{
		success = 1;
		pMem = makeNode(pItem);

		if (*pList == NULL) // dealing with an empty list!
		{
			(*pList) = pMem;
		}
		else // // not dealing with empty list
		{
			pMem->pNext = pCur;
			*pList = pMem;
			pCur->pPrev = pMem;

		}
	}

	return TRUE;
}

// tries to allocate space for a Node on the heap
// initializes the Node with the item passed in, sets the next pointer to NULL
// returns a pointer to the beginning of the allocated block
Node *makeNode(Record newData)
{
	Node *pMem = NULL;

	pMem = (Node *)malloc(sizeof(Node)); // allocate space on heap

	if (pMem != NULL) // malloc succeeded
	{
		// init memory
		pMem->pNext = NULL;
		pMem->pPrev = NULL;
		pMem->data = newData;
	}

	return pMem;
}


// This function inserts items in alphabetical A - Z order.
// The case of the character matters! 'a' > 'A'
Boolean sort(Node **pList)
{
	int success = 0, j = 1, choice = 0,change=0;
	Node *pMem = NULL, *pCur = NULL, *pNext = NULL,*pFemp = NULL;
	Node *pTemp = (Node *)malloc(sizeof(Node));
	pCur = *pList; // set to first node in list, if it exists
	pNext = pCur->pNext;

	pTemp->pNext = NULL;
	pTemp->pPrev = NULL;
	
	do
	{
		printf("1.Sort based on artist(A-Z)\n");
		printf("2.Sort based on album title(A-Z)\n");
		printf("3.Sort based on rating (1-5)\n");
		printf("4.Sort based on times played(largest-smallest)\n");
		printf("5.Exit\n");
		scanf("%d", &choice);
		getchar();
		
		switch (choice)
		{


		case 1:
			pFemp = NULL;

			do
			{
				change = 0;
				pCur = *pList;
				pNext = pCur->pNext;
				while (pCur->pNext != pFemp) // short circuit?
				{

					if (pCur->data.Artist[0] >= pNext->data.Artist[0])
					{
						
						//printList(*pList,1);
						//printf("Chagned to \n\n");
						pTemp->data = pNext->data;
						pNext->data = pCur->data;
						pCur->data = pTemp->data;
						

						change = 1;
					}
					// allow for us to advance through list
				

				 	pCur = pCur->pNext;
					if (pCur->pNext != NULL)
					{
						pNext = pCur->pNext;

					}
				}
				pFemp = pCur;


			} while (change);


				

			printf("Sorting Complete\n\n");
			break;

		case 2://album
			pFemp = NULL;

			do
			{
				change = 0;
				pCur = *pList;
				pNext = pCur->pNext;
				while (pCur->pNext != pFemp) // short circuit?
				{

					if (pCur->data.Album[0] >= pNext->data.Album[0])
					{
						
						//printList(*pList, 1);
						printf("Chagned to \n\n");
						pTemp->data = pNext->data;
						pNext->data = pCur->data;
						pCur->data = pTemp->data;
						

						change = 1;
					}
					// allow for us to advance through list


					pCur = pCur->pNext;
					if (pCur->pNext != NULL)
					{
						pNext = pCur->pNext;

					}
				}
				pFemp = pCur;


			} while (change);
			printf("Sorting Complete\n\n");

			break;
		case 3://rating
			pFemp = NULL;
			do
			{
				change = 0;
				pCur = *pList;
				pNext = pCur->pNext;
				while (pCur->pNext != pFemp) // short circuit?
				{

					if (pCur->data.Rating >= pNext->data.Rating)
					{
						
						//printList(*pList, 1);
						//printf("Chagned to \n\n");
						pTemp->data = pNext->data;
						pNext->data = pCur->data;
						pCur->data = pTemp->data;
						
						change = 1;
					}
					// allow for us to advance through list


					pCur = pCur->pNext;
					if (pCur->pNext != NULL)
					{
						pNext = pCur->pNext;

					}
				}
				pFemp = pCur;


			} while (change);
			printf("Sorting Complete\n\n");

			break;
		case 4://time played
			pFemp = NULL;
			do
			{
				change = 0;
				pCur = *pList;
				pNext = pCur->pNext;
				while (pCur->pNext != pFemp) // short circuit?
				{

					if (pCur->data.Timeplayed <= pNext->data.Timeplayed)
					{

						//printList(*pList, 1);
						//printf("Chagned to \n\n");
						pTemp->data = pNext->data;
						pNext->data = pCur->data;
						pCur->data = pTemp->data;

						change = 1;
					}
					// allow for us to advance through list


					pCur = pCur->pNext;
					if (pCur->pNext != NULL)
					{
						pNext = pCur->pNext;

					}
				}
				pFemp = pCur;


			} while (change);
			printf("Sorting Complete\n\n");

			break;

		}
	} while (choice != 5);

}

	// print the items in the list
void printList(Node *pList, int choice)
{
		int number = 0;
		char sArtist[128] = { 0 };
		Node *pCur = NULL;


		printf("-->\n ");
		pCur = pList;
		if (choice == 1)
		{
			while (pCur != NULL)
			{
				printf("(%d).%s/%s/%s/%s/%d:%d/%d/%d --> \n", number, pCur->data.Artist, pCur->data.Album, pCur->data.sTitle, pCur->data.Genre, pCur->data.length.minutes, pCur->data.length.seconds, pCur->data.Timeplayed, pCur->data.Rating);
				pCur = pCur->pNext;
				number++;
			}
			putchar('\n');
		}
		if (choice == 2)
		{
			printf("Type artist to search\n");
			//scanf("%s", sArtist);
			fgets(sArtist, sizeof(sArtist), stdin);
			sArtist[strlen(sArtist) - 1] = 0;

			while ((pCur != NULL))
			{
				if (strcmp(sArtist, pCur->data.Artist) == 0)
				{
					printf("(%d).%s/%s/%s/%s/%d:%d/%d/%d --> \n", number, pCur->data.Artist, pCur->data.Album, pCur->data.sTitle, pCur->data.Genre, pCur->data.length.minutes, pCur->data.length.seconds, pCur->data.Timeplayed, pCur->data.Rating);

				}


				pCur = pCur->pNext;
				number++;

			}
			if (pCur == NULL)
			{
				printf("Done Searching \n");
			}

		}
}




/*Search the data that has same song name and delete it
Input: linked list, Music struct to delete
Output: Bool Ture/false, modifed linked list
*/

Boolean deleteContact(Node **pList, char *sTitle)
{

	Node *pCur = NULL;
	Node *pPrevi = NULL;
	Node *pTemp = NULL;

	pCur = *pList;


	while ((pCur != NULL) && strcmp(sTitle, pCur->data.sTitle) != 0)
	{
		pPrevi = pCur;
		pCur = pCur->pNext;

	}

	if (pCur != NULL) // 
	{
		// not inserting at the front

		pTemp = pCur;
		pCur = pCur->pNext;
		pPrevi->pNext = pCur;
		pCur->pPrev = pPrevi;
		
		free(pTemp);
		return 1;
	}
	else
	{
		printf("Done Searching\n");
		return 0;
	}
	

}
//**plist -> plist-(node1,node2,.....)
//*plist -> first node;



//Edit the rating of the song

Boolean editRating(Node *pList, char *sName)
{
	Node *pCur = NULL;
	Node *pPrev = NULL;
	Node *pTemp = NULL;
	char answer = '\0';
	int number = 0, choice = 0, success = 0;

	pCur = pList;
	while ((pCur != NULL))
	{
		pPrev = pCur;

		if (strcmp(sName, pCur->data.sTitle) == 0)
		{
			printf("(%d).%s/%s/%s/%s/%d:%d/%d/%d --> \n", number, pCur->data.Artist, pCur->data.Album, pCur->data.sTitle, pCur->data.Genre, pCur->data.length.minutes, pCur->data.length.seconds, pCur->data.Timeplayed, pCur->data.Rating);
			pTemp = pCur;
			printf("Do you want to change rating of this song?(y/n)\n");
			scanf(" %c", &answer);
			if (answer == 'y')
			{
				printf("Rating:\n");
				scanf("%d", &(pCur->data.Rating));

				printf("Modified Data:\n");
				printf("(%d).%s/%s/%s/%s/%d:%d/%d/%d --> \n\n\n", number, pCur->data.Artist, pCur->data.Album, pCur->data.sTitle, pCur->data.Genre, pCur->data.length.minutes, pCur->data.length.seconds, pCur->data.Timeplayed, pCur->data.Rating);
				success = 1;
			}

		}
		pCur = pCur->pNext;
		number++;

	}
	return success;
}
/*Search the data that has same artist name and edit the and replace with search Contact
 Input: linked list, Music struct to replace
 Output: Bool Ture/false, modifed linked list
*/
Boolean editContact(Node *pList, char *artist)
{
	Node *pCur = NULL;
	Node *pPrev = NULL;
	Node *pTemp = NULL;
	char answer = '\0';
	int number = 0,choice=0,success=0;

	printf("%s",artist);
	pCur = pList;
	while ((pCur != NULL) )
	{
		pPrev = pCur;
		
		if (strcmp(artist, pCur->data.Artist) == 0)
		{
			printf("(%d).%s/%s/%s/%s/%d:%d/%d/%d --> \n", number, pCur->data.Artist, pCur->data.Album, pCur->data.sTitle, pCur->data.Genre, pCur->data.length.minutes, pCur->data.length.seconds, pCur->data.Timeplayed, pCur->data.Rating);
			pTemp = pCur;
			printf("Do you want to modify this song?(y/n)\n");
			scanf(" %c", &answer);
			if (answer == 'y')
			{
				do {
					printf("(1).Eddit artist name\n");
					printf("(2).Eddit Album name\n");
					printf("(3).Eddit Song Title\n");
					printf("(4).Eddit Genre\n");
					printf("(5).Eddit Minutes\n");
					printf("(6).Eddit Seconds\n");
					printf("(7).Eddit Time Played\n");
					printf("(8).Eddit Rating\n");
					printf("(9).Exit\n\n");

					scanf("%d", &choice);
					getchar();
					switch (choice)
					{
					case 1:
							printf("Artist name:\n");
							//scanf(" %s", pCur->data.Artist);
							fgets(pCur->data.Artist, sizeof(pCur->data.Artist), stdin);
							pCur->data.Artist[strlen(pCur->data.Artist) - 1] = 0;
							printf("Modified Data:\n");
							printf("(%d).%s/%s/%s/%s/%d:%d/%d/%d --> \n\n\n", number, pCur->data.Artist, pCur->data.Album, pCur->data.sTitle, pCur->data.Genre, pCur->data.length.minutes, pCur->data.length.seconds, pCur->data.Timeplayed, pCur->data.Rating);
							success = 1;
							break;
					case 2:
							printf("Album name:\n");
							//scanf("%s", pCur->data.Album);
							fgets(pCur->data.Album, sizeof(pCur->data.Album), stdin);
							pCur->data.Album[strlen(pCur->data.Album) - 1] = 0;
							printf("Modified Data:\n");
							printf("(%d).%s/%s/%s/%s/%d:%d/%d/%d --> \n\n\n", number, pCur->data.Artist, pCur->data.Album, pCur->data.sTitle, pCur->data.Genre, pCur->data.length.minutes, pCur->data.length.seconds, pCur->data.Timeplayed, pCur->data.Rating);
							success = 1;
							break;
					case 3:
							printf("Song title:\n");
							//scanf("%s", pCur->data.sTitle);
							fgets(pCur->data.sTitle, sizeof(pCur->data.sTitle), stdin);
							pCur->data.sTitle[strlen(pCur->data.sTitle) - 1] = 0;
							printf("Modified Data:\n");
							printf("(%d).%s/%s/%s/%s/%d:%d/%d/%d --> \n\n\n", number, pCur->data.Artist, pCur->data.Album, pCur->data.sTitle, pCur->data.Genre, pCur->data.length.minutes, pCur->data.length.seconds, pCur->data.Timeplayed, pCur->data.Rating);
							success = 1;
							break;
					case 4:
							printf("Genre:\n");
							//scanf("%s", pCur->data.Genre);
							fgets(pCur->data.Genre, sizeof(pCur->data.Genre), stdin);
							pCur->data.Genre[strlen(pCur->data.Genre) - 1] = 0;
							printf("Modified Data:\n");
							printf("(%d).%s/%s/%s/%s/%d:%d/%d/%d --> \n\n\n", number, pCur->data.Artist, pCur->data.Album, pCur->data.sTitle, pCur->data.Genre, pCur->data.length.minutes, pCur->data.length.seconds, pCur->data.Timeplayed, pCur->data.Rating);
							success = 1;
							break;
					case 5:
							printf("Minutes:\n");
							scanf("%d",&(pCur->data.length.minutes));

							printf("Modified Data:\n");
							printf("(%d).%s/%s/%s/%s/%d:%d/%d/%d --> \n\n\n", number, pCur->data.Artist, pCur->data.Album, pCur->data.sTitle, pCur->data.Genre, pCur->data.length.minutes, pCur->data.length.seconds, pCur->data.Timeplayed, pCur->data.Rating);
							success = 1;
							break;
					case 6:
							printf("Seconds:\n");
							scanf("%d", &(pCur->data.length.seconds));

							printf("Modified Data:\n");
							printf("(%d).%s/%s/%s/%s/%d:%d/%d/%d --> \n\n\n", number, pCur->data.Artist, pCur->data.Album, pCur->data.sTitle, pCur->data.Genre, pCur->data.length.minutes, pCur->data.length.seconds, pCur->data.Timeplayed, pCur->data.Rating);
							success = 1;
							break;
					case 7:
							printf("Time Played:\n");
							scanf("%d", &(pCur->data.Timeplayed));

							printf("Modified Data:\n");
							printf("(%d).%s/%s/%s/%s/%d:%d/%d/%d --> \n\n\n", number, pCur->data.Artist, pCur->data.Album, pCur->data.sTitle, pCur->data.Genre, pCur->data.length.minutes, pCur->data.length.seconds, pCur->data.Timeplayed, pCur->data.Rating);
							success = 1;
							break;
					case 8:
							printf("Rating:\n");
							scanf("%d", &(pCur->data.Rating));

							printf("Modified Data:\n");
							printf("(%d).%s/%s/%s/%s/%d:%d/%d/%d --> \n\n\n", number, pCur->data.Artist, pCur->data.Album, pCur->data.sTitle, pCur->data.Genre, pCur->data.length.minutes, pCur->data.length.seconds, pCur->data.Timeplayed, pCur->data.Rating);
							success = 1;
							break;
					}
		

				} while (choice != 9);

			}

		}
		pCur = pCur->pNext;
		number++;
	}

	


	return success;
}


/*Loop through infile data and save each datat type to struct music
  Input: data file, linked list node
  output:Boolean:true/false, modified linked list datas
  */
Boolean loadContacts(FILE *infile, Node **pList)
{
	char line[128] = "", copyline[128] = "", lineline[128]="",linecount[128]="";
	int numcom = 0;
	Node *pCur = NULL, *pPrev = NULL, *pTemp = NULL;
	int j = 1,count=0;

	pCur = *pList; 


	if (infile != NULL)
	{
		//loop

		while(fgets(line,sizeof(line),infile))
		{
			if (!*line) { break; }
			pTemp = (Node *)malloc(sizeof(Node));

			strcpy(linecount, line);

			
			numcom = countChar(linecount, ',');
		
			count += 1;
			//copy last name
			if (numcom > 6)
			{
				j = 1;
				for (int i = 1; line[i] != NULL; i++)
				{
					if (line[i] != '"')
					{
						copyline[i-j] = line[i];
						
					}
					else if (line[i] == '"')
					{
						j++;
					}
					
					

				}
				
				strcpy(pTemp->data.Artist,strtok(copyline, ","));
				strcat(pTemp->data.Artist, strtok(NULL, ","));//put thefirst name

			}
			else
			{
				strcpy(copyline, line);
				strcpy(pTemp->data.Artist, strtok(copyline, ","));
			}
			strcpy(pTemp->data.Album, strtok(NULL, ","));
			strcpy(pTemp->data.sTitle, strtok(NULL, ","));
			strcpy(pTemp->data.Genre, strtok(NULL, ","));
			pTemp->data.length.minutes = atoi(strtok(NULL, ":"));
			pTemp->data.length.seconds = atoi(strtok(NULL, ","));
			pTemp->data.Timeplayed = atoi(strtok(NULL, ","));
			pTemp->data.Rating = atoi(strtok(NULL, ","));
			pTemp->pNext = NULL;
			pTemp->pPrev = NULL;

			if (*pList == NULL) {
				*pList = pTemp;
				pCur = pTemp;
			}
			else
			{
				pCur->pNext = pTemp;
				pPrev = pCur;
				pCur = pCur->pNext;
				pPrev->pNext = pCur;
				pCur->pPrev = pPrev;
			}
			
		
			
			
		}
	}
	return TRUE;
}
/*
Print out each of all song or particular song name song  for a short time and clear screen

*/
Boolean playSong(Node *pList)
{
	Node *pCur = NULL;
	Node *pPrev = NULL;
	Node *pTemp = NULL;
	char answer = '\0', sName[100] = {0};
	int number = 0, check = 0, success = 0,choice=0;

	pCur = pList;

	if (pCur == NULL)
	{
		printf("Failed to find playlist\n");
		return success;
	}
	printf("1.Play all song\n");
	printf("2. Search song\n");
	scanf("%d", &choice);
	getchar();
	if (choice == 1)
	{
		while (pCur != NULL)
		{
			printf("(%d).%s/%s/%s/%s/%d:%d/%d/%d --> \n", number, pCur->data.Artist, pCur->data.Album, pCur->data.sTitle, pCur->data.Genre, pCur->data.length.minutes, pCur->data.length.seconds, pCur->data.Timeplayed, pCur->data.Rating);
			pCur = pCur->pNext;
			_sleep(1000);
			system("cls");//clear screen

			number++;
		}
		putchar('\n');
		success = 1;
		return success;
	}
	
	else
	{
		printf("Please type the song name\n");
		
		fgets(sName, sizeof(sName), stdin);

		sName[strlen(sName) - 1] = 0;
		printf("%s\n", sName);
		while ((pCur != NULL))
		{
			pPrev = pCur;

			if (strcmp(sName, pCur->data.sTitle) == 0)
			{
				if (check != 1)
				{
					printf("(%d).%s/%s/%s/%s/%d:%d/%d/%d --> \n", number, pCur->data.Artist, pCur->data.Album, pCur->data.sTitle, pCur->data.Genre, pCur->data.length.minutes, pCur->data.length.seconds, pCur->data.Timeplayed, pCur->data.Rating);
					pTemp = pCur;
					pCur = pCur->pNext;
					check = 1;
					success = 1;
					_sleep(1000);
					system("cls");//clear screen
					
				}

				while (pCur != NULL )
				{
					printf("%s/%s/%s/%s/%d:%d/%d/%d --> \n", pCur->data.Artist, pCur->data.Album, pCur->data.sTitle, pCur->data.Genre, pCur->data.length.minutes, pCur->data.length.seconds, pCur->data.Timeplayed, pCur->data.Rating);
					pCur = pCur->pNext;
					_sleep(1000);
					system("cls");
				}

				


			}
			if (pCur != NULL)
			{
				pCur = pCur->pNext;
			}

			number++;

		}
		if (check != 1)
		{
			return success;
		}
		pCur = pList;
		while (strcmp(sName, pCur->data.sTitle) != 0)
		{
			printf("%s/%s/%s/%s/%d:%d/%d/%d --> \n", pCur->data.Artist, pCur->data.Album, pCur->data.sTitle, pCur->data.Genre, pCur->data.length.minutes, pCur->data.length.seconds, pCur->data.Timeplayed, pCur->data.Rating);
			pCur = pCur->pNext;
			_sleep(1000);
			system("cls");//clear screen
		}

		return success;
	}

	

}

/*
generate the random order of song and print it
input:linked list
output: void, print the random list
*/
void shuffle(Node *pList)
{
	int number = 0,leber1=0,repcount=0;
	int  g2[100] = { -1 };
	int nLen =0;
	Node *pCur = NULL,*pTemp = NULL;
	int rannum = 0,check=0,count=0;

	pTemp = pList;
	
	while (pTemp != NULL)//get the length of linked list
	{
		pTemp = pTemp->pNext;
		nLen += 1;
	}

	while(count <nLen)
	{

		rannum = rand() % nLen +1;
		check = 0;

		for (int j = 0; j < nLen; j++)
		{
			if (g2[j] == rannum)
			{
				check = 1;
			}

		}
		if (check != 1)
		{
			g2[count] = rannum;
			count++;
		}

	}
	
		
	//just checked the list of int;
	/*for (int k = 0; k < nLen; k++)
	{
		printf("%d.->\n", g2[k]);
	}

	printf("-->\n ");*/

	//print out the song in random order;
	for (int s = 0; s < nLen; s++)
	{
		pCur = pList;
		if (pCur != NULL)
		{
			for (int i = 1; i < g2[s]; i++)
			{
				if (pCur != NULL)
				{
					pCur = pCur->pNext;

				}
			}
			printf("(%d).%s/%s/%s/%s/%d:%d/%d/%d --> \n", number, pCur->data.Artist, pCur->data.Album, pCur->data.sTitle, pCur->data.Genre, pCur->data.length.minutes, pCur->data.length.seconds, pCur->data.Timeplayed, pCur->data.Rating);


			putchar('\n');

		}
	}
}


/*Sotre current list to the outfile csv file
Input: outfile, linked list node
output: boolean value, modifed outfile
*/
Boolean storeList(FILE *outfile, Node *pList)
{
	char strline[128] = { 0 };
	Node *pCur = NULL;
	int success = 0;

	pCur = pList;

	if (pList == NULL )
	{
		return success;
	}
	else
	{
		fprintf(outfile,"Artist,Album,Title,Genre,Minutes:Seconds,Timeplayed,Rating,\n");
		while (pCur != NULL)
		{
			sprintf(strline, "%s,%s,%s,%s,%d:%d,%d,%d \n", pCur->data.Artist, pCur->data.Album, pCur->data.sTitle, pCur->data.Genre, pCur->data.length.minutes, pCur->data.length.seconds, pCur->data.Timeplayed, pCur->data.Rating);
			fprintf(outfile, strline);
			pCur = pCur->pNext;

		}
		putchar('\n');
		success = 1;
		return success;
	}



	
}

