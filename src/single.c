#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef _WIN32
#include <windows.h>
#include <conio.h>
// Windows
int getWidth() {
  // CONSOLE_SCREEN_BUFFER_INFO is a Struct that stores info abt.. the screen 0_0
  CONSOLE_SCREEN_BUFFER_INFO csbi; // Makes a struct named csbi
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi); // Assigns it values of the console
  
  // Now that it is assigned, It can be accessed using this
  int consoleWidth = csbi.dwSize.X;
  return consoleWidth;
}
int getHeight() {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  // Same thing as before, Except We find the Lines from Bottom to top
  int consoleHeight = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
  return consoleHeight;
}
void clearScreen(){
	system("cls");
}

#else

// Aap log linux istemal kro to smjhaunga

#include <sys/ioctl.h>
#include <unistd.h>
// Linux
int getWidth() {
  struct winsize w;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

  return w.ws_col;
}

int getHeight() {
  struct winsize w;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

  return w.ws_row;
}
void clearScreen(){
	system("clear");
}
#endif


void printCenteredText(const char *text) {
  clearScreen();
  int totalWidth = getWidth();
  // Vertical Centering
  int cnt = 0;
  for (int i = 0; i < strlen(text); i++) {
    if (text[i] == '\n') {
      cnt++;
    }
  }
  int vPads = (getHeight() - cnt) / 2;

  for (int i = 0; i < vPads; i++) {
    printf("\n");
  }

  const char *delim = "\n"; // Split text into lines by newline character
  char *token, *next;
  char *textCopy = strdup(text); // Make a copy to avoid modifying the original

  token = strtok_r(textCopy, delim, &next);
  while (token != NULL) {

    int textLength = strlen(token);
    if (textLength >= totalWidth) {
      // Text is longer than the available width, just print it as is
      printf("%s\n", token);
    } else {
      int padding = (totalWidth - textLength) / 2;

      // Print leading spaces
      for (int i = 0; i < padding; i++) {
        printf(" ");
      }

      // Print the text
      printf("%s\n", token);

    }
    token = strtok_r(NULL, delim, &next);
  }

  free(textCopy); // Free the memory allocated by strdup
}


// Update Menu

void updateMenu(char arr[][100], int size, int pos) {
  char buffer[1000]="";
  for (int i = 0; i < size; i++) {
    char part[100]="";
    if (i != pos) {
      sprintf(part, "%s\n", arr[i]);
    } else {
      sprintf(part, "[[ %s ]]\n", arr[i]);
    }
    strncat(buffer, part, strlen(part));
  }
  printCenteredText(buffer);
}

// Select Menu

int selectMenu(char arr[][100], int size) {
    #ifdef _WIN32
    #else
    system("stty -icanon");
    #endif

    clearScreen();
    updateMenu(arr, size, 0);

    char ch = 0;
    int pos = 0;
    
    // Windows Specific, _getch() is used to get the input
    #ifdef _WIN32
    _getch();
        
    while ((ch = _getch()) != 13) {
        if (pos > 0 && ch == 'w') {
      // Move up
            pos--;
        } else if (pos < size - 1 && ch == 's') {
      // Move down
            pos++;
        } else if (ch == 'q') {
      // Close
            pos = -1;
            break;
        }

        clearScreen();
        updateMenu(arr, size, pos);
    }

    #else
    getchar();
    
    while ((ch = getchar()) != '\n') {
        if (pos > 0 && ch == 'w') {
            pos--;
        } else if (pos < size - 1 && ch == 's') {
            pos++;
        } else if (ch == 'q') {
            pos = -1;
            break;
        }

        clearScreen();
        updateMenu(arr, size, pos);
    }

    #endif

    #ifdef _WIN32
    #else
    system("stty icanon");
    #endif

    return pos + 1;
}
// This function would later serve as the main root from which all child menus spawn

// Prints the Matrix
void printMatr(int r, int c, int mat[r][c], int px, int py) { // Px and Py indicate where [-] should be
  clearScreen();
  int size = r * c * 4 + 1; // Calculates the Size
  char matrix[size]; // Making the string to store the matrix in a string form
  matrix[0] = '\0'; // Makes sure it is empty

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {

      char part[100] = ""; // Part stores the text/num to be concatenated
      if (i == px && j == py) {
        strcpy(part, "[-] ");
        // printf("[-] ");
      } else if (i < px || (i == px && j <= py)) {
        // printf("%d ", mat[i][j]);
        sprintf(part, "%d ", mat[i][j]); // The number is stored in a string form 
        // strcat(part, num);
      } else {
        // printf(" - ");
        strcpy(part, "- ");
      }
      if (j == (c - 1)) {
        strcat(part, "\n");
      }
      strcat(matrix, part); // The Part is concatenated into the matrix
    }
  }
  printCenteredText(matrix);
}

void inputMatric(int r, int c, int mat[r][c]) {

  // Inputs the matrix, Printing eachtime
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      printMatr(r, c, mat, i, j);
      scanf("%d", &mat[i][j]);
    }
  }
  printMatr(r, c, mat, r, c);
}

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


