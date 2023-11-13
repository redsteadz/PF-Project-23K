/*
 *
 *@done Upper Triangle Matrix Identification
 *@done Lower Triangle Matrix Identification
 *@todo Hermitian Matrix Identification
 *@todo Skew-Hermitian Matrix Identification
 *
 * */

#include <stdbool.h>
#include <stdio.h>
#include "headers/matrices.h"

/*
 * RAYYAN'S WORK
 */

int transpose(){
    int r,c,i,j,x;
    printf("Enter the number of rows: ");
    scanf("%d",&r);
    printf("Enter the number of columns: ");
    scanf("%d",&c);
    
    int a[r][c];
    int t_a[c][r];
    
    for (i=0;i<r;i++){
        for (j=0;j<c;j++){
            printf("Enter element: ");
            scanf("%d",&x);
            a[i][j] = x;
            t_a[j][i] = x;
        }
    }
    printf("\n The original matrix is: \n");
    for (i=0;i<r;i++){
        for (j=0;j<c;j++){
            printf("%d  ",a[i][j]);
        } 
        printf("\n");
    }
    printf("\n The transpose matrix is: \n");
    for (j=0;j<c;j++){
        for (i=0;i<r;i++){
            printf("%d  ",t_a[j][i]);
        }
        printf("\n");
    }
  return 0;
}

int scalar_multiplication()
{
	int r,c,i,j,x;
    printf("Enter the number of rows: ");
    scanf("%d",&r);
    printf("Enter the number of columns: ");
    scanf("%d",&c);
    printf("Enter scalar to multiply: ");
    scanf("%d",&x);
    
    int a[r][c];
    
    for (i=0;i<r;i++){
    	for (j=0;j<c;j++){
    		printf("Enter element of array: ");
    		scanf("%d",&a[i][j]);
		}
	}
	
	for (i=0;i<r;i++){
    	for (j=0;j<c;j++){
    		a[i][j] = x * a[i][j];
    	}
	}
	printf("The scaled matrix is: \n");
    for (i=0;i<r;i++){
    	for (j=0;j<c;j++){
    		printf("%d    ",a[i][j]);
    	}
    	printf("\n");
	}
  return 0;
}

int unit_matrix(){
    int r,c,i,j;
    printf("Enter the number of rows: ");
    scanf("%d",&r);
    printf("Enter the number of columns: ");
    scanf("%d",&c);
    if (r!=c){
		printf("Only enter a square matrix...");
		return(0);
	}
	
    int a[r][c];
    
    for (i=0;i<r;i++){
        for (j=0;j<c;j++){
            printf("Enter element: ");
            scanf("%d",&a[i][j]);
           
        }
    }
    int sum=0;
    for (i=0;i<r;i++){
        for (j=0;j<c;j++){
        	if (i==j){
				if (a[i][j]==1){
					sum++;
				}
        		
			}
		}
	}
    
    if (sum==r){
    	return 1;
	}
  return 0;
}

int null_matrix(){
    int r,c,i,j;
    printf("Enter the number of rows: ");
    scanf("%d",&r);
    printf("Enter the number of columns: ");
    scanf("%d",&c);
    
    int a[r][c];
    
    for (i=0;i<r;i++){
        for (j=0;j<c;j++){
            printf("Enter element: ");
            scanf("%d",&a[i][j]);
            
        }
    }
	for (i=0;i<r;i++){
        for (j=0;j<c;j++){
            printf("%d  ",a[i][j]);
        }
        printf("\n");
    }
	
    
    for (i=0;i<r;i++){
        for (j=0;j<c;j++){
            if (a[i][j]!=0){
            	return 0;
			}
		}
	}
    return 1;
}


/*
 * HAMEES'S WORK
 */


bool u_tm (int r, int c, int matrix[r][c]){

  if (r >= c){
    int n = r;

    for (int i = 1; i < n; i++){
        for (int j = 0; j < i && j < c; j++ ){
          if (matrix[i][j] != 0){
            return false;
          }
        }
    } 
    return true;
  }
  
  return false;
}

bool l_tm (int r, int c, int matrix[r][c]){

  for (int j = 1; j < c; j++){
    for (int i = (r-j); i < j && i < r; i++){
      if (matrix[i][j] != 0){

        return false;
      }
    }
  }
  return true;
}

bool diag (int r, int c, int matrix[r][c]){
  if (r == c){
    for (int i = 1; i < r; i++){
      for (int j = 0; j < i; j++){
        if (matrix[i][j] == 0 && matrix[j][i] == 0){
          continue;
        } else {
          return false;
        }
      }
    }
  } else {
    return false;
  }
  return true;
}

//HUZAILA'S WORK:
//1.idemponent:
#include<stdio.h>
void idemponent(){
	//modifies code for idemponent.!!
	int row=0, column=0;
	printf("enter number of rows=");
	scanf("%d", &row);
	printf("enter number of column=");
	scanf("%d", &column);
	
	if (row==column){
	float matrix[row][column];
	int i=0, j=0;
	for (i=0; i<row; i++ ){
		for (j=0; j<column; j++){
			scanf("%f", &matrix[i][j]);
		}
	}
	
    float mult[row][column];
	float sum=0;
	int n=0;
	for (i=0; i<row; i++ ){
		for (j=0; j<column; j++){
			sum=0;
			for(n=0; n<row; n++){
				sum=sum+(matrix[i][n]*matrix[n][j]);
				mult[i][j]=sum;
			}
			printf("%d\n", mult[i][j]);		
}
}
int count=0;
     for (i=0;i<row; i++){
     	for (j=0;j<column;j++){
     		if (mult[i][j]==matrix[i][j]){
     			count=count+1;
			 }
		 }
	 }
	 if (count==(row*column)){
		 	printf("this is an idemponent matrix");
		 }
		 else {
		 	printf("this is not an idemponent matrix");
		 }
}
   else{
   	printf("this doesnot satisfy the conditions for an idemponent matrix");
   }

}
  //2.involuntary:
  #include<stdio.h>
