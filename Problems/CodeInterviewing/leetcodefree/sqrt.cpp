class Solution {
public:
    int mySqrt(int x) {
    	if(x < 0) return -1;
    	if(x == 0) return 0;

    	int left = 1;
    	int right = x / 2 + 1;

    	while( left <= right){
    		mid = (right- left)/2 + left;

    		if( x / mid >= mid && x /(mid+1) < (mid+1)){
    			return mid;
    		}

    		if( x / mid > mid){
    			left = mid + 1;
    		}else{
    			right = mid - 1;
    		}
    	}
        
    }
};