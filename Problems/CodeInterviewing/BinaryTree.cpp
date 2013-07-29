// haoru zhao
// Binary Tree problem


// Tree defination
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
        
    }else{
        cout<< node->data;
        cout << hashmap.find(k - node->data)->first;
    }
    check2Sum(hashmap, node->left, k);
    check2Sum(hashmap, node->right, k);
}

bool check2SumBinaryTree(int k, TreeNode* root){
    unordered_map<int, TreeNode*> hashmap;
    return check2Sum(hashmap, root,k);
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
            //cout << currNode->data;
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

bool check2Sum( TreeNode* root, int k){
    
    stack<TreeNode*> leftStack;
    stack<TreeNode*> rightStack;
    
    TreeNode* leftVal = NULL, *rightVal = NULL;
    TreeNode* curr1 = root, *curr2 = root;
    
    bool done1 = false, done2 = false;
    while(true){
        
        while(done1 == false){
            if(curr1 != NULL){
                leftStack.push(curr1);
                curr1 = curr1->left;
            }else{
                if(!leftStack.empty()){
                    curr1 = leftStack.top();
                    leftStack.pop();
                    leftVal = curr1;
                    curr1 = curr1->right;
                    done1 = true;
                }else
                    done1 = true;
            }    
        }
        
        while(done2 == false){
            if(curr2 != NULL){
                rightStack.push(curr2);
                curr2 = curr2->right;
            }else{
                if(!rightStack.empty()){
                    curr2 = rightStack.top();
                    rightStack.pop();
                    rightVal = curr2;
                    curr2 = curr2->left;
                    done2 = true;
                }else
                    done2 = true;
            }
        }
        if((leftVal != rightVal) && (leftVal->data + rightVal->data) == k){
            cout << leftVal->data << rightVal->data << endl;
            return true;
        }else if((leftVal->data + rightVal->data) > k){
            done2 = false;
        }else if((leftVal->data + rightVal->data) < k){
            done1 = false;
        }
        if(leftVal->data > rightVal->data || leftVal == rightVal)
            return false;
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

void zigZagTraverse(TreeNode* root){
    
    stack<TreeNode*> stack1;
    stack<TreeNode*> stack2;
    
    stack1.push(root);
    
    while(!stack1.empty() || !stack2.empty()){
        while(!stack1.empty()){
            TreeNode* node = stack1.top();
            stack1.pop();
            cout << node->data;
            if(node->left)
                stack2.push(node->left);
            if(node->right)
                stack2.push(node->right);
        }
    
        while(!stack2.empty()){
            TreeNode* node = stack2.top();
            stack2.pop();
            cout << node->data;
            if(node->right)
                stack1.push(node->right);
            if(node->left)
                stack1.push(node->left);
            
        }
    }
}


/*------------------------------------------------
 */
bool matchTree(TreeNode* t1, TreeNode* t2){
    if(t1 == NULL && t1 == NULL)
        return true;
    if(t1 == NULL || t1 == NULL)
        return false;
    
    if(t1->data != t1->data)
        return false;
    else
        return matchTree(t1->left, t2->left)&& matchTree(t1->right, t2->right);
}

bool isSubTree(TreeNode* t1, TreeNode* t2){
    if(t1 == NULL)
        return false;
    if(t1->data == t2->data)
        if(matchTree(t1, t2))
            return true;
    
    return isSubTree(t1->left, t2) || isSubTree(t2->right, t2);
}

bool containsTree(TreeNode* t1, TreeNode* t2){
    if(t2 == NULL)
        return true;
    return isSubTree(t1, t2);
}
/*------------------------------------------------
 */
void postorderTraverseIterative(TreeNode* root){
    if(root == NULL)
        return;
    stack<TreeNode*> aStack;
    do{
        while(root != NULL){
            if(root->right != NULL)
                aStack.push(root->right);
            aStack.push(root);
            root= root->left;
        }
        
        root = aStack.top(); 
        aStack.pop();
        
        if(root->right != NULL && aStack.top() == root->right){
            aStack.pop();
            aStack.push(root);
            root = root->right;
        }else{
            cout << root->data;
            root = NULL;
        }
        
            
    }while(!aStack.empty());
}

/*least common ancestor for BST
 * we can use property of BST to check if current node's value
 * is between two node.
 */

TreeNode* findLeastCommonAncestor(TreeNode* root, int n1, int n2){
    /* If we have reached a leaf node then LCA doesn't exist 
     If root->data is equal to any of the inputs then input is 
     not valid. For example 20, 22 in the given figure */ 
    if(root == NULL || root->data == n1 || root->data == n2)
        return NULL;
    /* If any of the input nodes is child of the current node
     we have reached the LCA. For example, in the above figure
     if we want to calculate LCA of 12 and 14, recursion should 
     terminate when we reach 8*/
    if((root->right != NULL) && root->right->data == n1 || root->right->data == n2)
        return root;
    if((root->left != NULL) && root->left->data == n1 || root->left->data == n2)
        return root;
    
    if(root->data > n1 && root->data < n2)
        return root;
    if(root->data > n1 && root->data > n2)
        return findLeastCommonAncestor(root->left, n1, n2);
    if(root->data < n1 && root->data < n2)
        return findLeastCommonAncestor(root->right, n1, n2);

}
/* least common ancestor for Binary Tree
 */
TreeNode* findLeastCommanAncestorBT(TreeNode* root, int n1, int n2){
    
}



TreeNode* buildTree(int pre[], char preLN[], int size){
    static int _index = 0;
    if(_index == size)
        return NULL;
    TreeNode* node = new TreeNode(pre[_index]);
    if(preLN[_index++] == 'N'){
        node->left  = buildTree(pre, preLN, size);
        node->right = buildTree(pre, preLN, size);
    }
    return node;
}




void FormDLLWithLeafNodes(TreeNode *root)
{
    if(root == NULL)
        return;
    /*
      Again we are making use of In-Order traversal to achieve this.
      Since we are asked to connect leaf nodes from left to right,
      we can traverse through the tree using In-Order and check for 
      leaf nodes and connect them as DLL. We can keep track of previous
      node using a static prevNode variable.
    */
    static TreeNode* prevNode = NULL;
    FormDLLWithLeafNodes(root->left);
    // Check if it is a leaf node
    if( ( root->left == NULL ) &&
        ( root->right == NULL ) )
    {
        if(prevNode == NULL)
        {
            prevNode = root;
            cout<<root->data;
        }
        else
        {
            // Connect the leaf nodes here
            prevNode->right = root;
            root->left     = prevNode;
            prevNode         = root;
            
            cout<<"<=>"<<root->data;
        }
    }
    FormDLLWithLeafNodes(root->right);
}

#ifdef BINARY_TREE

int main(){
    TreeNode* a1 = new TreeNode(0);
    TreeNode* a2 = new TreeNode(7);
    TreeNode* a = new TreeNode(1,a1, a2);
    
    TreeNode* b = new TreeNode(4);
    TreeNode* c = new TreeNode(2,a,NULL);
    
    TreeNode* d = new TreeNode(5,b,NULL);
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
    //check2SumBinaryTree(6, root);
    cout << "--------";
    //check2Sum(root,6);
    //inorderTraverseWithoutRercursive(root);
    //preorderTraverseIterative(root);
    //cout << findLeastCommonAncestor(root, 5, 4)->data;
    
//    int pre[]= {10, 30, 20, 5,15};
//    char preLN[] = {'N','N','L','L','L'};
//    TreeNode* tmp = buildTree(pre, preLN, 5);
//    cout <<"";
    
    FormDLLWithLeafNodes(root);
}

#endif