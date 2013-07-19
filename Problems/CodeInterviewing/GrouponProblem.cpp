/*Write a function that takes an integer n, and compute between 0 and n, 
 * how many integers contain 5 in it. Also write some test cases for your code.
 * Haoru Zhao, 07/08/2013
 */

#include<iostream>
using std::cout;
using std::endl;
bool hasNums5(int n){
    while(n){
        if(n%10 == 5)
            return true;
        n/=10;
    }
    return false;
}

int _countNums5(int n){
    int count = 0;
    for(int i=0;i <= n; ++i)
        if(hasNums5(i))
            count++;
    
    return count;
}

int countA(int n){
    int iCount = 0;
    int iFactor = 1;
    int iLowerNum = 0;
    int iCurrNum = 0;
    int iHigherNum = 0;
    
    while(n/iFactor != 0){
        iLowerNum = n - (n/iFactor)* iFactor;
        iCurrNum = (n/ iFactor) %10;
        iHigherNum = n/ (iFactor * 10);
        
        switch(iCurrNum){
            case 0:
                iCount += iHigherNum * (iFactor);
                break;
            case 1:
                iCount += iHigherNum * (iFactor);
                break;
            case 2:
                iCount += iHigherNum * (iFactor);
                break;
            case 3:
                iCount += iHigherNum * (iFactor);
                break;
            case 4:
                iCount += iHigherNum * (iFactor);
                break;
            case 5:
                iCount += iHigherNum * (iFactor) + iLowerNum + 1;
                break;
            default:
                iCount += (iHigherNum + 1) * (iFactor) ;
                break;
                
        }
        //if(iCurrNum < 5)
        iFactor *= 10;
    }
    return iCount;
}

/*
 * we can first caculate the number which contains 5;
 * then we just subtract those number
 * 
 * msd is most significant digit in n;
 * d is number of digits in n;
 * 
 * use math analysis:
 * for example: 
 * 
 * 440, we can calculate (0 - 399), (400 - 440)
 * number =              4 * 9 * 9+   4 * 9+        0 = 
 * 
 * 567, we can calculate (0 - 399), (400 - 490), (491 - 499)
 * number =              4 * 9 * 9+   8 * 9+        8
 * 
 * 667, we can calculate (0 - 499), (600 - 660), (661 - 667)
 * number =              5 * 9 * 9+   5 * 9+        6
 * 
 * 767, we can calculate (0 - 499) + (600 - 699), (700 - 760), (761 - 767)
 * number =              6 * 9 * 9+                5 * 9+       6
 */
#include<iostream>
using std::cout;
using std::endl;

int countNums5(int n){
    
    int nlist[16] = {0};
    int i, numOfNotConatain5 = 0, temp = n, p = 0;
    
    for (i = 0; temp > 0; ++i){
        
        nlist[i] = temp % 10;
        
        if (nlist[i] > 5){  // record base responding every digits
            --nlist[i];
        }else if (nlist[i] == 5){ // if we have 5, we don't include that. eg. 54 => 49, 567 => 499
            --nlist[i];
            while(p < i){  
                nlist[p] = 8;
                ++p;
            }
        }
        temp /= 10;
    }
    
    for (i = i - 1; i >= 0; --i)
    {
        numOfNotConatain5 = numOfNotConatain5 * 9 + nlist[i];
    }
   
    return n - numOfNotConatain5;
}
#ifdef GROUP
int main(){
    for(int i= 0; i < 1000; ++i)
       cout << countNums5(i) << endl;
    return 0;

}
#endif