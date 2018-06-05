#include "Header.h"

int main(void)
{
	//char str1[] = "potato", 
	char ar1[4]= "cab",ar2[4] = "xzy";
	char ary[7];
	char line[100],ch;
	FILE *infile = NULL;
	int arr[27] = { 0 };
	infile = fopen("Text.txt", "r");
	
	fscanf(infile,"%s",line);
	while ((ch != '\0'))
	{

	}


	sort(ar1, 3);
	display(ar1, 3);
	strcpy(ary, ar1);
	strcat(ary, ar2);
	//merge(ar1, ar2, ary);
	sort(ary,7);
	display(ary,7); 
	puts(ary);



	return 0;
}