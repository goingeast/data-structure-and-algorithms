class NumArray {
	private:
		vector<int> sums;
public:
    NumArray(vector<int> &nums) {
    	
    	sums = vector<int>(nums.size()+1, 0);
    	for(int i=1; i < nums.size(); ++i){
    		sums[i] = sums[i-1] + nums[i]; 
    	}
        
    }

    int sumRange(int i, int j) {
        return	sums[j + 1] - sums[i + 1] + nums[i];
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);

