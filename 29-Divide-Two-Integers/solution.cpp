class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor == 0) return INT_MAX;
        int result = 0;
        if(dividend == INT_MIN){ // avoid overflow
            if(divisor == -1)
                return INT_MAX;
            dividend += abs(divisor);
            result = 1;
        }
        if(divisor == INT_MIN){
            return result;       // 1 or 0
        }
    
        bool isNeg = (dividend>0)^(divisor>0) ? true : false;
        dividend = abs(dividend);
        divisor = abs(divisor);
    
        int digit = 0;
        while(divisor <= (dividend>>1)){
            divisor <<= 1;
            digit++;
        }
        while(digit >= 0){
            if(dividend >= divisor){
                dividend -= divisor;
                result += 1 << digit;
            }
            divisor >>= 1;
            --digit;
        }
        return isNeg? -result: result;
    }
};