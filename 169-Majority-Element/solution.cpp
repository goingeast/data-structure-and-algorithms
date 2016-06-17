class Solution {
public:
    int majorityElement(vector<int> &num) {
        int count = 1;
        int majority = num[0];
        for(int i = 1; i < num.size(); i++){
            majority == num[i]? count++ : count--;
            if(count == 0){
                majority = num[i];
                count = 1;
            }
        }
        return majority;
    }
};