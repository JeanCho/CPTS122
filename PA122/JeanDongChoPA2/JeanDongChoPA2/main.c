#include "Header.h"
/*
CPTS 122 PA2
This code will load music play list csv file into doubly linked node 
and will perform edit,delete, print, save to outfile, of those data


everything will work perfectly 100%

###############I also fixed the bugs at PA2 !!!#################################################

*/
int main(void)
{
	FILE *infile = NULL;
	FILE *outfile = NULL;
	Node *playlist = NULL;
	Record *insertp = (Record *)malloc(sizeof(Record));
	char sName[100] = { 0 }, aName[128] = { 0 };
	char c = '\0';
	int choice = 0, subchoice = 0, success = 0;


	infile = fopen("musicPlayList.csv", "r");
	
	strcpy(insertp->Album, "We Are");
	strcpy(insertp->Artist, "Drake");
	strcpy(insertp->Genre, "Hip Hop");
	insertp->length.minutes = 3;
	insertp->length.seconds = 16;
	insertp->Rating = 5;
	strcpy(insertp->sTitle, "Si Cha");
	insertp->Timeplayed = 13;

	do
	{//UI for main menu
		printf("Main Menu\n\n");
		printf("(1)Load\n");
		printf("(2)Store\n");
		printf("(3)Display\n");
		printf("(4)Insert\n");
		printf("(5)Delete\n");
		printf("(6)Edit\n");
		printf("(7)Sort\n");
		printf("(8)Rate\n");
		printf("(9)Play\n");
		printf("(10)Shuffle\n");
		printf("(11)Exit\n");
		scanf("%d",&choice);
		getchar();
		switch (choice)
		{

		case 1://loade data from file to node playlist
			loadContacts(infile, &playlist);
			printf("Load successful\n");
			break;

		case 2://store data to out file 
			outfile = fopen("musicPlayList.csv", "w");

			success = storeList(outfile, playlist);
			if (success == 1)
			{
				printf("storing succeed\n");
				
			}
			else
			{
				printf("Failed to store\n");
			}
			fclose(outfile);
			break;

		case 3://display data
			if (playlist == NULL)
			{
				printf("Null list\n");
			}
			else
			{
				printf("1.  Print all records.\n");
				printf("2.    Print all records that match an artist.\n");
				scanf("%d", &subchoice);
				getchar();
				printList(playlist, subchoice);
			}
			break;
		case 4://insert data at fornt of node
			printf("Please type the data of the inserting music\n");
			printf("Artist name:\n");
			fgets(insertp->Artist, sizeof(insertp->Artist), stdin);
			insertp->Artist[strlen(insertp->Artist) - 1] = 0;

			printf("Album name:\n");
			fgets(insertp->Album, sizeof(insertp->Album), stdin);
			insertp->Album[strlen(insertp->Album) - 1] = 0;

			printf("Song title:\n");
			fgets(insertp->sTitle, sizeof(insertp->sTitle), stdin);
			insertp->sTitle[strlen(insertp->sTitle) - 1] = 0;

			printf("Genre:\n");
			fgets(insertp->Genre, sizeof(insertp->Genre), stdin);
			insertp->Genre[strlen(insertp->Genre) - 1] = 0;

			printf("Minutes:\n");
			scanf("%d", &(insertp->length.minutes));

			printf("Seconds:\n");
			scanf("%d", &(insertp->length.seconds));

			printf("Time Played:\n");
			scanf("%d", &(insertp->Timeplayed));

			printf("Rating:\n");
			scanf("%d", &(insertp->Rating));
			insertFront(&playlist, *insertp);
			break;


		case 5://delete data
			if (playlist == NULL)
			{
				printf("null list\n\n");
			}
			else
			{
				printf("Please type the title of song you want to delete:\n ");
				fgets(sName, sizeof(sName), stdin);

				sName[strlen(sName) - 1] = 0;
				printf("%s\n", sName);
				success = deleteContact(&playlist, sName);
				if (success == 1)
				{
					printf("Deleted: %s\n", sName);

				}
				else
				{
					printf("Failed to find the song\n");
				}
			}
			break;

		case 6://edit data
			if (playlist == NULL)
			{
				printf("null list\n\n");
			}
			else
			{
				
				printf("Please type the artist name\n");
				
				fgets(aName, sizeof(aName), stdin);
				
				aName[strlen(aName) - 1] = 0;
				printf("%s\n", aName);
				
				success = editContact(playlist, aName);
				if (success == 1)
				{
					printf("Edited: %s\n", aName);

				}
				else
				{
					printf("Failed to find the artist\n");
				}
			}
			break;
		case 7://sort data
			if (playlist == NULL)
			{
				printf("null list\n\n");
			}
			else
			{
				sort(&playlist);
				printf("Done sorting\n");
			}
			
			break;

		case 8://change the rating value
			printf("Please type the song name\n");
			fgets(sName, sizeof(sName), stdin);

			sName[strlen(sName) - 1] = 0;
			printf("%s\n", sName);
			success = editRating(playlist, sName);
			if (success == 1)
			{
				printf("Rated: %s\n", sName);

			}
			else
			{
				printf("Failed to find the songname\n");
			}
			break;

		case 9: //play

			
			success = playSong(playlist);
			if (success == 1)
			{
				printf("Done Playing\n");

			}
			else
			{
				printf("Failed to play\n");
			}
			break;

		case 10: //shuffle
			if (playlist == NULL)
			{
				printf("null list\n\n");
			}
			else
			{
				shuffle(playlist);
			}
		
			break;


		}


		} while (choice != 11);

		fclose(infile);
		
		return 0;
	}

