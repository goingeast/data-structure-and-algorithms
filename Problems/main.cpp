/* 
 * File:   main.cpp
 * Author: haoruzhao
 *
 * Created on January 22, 2013, 9:20 PM
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include "WordSearch.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
     
    vector< vector<char> > board;
    vector<char> row1;
    row1.push_back('A');
    row1.push_back('B');
    row1.push_back('C');
    row1.push_back('E');
    
    vector<char> row2;
    row2.push_back('S');
    row2.push_back('F');
    row2.push_back('C');
    row2.push_back('S');
    
    vector<char> row3;
    row3.push_back('A');
    row3.push_back('D');
    row3.push_back('E');
    row3.push_back('E');
    
    board.push_back(row1);
    board.push_back(row2);
    board.push_back(row3);
    string word = "ABCSE";
    //cout << board[2][3];
    Solution test;
    if(test.exist(board,word)){
      cout << "True";   
    }else{
        cout << "False";
    }
    
    return 0;
}

