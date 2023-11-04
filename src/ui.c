#include <stdio.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <stdlib.h>
// #include <windows.h>

// Linux
int getWidthLinux(){
  struct winsize w;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

  return w.ws_col;
}

// Windows
// int getWidthWin(){
   // CONSOLE_SCREEN_BUFFER_INFO csbi;
    // GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
//
    // int consoleWidth = csbi.dwSize.X;
    // return consoleWidth;
// }


void printCenteredText(const char *text, int totalWidth) {
    const char *delim = "\n";  // Split text into lines by newline character
    char *token, *next;
    char *textCopy = strdup(text);  // Make a copy to avoid modifying the original

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

    free(textCopy);  // Free the memory allocated by strdup
}


void mainM()
{
  const char *menu = "1.Arithmetic\n2.Quadratic&Cubic\n3.Logarithmic\n4.Trigonometric\n5.Matrices\n6.Exit\n";
  int width = getWidthLinux();
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


void printMatr(int r, int c, int mat[3][3], int px, int py){

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (i == px && j == py){
        printf("[%d] ", mat[i][j]);
      } else if (j == 0){
      printf("[%d ", mat[i][j]);
      } else if(j == (c-1)){
      printf("%d]\n", mat[i][j]);
      } else {
      printf("_ ");
      }
    }
  }
}

int main(int argc, char const* argv[])
{
  int mat[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
  printMatr(3,3, mat, 1,1);
  // mainM();
  return 0;
}

