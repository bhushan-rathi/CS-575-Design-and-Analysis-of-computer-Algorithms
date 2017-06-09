#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

void powerSetFinder(int *set, int *set_weight, int *set_profit, int knapsack_capacity, int size_of_set)
{	
	int k, j, total_profit, total_weight, max_weight, max_profit, max_set[size_of_set], count, itemCount, setCounter;
	int number_of_subsets = pow(2, size_of_set);

	k = 0;
	j = 0;	
	total_profit = 0;
	total_weight = 0;
	max_weight = 0;
	max_profit = 0;
	count = 0;
	itemCount = 0;
	setCounter = 0;	
	int max_set2[size_of_set];
	
 
    /*counter for sets*/
    	for(k = 0 ; k < number_of_subsets ; k++)
	{
		int m=0;
		// will get execute for size_of_set times
		for(j = 0; j < size_of_set; j++)
		{
          		//will check every possible subset
			if((1<<j) & k)
	   		{
				count++;
				total_profit = total_profit + set_profit[j];
				total_weight = total_weight + set_weight[j];
				max_set[count-1]=j+1;
	   		}
       		}

		if(total_weight <= knapsack_capacity)
		{
			if(total_profit >= max_profit)
			{
				max_weight = total_weight;
				max_profit = total_profit;
				int z;
				for(z=0;z<count;z++)
				{
					max_set2[z]=max_set[z];
				}
				itemCount = count;
			}
    		}
		total_profit = 0;
		total_weight = 0;
		count = 0;
	}

	printf("\nTotal Profit = %d", max_profit);
	printf("\nTotal Weight = %d\n", max_weight);
	printf("\nfollowing are the selected item:");
	printf("\nitem's are printed as (item number, item price, item weight):\n");
	int n;
	for(n=0;n<itemCount;n++)
	{
		printf("\n(item%d, %d, %d)",max_set2[n], set_profit[n+1], set_weight[n+1]);	
	}
	printf("\n");	

}
 
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


int main(int argc, char **argv)
{

	FILE *fp;
    	char fileL[50];
	int super_set_size;
    	int set_weight[super_set_size];
	int knapsack_capacity;
	int set_profit[super_set_size];
    
	fp = fopen(argv[1], "r");
	if(fp == NULL)
	{
        	printf("find not found\n");
        	exit(0);
	}

	if( fp!= NULL)
	{ 
    	fscanf(fp, "%d\n", &super_set_size);
    	fscanf(fp, "%s\n", fileL);
    	settingValues(super_set_size, fileL, set_weight);
    	fscanf(fp, "%s\n", fileL);
    	settingValues(super_set_size, fileL, set_profit);
    	fscanf(fp, "%d\n", &knapsack_capacity);
	
	int set[100];
	int y;
	for(y=0;y<super_set_size;y++){set[y] = y+1;}
	powerSetFinder(set, set_weight, set_profit, knapsack_capacity, super_set_size);
	}
	fclose(fp);
    	return 0;
}
