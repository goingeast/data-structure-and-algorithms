#include<iostream>
using std::cout;

int FindMid(int a[], int n){
    
    int max = a[0];
    int cur = a[0];
    
    for(int i = 1; i < n; ++i){
        if(cur == -1 && a[i] > max){
            max = a[i];
            cur = max;
        }else if(cur != -1 && a[i] > cur){
            if(a[i] > max)
                max = a[i];
        }else if(cur == -1 && a[i] < max ){
            cur = -1;
        }else if(cur != -1 && a[i] < cur){
            cur = -1;
        }
    }
    return cur;
}


int main(){
    int a[]={6,9,8,10,5,21,7,4,23,25,24,27};
    int n=12;
    cout << FindMid(a, 12);

}