class Solution {
public:
    int mySqrt(int x) {
    	if(x < 0) return -1;
    	long r = x;
    while (r*r > x)
        r = (r + x/r) / 2;
    return r;
        
    }
};