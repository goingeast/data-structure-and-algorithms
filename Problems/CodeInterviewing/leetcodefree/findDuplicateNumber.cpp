class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //we use binary search, get mid, then we find how many number in [a, mid], and [mid+1, b]
        int left = 1;
        int right = nums.size() -1;

        while(left < right){
        	int mid = (right+left)/2;
        	int smaller = 0;
        	for(int i = 0; i < nums.size(); ++i){
        		if((nums[i] >= left) && (nums[i] <= mid)){
        			++smaller;
        		}
        	}
        	if(smaller > mid - left + 1){
        		right = mid;
        	}else{
        		left = mid + 1;
        	}
        }

        return left;
    }
};