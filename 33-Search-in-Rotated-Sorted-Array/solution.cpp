class Solution {
public:
    int search(vector<int>& input, int target){
    
    int left = 0;
    int right = input.size()- 1;

    while(left <= right){
        int mid = (right+left)>>1;
        if(target == input[mid]){
            return mid;
        }else if(input[mid] > input[right]){ //left half is sorted
            if(target >= input[left] && target < input[mid]){
                 right = mid - 1;
            }else{
                 left = mid + 1;
            }
        }else if(input[mid] < input[right]){                               //right half is sorted
            if(target > input[mid] && target <= input[right]){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }else{   // in case we have duplicated number
            --right;
        }
    }
    return -1;
}
};