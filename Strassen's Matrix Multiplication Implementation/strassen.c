#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<math.h>

int count = 0;

//to increment count to next 2^k 
int kFinder(int n)
{
  if (n == 0)
    return 0;
  while (n != 1)
  {
	count  = count + 1;    	
	n = n/2;
  }
  return 1;
} 

//to find that n is 2^k or not i.e.,[2^k]
int powerChecker(int n)
{
  if (n == 0)
    return 0;
  while (n != 1)
  {
    if (n%2 != 0)
	{
		//count  = count + 1;      		
		return 0;
	}
	//count  = count + 1;    	
	n = n/2;	
  }
  return 1;
} 

//function to genarate random floating point number
//takes 2 argument max and Min which is 5 and -5 respectively
 float randomGenarator(float Max, float Min)
{
    return Max + (rand() / ( RAND_MAX / (Min-Max) ) ) ;
}

// function to perform matrix multiplication with complexity O(n^3) 
//takes 3 argument
//size of matrix
//2 matrix for multiplication of size n
void standardMultiplication(int n, float A[n][n], float B[n][n])
{
        int k;
        int l;
        int m;

	float C[n][n];

	float temp = 0;

        for(k=0;k<n;k++){
            for(l=0;l<n;l++){
                for(m=0;m<n;m++)
                    temp += A[k][m] * B[m][l];	

                C[k][l] = temp;
                temp = 0;
            }
        }
        printf("\n\nStandard Multiplication Output:\n");

        for(k=0;k<n;k++){
            for(l=0;l<n;l++){
                printf("%.2f\t", C[k][l]);
            }
            printf("\n");
        }

    }

//dividing a matrix of size n to n/2th size wrt row and coloumn
//taking 6 arguments as follows
//oldrow number: from which row to start
//oldcol number: from which coloumn to start
//oldsize: size of the the original matrix
//newsize: size of the new matrix we want
//oldAB: old matrix
//newAB: new matrix that we want 
void dividingMatrix(int oldrow, int oldcol, int oldsize, int newsize, float oldAB[oldsize][oldsize], float newAB[newsize][newsize])
{
	
	int newrow = 0;
	int newcol = 0;
	
	int k = 0;
	int l = 0;

	for (k=0,newrow=oldrow; k<newsize; k++,newrow++)
	{
		for (l=0,newcol=oldcol; l<newsize; l++,newcol++)
				newAB[k][l] = oldAB[newrow][newcol];
	}
}
//this method is used to compose the original matrix which we divided.
//have 6 arguments as follows
//oldrow & oldcol: indicated old row and coloumn number
//oldsize & newsize: indicated old size of matrix and new size of matrix which //will become
//oldmatrix and newmatrix :  
void rearrange(int oldrow, int oldcol, int oldsize, int newsize, float oldmatrix[oldsize][oldsize], float newmatrix[newsize][newsize])
{
	int newrow=0;
	int newcol=0;
	
	int k;
	int l;	

	for (k=0, newrow=oldrow;k<oldsize;k++, newrow++)
	{
		for (l=0, newcol=oldcol;l<oldsize; l++,newcol++)
			newmatrix[newrow][newcol] = oldmatrix[k][l];
	}
}

//method to subtract 2 matrices
//with 4 arguments as follows
//n: size of the matrix
//operand1: 1st matrix which we want to add
//operand2: 2nd matrix which we want to add
//subtractionresult: final matrix after subtraction
void OprationSubtraction(int n, float operand1[n][n], float operand2[n][n], float subtractionresult[n][n])
{
	int k;
	int l;
	for (k=0;k<n;k++)
	{
		for (l=0;l<n;l++)
			subtractionresult[k][l] = operand1[k][l] - operand2[k][l];
	}
}

