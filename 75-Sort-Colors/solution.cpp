class Solution {
    /* counting sort*/
public:
    void sortColors_(vector<int>& nums) {
        int lastZero = 0;
        int lastOne = 0;
        for(int i =0; i < nums.size(); i++){
            if(nums[i] == 0){
                nums[i] = 2;
                nums[lastOne++] = 1;
                nums[lastZero++] = 0;
            }else if(nums[i] == 1){
                nums[i] = 2;
                nums[lastOne++] = 1;
            }
        }
    }
    void sortColors(vector<int>& input){
        int i = 0;
        int k = input.size()-1;
        int j = 0;
        while(j <= k){
            if(input[j] == 0){
                swap(input[i++], input[j++]);
            }else if(input[j] == 2){
                swap(input[k--], input[j]);
            }else{
                j++;
            }
        }
    }
    /*void sortColors(int[] A) {
		if (A == null || A.length == 0) {
			return;
		}
		
		int redIndex = 0; //for 1
		int blueIndex = A.length - 1;//for 2
		int i = 0;
		
		while (i <= blueIndex) {
			if (A[i] == 0) {
				swap(A, redIndex, i);
				i++;
				redIndex++;
			} else if (A[i] == 1) {
				i++;
			} else {
				swap(A, blueIndex, i);
				blueIndex--;
			}
		}
	}*/
};