#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#define size 1000

// function used to parse line    

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

void dynamic_knapsack(int set_weight[], int set_profit[], int super_set_size, int knapsack_capacity)
{
	int array[super_set_size+1][knapsack_capacity+1];
	int a[super_set_size+1][knapsack_capacity+1];
	int w;
	int totalProfit=0;
	int totalWeight=0;
	int maxProfit;
	int maxWeight;
	//initilizing
	int q;
	for(q =0; q<=super_set_size;q++)
		{
			for( w=0; w<=knapsack_capacity;w++)
			{array[q][w] = 0;a[q][w]=0;}
		}
	//implementing algorithm
	int k;
	for(k = 1; k<=super_set_size;k++)
	{
		for(w=1; w<=knapsack_capacity; w++)
		{
			if( (set_weight[k-1]<=w) && ((array[k-1][w-set_weight[k-1]] + set_profit[k-1]) > array[k-1][w]))
			{
				array[k][w] = array[k-1][w-set_weight[k-1]] + set_profit[k-1];
				maxProfit=array[k][w]; 
				a[k][w] = a[k-1][w-set_weight[k-1]] + set_weight[k-1];
			}
			else
			{
				array[k][w]=array[k-1][w];
				maxProfit=array[k][w];
				a[k][w]=a[k-1][w];
			}
			
		}
		
	}
		//finding out total weight
	for(k=0; k<=super_set_size;k++)
	{	
		for(w=0; w<=knapsack_capacity; w++)
		{
			totalWeight=a[k][w];
		}
	}
	k=0;
	printf("\nTotal Profit = %d", maxProfit);
	printf("\nTotal Weight = %d\n", totalWeight);
	printf("\nBelow are the item selected:\n");
	
	int c;
	c=0;
	int z[50];
	for(k=0;k<50;k++){z[k] = 0;}
	int temp2 = knapsack_capacity;
	// printing selected item
	int i=0;
	for(i=super_set_size; i>0;i--)
	{
		
		if(array[i][temp2]!=array[i-1][temp2] && (array[i][temp2] == array[i-1][temp2-set_weight[i-1]]+set_profit[i-1]))
		{
			z[c] = i; 
			c++;
			temp2 = temp2-set_weight[i-1];	
		}
	}

	
	for(k=c-1;k>=0;k--)
	{
		printf("\n(item%d, %d, %d)", z[k], set_profit[z[k]-1],set_weight[z[k]-1]);
	}
	printf("\n");

}

int main(int argc, char **argv)
{

	int super_set_size;
	int set_weight[super_set_size];
	int knapsack_capacity;
	int set_profit[super_set_size];
	//int array[super_set_size+1][knapsack_capacity+1];
	FILE *fp;
    	char fileL[50];
	
	//taking input from file
	fp = fopen(argv[1], "r");
	if(fp == NULL)
	{
        	printf("find not found\n");
        	exit(0);
	}
	if(fp != NULL)
	{
    	fscanf(fp, "%d\n", &super_set_size);
    	fscanf(fp, "%s\n", fileL);
    	settingValues(super_set_size, fileL, set_weight);
    	fscanf(fp, "%s\n", fileL);
    	settingValues(super_set_size, fileL, set_profit);
    	fscanf(fp, "%d\n", &knapsack_capacity);
	dynamic_knapsack(set_weight, set_profit, super_set_size, knapsack_capacity);
	}
	fclose(fp);
return 0;
}
