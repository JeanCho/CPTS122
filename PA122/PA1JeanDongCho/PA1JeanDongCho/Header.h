/*******************************************************************************
* Programmer: Jean Dong Cho                                              *
* Class: CptS 122; Lab Section 5                                             *
* Programming Assignment: PA1                                             *
* Date:            2017 08 28                                                           *
*                                                                             *
* Description: This program read the fitbit data file and calculate the average          *
*            of presented data and max and make output file that records those                                           *
*                                                                             *
* Relevant Formulas: Refer to each function definition.                       *
*                                                                             *
* Format of record in input file (input.dat):                *
*                                                     *
*			minute,calories,distance,floors,heart,steps,sleep_level   *
*									                      *
*                                                                             *
* Format of output file (output.dat): See problem specification.              *
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>//strcpy strtok

typedef enum sleep
{
	NONE = 0, ASLEEP = 1, AWAKE = 2, REALLYAWAKE = 3
} Sleep;

typedef struct fitbit
{
	char minute[9];
	double calories;
	double distance;
	unsigned int floors;
	unsigned int heartRate;
	unsigned int steps;
	Sleep sleepLevel;
} FitbitData;


char *replace_string(char *string,char *needle, char *replace);