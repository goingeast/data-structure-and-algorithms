// longest increasing sequence

#include<iostream>
#include<vector>
using namespace std;

int LIS(vector<int> num){
    vector<int> LIS;
    for(int i=0; i < num.size(); ++i){
    
        LIS.push_back(1);
        for(int j=0; j < i; j++){
            if(num[i] > num[j] && LIS[j] + 1 > LIS[i]){
                LIS[i] = LIS[j] + 1;
            }
        }
        
    }
}
#ifdef _LIS
int main(){

    vector<int> num;
    num.push_back(1);
    num.push_back(-1);
    
    num.push_back(2);
    num.push_back(-3);
    
    num.push_back(4);
    num.push_back(-5);
    
    num.push_back(6);
    num.push_back(-7);
    LIS(num);
}
#endif