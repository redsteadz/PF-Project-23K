#include <vector>
#include <iostream>
using namespace std;

bool u_tm (vector<vector<int>> matrix){
    if (matrix.empty()) {return false;};
    int n = matrix.size();
    int c = matrix[0].size();

    for (int i = 1; i < n; i++){
        for (int j = 0; j < i && j < c; j++ ){
          if (matrix[i][j] != 0){
            return false;
          }
        }
    } 
    return true;
}

bool l_tm (vector <vector<int>> matrix){
  if (matrix.empty()) {return false;};
  int r = matrix.size();
  int c = matrix[0].size();

  for (int j = 1; j < c; j++){
    for (int i = (r-j); i < j && i < r; i++){
      if (matrix[i][j] != 0){
        cout << "The loc " << ' ' << i << ' ' << j;
        return false;
      }
    }
  }
  return true;
}

