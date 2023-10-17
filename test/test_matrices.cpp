#include "gtest/gtest.h"
#include <gmock/gmock.h>
#include "matrices.cpp"
#include "vector"
using namespace std;

// Define your test cases using TEST() and ASSERT_*() macros
// TEST(MatricesTest, upperTriangular_Regular) {
  // vector <vector<int>> up3x3 = {
      // {1, 2, 3},
      // {0, 4, 5},
      // {0, 0, 6}
  // };
  // vector <vector <int >> up4x4 = {
      // {1, 2, 3, 4},
      // {0, 5, 6, 7},
      // {0, 0, 8, 9},
      // {0, 0, 0, 10}
  // };
  // vector <vector <int>> up5x5 = {
      // {1, 2, 3, 4, 5},
      // {0, 6, 7, 8, 9},
      // {0, 0, 10, 11, 12},
      // {0, 0, 0, 13, 14},
      // {0, 0, 0, 0, 15}
  // };
//
  // EXPECT_THAT(u_tm(up3x3), 1);
  // EXPECT_THAT(u_tm(up4x4), 1);
  // EXPECT_THAT(u_tm(up5x5), 1);
// }
//
// TEST(MatricesTest, upperTriangular_CgreaterR) {
// vector <vector<int>> up3x4 ={
   // {1, 2, 3, 4},
  // {0, 5, 6, 7},
  // {0, 0, 8, 9}
// };
//
// vector <vector <int >> up2x3 =  {
   // {1, 2, 3},
  // {0, 4, 5}
// };
//
// vector <vector <int>> up4x5 = {
  // {1, 2, 3, 4, 5},
  // {0, 6, 7, 8, 9},
  // {0, 0, 10, 11, 12},
  // {0, 0, 0, 13, 14}
// };
//
  // EXPECT_THAT(u_tm(up3x4), 1);
  // EXPECT_THAT(u_tm(up2x3), 1);
  // EXPECT_THAT(u_tm(up4x5), 1);
// }
//
// TEST (MatricesTest, DozenVariety){
//
  // vector<vector<int>> matrix1 = {
        // {1, 2, 3},
        // {0, 4, 5},
        // {0, 0, 6}
    // };
//
    // vector<vector<int>> matrix2 = {
        // {7, 8, 9, 10},
        // {0, 11, 12, 13},
        // {0, 0, 14, 15},
        // {0, 0, 0, 16}
    // };
//
    // vector<vector<int>> matrix3 = {
        // {1, 2, 3, 4, 5},
        // {0, 6, 7, 8, 9},
        // {0, 0, 10, 11, 12},
        // {0, 0, 0, 13, 14},
        // {0, 0, 0, 0, 15}
    // };
//
    // vector<vector<int>> matrix4 = {
        // {1, 2},
        // {0, 3},
    // };
//
    // vector<vector<int>> matrix5 = {
        // {4, 5, 6},
        // {0, 7, 8},
        // {0, 0, 9}
    // };
//
    // vector<vector<int>> matrix6 = {
        // {10, 11, 12},
        // {0, 13, 14},
        // {0, 0, 15}
    // };
//
    // vector<vector<int>> matrix7 = {
        // {1, 2, 3, 4, 5, 6},
        // {0, 7, 8, 9, 10, 11},
        // {0, 0, 12, 13, 14, 15},
        // {0, 0, 0, 16, 17, 18},
        // {0, 0, 0, 0, 19, 20},
        // {0, 0, 0, 0, 0, 21}
    // };
//
    // vector<vector<int>> matrix8 = {
        // {1}
    // };
//
    // vector<vector<int>> matrix9 = {
        // {0}
    // };
//
    // vector<vector<int>> matrix10 = {}; // THIS IS A NULL MATRIX
//
    // vector<vector<int>> matrix11 = {
        // {1, 2, 3},
        // {0, 4, 5},
        // {0, 0, 0}
    // };
//
    // vector<vector<int>> matrix12 = {
        // {1, 2, 3},
        // {0, 0, 5},
        // {0, 0, 0}
    // };
//
  // EXPECT_THAT(u_tm(matrix1), 1);
  // EXPECT_THAT(u_tm(matrix2), 1);
  // EXPECT_THAT(u_tm(matrix3), 1);
  // EXPECT_THAT(u_tm(matrix4), 1);
  // EXPECT_THAT(u_tm(matrix5), 1);
  // EXPECT_THAT(u_tm(matrix6), 1);
  // EXPECT_THAT(u_tm(matrix7), 1);
  // EXPECT_THAT(u_tm(matrix8), 1);
  // EXPECT_THAT(u_tm(matrix9), 1);
  // EXPECT_THAT(u_tm(matrix10), 0);
  // EXPECT_THAT(u_tm(matrix11), 1);
  // EXPECT_THAT(u_tm(matrix12), 1);
