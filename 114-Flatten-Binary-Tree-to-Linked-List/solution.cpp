/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        
        TreeNode* dummy;
        flatten_helper(root, dummy);
        
    }
    
    TreeNode* flatten_helper( TreeNode* root, TreeNode*& prev){
        if(root == NULL){
            return root;
        }
        
        TreeNode* right = root->right;
        TreeNode* left = root->left;
        
        prev->right = root;
        prev->left = NULL;
        prev = root;
        
        flatten_helper(left, prev);
        flatten_helper(right, prev);
        
        return NULL;
    }
};