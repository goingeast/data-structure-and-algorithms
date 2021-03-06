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
    void connectRecursive(TreeLinkNode *root) {
    	if( root == NULL)
    		return;
    	if(root->left){
    		root->left->next = root->right;
    	}
    	if(root->right && root->next){
    		root->right->next = root->next->left;
    	}

    	connect(root->left);
    	connect(root->right);
    }

    void connect1(TreeLinkNode *root){
    	if(root == NULL)
    		return;
    	TreeLinkNode* prev = root;
    	TreeLinkNode* cur = NULL;
    	while(prev){
    		cur = prev;

    		while(cur && cur->left){
    			cur->left->next = cur->right;
    			if(cur->next)
    				cur->right->next = cur->next->left;
    			cur = cur->next;
    		}

    		prev = prev->left;
    	}
    }
    
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