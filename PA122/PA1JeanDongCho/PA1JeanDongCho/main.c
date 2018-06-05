#include "Header.h"

int main(void)
{
	char line[100] = "",copyline[128] ="",minutes[9] ="", calories[12]="",distance[13]="",floors[10]="",heart[7]="",step[7]="",sleep_level[7]="";
	char maxsteptime[9] = "",start_poorsleep[9]="",end_poorsleep[9]="",replace[7] = ",none,",none[5] ="none";
	char finaloutput1[100] = { 0 };
	char *temporary =NULL;
	FILE *infile = NULL;
	FILE *outfile = NULL;
	FitbitData datasum;
	double avgheart = 0.0;
	char longest_distance = 0, needle[3] =",,";
	int consecutive = 0,max_consecutive =0, max_step = 0, calnone=0,distnone=0,floornone=0,heartnone=0,stepnone=0,sllvnone=0;
	int count = 0; // for debugging

	infile = fopen("FitbitData.csv", "r");
	outfile = fopen("Result.csv", "w");
	datasum.calories = 0;
	datasum.distance = 0;
	datasum.floors = 0;
	datasum.heartRate = 0;
	datasum.sleepLevel = 0;
	datasum.steps = 0;
	if (infile != NULL)
	{
		// opened the file successfully
		//read the line
		fgets(line, 100, infile);
		fputs(line, stdout);//display header
		for (int i = 0; i < 1440; i += 1)//loop for entire file
		{
			fgets(line, 100, infile);

			strcpy(copyline, line);
			count++;
		
			temporary = replace_string(copyline, needle, ",none");//find the missing datas and put none in the missing info slot,
				
			if (temporary != NULL)//if there is missing dat and been modified
			{
				strcpy(copyline, temporary);
			}
			
			
			/****gather datasum by using struct &gather the none data****/
			strcpy(minutes, strtok(copyline, ","));
			puts(minutes);
			strcpy(calories, strtok(NULL, ","));
			if (strstr(calories,none) != NULL)
			{
				calnone += 1;
			}
			else
			{
				datasum.calories = datasum.calories + atof(calories);
			}
			puts(calories);
			strcpy(distance, strtok(NULL, ","));
			if (strstr(distance,none) != NULL)
			{
				distnone += 1;
			}
			else
			{
				datasum.distance = datasum.distance + atof(distance);
			}
			puts(distance);
			strcpy(floors, strtok(NULL, ","));
			if (strstr(floors,none) != NULL)
			{
				floornone += 1;
			}
			else
			{
				datasum.floors = datasum.floors + atof(floors);
			}
			puts(floors);
			strcpy(heart, strtok(NULL, ","));
			if (strstr(heart,none) != NULL)
			{
				heartnone += 1;
			}
			else
			{
				datasum.heartRate = datasum.heartRate + atof(heart);
			}
			puts(heart);
			strcpy(step, strtok(NULL, ","));
			if (strstr(step, none) != NULL)
			{
				stepnone += 1;
			}
			else
			{
				datasum.steps = datasum.steps + atoi(step);
				if (atoi(step) >= max_step)//save the max step and its time
				{
					max_step = atoi(step);
					strcpy(maxsteptime, minutes);
				}
			}
			puts(step);
			strcpy(sleep_level, strtok(NULL, ","));
			if (strstr(sleep_level, none) != NULL)
			{
				sllvnone += 1;
				puts(sleep_level);
			}
			else
			{
				if (atoi(sleep_level) == 1)//start of poor sleep
				{
					
			
					consecutive += 1;
					if (consecutive >= max_consecutive)
					{
						max_consecutive = consecutive;
						
					}

				}
				else if (atoi(sleep_level)!=1) // if not poor sleep
				{
					if (consecutive >= max_consecutive)
					{
						strcpy(end_poorsleep, minutes);
					}
					
					consecutive = 0;//reset the consecutive count
				}
				puts(sleep_level);
			}
			
			
		}
		
		//print out the none data counted
		printf("calnone%d,distnone%d,floornone%d,heartnone%d,stepnone%d,sllvnone%d\n\n\n\n", calnone, distnone, floornone, heartnone, stepnone, sllvnone);
	}
	else//if failed to open file
	{
		printf("File open fail\n");
	}
	strcpy(start_poorsleep, "4:04:00");// poor sleep start = 6:45 -2:41 = 04:04:00
	avgheart = datasum.heartRate / (1440-heartnone);
	sprintf(finaloutput1, "%lf, %lf, %d, %d, %.2lf,%d,%d, %s:%s\n",datasum.calories,datasum.distance,datasum.floors,datasum.steps,avgheart,max_step,max_consecutive,start_poorsleep,end_poorsleep);
	
	printf("Total Calories,Total Distance,Total Floors,Total Steps,Avg Heartrate,Max Steps,Sleep\n");
	printf("%s", finaloutput1);
	
	fprintf(outfile, "Total Calories, Total Distance, Total Floors, Total Steps, Avg Heartrate, Max Steps, Sleep\n");
	fprintf(outfile, finaloutput1);
	
	

	fclose(infile);
	fclose(outfile);
	
	return 0;
}