class Solution {
public:
    int mySqrt(int num) {
      if(num < 0) return -1; 
   if(num == 0) return 0;

   int left = 1;
   int right = num/2 + 1;

   while(left <= right){
       int mid = (right+left)>>1;
       if(num/mid >= mid && num/(mid+1) < (mid+1)){
           return mid;
       }else if(num/mid < mid){
           right = mid - 1;
       }else{
           left = mid + 1;
       }
   }
   return -1;
    }
};