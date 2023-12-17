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
  char *buffer = NULL;
  size_t initL = 0;
  for (int i = 0; i < size; i++) {
    char *part= NULL;
    if (i != pos) {
      size_t partL = snprintf(NULL, 0, "%s\n", arr[i]);
      part = (char*) realloc(part, partL+1);
      sprintf(part, "%s\n", arr[i]);
    } else {
      size_t partL = snprintf(NULL, 0, "[[ %s ]]\n", arr[i]);
      part = (char*) realloc(part, partL+1);
      sprintf(part, "[[ %s ]]\n", arr[i]);
    }
    initL += strlen(part);
    buffer = (char*) realloc(buffer, initL+1);
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
      size_t len = snprintf(NULL, 0,"%d",mat[i][j]);
      char *part = (char*) malloc (len); // Part stores the text/num to be concatenated
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
