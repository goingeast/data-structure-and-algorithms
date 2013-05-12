#include<iostream>
#include<stack>
#include<string>
using std::string;
using std::cout;
using std::stack;
int postTree(string& S){
    stack<int> postStack;
    for(size_t i = 0; i < S.size(); ++i){
        int x, y, z;
        //if(i < 2 && (S[i] == '+'||S[i] == '*'))
        //    return -1;
        if(S[i] >= '0' && S[i]<= '9')
            postStack.push(S[i] - '0');
        else{
            if(postStack.size() < 2)
                return -1;
            y = postStack.top();
            postStack.pop();
            x = postStack.top();
            postStack.pop();
            
            switch(S[i]){
                case '+': z = x + y; break;
                case '*': z = x * y; break;
                default: return -1;
            }
            postStack.push(z);
        }
    }
    return postStack.top();
}

int main(){
    string a= "999999999*+9+";
    cout << postTree(a);
    return 0;
}