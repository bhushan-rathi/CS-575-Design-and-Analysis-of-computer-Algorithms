#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>


void settingValues(int p, char fileL[], int array[])
{
	int i = 0;
	int z = 0;
	array[i] = atoi(strtok(fileL, ","));
	for(i = 1; i < p; i++)
	{
		array[i] = atoi(strtok(NULL, ","));
	}
}


int minDistFinder(int D[], int T[])
{
  
	int min = 99999;
	int index;
	int i;
	for (i = 0; i < 5; i++)
	{
		if (T[i] == 0 && D[i] <= min)
		{
			min = D[i], index = i;
		}
	}
	  
	return index;
}

void pathSetter(int base[], int a)
{
	if(-5 == base[a])
	{
		return ;
	}
	
	pathSetter(base, base[a]);
	
	printf("v%d ", a);

}
void sortestPathFinder(int a, int arr [5][5], int b)
{

	printf("\nNote: Initial vertex is Vertex 0 and not Vertex 1\n");
	int k;
	int l;
	for(k=0; k<5;k++)
	{
		for(l=0;l<5;l++)
		{
			if(arr[k][l] == -99){arr[k][l] = b;}
		}
	}


	int D[5];
	int T[5];
	int y;
	int base[5];
	for(y=0; y<5;y++){base[y]=0;}
	base[0]=-5;
	//assiging inifinity as 99999 and T[] array elements 0
	for(y=0; y<5;y++){D[y]=99999; T[y] = 0;}
	D[0]=0;	
	
	//working on every vertex to find min. distance
	for(k=0;k<4;k++)
	{
		l = minDistFinder(D,T);
		T[l]=1;

		int p;
		//checking every node which to find adjecent node
		for(p=0;p<5;p++)
		{
			//updating minimum distance if current wait is better than old one
			if(D[l] + arr[l][p] < D[p] && T[p]==0 )
			{
				base[p] = l;				
				D[p] = D[l] + arr[l][p];
			}	
		}
	}
	
	//printing the output
	int p;	
	for(p=0; p<5; p++)
	{
		if(D[p] == 99999)
		{
			printf("\nvertex %d  is unreachable(-99) from vertex0 ", p);
		}
		else
		{		
			printf("\nvertex%d  have distace %d from vertex0  path from vertex0 is v0,", p, D[p]);
			pathSetter(base, p);
		}
	}
	printf("\n");
	
}

int main(int argc, char **argv)
{
	
	int arr[5][5];
	char *rowReader=NULL;
	int number=0;
	char* row[25];
	size_t bufferSize=0;
	FILE *fp;
	int counter = 5;
	
	char fileL[200];
	int counterPointer = 2;

	fp=fopen(argv[1],"r");
	int m=0;
	int value=0;
	if(fp == NULL)
	{
        	printf("find not found\n");
        	exit(0);
	}

    	if(fp!=NULL)
	{
	int x = getline(&rowReader,&bufferSize,fp);
	int n=0;
	while(x != -1)
	{
		row[value] = strtok(rowReader,",");

		counterPointer++;
		number =3;

	        arr[m][n] = atoi(row[value]);

	        value++;
		n++;

        	while(number!=0)
		{
			row[value] = strtok(NULL,",");

			counter++;
			number--;

			arr[m][n] = atoi(row[value]);

			value++;			
			n++;
        	}

	        row[value] = strtok(NULL,"\n");

		counterPointer++;

	        arr[m][n] = atoi(row[value]);

		value++;	
	
		x = getline(&rowReader,&bufferSize,fp);

		n=0;	        
		m++;		
	}
	}

	sortestPathFinder(0, arr, 99999);
	fclose(fp);

return 0;
}
