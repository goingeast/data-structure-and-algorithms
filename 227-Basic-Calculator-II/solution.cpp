class Solution {
public:
    int calculate(string s) {
        stack<int> calculator;
        int number = 0;
        int res = 0;
        char sign = '+';
        for(int i =0; i < s.size(); ++i){
          if(isdigit(s[i])){
            number = number*10 + s[i] - '0';
          }
          if(!isdigit(s[i]) && ' '!= s[i] || i == s.size() -1){
            if(sign == '-'){
              calculator.push(-number);
            }else if(sign == '+'){
              calculator.push(number);
            }else if(sign == '*'){
              res = calculator.top()*number;
              calculator.pop();
              calculator.push(res);

            }else if(sign == '/'){
              res = calculator.top()/number;
              calculator.pop();
              calculator.push(res);
            }
            number = 0;
            sign = s[i];
          }
        }
        res = 0;
        while(!calculator.empty()){
          res+=calculator.top();
          calculator.pop();
        }
        return res;
    }
};
