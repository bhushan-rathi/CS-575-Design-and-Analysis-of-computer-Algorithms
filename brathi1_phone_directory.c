#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
typedef struct{	
	char fname[100];
	char lname[100];
	char number[20];	
}data;
data person[200];
int i =0;
int numberOfLines=0;
void create(char filename1[1000]){
	char line[100];
	FILE *fp;
    if ((fp = fopen(filename1, "r")) == NULL)  //if file is empty then exit the program
    {
        printf("File is empty");
        exit(1);         
    }
	const char s[10] = " ";
	char *token;
	while ( fgets ( line, sizeof line, fp ) != NULL ) // reads the line, store first name, last, mobile number in fname, lname, number respectivelly
	{
        //fputs ( line, stdout ); //print each line in the file
	token = strtok(line, s);
	strcpy(person[i].fname, token);
	//printf("%s\n", person[i].fname); // print first name 
	token = strtok(NULL, ", ");
	strcpy(person[i].lname, token);
	//printf("%s\n", person[i].lname); // print last name 
	token = strtok(NULL, "\n");
	token++; //removes space before number
	strcpy(person[i].number, token);
	//printf("%s\n", person[i].number); // print number
	i++;
	numberOfLines = i;
	}
		fclose ( fp );
}//line 37


//this fuction is used to perform swap
// it returns void
void exchange(data *indexOfPivotIn, data *rIn)
{
	data reqForSwap;
	reqForSwap = *indexOfPivotIn;
	*indexOfPivotIn = *rIn;
	*rIn = reqForSwap;
}


//this fuction is used to compare first name, last and number
//this fuction retruns boolen
bool compare(data j , data pivotIn)
{
	if(strcasecmp(j.fname , pivotIn.fname) < 0)
	{
			return true;
	}
			else if(strcasecmp(j.fname , pivotIn.fname) == 0){
					if(strcasecmp(j.lname , pivotIn.lname) < 0)
					{
						return true;	

					}
							else if(strcasecmp(j.lname , pivotIn.lname) ==0){
								
								if(strcasecmp(j.number , pivotIn.number) < 0)
								{
									return true;
								}else{
									return false;
								 }		
							}	
			}
				

	return false;
}


//this fuction is used to create partition while doing quicksort
//it retruns integer which is used as partion element
int partition(data arr[], int l, int r)
{
	srand(time(NULL));    	
	int indexOfPivot = l + rand()%(r - l + 1); //to get random number
    	data pivot = arr[indexOfPivot];
	//printf("position of pivot element%d\n",indexOfPivot);
    	exchange(&arr[indexOfPivot], &arr[r]); //
	int i = l - 1;
    	int j;
    for (j = l; j <= r-1; j++)
    {

        if (compare(person [j] ,  pivot) )//data arr[j] < pivot)
        {
            i=i+1;
            exchange(&arr[i], &arr[j]);
        }
 
    }
    exchange(&arr[i+1], &arr[r]);
    return i + 1;
}

//this fuction is impleted from quicksort algorithm
// it returns void
void sortIn(data arr[], int l, int r)
{

    int j;
    if (l < r)
    {
        j = partition(person, l, r);
        sortIn(person, l, j-1);
        sortIn(person, j+1, r);
    }

}

// this function is used to display structure array data on display screen
// it returns void
void show()
{
	for(int m =0; m<numberOfLines;m++)
	{ printf("\n%s %s, %s", person[m].fname, person[m].lname, person[m].number);
	}
}

// this function will call sortIn(structure array,l,r) fuction for sorting.
// it returns void.
void sort_contact()
{
	sortIn(person, 0, numberOfLines-1);
	show();
}

//this fuction is used to search contact
// Binary search algorithm is implemented
//it returns void
void search (char* nameIn)
{
	char fnameIn[50];
	char lnameIn[50];	
	const char s[10] = " ";
	char *token;
	token = strtok(nameIn, s);
	strcpy(fnameIn, token);
	//printf("%s\n", fnameIn); // print first name 
	token = strtok(NULL, "\n");
	strcpy(lnameIn, token);
	//printf("%s\n", lnameIn); // print last name 

	int l, r, middle,n;//n & search?
 
	l = 0;
	r = numberOfLines - 1;
	middle = (l+r)/2;
	//printf("numberOfLines = %d\n", numberOfLines);

 
	while (l <= r)
	{
		if (strcasecmp(person [middle].fname ,  fnameIn) < 0)
		{
			l = middle + 1;
		}
		else if (strcasecmp(person [middle].fname ,  fnameIn) == 0)
		{
				if(strcasecmp(person [middle].lname ,  lnameIn) == 0){

					printf("\n%s %s, %s", person[middle].fname, person[middle].lname, person[middle].number);
							break;
				
				}
			
				else if(strcasecmp(person [middle].lname ,  lnameIn) < 0)
					{
						l = middle + 1;	
					}
				else
				{
					r = middle - 1;
				}
									
		}
		else
		{
         		r = middle - 1;
		}

		middle = (l + r)/2;
	}
	if (l > r)
	{
		printf("Name not Found\n");
	}
}

