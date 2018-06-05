#include "Header.h"
char reversestr(char string[], int length)
{
	char temp[1] = "";
	for (int i = 0; i < ((length / 2)-1 ); i++)
	{
		temp[0] = string[i];
		string[i] = string[length - i];
		string[length - i] = temp;

	}

	return string;
}

void sort(char ary[],int length)
{
	int x, y, z;
	for (x = 0; x < (length - 1); x++)
	{
		for (y = 0; y < length - x - 1; y++)
		{
			if (ary[y] > ary[y + 1])
			{
				z = ary[y];
				ary[y] = ary[y + 1];
				ary[y + 1] = z;

			}
		}
	}


}
void display(char ary[], int length)
{
	for (int i = 0; i < length; i++)
	{
		printf("%c\n", ary[i]);
	}
}

