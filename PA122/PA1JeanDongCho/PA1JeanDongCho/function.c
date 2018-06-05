

#include "Header.h"

//function that check ",," or if string ends with ',' and change it to replace or none
//input:original string, string you wanto repalce, string to replace with
//output:copied string of changed string
char *replace_string(char *string, char *needle, char *replace) 
{
	int i = 0,check =0;
	char temporary[128] = { 0 };
	if (strstr(string, needle) != NULL || strstr(string, ",\n"))
	{
		
		while (string[i] != '\n')
		{
			if ((string[i] == ',') && (string[i] == string[i - 1]))//check if string has ,, or string end with ,
			{
				strncpy(temporary, string, i - 1);
				strcat(temporary, replace);
				strcat(temporary, &string[i]);
				check = 1;
			
			}
			i++;
		}
		if (string[i-1] == ',')
		{
			if (check == 0)//if original string does not contains ",,"
			{
				strcpy(temporary, string); //copy original string into temporary
				temporary[i] = '\0'; // change last character \n to \0
			}
			
			if (check == 1)//if original string had ,, and been modified
			{
				temporary[i + 4] = '\0'; //location of last char is i+4 since "none" was added
			}

			strcat(temporary, "none\n");//add none at the end of the string
			
		}
		return temporary; //return modified string
	}
}