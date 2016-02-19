lass Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> hashtable;
        for(int i = 0; i < nums.size(); ++i){
        	int key = numbers[i];
        	if(hashtable.find(target - key) != hashtable.end()){
        		std::vector<int> index;
        		index.push_back(hashtable[target -key]);
        		index.push_back(i);
        		return index;
        	}
        	hashtable[key] = i;
        }
    }
};