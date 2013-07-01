// 100 -> one hundred
// 1990 -> one thousand nine hundred ninety

#include<iostream>
#include<string>

using namespace std;

string digits[] = {"One", "Two","Three","Four", "Five", "Six", "Seven", "Eight",
                    "Nine"};
string teens[] = {"Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen", 
                    "Seventeen", "Eighteen","Nineteen"};
string tens[] = {"Ten","Twenty","Thirty","Forty", "Fifty", "Sixty","Seventy","Eighty", "Ninety"};
string bigs[] = {"","Thousand ", "Million "};
string numToString100(int number){
    //hundred
    string ret ="";
    if(number/100){
        ret = digits[number/100 - 1] + " Hundred ";
        number%= 100;
    }
    if(number){
        //int tensNum = number%100;
        if(number/10 > 1){
            ret = ret + tens[number/10 - 1];
            number%=10;
        }else if(number >= 11 && number <= 19){
            ret = ret + teens[number - 11] +' ';
            return ret;
        }
        if(number){
            ret += digits[number - 1];
        }
    }
    return ret + ' ';
}
string numToString(int number){
    string ret = "";
    if(number == 0){
        return "zero";
    }else if(number < 0){
        return "negative" + numToString(-number);
    }
    
    int count = 0;
    while(number > 0){
        if(number % 1000 != 0){
            ret = numToString100(number % 1000) + bigs[count]+ ret;
        }
        number/=1000;
        count++;
    }
    return ret;
}
#ifdef NUMTOSTRING
int main(){
    int a = 12234345;
    cout << numToString(a);
}
#endif