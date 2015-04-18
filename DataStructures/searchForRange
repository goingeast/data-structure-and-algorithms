class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int leftL = 0;
        int rightR = n-1;
        int mid;
        vector<int> result;
        while(left <= right){
            mid = (right-left)/2 + left;
            if(A[mid] == target){
                break;
            }else if(A[mid] < target){
                left = mid +1;
            }else{
                right = mid-1;
            }
        }
        if(left > right){
            result.push_back(-1);
            result.push_back(-1);
            return result;
        }
        int temp1 = mid ,temp2 = mid;
        while((temp1-1)>=0){
            if(A[temp1-1] != target){
                break;
            }
            temp1--;
        }
        while((temp2+1)<n){
            if(A[temp2+1] != target){
                break;
            }
            temp2++;
        }
        result.push_back(temp1);
        result.push_back(temp2);
        return result;
    }
};
