/* 
 * File:   binaryStringAdd.h
 * Author: haoruzhao
 *
 * Created on January 29, 2013, 11:41 PM
 */

#ifndef BINARYSTRINGADD_H
#define	BINARYSTRINGADD_H
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    Solution(){};
    string addBinary(string a, string b) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int sizeA = a.size();
        int sizeB = b.size();
        bool carry = false;
        int i;
        
        int size = sizeA >= sizeB ? (sizeA - sizeB) : ( sizeB - sizeA);
        int maxSize = sizeA >= sizeB ? (sizeA) : ( sizeB);
        string result;
        //string zeros(size, '0');
        string c_0(1,'0');
        string c_1(1,'1');
        
        if(sizeA > sizeB){
            b.insert(0,size, '0');
        }else if( sizeA < sizeB){
            a.insert(0,size, '0');
        }
        
        for(i = maxSize - 1; i >=0; --i ){
            if(carry){
                if(int(a[i]) + int(b[i]) == 96){
                    //result.insert(0, 1, '1');
                    b[i] = '1';
                    carry = false;
                }else if(int (a[i]) + int(b[i]) == 97){
                    //result.insert(0, c_0);
                    b[i] = '0';
                    carry = true;
                }else if(int (a[i]) + int(b[i]) == 98){
                    //result.insert(0, c_1);
                    b[i] = '1';
                    carry = true;
                } 
            }else{
                if(int (a[i]) + int(b[i]) == 96){ // 0 + 0
                    //result.insert(0, c_0);
                    b[i] = '0';
                    carry = false;
                }else if(int (a[i]) + int(b[i]) == 97){ // 1 + 0 or 0 + 1
                    //result.insert(0, c_1);
                    b[i] = '1';
                    carry = false;
                }else if(int (a[i]) + int(b[i]) == 98){ // 1 + 1
                    //result.insert(0, c_0);
                    b[i] = '0';
                    carry = true;
                } 
            }
        }
        if(carry){
            b.insert(0,c_1);
        }
        return b;
    }
};

#endif	/* BINARYSTRINGADD_H */

