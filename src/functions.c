/*
 *
 *@done Upper Triangle Matrix Identification
 *@done Lower Triangle Matrix Identification
 *@todo Hermitian Matrix Identification
 *@todo Skew-Hermitian Matrix Identification
 *
 * */

// Main functions file

#include "headers/ui.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
 * RAYYAN'S WORK
 */


int det_2x2(int n,int a[n][n])
{
	int det,ad,bc;
	ad = a[0][0] * a[1][1];
	bc = a[0][1] * a[1][0];
	det = ad-bc;
  char det_s[20];
  sprintf(det_s, "%d", det);
  printCenteredText(det_s);
	return det;
}

int det_3x3()
{
  int a[3][3];
  inputMatric(3,3,a);
  int det;
	int term1,term2,term3;
	
	term1 = a[0][0] * (a[1][1]*a[2][2]-a[1][2]*a[2][1]);
	term2 = a[0][1] * (a[1][0]*a[2][2]-a[1][2]*a[2][0]);
	term3 = a[0][2] * (a[1][0]*a[2][1]-a[1][1]*a[2][0]);
	
	det = term1 - term2 + term3;
  char det_s[20];
  sprintf(det_s, "%d", det);
  printCenteredText(det_s);
	return det;
	
}

int transpose() {
  int r, c, i, j;
  printf("Enter the number of rows: ");
  scanf("%d", &r);
  printf("Enter the number of columns: ");
  scanf("%d", &c);

  int a[r][c];
  inputMatric(r, c, a);
  int t_a[c][r];

  for (i = 0; i < r; i++) {
    for (j = 0; j < c; j++) {
      t_a[j][i] = a[i][j];
    }
  }

  printMatr(c, r, t_a, c, r);
  return 0;
}

int scalar_multiplication() {
  int r, c, i, j, x;
  printf("Enter the number of rows: ");
  scanf("%d", &r);
  printf("Enter the number of columns: ");
  scanf("%d", &c);
  int a[r][c];
  inputMatric(r, c, a);
  printf("Enter scalar to multiply: ");
  scanf("%d", &x);

  for (i = 0; i < r; i++) {
    for (j = 0; j < c; j++) {
      a[i][j] = x * a[i][j];
    }
  }
  printMatr(r, c, a, r, c);
  return 0;
}

int unit_matrix() {
  int r, c, i, j;
  printf("Enter the number of rows: ");
  scanf("%d", &r);
  printf("Enter the number of columns: ");
  scanf("%d", &c);
  if (r != c) {
    printf("Only enter a square matrix...");
    return (0);
  }

  int a[r][c];
  inputMatric(r, c, a);

  int sum = 0;
  for (i = 0; i < r; i++) {
    for (j = 0; j < c; j++) {
      if (i == j) {
        if (a[i][j] == 1) {
          sum++;
        }
      }
    }
  }

  if (sum == r) {
    return 1;
  }
  return 0;
}

int null_matrix() {
  int r, c, i, j;
  printf("Enter the number of rows: ");
  scanf("%d", &r);
  printf("Enter the number of columns: ");
  scanf("%d", &c);

  int a[r][c];
  inputMatric(r, c, a);

  for (i = 0; i < r; i++) {
    for (j = 0; j < c; j++) {
      if (a[i][j] != 0) {
        return 0;
      }
    }
  }
  return 1;
}

/*
 * HAMEES'S WORK
 */

bool u_tm() {
  int r, c;
  printf("Input Rows: ");
  scanf("%d", &r);
  printf("Input Columns: ");
  scanf("%d", &c);
  int matrix[r][c];
  inputMatric(r, c, matrix);

  if (r >= c) {
    int n = r;

    for (int i = 1; i < n; i++) {
      for (int j = 0; j < i && j < c; j++) {
        if (matrix[i][j] != 0) {
          return false;
        }
      }
    }
    return true;
  }

  return false;
}

bool l_tm() {
  int r, c;
  printf("Input Rows: ");
  scanf("%d", &r);
  printf("Input Columns: ");
  scanf("%d", &c);
  int matrix[r][c];

  inputMatric(r, c, matrix);
  for (int j = 1; j < c; j++) {
    for (int i = (r - j); i < j && i < r; i++) {
      if (matrix[i][j] != 0) {

        return false;
      }
    }
  }
  return true;
}