void invoulantry(){
	int row=0, column=0;
	printf("enter number of rows=");
	scanf("%d", &row);
	printf("enter number of column=");
	scanf("%d", &column);
	
	if (row==column){
	float matrix[row][column];
	int i=0, j=0;
	for (i=0; i<row; i++ ){
		for (j=0; j<column; j++){
			scanf("%f", &matrix[i][j]);
		}
	}
	
    float mult[row][column];
	float sum=0;
	int n=0;
	for (i=0; i<row; i++ ){
		for (j=0; j<column; j++){
			sum=0;
			for(n=0; n<row; n++){
				sum=sum+(matrix[i][n]*matrix[n][j]);
				mult[i][j]=sum;
			}
			printf("%d\n", mult[i][j]);		
}
}

//cheching for involuntary matrix:

int count=0;
     for (i=0;i<row;i++){
     	for(j=0;j<column;j++){
     		if (i==j){
     			if(mult[i][j]==1){
     				count=count+1;
				 }
			 }
			 else{
			 	if(mult[i][j]==0){
			 		count=count+1;
				 }
			 }
		 }
	 }
	 if(count==(row*column)){
	 	printf("this is an invoulantry matrix");
	 }
	 else {
	 	printf("this is not an invoulantry matrix");
	 }
}
    else {
    	printf("this doesnot satisfy the conditions for an invoulantry matrix");
	}
}
 //3.nilponent:
 void nilponent(){
	int row=0, column=0;
	printf("enter number of rows=");
	scanf("%d", &row);
	printf("enter number of column=");
	scanf("%d", &column);
		if (row==column){
			float matrix[row][column];
	int i=0, j=0;
	for (i=0; i<row; i++ ){
		for (j=0; j<column; j++){
			scanf("%f", &matrix[i][j]);
		}
	}
	float mult[row][column];
	float sum=0;
	int n=0;
	for (i=0; i<row; i++ ){
		for (j=0; j<column; j++){
			sum=0;
			for(n=0; n<row; n++){
				sum=sum+(matrix[i][n]*matrix[n][j]);
				mult[i][j]=sum;
			}
			//printf("%d\t", mult[i][j]);		
}
}
	int times=row-2;
	int k;
	for(k=1;k<=times; k++){
		for (i=0; i<row; i++ ){
		for (j=0; j<column; j++){
			sum=0;
			for(n=0; n<row; n++){
				sum=sum+(mult[i][n]*matrix[n][j]);
				mult[i][j]=sum;
			}
			//printf("%d\n", mult[i][j]);		
}
}
		
	}
	int count=0;
	for(i=0;i<row;i++){
		for(j=0; j<column; j++ ){
			if(mult[i][j]==0){
			count=count+1;	
			}
		}
	}
	if (count==(row*column)){
			printf("this is a nilponent matrix");
		}
		else {
			printf("this is a not nilponent matrix");
		}
}

else {
	printf("this doesnot satisfy the conditions for a nilponent matrix");
}

}
//4.symmetric:
#include<stdio.h>
void symmetric(){
int row,column;
printf("enter the number of rows=");
scanf("%d", &row);
printf("enter the number of columns=");
scanf("%d", &column);

if (row==column){
	int matrix[row][column];
int i,j;
for (i=0; i<row; i++){
for(j=0; j<column; j++){
scanf("%d", &matrix[i][j]);
}
}
printf("\n");
int At[row][column];
int temp=0;
for (i=0;i<row;i++){
	for (j=0;j<column;j++){
	temp=matrix[j][i];
	At[i][j]=temp;
	//printf("%d\n", At[i][j]);	
	}
}
int count=0;
for (i=0;i<row;i++){
	for (j=0;j<column;j++){
		if(At[i][j]==matrix[i][j]){
		count=count+1;	
		}
	}
}
if(count==(row*column)){
	printf("this is a symmetric matrix");
}
else {
	printf("this is not a symmetric matrix");
}
}

else {
	printf("symmetric matrix of this matix doesnot exist");
}
}
//5.skew symmetric:
#include<stdio.h>
void skewsym(){
int row,column;
printf("enter the number of rows=");
scanf("%d", &row);
printf("enter the number of columns=");
scanf("%d", &column);

if (row==column){
	int matrix[row][column];
int i,j;
for (i=0; i<row; i++){
for(j=0; j<column; j++){
scanf("%d", &matrix[i][j]);
}
}
printf("\n");
int At[row][column];
int temp=0;
for (i=0;i<row;i++){
	for (j=0;j<column;j++){
	temp=matrix[j][i];
	At[i][j]=temp;
	//printf("%d\n", At[i][j]);	
	}
}
int count=0;
for (i=0;i<row;i++){
	for (j=0;j<column;j++){
		At[i][j]=-1*At[i][j];
		if(At[i][j]==matrix[i][j]){
		count=count+1;	
		}
		//printf("%d\n", At[i][j]);
	}
}
if(count==(row*column)){
	printf("this is a skew-symmetric matrix");
}
else {
	printf("this is not a skew-symmetric matrix");
}
  
}
 else {
	printf("skew-symmetric matrix of this matix doesnot exist");
}
}

