#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef _WIN32
#include <windows.h>
  // Windows
  int getWidth(){
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);

  int consoleWidth = csbi.dwSize.X;
  return consoleWidth;
  }
  int getHeight(){
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);

  int consoleHeight = csbi.dwSize.Y;
  return consoleHeight;
  }
#else
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
#endif

// Windows
// int getWidthWin(){
// CONSOLE_SCREEN_BUFFER_INFO csbi;
// GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
//
// int consoleWidth = csbi.dwSize.X;
// return consoleWidth;
// }

void printCenteredText(const char *text, int totalWidth) {
  // Vertical Centering
  int cnt = 0;
  for (int i = 0; i < strlen(text); i++) {
    if (text[i] == '\n') {
      cnt++;
    }
  }
  int vPads = (getHeight() - cnt) / 2;
  // printf("Vertical Padding = %d \nLines= %d\nHeight = %d", vPads, cnt,
//   printf("%d ", getHeight());
//  for (int i = 0; i < vPads; i++) {
//    printf("\n");
//  }

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

void mainM() {
  const char *menu = "1.Arithmetic\n2.Quadratic&Cubic\n3.Logarithmic\n4."
                     "Trigonometric\n5.Matrices\n6.Exit\n";
  int width = getWidth();
  printCenteredText(menu, width);
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

void printMatr(int r, int c, int mat[4][4], int px, int py) {
  int size = r*c*4 + 1;
  char matrix[size];
  matrix[0]='\0';

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (i == px && j == py) {
        // printf("[%d] ", mat[i][j]);
        char part[4] = "[";
        char num[10000];
        sprintf(num, "%d", mat[i][j]);
        strcat(part, num);
        strcat(part, "]");
        strcat(matrix, part);
      } else if (j == 0) {
        // printf("[%d ", mat[i][j]);
        char part[4] = "[";
        char num[10000];
        sprintf(num, "%d", mat[i][j]);
        strcat(part, num);
        strcat(part, " ");
        strcat(matrix, part);
      } else if (j == (c - 1)) {
        // printf("%d]\n", mat[i][j]);
        char part[4] = " ";
        char num[10000];
        sprintf(num, "%d", mat[i][j]);
        strcat(part, num);
        strcat(part, "]");
        strcat(matrix, part);
        strcat(matrix, "\n");
      } else {
        // printf("_ ");
        char part[4] = " _ ";
        strcat(matrix, part); 
      }
      // printf("Working?\n");
    }
  }
  // puts(matrix);
  printCenteredText(matrix, getWidth()-1);
}

int main(int argc, char const *argv[]) {
  int mat[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
int mat2x2[2][2] = {
  {1, 2},
  {3, 4}
};
  printf("The Matrix calculator\n");
  // system("clear");
  int mat4x4[4][4] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 1, 1, 7},
    {1, 3, 5, 6}
  };
  // printf("\n");
  // printMatr(3,3, mat, 1,1);
  printf("\n");
  printMatr(4,4, mat4x4, 1,1);
  // mainM();
  // printf("%d\n", getHeightLinux());
  return 0;
}
