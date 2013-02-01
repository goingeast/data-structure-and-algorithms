/* 
 * File:   main.cpp
 * Author: haoruzhao
 *
 * Created on January 22, 2013, 9:20 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
#include "binaryStringAdd.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
     
//    vector< vector<char> > board;
//    vector<char> row1;
//    row1.push_back('A');
//    row1.push_back('B');
//    row1.push_back('C');
//    row1.push_back('E');
//    
//    vector<char> row2;
//    row2.push_back('S');
//    row2.push_back('F');
//    row2.push_back('C');
//    row2.push_back('S');
//    
//    vector<char> row3;
//    row3.push_back('A');
//    row3.push_back('D');
//    row3.push_back('E');
//    row3.push_back('E');
//    
//    board.push_back(row1);
//    board.push_back(row2);
//    board.push_back(row3);
//    string s = "ab";
    //int i;
//    int num = s.size();
//        vector<char> s1;
//        int i, mid;
//        for(i = 0; i < num; ++i){
//            if( (s[i] > '0' && s[i] < '9') || (s[i] > 'A' && s[i] < 'Z') || (s[i] > 'a' && s[i] < 'z') ){
//                s1.push_back( std::tolower(s[i]) );
//            }
//        }
//        
//        //cout << s1 << endl;
//        
//        if(s1.size() % 2){
//            mid = s1.size()/2;
//            for(i = 1; i <= mid; ++i){
//                if(s1[mid - i] != s1[mid + i]){
//                    cout << "false";
//                }
//            }
//            std::cout << "true";
//            
//        }else{
//            mid = s1.size()/2 ;
//            for(i = 0; i < mid; ++i ){
//                if(s1[mid - i - 1] != s1[mid + i]){
//                    cout << "false";
//                }
//            }
//            std::cout << "true";
//        }
//        
            
	
    //cout << board[2][3];
    Solution test;
    cout << test.addBinary("11", "11");
   
    
    return 0;
}

