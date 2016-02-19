/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
    	if(root == NULL)
    		return;

    	TreeLinkNode dummy(INT_MAX);
    	TreeLinkNode* prev = &dummy;
    	TreeLinkNode* cur = root;
    	while(cur){
    		prev = &dummy;
			while(cur){
				if(cur->left){
					prev->next = cur->left;
					prev = prev->next;
				}
				if(cur->right){
					prev->next = cur->right;
					prev = prev->next;
				}
				cur = cur->next;
			}
			cur = dummy.next;
			dummy.next = NULL;
		}
    }
};