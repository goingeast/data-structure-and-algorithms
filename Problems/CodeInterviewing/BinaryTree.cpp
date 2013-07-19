// haoru zhao
// Binary Tree problem

#include<iostream>
#include<deque>
#include<queue>
#include<limits>
#include<tr1/unordered_map>
#include <stack>

using namespace std;
using namespace std::tr1;

class TreeNode{
public:
    TreeNode(int D,TreeNode* L = NULL, TreeNode* R = NULL)
    :left(L), right(R), data(D){
    }
    TreeNode* left;
    TreeNode* right;
    int data;
};
class BinarySearchTree{
public:
    BinarySearchTree(TreeNode* R)
    :root(R){}
    TreeNode* root;
};


void mirrorTree(TreeNode* &node){
    if(node == NULL || (!node->left && !node->right))
        return;
    TreeNode* temp = node->left;
    node->left = node->right;
    node->right = temp;
    
    mirrorTree(node->left);
    mirrorTree(node->right);

}

void levelTraverse(TreeNode* &node){
    queue<TreeNode*> iterateQueue;
    if(node == NULL)
        return;
    else
        iterateQueue.push(node);
    while(!iterateQueue.empty()){
        TreeNode* temp = iterateQueue.front();
        cout << temp->data;
        if(temp->left)
            iterateQueue.push(temp->left);
        if(temp->right)
            iterateQueue.push(temp->right);
        iterateQueue.pop();
    }
    
}

int maxHeight(TreeNode* &node){
    if(node == NULL)
        return -1;
    int lmax = maxHeight(node->left);
    int rmax = maxHeight(node->right);
    return lmax > rmax ? lmax +1 : rmax +1;

}

/* check it is balanced
 */
int getHeight(TreeNode* node){
    if(node == NULL)
        return -1;
    
    int lmax = maxHeight(node->left);
    int rmax = maxHeight(node->right);
    
    if(lmax > rmax + 1 || lmax < rmax - 1)
        return -2;
    if(lmax == -2 || rmax == -2)
        return -2;
    
    return lmax > rmax ? lmax +1 : rmax +1;  
}

bool isBalanced(TreeNode* node){
    return getHeight(node) != -2;
}
///////bad idea O(n^2)
int _maxHeight(TreeNode* &node){
    if(node == NULL)
        return 0;
    int lmax = _maxHeight(node->left);
    int rmax = _maxHeight(node->right);
    return lmax > rmax ? lmax +1 : rmax +1;

}

bool _isBalanced(TreeNode* node){
    if(node == NULL)
        return true;
    
    int lmax = _maxHeight(node->left);
    int rmax = _maxHeight(node->right);
    
    if(lmax > rmax + 1 || lmax < rmax - 1)
        return false;
    if(lmax == rmax || lmax == rmax + 1|| rmax == lmax + 1)
        return _isBalanced(node->left)&&_isBalanced(node->right);
    
}
/* optimized solution
 */

bool __isBalanced(TreeNode* node, int* height){
    int lh = 0, rh = 0;
    bool leftTreeBalanced = false;
    bool rightTreeBalanced = false;
    if(node == NULL){
        *height = 0;
        return true;     
    }
    
    leftTreeBalanced = __isBalanced(node->left, &lh);
    rightTreeBalanced = __isBalanced(node->right, &rh);
    
    *height = ( lh > rh? lh : rh ) + 1;
    
    if(abs(lh - rh) >= 2)
        return false;
    else
        return leftTreeBalanced && rightTreeBalanced;
}

/*
 */
int nodeDepth(TreeNode* root, TreeNode* node, int depth){
    if(root == NULL)
        return 0;
    if(node->data == root->data)
        return depth;
    return nodeDepth(node->left, node, depth + 1) ^ nodeDepth(node->right, node, depth + 1);
    
}
////pre-order from left to right equals to from right to left
bool sysmeticTree(TreeNode * root1, TreeNode * root2){
    if(root1 == NULL && root2 == NULL)
        return true;
    if(root1 == NULL || root2 == NULL)
        return false;
    if(root1->data != root2->data)
        return false;
    return sysmeticTree(root1->left, root2->right) 
            && sysmeticTree(root1->right, root2->left);
}
/* check a tree is a BST, pass down the min and max
 */
