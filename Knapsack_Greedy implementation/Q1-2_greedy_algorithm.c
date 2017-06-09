#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>


float temp[50];
float total_profit = 0.0;
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

//apply greedy algo. for maxBenefitPerUnit
void maxBenefitPerUnit( int super_set_size, int set_profit[],int set_weight[], int itemRank[], int knapsack_capacity, int W[], int P[])
{
	int i, totalProfit,totalWeight,currentWeight,counter;
	totalProfit=0;
	totalWeight=0;
	currentWeight=0;
	counter=0;
	int a[super_set_size];
	int b;
	for(b=0;b<super_set_size;b++){a[b] = 0;}
	printf("\nMAX_BENIFIT_PER_UNIT");
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	
	for(i =0;i<super_set_size;i++)
	{
		if(totalWeight<knapsack_capacity)
		{
			totalProfit = totalProfit + set_profit[i];
			totalWeight = totalWeight + set_weight[i];
			a[counter] = itemRank[i];			
			counter++;
			
		}
		if(totalWeight>knapsack_capacity)
		{
			totalProfit = totalProfit - set_profit[i];
			totalWeight = totalWeight - set_weight[i];
			a[counter]=0;
			counter--;
		}

	}


	
	printf("\nTotal Profit = %d", totalProfit);
	printf("\nTotal Weight = %d", totalWeight);
	printf("\nItem Selected:");
	int j;
	for(j=0;j<counter;j++)
	{
		printf("\n(item%d, %d, %d)", a[j], P[a[j]-1], W[a[j]-1] );
	}

	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");

}
//apply greedy algo. for maxWeightFirst
void maxWeightFirst( int super_set_size, int set_profit[],int set_weight[], int itemRank[], int knapsack_capacity, int W[], int P[])
{
	int i, totalProfit,totalWeight,currentWeight,counter;
	totalProfit=0;
	totalWeight=0;
	currentWeight=0;
	counter=0;
	int a[super_set_size];
	int b;
	for(b=0;b<super_set_size;b++){a[b] = 0;}
	printf("\nMAX_WEIGHT_First");
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	for(i =0;i<super_set_size;i++)
	{
		if(totalWeight<knapsack_capacity)
		{
			totalProfit = totalProfit + set_profit[i];
			totalWeight = totalWeight + set_weight[i];
			a[counter] = itemRank[i];
			counter++;
		}
		if(totalWeight>knapsack_capacity)
		{
			totalProfit = totalProfit - set_profit[i];
			totalWeight = totalWeight - set_weight[i];
			a[counter]=0;
			counter--;
		}

	}

	printf("\nTotal Profit = %d", totalProfit);
	printf("\nTotal Weight = %d", totalWeight);
	printf("\nItem Selected:");
	int j;
	for(j=0;j<counter;j++)
	{
		
		printf("\n(item%d, %d, %d)", a[j], P[a[j]-1], W[a[j]-1] );
	}

	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
}

//apply greedy algo. for minWeightFirst
void minWeightFirst( int super_set_size, int set_profit[],int set_weight[], int itemRank[], int knapsack_capacity, int W[], int P[])
{
	int i, totalProfit,totalWeight,currentWeight,counter;
	totalProfit=0;
	totalWeight=0;
	currentWeight=0;
	counter=0;
	int a[super_set_size];
	int b;
	for(b=0;b<super_set_size;b++){a[b] = 0;}
	printf("\nMIN_WEIGHT_First");
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	for(i =0;i<super_set_size;i++)
	{
		if(totalWeight<knapsack_capacity)
		{
			totalProfit = totalProfit + set_profit[i];
			totalWeight = totalWeight + set_weight[i];
			a[counter] = itemRank[i];
			counter++;
		}
		if(totalWeight>knapsack_capacity)
		{
			totalProfit = totalProfit - set_profit[i];
			totalWeight = totalWeight - set_weight[i];
			a[counter]=0;
			counter--;
		}

	}

	printf("\nTotal Profit = %d", totalProfit);
	printf("\nTotal Weight = %d", totalWeight);
	printf("\nItem Selected:");
	int j;
	for(j=0;j<counter;j++)
	{
		printf("\n(item%d, %d, %d)", a[j], P[a[j]-1], W[a[j]-1] );
	}

	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
}

//apply greedy algo. for maxBenifitFirst
void maxBenifitFirst( int super_set_size, int set_profit[],int set_weight[], int itemRank[], int knapsack_capacity, int W[], int P[])
{
	int i, totalProfit,totalWeight,currentWeight,counter;
	totalProfit=0;
	totalWeight=0;
	currentWeight=0;
	counter=0;
	int a[super_set_size];
	int b;
	for(b=0;b<super_set_size;b++){a[b] = 0;}
	printf("\nMAX_BENIFIT_First");
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	for(i =0;i<super_set_size;i++)
	{
		if(totalWeight<knapsack_capacity)
		{
			totalProfit = totalProfit + set_profit[i];
			totalWeight = totalWeight + set_weight[i];
			a[counter] = itemRank[i];
			counter++;
		}
		if(totalWeight>knapsack_capacity)
		{
			totalProfit = totalProfit - set_profit[i];
			totalWeight = totalWeight - set_weight[i];
			a[counter]=0;
			counter--;
		}

	}

	printf("\nTotal Profit = %d", totalProfit);
	printf("\nTotal Weight = %d", totalWeight);
	printf("\nItem Selected:");
	int j;
	for(j=0;j<counter;j++)
	{
		printf("\n(item%d, %d, %d)", a[j], P[a[j]-1], W[a[j]-1] );
	}

	printf("\n");
}

