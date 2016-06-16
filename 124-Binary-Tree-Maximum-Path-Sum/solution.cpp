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
    int maxPathSum(TreeNode *root) {
        int res = INT_MIN;
        _maxPathSum(root, res);
        return res;
    }
    
    int _maxPathSum(TreeNode* node, int& res){
        if(node == NULL)
            return 0;
        int left = _maxPathSum(node->left,res);
        int right = _maxPathSum(node->right,res);
        int cur = node->val + (left>0? left:0) + (right>0?right:0); /* current node maximum path sum*/
        if(cur > res){
            res=cur;
        }
        return node->val + max(left, max(right, 0)); /* return largest sum to parent node*/
    }
};