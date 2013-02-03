/* 
 * File:   ReverseInt.h
 * Author: haoruzhao
 *
 * Created on February 1, 2013, 5:29 PM
 */

#ifndef REVERSEINT_H
#define	REVERSEINT_H

#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    Solution(){};
    
    int reverse(int x) {
        
        bool isNegative  = x < 0 ? true : false;
        if(isNegative)
            x = -x;
        int result = 0;
        
        while( x ){
            result  = result * 10 + x % 10;
            x = x /10;
        }
        if(result < 0 )
            return -1;
        if(isNegative)
            result = -result;
        return result;  
    }
};

#endif	/* REVERSEINT_H */

