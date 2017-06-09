#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//global variable for tile count
int tilecount = 0;
//fuction to show final output
void show(int bSize, int trominoBoard[bSize][bSize])
{
	int k;
	int l;
	for( k = 0; k<bSize;k++)
		{
			for(l = 0; l<bSize; l++)
			{	if(trominoBoard[k][l] == -10)
					printf("X\t");
				else
					printf("%d\t", trominoBoard[k][l]);
			}
		printf("\n");		

		}
}

//tromino fuction which implement tromino algorithm
void tromino( int xHole, int yHole, int x, int y, int bSize, int newBSize, int trominoBoard[bSize][bSize])
{
	//base condition
	if(newBSize ==2)
	{
		int k;
		int l;
		for(k = x; k<x+2; k++)
		{
			for(l=y; l<y+2; l++)
			{
				if(trominoBoard[k][l] != 0 )
				{}else trominoBoard[k][l] = tilecount;	
			}
		}
		tilecount++;
		return;
	}
	//calculating new cetre points
	int tempX = x+newBSize/2;
	int tempY = y+newBSize/2;

	//variable for new hole's from 1st quadrant to 4th
	int x1,y1;
	int x2,y2;
	int x3,y3;
	int x4,y4;

	//to check if hole is in 1st quadrant
	if(xHole < tempX && yHole < tempY)
	{	
 		//printf("Hole is in 1st quadrant\n");
		//trominoBoard[tempX-1][tempY-1] = tilecount;//1st
		trominoBoard[tempX-1][tempY] = tilecount; //2nd
		trominoBoard[tempX][tempY-1] = tilecount; //3rd
		trominoBoard[tempX][tempY] = tilecount; //4th
	
		x1 = xHole;
		y1 = yHole;
		x2 = tempX-1;
		y2 = tempY;
		x3 = tempX;
		y3 = tempY-1;
		x4 = tempX;
		y4 = tempY;

		tilecount++;
	
	}

	//to check if hole is in 2nd quadrant
	if(xHole >= tempX && yHole < tempY)
	{ 
		//printf("Hole is in 2nd quadrant\n");
		trominoBoard[tempX-1][tempY-1] = tilecount;//1st
		//trominoBoard[tempX-1][tempY] = tilecount; //2nd
		trominoBoard[tempX][tempY-1] = tilecount; //3rd
		trominoBoard[tempX][tempY] = tilecount; //4th
		
		x1 = tempX-1;
		y1 = tempY-1;
		x2 = xHole;
		y2 = yHole;
		x3 = tempX;
		y3 = tempY-1;
		x4 = tempX;
		y4 = tempY;

		tilecount++;
	}
	//to check if hole is in 3rd quadrant
	if(xHole < tempX && yHole >= tempY)
	{ 	
		//printf("Hole is in 3rd quadrant\n");
		trominoBoard[tempX-1][tempY-1] = tilecount;//1st
		trominoBoard[tempX-1][tempY] = tilecount; //2nd
		//trominoBoard[tempX][tempY-1] = tilecount; //3rd
		trominoBoard[tempX][tempY] = tilecount; //4th
	
		x1 = tempX-1;
		y1 = tempY-1;
		x2 = tempX-1;
		y2 = tempY;
		x3 = xHole;
		y3 = yHole;
		x4 = tempX;
		y4 = tempY;

		tilecount++;
	}
	if(xHole >= tempX && yHole >= tempY)
	{
 		//printf("Hole is in 4th quadrant\n");
		trominoBoard[tempX-1][tempY-1] = tilecount;//1st
		trominoBoard[tempX-1][tempY] = tilecount; //2nd
		trominoBoard[tempX][tempY-1] = tilecount; //3rd
		//TrominoBoard[tempX][tempY] = tilecount; //4th

		x1 = tempX-1;
		y1 = tempY-1;
		x2 = tempX-1;
		y2 = tempY;
		x3 = tempX;
		y3 = tempY-1;
		x4 = xHole;
		y4 = yHole;

		tilecount++;
	}

	//recurcive calls to work on 1st, 2nd, 3rd and 4th quadrant
	tromino(x1, y1, x, y, bSize, newBSize/2, trominoBoard);
	tromino(x2, y2, x, tempY, bSize, newBSize/2, trominoBoard);	
	tromino(x3, y3, tempX, y, bSize, newBSize/2, trominoBoard);
	tromino(x4, y4, tempX, tempY, bSize, newBSize/2, trominoBoard);
										
}

int main(int argc, char* argv[])
{
    
	if(argc != 4)
	{
		printf(" Number of argumants should be 4\n");	
		exit(1);
	}
	
	int k = atoi(argv[1]);
	int bSize = pow(2, k);
	int trominoBoard[bSize][bSize];
	int xHole = atoi(argv[2]);
	int yHole = atoi(argv[3]);
	tilecount++;

	//to initilise trominoBoard with 0
	int l;
	for( k = 0; k<bSize;k++)
	{
		for(l = 0; l<bSize; l++)
			trominoBoard[k][l] = 0;
	}
	//to show hole with special value
	trominoBoard[xHole][yHole] = -10;

	tromino(yHole, xHole, 0, 0, bSize, bSize, trominoBoard);
	//to print final output
	show(bSize, trominoBoard);
	return 0;
}

	
