#include<stdio.h>

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
}


main(){
	scalar_multiplication();
}