//method to add 2 matrices
//with 4 arguments as follows
//n: size of the matrix
//operand1: 1st matrix which we want to add
//operand2: 2nd matrix which we want to add
//additionresult: final matrix after addtion
void OpraationAddition(int n, float operand1[n][n], float operand2[n][n], float additionresult[n][n])
{
	int k;
	int l;
	for (k=0;k<n;k++)
	{
		for (l=0;l<n;l++)
			additionresult[k][l] = operand1[k][l] + operand2[k][l];
	}
}


	
void divideStrassens(int n, float A[n][n], float B[n][n],  float D[n][n])
{
	int k;
	int l;
	int m;

	float temp=0;
	//base condition
if(n==2){
	float d1;
	float d2;
	float d3;
	float d4;
	float d5;
	float d6;
	float d7;
	
	d2 = (A[1][0]+A[1][1])*B[0][0];
	d3 = A[0][0]*(B[0][1]-B[1][1]);
	d4 = A[1][1]*(B[1][0]-B[0][0]);
	d5 = (A[0][0]+A[0][1])*B[1][1];
	d6 = (A[1][0]-A[0][0])*(B[0][0]+B[0][1]);
	d7 = (A[0][1]-A[1][1])*(B[1][0]+B[1][1]);
	d1 = (A[0][0]+A[1][1])*(B[0][0]+B[1][1]);

	D[0][1]	= d3+d5;
	D[1][0] = d2+d4;

	D[0][0] = d1+d4-d5+d7;	
	D[1][1] = d1+d3-d2+d6;


    		return;
	}


	
	// n/2 matrix varibale to divide matrix A of size n.
	float A11[n/2][n/2];
	float A12[n/2][n/2];
	float A21[n/2][n/2];
	float A22[n/2][n/2];

	// n/2 matrix varibale to divide matrix B of size n.
	float B11[n/2][n/2];
	float B12[n/2][n/2];
	float B21[n/2][n/2];
	float B22[n/2][n/2];

	// Dividing the Matrix B to 4 parts
	dividingMatrix(0,0,n,n/2,B,B11);
	dividingMatrix(0,n/2,n,n/2,B,B12);
	dividingMatrix(n/2,0,n,n/2,B,B21);
	dividingMatrix(n/2,n/2,n,n/2,B,B22);
	
	// Dividing the Matrix A to 4 parts
	dividingMatrix(0,0,n,n/2,A,A11);
	dividingMatrix(0,n/2,n,n/2,A,A12);
	dividingMatrix(n/2,0,n,n/2,A,A21);
	dividingMatrix(n/2,n/2,n,n/2,A,A22);	
	

	
	//variable to store intermidiate matrix addition and subtraction operations
	//operation1 to operation18 are used to stored result of matrix addition or subtraction

	//intermidiate 7 matirces as per strassen's algorithms
	float m1[n/2][n/2];
	float m2[n/2][n/2];
	float m3[n/2][n/2];
	float m4[n/2][n/2];
	float m5[n/2][n/2];
	float m6[n/2][n/2];
	float m7[n/2][n/2];


	float opration1[n/2][n/2];		
	OpraationAddition(n/2, A11, A12, opration1);
	divideStrassens(n/2, opration1, B22, m5);


	float opration4[n/2][n/2];
	OpraationAddition(n/2, A21, A22, opration4);
	divideStrassens(n/2, opration4, B11, m2);

	float opration5[n/2][n/2];
	OprationSubtraction(n/2, B21, B11, opration5);
	divideStrassens(n/2, A22, opration5, m4);

	float opration6[n/2][n/2];
	OprationSubtraction(n/2, B12, B22,opration6);
	divideStrassens(n/2, A11, opration6, m3);

	float opration7[n/2][n/2];
	float opration8[n/2][n/2];
	OprationSubtraction(n/2, A12, A22,opration7);
	OpraationAddition(n/2, B21, B22,opration8);
	divideStrassens(n/2, opration7, opration8, m7);
	
	float opration9[n/2][n/2];
	float opration10[n/2][n/2];
	OpraationAddition(n/2, A11, A22, opration9);
	OpraationAddition(n/2, B11, B22, opration10);
	divideStrassens(n/2, opration9, opration10, m1);

	float opration11[n/2][n/2];
	float opration12[n/2][n/2];	
	OprationSubtraction(n/2, A21, A11,opration11);
	OpraationAddition(n/2, B11,B12,opration12);
	divideStrassens(n/2, opration11, opration12, m6);
	


//rearranging the matrix by calulating m1 to m7 and composing it final //matrix	

	float opration2[n/2][n/2];	
	OpraationAddition(n/2, m2, m4, opration2);
	rearrange(n/2, 0, n/2, n, opration2, D);

	float opration3[n/2][n/2];
	OpraationAddition(n/2, m3, m5, opration3);
	rearrange(0, n/2, n/2, n, opration3, D);

	float opration13[n/2][n/2];
	float opration14[n/2][n/2];
	float opration15[n/2][n/2];
	OpraationAddition(n/2, m1, m3, opration13);
	OprationSubtraction(n/2, opration13, m2, opration15);
	OpraationAddition(n/2, opration15, m6,opration14);
	rearrange(n/2, n/2, n/2, n, opration14, D);

	float opration16[n/2][n/2];
	float opration17[n/2][n/2];
	float opration18[n/2][n/2];
	OpraationAddition(n/2, m1, m4, opration16);
	OprationSubtraction(n/2, opration16, m5, opration18);
	OpraationAddition(n/2, opration18, m7,opration17);
	rearrange(0, 0 , n/2, n, opration17, D);
	
}

