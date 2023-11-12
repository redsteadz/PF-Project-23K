#include<stdio.h>

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


main(){
	int x;
	x = null_matrix() ;
	if (x==0){
		printf("The above matrix is NOT a null matrix");
	}
	else if (x==1){
		printf("The above matrix is a null matrix!");
	}
}
