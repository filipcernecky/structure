#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct date 
{
	int d;
	int m;
	int y;
}date;


typedef struct student 
{
	char fname[30];
	char lname[30];
	struct date dob;
	char gender[1];
	
}student;


int main()
{
	
	FILE*f;
	struct student School[20];
	int index=0;
	f=fopen("pp.txt","r");
	
	if(f==NULL)
	{
		printf("File not loaded");
	}
	
	while(fscanf(f,"%s",&School[index].fname) !=EOF)
	{
		
		fscanf(f,"%s",&School[index].lname);
		fscanf(f,"%d",&School[index].dob.d);
		fscanf(f,"%d",&School[index].dob.m);
		fscanf(f,"%d",&School[index].dob.y);
		fscanf(f,"%s",&School[index].gender);
		
		index++;
	}

	
	int i;
	printf("\nFemale students:");
	for(i=0;i<index;i++)
	{
		School[i].gender;
		if(School[i].gender[0]=='F')
		{
		printf("\n%s %s",School[i].fname,School[i].lname);	
		}
	}
	
	printf("\nMale students:");
	for(i=0;i<index;i++)
	{
		School[i].gender;
		if(School[i].gender[0]=='M')
		{
		printf("\n%s %s",School[i].fname,School[i].lname);	
		}
	}
	
	printf("\nBorn in December:");
	for(i=0;i<index;i++)
	{

		if(School[i].dob.m==12)
		{
		printf("\n%s %s",School[i].fname,School[i].lname);
		}
	}
	
	printf("\nLess than 18 years old:");
    for (i=0; i<index; i++)
	{
        if ((School[i].dob.y==2000 && School[i].dob.m==11 && School[i].dob.d>=24) || (School[i].dob.y==2000 && School[i].dob.m==12) || School[i].dob.y>=2001)
		{
            printf("\t \n%s %s", School[i].fname, School[i].lname);
   		}
	}
	
	printf("\nVirgo sign:");
	for(i=0;i<index;i++)
	{
		
		School[i].dob.d;
		School[i].dob.m;
		if( (School[i].dob.m == 8 && (School[i].dob.d>=24 && School[i].dob.d<=31)) || (School[i].dob.m == 9 && (School[i].dob.d>=1 && School[i].dob.d<=23)))
		{
		printf("\n%s %s",School[i].fname,School[i].lname);
		}
	}
	

	int temp,j;
	printf("\nSorted by age:");
    for (i=0;i<index-1;i++)
	{
		for (j = 0;j<index-i-1;j++)
		{
			if (School[j].dob.d > School[j+1].dob.d)
			{
				struct student temp = School[j];
				School[j] = School[j+1];
				School[j+1] = temp;
			}
		}
	}
	
	for (i=0;i<index-1;i++)
	{
		for (j = 0;j<index-i-1;j++)
		{
			if (School[j].dob.m > School[j+1].dob.m)
			{
				struct student temp = School[j];
				School[j] = School[j+1];
				School[j+1] = temp;
			}
		}
	}
	
	for (i=0;i<index-1;i++)
	{
		for (j = 0;j<index-i-1;j++)
		{
			if (School[j].dob.y > School[j+1].dob.y)
			{
				struct student temp = School[j];
				School[j] = School[j+1];
				School[j+1] = temp;
			}
		}
	}
	
    for(i=0;i<index;i++)
	{
    	printf("\n %d %d %d %s %s",School[i].dob.d,School[i].dob.m,School[i].dob.y,School[i].fname,School[i].lname);
	}
    
    fclose(f);
}
