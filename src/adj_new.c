 #include <stdio.h>

void adj_3x3() {
  int i, j, k, l, t;
  int a[3][3];
  
  // Input the matrix
  printf("Enter the elements of the 3x3 matrix:\n");
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      scanf("%d", &a[i][j]);
    }
  }

  int temp[2][2];
  int det[3][3];

  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      int x = 0, y = 0;
      // Create the submatrix without row i and column j
      for (k = 0; k < 3; k++) {
        for (l = 0; l < 3; l++) {
          if (k != i && l != j) {
            temp[x][y] = a[k][l];
            y = (y + 1) % 2;
            if (y == 0) {
              x++;
            }
          }
        }
      }

      // Calculate the determinant of the 2x2 submatrix
      t = (temp[0][0] * temp[1][1]) - (temp[0][1] * temp[1][0]);

      // Calculate the cofactor with alternating signs similar to odd even 
      det[i][j] = (i + j) % 2 == 0 ? t : -t;
    }
  }

  printf("Adjoint matrix:\n");
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      printf("%d ", det[j][i]);
    }
    printf("\n");
  }

  return 0;
}
void adj_2x2(){
	int i,j;
	int a[2][2];
	printf("Enter the elements of the 2x2 matrix:\n");
  for (i = 0; i < 2; i++) {
    for (j = 0; j < 2; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  int adj[2][2];
  adj[0][0]=a[1][1];
  adj[0][1]=-a[0][1];
  adj[1][0]=-a[1][0];
  adj[1][1]=a[0][0];
	for (i = 0; i < 2; i++) {
    for (j = 0; j < 2; j++) {
      printf("%d ", adj[i][j]);
    }
    printf("\n");
  }
 
	
}

 
