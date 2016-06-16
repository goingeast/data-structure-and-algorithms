class Solution {
public:
    int calculate(string s) {
        /* just do operation like remove all parenthese*/
      /* use stack to track parenthese*/
      
      stack<int> calculator;
      calculator.push(1);
      
      int total = 0;
      int number = 0;
      int lastSign = 1;
      
      for(int i = 0; i < s.size(); ++i){
        if(isdigit(s[i])){
          number = number*10 + (s[i] - '0');
        }
        
        if(s[i] == '-'|| s[i] == '+'){
          total += lastSign * number;
          number = 0;
          lastSign = (s[i] == '-'? -1:1) * calculator.top(); // like we remove parenthese, we need previous sign
        }  
        
        if(s[i] == '('){
          calculator.push(lastSign);
        }else if(s[i] == ')'){
          calculator.pop();
        }
      }
      total += lastSign* number;
      return total;
    }
};