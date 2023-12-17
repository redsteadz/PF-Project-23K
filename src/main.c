#include <stdbool.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "headers/functions.h"
#include "headers/ui.h"

// <<<<<<< Updated upstream
// =======

// #include <math.h>
// >>>>>>> Stashed changes

// <--------- Matrices Menu --------->

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

void crossPlatformSleep(int seconds) {
#ifdef _WIN32
    // Windows
    Sleep(seconds * 1000);
#else
    // Linux and other Unix-like systems
    sleep(seconds);
#endif
}

void detM() {
  char menuArr[4][100] = {"1. Determinant3x3", "2. Determinant2x2",
                          "3. Adjoint3x3", "4. Adjoint2x2"};
  int n;
  n = selectMenu(menuArr, 4);

  switch (n) {
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
  crossPlatformSleep(2);
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
  crossPlatformSleep(2);
}

// <--------- Arithmetic Menu --------->

void arithM() {

  char menuArr[][100] = {"1. Expression Eval", "2. Quadratic"};
  // printCenteredText(menu);
  int n = selectMenu(menuArr, 2);
  // scanf("%d", &n);
  switch (n) {
  case 1:
    processCalc();
    break;
  case 2:
    quad();
    break;
  }
  crossPlatformSleep(2);
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
  crossPlatformSleep(2);
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
  crossPlatformSleep(2);
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
  crossPlatformSleep(2);
  const char *menu = "1.Arithmetic\n2.Logarithmic\n3."
                     "Trigonometric\n4.Matrices\n5.Exit\n";

  char menuArr[][100] = {"1. Arithmetic", "2. Logarithmic", "3. Trigonometric",
                         "4. Matrices", "5. Exit"};

  int cnt = 1;
  while (cnt) {
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
      cnt = 0;
      printf("Exiting...\n");
      break;
    }

  }
}

int main() {
  clearScreen();
  mainM();
  return 0;
}
