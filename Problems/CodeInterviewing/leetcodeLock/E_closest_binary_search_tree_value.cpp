/*Problem Description:
Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.
Note:
Given target value is a floating point.
You are guaranteed to have only one unique value in the BST that is closest to the target.
*/

class Solution {
   int closestValue(TreeNode* root, double target){
     
     int minDiff = INT_MIN;
     int result;

     while(root){
       int diff = abs(root->val - target);

       if(diff < minDiff){
         minDiff = diff;
         result = root.val;
       }
       if(diff == 0)
          break;
        if(target >= root->val){
          root = root->right;
        }else{
          root = root->left;
        }
     }
     return result;
   }
};
