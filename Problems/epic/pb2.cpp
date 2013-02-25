// You are given a grid of numbers. A snake sequence is made up of adjacent numbers
// such that for each number, the number on the right or the number below it is +1 
// or -1 its value. For example,

// 1 3 2  6  8
//-9 7 1 -1  2
// 1 5 0  1  9
// In this grid, (3, 2, 1, 0, 1) is a snake sequence.
// Given a grid, find the longest snake sequences and their lengths 
// (so there can be multiple snake sequences with the maximum length).

// dp solution
#include<iostream>
#include<cstdlib>
using std::cout;
using std::endl;
int main(void){
    int array[3][5]={ {4, 3, 2, 6, 8},
                   {-9, 7, 1, 0, 2},
                   {1, 5, 0, 1, 9}};
    int dp[3][5] = { {1, 1, 1, 1, 1},
                  {1, 1, 1, 1, 1},
                  {1, 1, 1, 1, 1}};
    int  n = sizeof(array)/sizeof(array[0]);
    int  m = sizeof(array[0])/sizeof(int);
    // dynamic prgramming backtrace
    for(int i = n - 1; i >= 0; --i)
        for(int j = m - 1; j >= 0; --j){
            if( (j + 1 < m) && (abs(array[i][j] - array[i][j + 1]) == 1) ){
                dp[i][j] = dp[i][j] > dp[i][j+1] ? dp[i][j] : dp[i][j+1] + 1;
            }
            if((i + 1 < n) && (abs(array[i][j] - array[i + 1][j]) == 1)){
                dp[i][j] = dp[i][j] > dp[i + 1][j] ? dp[i][j] : dp[i + 1][j] + 1;
            }
        }

   for(int i = 0; i < n; ++i){   
       for(int j = 0; j < m; ++j){
            cout << dp[i][j]<< ' ';
       }
      cout << endl;
    }
}