bool checkBST(TreeNode* n, int min, int max){
    if(n == NULL)
        return false;
    if(n->data <= min || n->data > max)
        return false;
    if(!checkBST(n->left, min, n->data)|| !checkBST(n->right, n->data, max))
        return false;
    return true;
}
bool isBST(TreeNode* n){
    return checkBST(n, -1000, 1000);
}
/* build bst tree from pre-order sequence
 */
TreeNode* builder(int pre[], int size, int* preIndex, int key, int min, int max){
    if(*preIndex >= size)
        return NULL;
    TreeNode* root = NULL;
    if(key > min && key < max){
       root = new TreeNode(key);
       (*preIndex)++;
       if(*preIndex < size){
           root->left = builder(pre, size, preIndex, pre[*preIndex], min, key);
           root->right = builder(pre, size, preIndex, pre[*preIndex], key, max);
       }
    }
    return root;
}
TreeNode* buildTreeFromPreOrder(int pre[], int size){
    int preIndex = 0;
    int min = std::numeric_limits<int>::min();
    int max = std::numeric_limits<int>::max();
    return builder(pre, size, &preIndex, pre[0], min, max );
}


/* find a pair of nodes in BINARY TREE, their sum is equal to K
 * 
 * method, use unordered_map, time O(n), space O(n)
 *  
 */
bool check2Sum(unordered_map<int, TreeNode*>& hashmap, TreeNode* node, int k){
    if(node == NULL)
        return false;
    if(hashmap.count(k - node->data) == 0){
        hashmap.insert(make_pair<int, TreeNode*>(node->data, node));
        check2Sum(hashmap, node->left, k);
        check2Sum(hashmap, node->right, k);
    }else{
        cout<< node->data;
        cout << hashmap.find(k - node->data)->first;
    }
}

/*
 * the function returns true if there is a pair with sum equals to target sum
 * 
 * 1. we can also use hashmap
 * 2. we can convert it to double linked list
 * 3. we can do inorder traverse from left to right, and from right to left,'
 *    just like sorted array
 */

void inorderTraverseWithoutRercursive( TreeNode* root){
    stack<TreeNode*> aStack;
    bool done = false;
    TreeNode* currNode = root;
    while(done == false){
        if(currNode != NULL){
            aStack.push(currNode);
            cout << currNode->data;
            currNode = currNode->left;
        }else{
            if(!aStack.empty()){
                currNode = aStack.top();
                aStack.pop();
                //cout << currNode->data;
                currNode = currNode->right;
                
            }else
                done = true;
        }
    }
}

void preorderTraverseIterative(TreeNode* root){
    if(root == NULL)
        return;
    stack<TreeNode*> aStack;
    aStack.push(root);
    while(!aStack.empty()){
       TreeNode* node = aStack.top();
       aStack.pop();
       cout << node->data;
       if(node->right)
           aStack.push(node->right);
       if(node->left)
           aStack.push(node->left);
    }
}

bool check2SumBinaryTree(int k, TreeNode* root){
    unordered_map<int, TreeNode*> hashmap;
    return check2Sum(hashmap, root,k);
}

//#ifdef BINARY_TREE

int main(){
    TreeNode* a1 = new TreeNode(0);
    TreeNode* a = new TreeNode(1,a1, NULL);
    
    TreeNode* b = new TreeNode(4);
    TreeNode* c = new TreeNode(2,a,NULL);
    
    TreeNode* d = new TreeNode(5);
    TreeNode* root = new TreeNode(3,c,d);
    
//    cout << isBST(root);
//    cout << maxHeight(root);
//    int pre[]={3, 2, 1, 4, 5};
//    TreeNode* x = buildTreeFromPreOrder(pre, 5);
//    cout << endl;
//    ///
//    int height = 0;
//    int height1 = 0;
//    if(__isBalanced(a, &height))
//        cout << "balanced";
//    else
//        cout << "no";
//    
//    if(__isBalanced(c, &height1))
//        cout << "balanced";
//    else
//        cout << "no";
    //check2SumBinaryTree(7, root);
    inorderTraverseWithoutRercursive(root);
    preorderTraverseIterative(root);
}

//#endif