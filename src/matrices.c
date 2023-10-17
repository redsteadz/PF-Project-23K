/*
 *
 *@done Upper Triangle Matrix Identification
 *@done Lower Triangle Matrix Identification
 *@todo Hermitian Matrix Identification
 *@todo Skew-Hermitian Matrix Identification
 *
 * */

#include <stdbool.h>
#include "headers/matrices.h"

bool u_tm (int r, int c, int matrix[r][c]){

  if (r >= c){
    int n = r;

    for (int i = 1; i < n; i++){
        for (int j = 0; j < i && j < c; j++ ){
          if (matrix[i][j] != 0){
            return false;
          }
        }
    } 
    return true;
  }
  
  return false;
}

bool l_tm (int r, int c, int matrix[r][c]){

  for (int j = 1; j < c; j++){
    for (int i = (r-j); i < j && i < r; i++){
      if (matrix[i][j] != 0){

        return false;
      }
    }
  }
  return true;
}

bool diag (int r, int c, int matrix[r][c]){
  if (r == c){
    for (int i = 1; i < r; i++){
      for (int j = 0; j < i; j++){
        if (matrix[i][j] == 0 && matrix[j][i] == 0){
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