// }
// Define more test cases for other functions

// TEST (lowerTriangle, DozenUniq){
 // vector<vector<int>> matrix1 = {
        // {1, 0, 0},
        // {2, 3, 0},
        // {4, 5, 6}
    // };
//
    // vector<vector<int>> matrix2 = {
        // {7, 0, 0, 0},
        // {8, 9, 0, 0},
        // {10, 11, 12, 0},
        // {13, 14, 15, 16}
    // };
//
    // vector<vector<int>> matrix3 = {
        // {1, 0, 0, 0, 0},
        // {2, 3, 0, 0, 0},
        // {4, 5, 6, 0, 0},
        // {7, 8, 9, 10, 0},
        // {11, 12, 13, 14, 15}
    // };
//
    // vector<vector<int>> matrix4 = {
        // {1, 0},
        // {2, 3},
    // };
//
    // vector<vector<int>> matrix5 = {
        // {4, 0, 0},
        // {5, 6, 0},
        // {7, 8, 9}
    // };
//
    // vector<vector<int>> matrix6 = {
        // {10, 0, 0},
        // {11, 12, 0},
        // {13, 14, 15}
    // };
//
    // vector<vector<int>> matrix7 = {
        // {1, 0, 0, 0, 0, 0},
        // {2, 3, 0, 0, 0, 0},
        // {4, 5, 6, 0, 0, 0},
        // {7, 8, 9, 10, 0, 0},
        // {11, 12, 13, 14, 15, 0},
        // {16, 17, 18, 19, 20, 21}
    // };
//
    // vector<vector<int>> matrix8 = {
        // {1}
    // };
//
    // vector<vector<int>> matrix9 = {
        // {0}
    // };
//
    // vector<vector<int>> matrix10 = {};
//
    // vector<vector<int>> matrix11 = {
        // {0, 0, 0},
        // {1, 0, 0},
        // {2, 3, 0}
    // };
//
    // vector<vector<int>> matrix12 = {
        // {0, 0, 0},
        // {0, 0, 0},
        // {1, 0, 0}
    // };
//
//
  // EXPECT_THAT(l_tm(matrix1), 1);
  // EXPECT_THAT(l_tm(matrix2), 1);
  // EXPECT_THAT(l_tm(matrix3), 1);
  // EXPECT_THAT(l_tm(matrix4), 1);
  // EXPECT_THAT(l_tm(matrix5), 1);
  // EXPECT_THAT(l_tm(matrix6), 1);
  // EXPECT_THAT(l_tm(matrix7), 1);
  // EXPECT_THAT(l_tm(matrix8), 1);
  // EXPECT_THAT(l_tm(matrix9), 1);
  // EXPECT_THAT(l_tm(matrix10), 0);
  // EXPECT_THAT(l_tm(matrix11), 1);
  // EXPECT_THAT(l_tm(matrix12), 1);
//
// }

TEST (Matrix, diagonalTrue){
vector<vector<int>> m1 = {{4, 0}, {0, 7}};
vector<vector<int>> m2 = {{3, 0, 0}, {0, 5, 0}, {0, 0, 9}};
vector<vector<int>> m3 = {{1, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 6, 0}, {0, 0, 0, 2}};
vector<vector<int>> m4 = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
vector<vector<int>> m5 = {{8, 0}, {0, 0}};
vector<vector<int>> m6 = {{5}};


  EXPECT_THAT(diag(m1), true);
  EXPECT_THAT(diag(m2), true);
  EXPECT_THAT(diag(m3), true);
  EXPECT_THAT(diag(m4), true);
  EXPECT_THAT(diag(m5), true);
  EXPECT_THAT(diag(m5), true);


}

TEST (Matrix, diagonalFalse){
vector<vector<int>> m7 = {{2, 3}, {0, 4}};
vector<vector<int>> m8 = {{1, 0, 0}, {4, 3, 0}, {0, 0, 2}};
vector<vector<int>> m9 = {{1, 0, 0, 0}, {0, 2, 0, 0}, {0, 0, 3, 0}, {0, 0, 0, 4}};
vector<vector<int>> m10 = {{2, 0}, {5, 3}};
vector<vector<int>> m11 = {{2, 1, 0}, {0, 3, 0}, {0, 0, 4}};
vector<vector<int>> m12 = {{1, 0, 0}, {0, 2, 0}, {0, 0, 0}};


  EXPECT_THAT(diag(m7), false);
  EXPECT_THAT(diag(m8), false);
  EXPECT_THAT(diag(m9), true);
  EXPECT_THAT(diag(m10), false);
  EXPECT_THAT(diag(m11), false);
  EXPECT_THAT(diag(m12), true);



}

int main(int argc, char* argv[]){
  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}

