#include<iostream>
#include<deque>
#include<queue>

using namespace std;

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


////int main(){
//    int a = 5;
//    int* p = &a;
//    func(p);
//    cout << *p << ' ';
//    func1(p);
//    cout << *p ;
//}
