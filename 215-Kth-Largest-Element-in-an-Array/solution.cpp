class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int> > minHeap;
        for(int i=0; i < nums.size(); ++i){
            if(i < k){
                minHeap.emplace(nums[i]);
            }else{
                
                minHeap.emplace(nums[i]);
                minHeap.pop();
            }
        }
        return minHeap.top();
    }
};