int main(int argc, char **argv)
{

	
	int super_set_size;
    	int set_weight[super_set_size];
	int knapsack_capacity;
	int set_profit[super_set_size];
	float set_ratio[super_set_size];
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
	}
	fclose(fp);
	//delaclaring varibales
	int set[100];
	int temp1;
	int temp2;
	float temp3;
	int i;
	int itemRank[super_set_size];
	int W[super_set_size];
	int P[super_set_size];
	for(i=0;i<super_set_size;i++){W[i]=set_weight[i];P[i]=set_profit[i]; }
	//for(i=0;i<super_set_size;i++){printf("\nW[%d]=%d P[%d] =%d\n", i, W[i],i,P[i]); }
	//calculating per unit cost and inilising intemRank Array.
	for(i=0;i<super_set_size;i++)
	{
		set_ratio[i] = set_profit[i]/(float)set_weight[i];
		itemRank[i] = i+1;
	}
	int k,l,m;

	printf("\nItems are printed as item Number, item Cost, item weight\n");
	//sorting on per unit cost basis
	for (k = 0; k<super_set_size; k++) {
      		for (l = k + 1; l < super_set_size; l++) {
         		if (set_ratio[k] < set_ratio[l]) {
			
				temp3 = set_ratio[l];
				set_ratio[l] = set_ratio[k];
        			set_ratio[k] = temp3;

				temp2 = set_profit[l];
				set_profit[l] = set_profit[k];
				set_profit[k] = temp2;

				temp2 = set_weight[l];
				set_weight[l] = set_weight[k];
				set_weight[k] = temp2;
				
				temp2 = itemRank[l];
				itemRank[l] = itemRank[k];
            			itemRank[k] = temp2;
         		}
      		}
   	}


	maxBenefitPerUnit(super_set_size, set_profit, set_weight, itemRank, knapsack_capacity, W, P);
	
	//sorting maximum weight first
	for (k = 0; k<super_set_size; k++) {
      		for (l = k + 1; l < super_set_size; l++) {
         		if (set_weight[k] < set_weight[l]) {
			

				temp2 = set_profit[l];
				set_profit[l] = set_profit[k];
				set_profit[k] = temp2;

				temp2 = set_weight[l];
				set_weight[l] = set_weight[k];
				set_weight[k] = temp2;
				
				temp2 = itemRank[l];
				itemRank[l] = itemRank[k];
            			itemRank[k] = temp2;
         		}
      		}
   	}
/*
	for(i=0;i<super_set_size;i++)
	{
		printf(" \nweight[%d] = %d", i+1, set_weight[i]);
		
	}
	for(i=0;i<super_set_size;i++)
	{
		printf(" \nprofit[%d] = %d", i+1, set_profit[i]);
		
	}
	for(i=0;i<super_set_size;i++)
	{
		printf(" \nrank[%d] = %d", i+1, itemRank[i]);
		
	}
*/	
	maxWeightFirst(super_set_size, set_profit, set_weight, itemRank, knapsack_capacity, W, P);

	//sorting minimum weight first
	for (k = 0; k<super_set_size; k++) {
      		for (l = k + 1; l < super_set_size; l++) {
         		if (set_weight[k] > set_weight[l]) {
			

				temp2 = set_profit[l];
				set_profit[l] = set_profit[k];
				set_profit[k] = temp2;

				temp2 = set_weight[l];
				set_weight[l] = set_weight[k];
				set_weight[k] = temp2;
				
				temp2 = itemRank[l];
				itemRank[l] = itemRank[k];
            			itemRank[k] = temp2;
         		}
      		}
   	}

	minWeightFirst(super_set_size, set_profit, set_weight, itemRank, knapsack_capacity, W, P);

	//sorting maximum profit first
	for (k = 0; k<super_set_size; k++) {
      		for (l = k + 1; l < super_set_size; l++) {
         		if (set_profit[k] < set_profit[l]) {
			

				temp2 = set_profit[l];
				set_profit[l] = set_profit[k];
				set_profit[k] = temp2;

				temp2 = set_weight[l];
				set_weight[l] = set_weight[k];
				set_weight[k] = temp2;
				
				temp2 = itemRank[l];
				itemRank[l] = itemRank[k];
            			itemRank[k] = temp2;
         		}
      		}
   	}

	maxBenifitFirst(super_set_size, set_profit, set_weight, itemRank, knapsack_capacity, W, P);


return 0;
}



