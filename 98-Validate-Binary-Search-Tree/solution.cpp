/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    /*bool isValidBST(TreeNode *root) {
        return _isValidBST(root,LONG_MIN,LONG_MAX);
    }
    
    bool _isValidBST(TreeNode* root, long min, long max){
        if(root == NULL)
            return true;
        if(root->val <= min || root->val >= max){
            return false;
        }
        return _isValidBST(root->left, min, root->val)&&_isValidBST(root->right, root->val, max);
  
    }*/
    
    bool isValidBST(TreeNode *root) {
        TreeNode* prev = NULL;
        
        return isBSTInOrderHelper(root, prev);
    }
    
    bool isBSTInOrderHelper(TreeNode *p, TreeNode*& prev) {
        
        if (p != NULL)
        {
            if (!isBSTInOrderHelper(p->left, prev))
              return false;
     
            // Allows only distinct valued nodes 
            if ((prev) && p->val <= (prev)->val)
              return false;
     
            prev = p;
     
            return isBSTInOrderHelper(p->right, prev);
        }
 
        return true;
    }
    
    private:
    TreeNode* prev1 =NULL;
    
};