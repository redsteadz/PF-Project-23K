#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef _WIN32
#include <windows.h>
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


// This function would later serve as the main root from which all child menus spawn
void mainM() {
  const char *menu = "1.Arithmetic\n2.Quadratic&Cubic\n3.Logarithmic\n4."
                     "Trigonometric\n5.Matrices\n6.Exit\n";

  printCenteredText(menu);
  int n;
  scanf("%d", &n);
  switch (n) {
  case 1:
    // Arithmetic Menu
    break;
  case 2:
    // Quadratic
    break;
  case 3:
    // Logarithmic
    break;
  case 4:
    // Trignometric
    break;
  case 5:
    // Matrices
    break;
  case 6:
  default:
    // Exit
    printf("Exiting...\n");
    break;
  }
}

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

void inputMatric() {
  int r, c;
  printf("Input Rows: ");
  scanf("%d", &r);
  printf("Input Column: ");
  scanf("%d", &c);
  int mat[r][c];

  // Inputs the matrix, Printing eachtime
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      printMatr(r, c, mat, i, j);
      scanf("%d", &mat[i][j]);
    }
  }
  printMatr(r, c, mat, r, c);
}

int main(int argc, char const *argv[]) {
  int mat[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  int mat2x2[2][2] = {{1, 2}, {3, 4}};
  printf("The Matrix calculator\n");

  int mat4x4[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 1, 1, 7}, {1, 3, 5, 6}};
  // printf("\n");
//  printMatr(3,3, mat, 3,3);
  // system("clear");
  printf("\n");
  // printMatr(4,4, mat4x4, 4,4);
   inputMatric();
  // printf("%d\n", getHeightLinux());
  return 0;
}
