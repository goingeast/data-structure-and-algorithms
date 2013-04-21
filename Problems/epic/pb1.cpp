// epic problems in carceer
//
//
// Implement LookAndSay function. For example, first, let user input a number,
// say 1. Then, the function will generate the next 10 numbers which satisfy
// this condition: 1, 11,21,1211,111221,312211...
// explanation: first number 1, second number is one 1, so 11. Third number 
// is two 1(previous number), so 21. next number one 2 one 1, so 1211 and so on.

#include<iostream>
using std::to_string;
using std::cout;
using std::endl;

#include<string>
using std::string;

void lookAndSay(string& num, int times){
    if(times > 10){
        return;
    }
    string newNum;
    int count = 1;
    char digit;
    if(num.size() == 1){
        digit = num[0];
        newNum.append(to_string(count));
        newNum.push_back(digit);
        cout << newNum << endl;
        lookAndSay(newNum, ++times);
        return;
    }
 
    for(int i = 1; i < num.size(); ++i){
         digit = num[i - 1];
        if(num[i - 1] == num[i]){
            count++ ;
        }else{
            //digit = num[i - 1];
            newNum.append(to_string(count));
            newNum.push_back(digit); 
            count = 1;
        }
    }
    digit = num.back();
    newNum.append(to_string(count));
    newNum.push_back(digit); 
    cout << newNum << endl;
    lookAndSay(newNum, ++times);
}
int main(int argc, char** argv){
    cout << argv[1]<<"\n";
    string number = argv[1];

    lookAndSay(number,1);
}
