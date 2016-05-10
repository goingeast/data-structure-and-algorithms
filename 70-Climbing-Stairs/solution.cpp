class Solution {
    //like fabinacci f(0)=1, f(1)=1, f(2)= f(1)+ f(0)...
public:
    int climbStairs(int n) {
        if(n == 1 || n == 0)
            return 1;
        if(n == 2)
            return 2;
        return climbStairs(n-1) + climbStairs(n-2);
    }
};