#include <stdio.h>

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
}

main()
{
	transpose();
}