int det_2x2()
{
	int det,ad,bc;
  int a[2][2];
  inputMatric(2,2,a);
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


void adj_3x3() {
  int i, j, k, l, t;
  int a[3][3];
  inputMatric(3, 3, a);
  // Input the matrix
  // printf("Enter the elements of the 3x3 matrix:\n");
  // for (i = 0; i < 3; i++) {
  //   for (j = 0; j < 3; j++) {
  //     scanf("%d", &a[i][j]);
  //   }
  // }

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

  // printf("Adjoint matrix:\n");
  // for (i = 0; i < 3; i++) {
  //   for (j = 0; j < 3; j++) {
  //     printf("%d ", det[j][i]);
  //   }
  //   printf("\n");
  // }
  printMatr(3, 3 , det, 3, 3);
}
void adj_2x2(){
	int i,j;
	int a[2][2];
	// printf("Enter the elements of the 2x2 matrix:\n");
  // for (i = 0; i < 2; i++) {
  //   for (j = 0; j < 2; j++) {
  //     scanf("%d", &a[i][j]);
  //   }
  // }
  inputMatric(2, 2, a);
  int adj[2][2];
  adj[0][0]=a[1][1];
  adj[0][1]=-a[0][1];
  adj[1][0]=-a[1][0];
  adj[1][1]=a[0][0];
	// for (i = 0; i < 2; i++) {
 //    for (j = 0; j < 2; j++) {
 //      printf("%d ", adj[i][j]);
 //    }
 //    printf("\n");
 //  }
printMatr(2, 2 , adj, 2, 2); 
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

void write_to_file(char *fname, int r, int c, int a[r][c]){
  FILE *fptr;
  fptr = fopen(fname,"a");
  
  fprintf(fptr, "[ %d %d\n", r, c);
  for (int i = 0; i < r ; i++) {
    for (int j = 0 ; j < c ; j++) {
      fprintf(fptr,"%d ",a[i][j]);

      if(j < c - 1){
        fprintf(fptr," ");
      }
    }
    fprintf(fptr, "\n");
  }
  fprintf(fptr, "]\n");
  fclose(fptr);
}

int** read_from_file(char *fname, int x, int **ans, int *r, int *c){
  FILE *fptr;
  fptr = fopen(fname,"r");
  char buffer[50];
  char ch;
  while (x!=0) { 
    if ((ch = fgetc(fptr)) == '[') {
      x--;
    }
    }
  // int r, c;
    fscanf(fptr, "%d%d", r, c);
  ans = (int **)malloc(*r * sizeof(int *));
  for (int i = 0; i < *r; i++) {
    ans[i] = (int *)malloc(*c * sizeof(int));
  }
  // printf("r: %d c: %d\n", *r, *c);
  for (int i = 0; i < *r; i++) {
    for (int j = 0; j < *c; j++) {
      fscanf(fptr, "%d", &ans[i][j]);
      // printf("%d ",ans[i][j]);
    }
    // printf("\n");
  }
  fclose(fptr);
  return ans;
}


#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
// #include "headers/functions.h"
// #include "headers/ui.h"
// <<<<<<< Updated upstream
// =======

// #include <math.h>
// >>>>>>> Stashed changes

// <--------- Matrices Menu --------->

void detM(){
  char menuArr[4][100] = {"1. Determinant3x3","2. Determinant2x2","3. Adjoint3x3", "4. Adjoint2x2"};
  int n;
  n = selectMenu(menuArr,4);
  
  switch(n){
    case 1:
      det_3x3();
      break;
    case 2:
      det_2x2();
      break;
    case 3:
      adj_3x3();
      break;
    case 4:
      adj_2x2();
      break;
    default:
      printCenteredText("Invalid Input");
      break;
  }

}

void matM() {
  const char *menu =
      "1. Upper Triangular\n2. Lower Triangular\n3. Determinant\n4. "
      "Transpose\n5. Scalar Multiplication\n6. Unit Matrix\n7. Null Matrix\n8. "
      "Diagonal\n9. Idempotent\n10. Involuntary\n11. Nilpotent\n12. "
      "Symmetric\n13. Skewsymmetric\n";
  char menuArr[15][100] = {"1. Upper Triangular",
                           "2. Lower Triangular",
                           "3. Determinant/Adjoint",
                           "4. Transpose",
                           "5. Scalar Multiplication",
                           "6. Unit Matrix",
                           "7. Null Matrix",
                           "8. Diagonal",
                           "9. Idempotent",
                           "10. Involuntary",
                           "11. Nilpotent",
                           "12. Symmetric",
                           "13. Skewsymmetric",
                           "14. Addition",
                           "15. Subtraction"};
  // printCenteredText(menu);
  int n;
  n = selectMenu(menuArr, 15);
  // scanf("%d", &n);
  switch (n) {
  case 1:
    if (u_tm()) {
      printCenteredText("Is an upper triangular matrix");
    } else {
      printCenteredText("Is not an upper triangular matrix");
    }
    break;
  case 2:
    if (l_tm()) {
      printCenteredText("Is an lower triangular matrix");
    } else {
      printCenteredText("Is not an lower triangular matrix");
    }
    break;
  case 3:
    // Determinent
    // det_3x3();
    detM();
    break;
  case 4:
    transpose();

    break;
  case 5:
    scalar_multiplication();
    // Matrices
    break;
  case 6:
    // Exit
    if (unit_matrix()) {
      printCenteredText("It is Unit Matrix");
    } else {
      printCenteredText("It is not Unit Matrix or Input was incorrect");
    }
    break;
  case 7:
    if (null_matrix()) {
      printCenteredText("It is a null matrix");
    } else {
      printCenteredText("It is not a null matrix");
    }
    break;
  case 8:
    if (diag()) {
      printCenteredText("It is a diagonal matrix");
    } else {
      printCenteredText("It is not a diagonal matrix");
    };
    break;
  case 9:
    idemponent();
    break;
  case 10:
    invoulantry();
    break;
  case 11:
    nilponent();
    break;
  case 12:
    symmetric();
    break;
  case 13:
    skewsym();
    break;
  case 14:
    addM();
    break;
  case 15:
    subM();
    break;
  }
}


// <--------- Arithmetic Menu --------->

void arithM() {
  const char *menu = "1. Addition\n2. Subtraction\n3. Multiplication\n4. "
                     "Division\n5. Quadratic";
  char menuArr[][100] = {"1. Addition", "2. Subtraction", "3. Multiplication",
                         "4. Division", "5. Quadratic"};
  // printCenteredText(menu);
  int n = selectMenu(menuArr, 5);
  // scanf("%d", &n);
  switch (n) {
  case 1:
    add();
    break;
  case 2:
    sub();
    break;
  case 3:
    multiply();
    break;
  case 4:
    division();
    break;
  case 5:
    quad();
    break;
  }
}
// <<<<<<< Updated upstream

// <--------- Trigonometry Menu --------->

void trig() {

  char menuarr[][100] = {"1. Sin",         "2. Cos",         "3. Tan",
                         "4. Sec",         "5. Cosec",       "6. Cot",
                         "7. Sin inverse", "8. Cos inverse", "9. Cot inverse"};

  int n = selectMenu(menuarr, 9);

  switch (n) {
  case 1:
    sine();
    break;
  case 2:
    cosine();
    break;
  case 3:
    tangent();
    break;
  case 4:
    secant();
    break;
  case 5:
    cosecant();
    break;
  case 6:
    cotangent();
    break;
  case 7:
    asine();
    break;
  case 8:
    acosine();
    break;
  case 9:
    atangent();
    break;
  default:
    printCenteredText("invalid option");
    break;
  }
}

// <----- Log Menu ----->

void logM() {

  char menuarr[][100] = {"1. log", "2. ln"};

  int n = selectMenu(menuarr, 2);

  switch (n) {
  case 1:
    log_10();
    break;
  case 2:
    ln();
    break;
  default:
    printCenteredText("invalid option");
    break;
  }
}


// <------- Main Menu ------->

void mainM() {
  const char *asciiArt =
      "    ___  ___      _        _        _____       _            _       _  "
      "           \n"
      "    |  \\/  |     | |      (_)      /  __ \\     | |          | |     | "
      "|            \n"
      "    | .  . | __ _| |_ _ __ ___  __ | /  \\/ __ _| | ___ _   _| | __ _| "
      "|_ ___  _ __ \n"
      "    | |\\/| |/ _` | __| '__| \\ \\/ / | |    / _` | |/ __| | | | |/ _` "
      "| __/ _ \\| '__|\n"
      "    | |  | | (_| | |_| |  | |>  <  | \\__/\\ (_| | | (__| |_| | | (_| | "
      "|| (_) | |   \n"
      "    \\_|  |_|\\__,_|\\__|_|  |_/_/\\_\\  "
      "\\____/\\__,_|_|\\___|\\__,_|_|\\__,_|\\__\\___/|_|   \n";

  printCenteredText(asciiArt);
  system("sleep 1");
  const char *menu = "1.Arithmetic\n2.Logarithmic\n3."
                     "Trigonometric\n4.Matrices\n5.Exit\n";

  char menuArr[][100] = {"1. Arithmetic", "2. Logarithmic", "3. Trigonometric",
                         "4. Matrices", "5. Exit"};

  int n = selectMenu(menuArr, 5);
  switch (n) {
  case 1:
    // Arithmetic Menu
    arithM();
    break;
  case 2:
    // Logarithmic
    logM();
    break;
  case 3:
    // Trignometric
    trig();
    break;
  case 4:
    // Matrices
    matM();
    break;
  case 5:
  default:
    // Exit
    printf("Exiting...\n");
    break;
  }
}

int main() {
  clearScreen();
  mainM();
  return 0;
}