bool diag() {
  int r, c;
  printf("Input Rows: ");
  scanf("%d", &r);
  printf("Input Columns: ");
  scanf("%d", &c);
  int matrix[r][c];
  inputMatric(r, c, matrix);

  if (r == c) {
    for (int i = 1; i < r; i++) {
      for (int j = 0; j < i; j++) {
        if (matrix[i][j] == 0 && matrix[j][i] == 0) {
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

void addM(){
  int r, c;
  printCenteredText("Enter the number of rows:");
  scanf("%d", &r);
  printCenteredText("Enter the number of column:");
  scanf("%d", &c);
  int mat1[r][c];
  int mat2[r][c];
  inputMatric(r, c, mat1);
  inputMatric(r, c, mat2);

  for (int i = 0; i < r; i++){
    for (int j = 0 ; j < c ; j++) {
      mat1[i][j] += mat2[i][j];
    }
  }
  printMatr(r, c, mat1, r, c);
}


void subM(){
  int r, c;
  printCenteredText("Enter the number of rows:");
  scanf("%d", &r);
  printCenteredText("Enter the number of column:");
  scanf("%d", &c);
  int mat1[r][c];
  int mat2[r][c];
  inputMatric(r, c, mat1);
  inputMatric(r, c, mat2);

  for (int i = 0; i < r; i++){
    for (int j = 0 ; j < c ; j++) {
      mat1[i][j] -= mat2[i][j];
    }
  }
  printMatr(r, c, mat1, r, c);
}

// HUZAILA'S WORK:
//trigonometric functions:
void sine(){
	float a;	
	printCenteredText("enter the value of a:");
	scanf("%f", &a );
	float ans;
	ans=sin(a);
	char output[50];
	printf("ans: %f", ans);
	sprintf(output,"%f", ans);
	printCenteredText(output);
}
void cosine(){
	float a;	
	printCenteredText("enter the value of a:");
	scanf("%f", &a);
	float ans;
	ans=cos(a);
	char output[50];
	sprintf(output,"%f", ans);
	printCenteredText(output);
}
void tangent(){
	float a;	
	printCenteredText("enter the value of a:");
	scanf("%f", &a );
	float ans;
	ans=tan(a);
	char output[50];
	sprintf(output,"%f", ans);
	printCenteredText(output);
}
void secant(){
	float a;	
	printCenteredText("enter the value of a:");
	scanf("%f", &a );
	float ans;
	ans=cos(a);
	ans=1/ans;	
	char output[50];
	sprintf(output,"%f", ans);
	printCenteredText(output);
}
void cosecant(){
	float a;	
	printCenteredText("enter the value of a:");
	scanf("%f", &a );
	float ans;
	ans=sin(a);
	ans=1/ans;
    char output[50];
	sprintf(output,"%f", ans);
	printCenteredText(output);
}
void cotangent(){
	float a;
	printCenteredText("enter the value of a:");
	scanf("%f", &a );
	float ans;
	ans=tan(a);
	ans=1/ans;
	char output[50];
	sprintf(output,"%f", ans);
	printCenteredText(output);
}
void asine(){
	float a;
	printCenteredText("enter the value of a:");
	scanf("%f", &a );
	float ans;
	ans=asin(a);
	char output[50];
	sprintf(output,"%f", ans);
	printCenteredText(output);
}
void acosine(){
	float a;
	printCenteredText("enter the value of a:");
	scanf("%f", &a );
	float ans;
	ans=acos(a);
	char output[50];
	sprintf(output,"%f", ans);
	printCenteredText(output);
}
void atangent(){
	float a;	
	printCenteredText("enter the value of a:");
	scanf("%f", &a );
	float ans;
	ans=atan(a);
	char output[50];
	sprintf(output,"%f", ans);
	printCenteredText(output);
}
//logarithmic functions:
void ln(){
	float a;
	printCenteredText("enter the value of a:");
	printf("enter the value of a:");
	scanf("%f", &a );
	float ans;
	ans=log(a);
	char output[50];
	sprintf(output,"%f", ans);
	printCenteredText(output);
}

void log_10(){
	float a;
	printCenteredText("enter the value of a:");
	scanf("%f", &a );
	float ans;
	ans=log10(a);
	char output[50];
	sprintf(output,"%f", ans);
	printCenteredText(output);
}


// 1.idemponent:
void idemponent() {
  // modifies code for idemponent.!!
  int row = 0, column = 0;
  printf("enter number of rows=");
  scanf("%d", &row);
  printf("enter number of column=");
  scanf("%d", &column);

  if (row == column) {
    int matrix[row][column];
    inputMatric(row, column, matrix);

    int mult[row][column];
    float sum = 0;
    int n = 0, i, j;
    for (i = 0; i < row; i++) {
      for (j = 0; j < column; j++) {
        sum = 0;
        for (n = 0; n < row; n++) {
          sum = sum + (matrix[i][n] * matrix[n][j]);
          mult[i][j] = sum;
        }
        printf("%d\n", mult[i][j]);
      }
    }
    int count = 0;
    for (i = 0; i < row; i++) {
      for (j = 0; j < column; j++) {
        if (mult[i][j] == matrix[i][j]) {
          count = count + 1;
        }
      }
    }
    if (count == (row * column)) {
      printCenteredText("this is an idemponent matrix");
    } else {
      printCenteredText("this is not an idemponent matrix");
    }
  } else {
    printCenteredText("this doesnot satisfy the conditions for an idemponent matrix");
  }
}
// 2.involuntary:
void invoulantry() {
  int row = 0, column = 0;
  printf("enter number of rows=");
  scanf("%d", &row);
  printf("enter number of column=");
  scanf("%d", &column);

  if (row == column) {
    int matrix[row][column];
    inputMatric(row, column, matrix);

    int mult[row][column];
    float sum = 0;
    int n = 0, i, j;
    for (i = 0; i < row; i++) {
      for (j = 0; j < column; j++) {
        sum = 0;
        for (n = 0; n < row; n++) {
          sum = sum + (matrix[i][n] * matrix[n][j]);
          mult[i][j] = sum;
        }
        printf("%d\n", mult[i][j]);
      }
    }

    // cheching for involuntary matrix:

    int count = 0;
    for (i = 0; i < row; i++) {
      for (j = 0; j < column; j++) {
        if (i == j) {
          if (mult[i][j] == 1) {
            count = count + 1;
          }
        } else {
          if (mult[i][j] == 0) {
            count = count + 1;
          }
        }
      }
    }
    if (count == (row * column)) {
      printCenteredText("this is an invoulantry matrix");
    } else {
      printCenteredText("this is not an invoulantry matrix");
    }
  } else {
    printCenteredText("this doesnot satisfy the conditions for an invoulantry matrix");
  }
}
// 3.nilponent:
void nilponent() {
  int row = 0, column = 0;
  printf("enter number of rows=");
  scanf("%d", &row);
  printf("enter number of column=");
  scanf("%d", &column);
  if (row == column) {
    int matrix[row][column];
    int i = 0, j = 0;
    inputMatric(row, column, matrix);
    float mult[row][column];
    float sum = 0;
    int n = 0;
    for (i = 0; i < row; i++) {
      for (j = 0; j < column; j++) {
        sum = 0;
        for (n = 0; n < row; n++) {
          sum = sum + (matrix[i][n] * matrix[n][j]);
          mult[i][j] = sum;
        }
        // printf("%d\t", mult[i][j]);
      }
    }
    int times = row - 2;
    int k;
    for (k = 1; k <= times; k++) {
      for (i = 0; i < row; i++) {
        for (j = 0; j < column; j++) {
          sum = 0;
          for (n = 0; n < row; n++) {
            sum = sum + (mult[i][n] * matrix[n][j]);
            mult[i][j] = sum;
          }
          // printf("%d\n", mult[i][j]);
        }
      }
    }
    int count = 0;
    for (i = 0; i < row; i++) {
      for (j = 0; j < column; j++) {
        if (mult[i][j] == 0) {
          count = count + 1;
        }
      }
    }
    if (count == (row * column)) {
      printCenteredText("this is a nilponent matrix");
    } else {
      printCenteredText("this is a not nilponent matrix");
    }
  }

  else {
    printf("this doesnot satisfy the conditions for a nilponent matrix");
  }
}
// 4.symmetric:
void symmetric() {
  int row, column;
  printf("enter the number of rows=");
  scanf("%d", &row);
  printf("enter the number of columns=");
  scanf("%d", &column);

  if (row == column) {
    int matrix[row][column];
    int i, j;
    inputMatric(row, column, matrix);
    printf("\n");
    int At[row][column];
    int temp = 0;
    for (i = 0; i < row; i++) {
      for (j = 0; j < column; j++) {
        temp = matrix[j][i];
        At[i][j] = temp;
        // printf("%d\n", At[i][j]);
      }
    }
    int count = 0;
    for (i = 0; i < row; i++) {
      for (j = 0; j < column; j++) {
        if (At[i][j] == matrix[i][j]) {
          count = count + 1;
        }
      }
    }
    if (count == (row * column)) {
      printCenteredText("this is a symmetric matrix");
    } else {
      printCenteredText("this is not a symmetric matrix");
    }
  }

  else {
    printCenteredText("symmetric matrix of this matix doesnot exist");
  }
}
// 5.skew symmetric:
void skewsym() {
  int row, column;
  printf("enter the number of rows=");
  scanf("%d", &row);
  printf("enter the number of columns=");
  scanf("%d", &column);

  if (row == column) {
    int matrix[row][column];
    int i, j;
    inputMatric(row, column, matrix);
    int At[row][column];
    int temp = 0;
    for (i = 0; i < row; i++) {
      for (j = 0; j < column; j++) {
        temp = matrix[j][i];
        At[i][j] = temp;
        // printf("%d\n", At[i][j]);
      }
    }
    int count = 0;
    for (i = 0; i < row; i++) {
      for (j = 0; j < column; j++) {
        At[i][j] = -1 * At[i][j];
        if (At[i][j] == matrix[i][j]) {
          count = count + 1;
        }
        // printf("%d\n", At[i][j]);
      }
    }
    if (count == (row * column)) {
      printCenteredText("this is a skew-symmetric matrix");
    } else {
      printCenteredText("this is not a skew-symmetric matrix");
    }

  } else {
    printCenteredText("skew-symmetric matrix of this matix doesnot exist");
  }
}


// 002 Arithmetic

float add() {
  float a, b;
  float ans = 0;
  int n;
  printCenteredText("enter the number of values for which you have to perform this "
         "operation");
  scanf("%d", &n);
  int i = 0;
  if (n == 2) {
    printCenteredText("enter the first value=");
    scanf("%f", &a);
    printCenteredText("enter the second value=");
    scanf("%f", &b);
    ans = a + b;
  }

  else {
    printCenteredText("enter the first value=");
    scanf("%f", &a);
    ans = a;
    for (i = 1; i <= (n - 1); i++) {
      printCenteredText("enter the other number=");
      scanf("%f", &b);
      ans = ans + b;
    }
  }
  char buf[256];
  sprintf(buf, "%.1f", ans);
  printCenteredText(buf);
  return ans;
}
// subtraction
float sub() {
  float a, b;
  float ans = 0;
  int n;
  printCenteredText("enter the number of values for which you have to perform this "
         "operation");
  scanf("%d", &n);
  int i = 0;
  if (n == 2) {
    printCenteredText("enter the first value=");
    scanf("%f", &a);
    printCenteredText("enter the second value=");
    scanf("%f", &b);
    ans = a - b;
  }

  else {
    printCenteredText("enter the first value=");
    scanf("%f", &a);
    ans = a;
    for (i = 1; i <= (n - 1); i++) {
      printCenteredText("enter the other number=");
      scanf("%f", &b);
      ans = ans - b;
    }
  }
  char buf[256];
  sprintf(buf, "%.1f", ans);
  printCenteredText(buf);
  return ans;
}
// multipliction
float multiply() {
  float a, b;
  float ans = 0;
  int n;
  printCenteredText("enter the number of values for which you have to perform this "
         "operation");
  scanf("%d", &n);
  int i = 0;
  if (n == 2) {
    printCenteredText("enter the first value=");
    scanf("%f", &a);
    printCenteredText("enter the second value=");
    scanf("%f", &b);
    ans = a * b;
  }

  else {
    printCenteredText("enter the first value=");
    scanf("%f", &a);
    ans = a;
    for (i = 1; i <= (n - 1); i++) {
      printCenteredText("enter the other number=");
      scanf("%f", &b);
      ans = ans * b;
    }
  }
  char buf[256];
  sprintf(buf, "%.1f", ans);
  printCenteredText(buf);
  return ans;
}
// Division
float division() {
  float a, b;
  float ans = 0;
  int n;
  printCenteredText("enter the number of values for which you have to perform this "
         "operation");
  scanf("%d", &n);
  int i = 0;
  if (n == 2) {
    printCenteredText("enter the first value=");
    scanf("%f", &a);
    printCenteredText("enter the second value=");
    scanf("%f", &b);
    int i = 0;
    if (b == 0) {
      printCenteredText("invalid");
    } else {
      ans = a / b;
    }
  }

  else {
    printCenteredText("enter the first value=");
    scanf("%f", &a);
    ans = a;
    for (i = 1; i <= (n - 1); i++) {
      printCenteredText("enter the other number=");
      scanf("%f", &b);
      if (b == 0) {
        printCenteredText("invalid");
      } else {
        ans = ans / b;
      }
    }
  }
  char buf[256];
  sprintf(buf, "%.1f", ans);
  printCenteredText(buf);
  return ans;
}
// quadratic equation solving:
float quad() {
  float a, b, c;
  float x1, x2;
  float bsqr, root;
  printCenteredText("enter the value of a= ");
  scanf("%f", &a);
  printCenteredText("enter the value of b= ");
  scanf("%f", &b);
  printCenteredText("enter the value of c= ");
  scanf("%f", &c);
  bsqr = b * b;
  root = sqrt(bsqr - (4 * a * c));
  x1 = (-(b) - (root)) / (2 * a);
  x2 = (-(b) + (root)) / (2 * a);
  // printf("%f\n", x1);
  // printf("%f", x2);
  char buffer[256];
  sprintf(buffer, "%.1f, %.1f", x1, x2);
  printCenteredText(buffer);
  return 0;
}
