#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "headers/functions.h"
#include "headers/ui.h"

void matM() {

  // UpperTriangular
  // LowerTriangular
  // Determinent
  // transpose
  // scalar_multiplication
  // unit_matrix
  // null_matrix
  // UpperTriangular
  // LowerTriangular
  // Diagonal
  // Idempotent
  // Involantry
  // NilPonent
  // Symmetric
  // Skewsym
  const char *menu =
      "1. Upper Triangular\n2. Lower Triangular\n3. Determinant\n4. "
      "Transpose\n5. Scalar Multiplication\n6. Unit Matrix\n7. Null Matrix\n8. "
      "Diagonal\n9. Idempotent\n10. Involuntary\n11. Nilpotent\n12. "
      "Symmetric\n13. Skewsymmetric\n";
  char menuArr[15][100] = {"1. Upper Triangular",
                           "2. Lower Triangular",
                           "3. Determinant",
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
      printCenteredText("TRUE");
    } else {
      printCenteredText("FALSE");
    }
    break;
  case 2:
    if (l_tm()) {
      printCenteredText("TRUE");
    } else {
      printCenteredText("FALSE");
    }
    break;
  case 3:
    // Determinent
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
    // Determinent
    multiply();
    break;
  case 4:
    division();
    break;
  case 5:
    quad();
    // Matrices
    break;
  }
}
void trig() {

  char menuarr[][100] = {"1. Sin",         "2. Cos",         "3. Tan",
                         "4. Sec",         "5. Cosec",       "6. Cot",
                         "7. Sin inverse", "8. Cos inverse", "9. Cot inverse"};

  // printcenteredtext(menu);

  int n = selectMenu(menuarr, 9);
  // scanf("%d", &n);

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

void logM() {

  char menuarr[][100] = {"1. log", "2. ln"};

  // printcenteredtext(menu);

  int n = selectMenu(menuarr, 2);
  // scanf("%d", &n);

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

  // printCenteredText(menu);
  int n = selectMenu(menuArr, 5);
  // scanf("%d", &n);
  switch (n) {
  case 1:
    // Arithmetic Menu
    arithM();
    break;
  case 2:
    // Logarithmic
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