void getName(char *nameIn)
{
	char s;
	while((s = getchar()) != EOF && s != '\n');
	fgets(nameIn, 500, stdin);
}

void delete(char *nameIn)
{

	int fl=0;
	char fnameIn[50];
	char lnameIn[50];
	char numberIn[50];	
	const char s[10] = " ";
	char *token;
	token = strtok(nameIn, s);//taking first name out of name
	strcpy(fnameIn, token); 
	//printf("$%s$\n", token);
	token = strtok(NULL, ", ");////taking last name out of name
	strcpy(lnameIn, token); 
	//printf("$%s$\n", token);
	token = strtok(NULL, "\n");////taking number out
	//printf("$%s$\n", token);
	token++; //removes "\n" before number
	strcpy(numberIn, token);
	//printf("%s %s, %sT",fnameIn,  lnameIn, numberIn);
/*

	for(int r=0;r<strlen(token);r++){
		token[r] = numberIn[r+1];
	}
	strcpy(numberIn, token);
	//printf("$%s$\n", numberIn);

*/
	for(int p=0; p<numberOfLines-1; p++)
	{
		//printf("$%s$ $%s$\n", person [p].fname, fnameIn);
		if(strcasecmp(person [p].fname ,  fnameIn) == 0)
		{
			//printf("$%s$ $%s$\n", person [p].lname, lnameIn);
			if(strcasecmp(person [p].lname ,  lnameIn) == 0)
			{
					
				for(int q=p; q<numberOfLines-1; q++)
				{	
					
					strcpy(person[q].fname, person[q+1].fname); 
					strcpy(person[q].lname, person[q+1].lname); 
					strcpy(person[q].number, person[q+1].number);
					fl=1;
				}
					numberOfLines--;
					i = numberOfLines;	
			}
			
			
		}	
	
		
	
	}

	if(fl!=1)
	{
		printf("\nName not Found");
	}
	if(fl==1)
	{
		show();
		fl=0;
		
	}	

}

void insert( char *nameIn, char *number)
{

	char fnameIn[50];
	char lnameIn[50];
	char numberIn[50];	
	const char s[10] = " ";
	char *token;
	token = strtok(nameIn, s);//taking first name out of name
	strcpy(fnameIn, token); 
	token = strtok(NULL, ", ");////taking last name out of namehu
	//printf("$%s$\n", token);
	strcpy(lnameIn, token); 
	token = strtok(NULL, "\n");////taking number out
	//printf("$%s$\n", token);
	token++; //removes "\n" before number
	strcpy(numberIn, token);

/*
	for(int r=0;r<strlen(token);r++){
		token[r] = numberIn[r+1];
	}
	strcpy(numberIn, token);
	//printf("$%s$\n", token);
*/

        strcpy(person[numberOfLines].fname, fnameIn);//transfering data to person structure
	strcpy(person[numberOfLines].lname, lnameIn);////transfering data to person structure
	strcpy(person[numberOfLines].number, numberIn);//transfering data to person structure
	numberOfLines++;//incrementing person size
	i = numberOfLines;
	sortIn(person, 0, numberOfLines-1);//sorting list
	show();// to display sorted data

}

int main(int argc, char* argv[])
{
	char name[100];
	if(argc != 2){
	printf(" something went wrong with filepath\n");	
	exit(1);
	}
	//char filename[1000];	
	//printf("Please enter the input file");
	create(argv[1]);
	int catchInput;

	while(5)
	{
	printf("\n1) sort_contact\n2) search\n3) delete\n4) insert\nEnter the chhoise\n");
	scanf("%d", &catchInput);
	printf("\n");

		switch(catchInput)
		{
			case 1: sort_contact();
				break;

			case 2:
				printf("\nEnter the name ->");
				getName(name);
				search(name);
				break;
			case 3: 
				printf("\nEnter the name ->");
				getName(name);
				delete(name);
				break;
			case 4: 
				printf("\nEnter the name ->");
				getName(name);
				insert(name, "A");
				break;
		}
	}
	
	return 0;
}



