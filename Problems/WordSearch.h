/* 
 * File:   WordSearch.h
 * Author: haoruzhao
 *
 * Created on January 22, 2013, 11:22 PM
 */

#ifndef WORDSEARCH_H
#define	WORDSEARCH_H

#include <vector>
#include <string>
using std::vector;
using std::string;

class Solution {
public:
   // Solution()
   // :k(0){
        
    //}
    bool Search(int i, int j, vector<vector<char> >& board, string word){
    
        //unsigned int N = board.size();
        //unsigned int M = board[0].size();
        if(k >= word.size()){
            return false;
        }
        if(board[i][j] != word[k]){
            k--;
            return false;
        }
        if(j+1 < M && board[i][j] == word[k]){
            k++;
            Search(i, j+1, board, word);
        }
            
        if(i+1 < N && board[i][j] == word[k]){
            k++;
            Search(i+1, j, board, word);
        }    
            
        if(i-1 >= 0 && board[i][j] == word[k]){
            k++;
            Search(i-1, j, board, word);
        }
            
        if(j-1 >= 0 && board[i][j] == word[k]){
            k++;
            Search(i, j-1, board, word);
        }
            
        if(k == length)
            return true;
        else{
            return false;
        }
            
    }
    
    bool exist(vector<vector<char> > &board, string word) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        N = board.size();
        M = board[0].size();
        unsigned int maxSize = N * M;
        length = word.length();
        k = 0;
        if( word.length() > maxSize ){
            return false;
        }
        unsigned int i, j;
        
       // k = 0;
        
        for(i = 0; i < N; ++i){
            for(j = 0; j < M; ++j){
                
                if( Search(i, j, board, word) ){
                    return true;
                }
            }
        }
        
        return false;
        
    }
private:
    int k;
    unsigned int N;
    unsigned int M;
    unsigned int length;
};

#endif	/* WORDSEARCH_H */