void strassensMultiplication(int n, int nNew, float A[n][n], float B[n][n] ){
	
	int k =0;
	int l = 0;
	int new;

	if(n == nNew)
		new = n;
	else
		new = nNew;
	float D[new][new];
	divideStrassens(new, A, B, D);
	printf("\n\nStrassen's matrix multiplication:\n");
	for(k=0;k<n;k++){
            for(l=0;l<n;l++)
                printf("%.2f\t", D[k][l]);
            printf("\n");
        }
       }


void strassensMultiplication2(int temp2, int n, float A[temp2][temp2], float B[temp2][temp2] ){
	
	int k =0;
	int l = 0;
	float D[temp2][temp2];
	divideStrassens(temp2, A, B, D);
	printf("\n\nStrassen's matrix multiplication:\n");
	
	
 	for(k=0;k<n;k++){
            for(l=0;l<n;l++){
                printf("%.2f\t", D[k][l]);
            }
            printf("\n");
        }

	 
       }
int main(int argc, char* argv[]) {
    
	if(argc != 2){
		printf(" Number of argumants should be 2\n");	
		exit(1);
	}

	int n = atoi(argv[1]);

	float A[n][n];
    	float B[n][n];
	int k;
	int l;
	
	//to get differant random values every time
	srand(time(0));

 	//printing Matrix A
        printf("\nMatrix A:\n");
        for(k=0;k<n;k++){
            for(l=0;l<n;l++){
		A[k][l] = randomGenarator(5,-5);
                printf("%.2f\t", A[k][l]);
            }
            printf("\n");
        }


        //printing matrix B
        printf("\nMatrix B:\n");
        for(k=0;k<n;k++){
            for(l=0;l<n;l++){
		B[k][l] = randomGenarator(5,-5);
                printf("%.2f\t", B[k][l]);
            }
            printf("\n");
        }

	if(powerChecker(n))
	{
		strassensMultiplication(n,n,A,B);
	}
	else{
		kFinder(n);
		int power = count+1;
		int temp2 = pow(2, power);
		float Anew[temp2][temp2];
		float Bnew[temp2][temp2];
		
		int k;
		int l;
		for(k=0;k<temp2;k++){
            		for(l=0;l<temp2;l++){
				Anew[k][l] = 0.0;
				Bnew[k][l] = 0.0;
            		}
        	}		
		
		for(k=0;k<n;k++){
            		for(l=0;l<n;l++){
				Anew[k][l] = A[k][l];
				Bnew[k][l] = B[k][l];
                		
            		}
        	}
		
		strassensMultiplication2(temp2,n,Anew,Bnew);
	}

    	standardMultiplication(n, A, B);
   	
	return 0;
}

