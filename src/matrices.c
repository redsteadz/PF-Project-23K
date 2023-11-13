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
