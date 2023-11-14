#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "headers/matrices.h"
#include "headers/ui.h"

void matM() {

  const char *menu = "1.UpperTriangular\n2.LowerTriangular\n3.Transpose\n4.ScalarMatrix\n5.UnitMatrixCheck";
  printCenteredText(menu);
  int n;
  scanf("%d", &n);
  switch (n) {
  case 1:
    if(u_tm()){
    printCenteredText("TRUE");}
    else{
        printCenteredText("FALSE");
      }
    break;
  case 2:
    if(l_tm()){
    printCenteredText("TRUE");}
    else{
        printCenteredText("FALSE");
      }
    break;
  case 3:
    transpose();
    break;
  case 4:
    scalar_multiplication();
    break;
  case 5:
    if(unit_matrix()){
        printCenteredText("It is Unit Matrix");
    } else {
        printCenteredText("It is not Unit Matrix or Input was incorrect");
      }
    // Matrices
    break;
  case 6:
    // Exit
    if(null_matrix()){
        printCenteredText("It is a null matrix");
      } else {
        printCenteredText("It is not a null matrix");
      }
    break;
  }
}
void mainM() {
const char* asciiArt = 
"    ___  ___      _        _        _____       _            _       _             \n"
"    |  \\/  |     | |      (_)      /  __ \\     | |          | |     | |            \n"
"    | .  . | __ _| |_ _ __ ___  __ | /  \\/ __ _| | ___ _   _| | __ _| |_ ___  _ __ \n"
"    | |\\/| |/ _` | __| '__| \\ \\/ / | |    / _` | |/ __| | | | |/ _` | __/ _ \\| '__|\n"
"    | |  | | (_| | |_| |  | |>  <  | \\__/\\ (_| | | (__| |_| | | (_| | || (_) | |   \n"
"    \\_|  |_|\\__,_|\\__|_|  |_/_/\\_\\  \\____/\\__,_|_|\\___|\\__,_|_|\\__,_|\\__\\___/|_|   \n";

  printCenteredText(asciiArt);
  system("sleep 1");
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
    matM();
    break;
  case 6:
  default:
    // Exit
    printf("Exiting...\n");
    break;
  }
}

int main(){
  clearScreen();
  mainM();
  return 0;
}
