#include<stdio.h>

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
	else
	return 0;
}

main(){
	int x;
	x = unit_matrix();
	if (x==1){
		printf("Matrix is a unit/identity matrix!");
	}
	else if (x==0){
		printf("Matrix is not a unit/identity matrix!");
	}
}

