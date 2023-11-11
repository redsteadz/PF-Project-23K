#include<stdio.h>

int det_2x2(int n,int a[n][n])
{
	int det,ad,bc;
	ad = a[0][0] * a[1][1];
	bc = a[0][1] * a[1][0];
	det = ad-bc;
	return det;
}

int det_3x3(int n,int a[n][n])
{
	int det;
	int term1,term2,term3;
	
	term1 = a[0][0] * (a[1][1]*a[2][2]-a[1][2]*a[2][1]);
	term2 = a[0][1] * (a[1][0]*a[2][2]-a[1][2]*a[2][0]);
	term3 = a[0][2] * (a[1][0]*a[2][1]-a[1][1]*a[2][0]);
	
	det = term1 - term2 + term3;
	return det;
	
}




main()
{
	int x,i,j;
	int n;
	printf("Enter the dimensions of the matrix (nxn): ");
	scanf("%d",&n);
	int a[n][n];
	for (i=0;i<n;i++)	{
		for (j=0;j<n;j++){
			printf("Enter element: ");
			scanf("%d",&a[i][j]);
		}
	}
	if (n==2){
		x = det_2x2(n,a);
	}
	else if (n==3){
		x = det_3x3(n,a);
	}
	printf("The determinant for this %dx%d matrix is: %d",n,n,x);
	
	
}


