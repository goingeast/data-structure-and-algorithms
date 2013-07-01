
/* imagine you are reading in a stream of integers, Periodically, you wish to be 
 * able to look up the rank of a number x (the number of values less than or equal
 * to x).
 */
#include<iostream>
using namespace std;

class TreeNode{
public:
    int leftSize;
    TreeNode * left, *right;
    int data;
    TreeNode()
    :leftSize(0),left(NULL),right(NULL),data(0){
    
    }
    TreeNode(int lfsize, TreeNode * lf, TreeNode* rt, int d)
    :leftSize(lfsize),left(lf), right(rt), data(d){
    }
    
    TreeNode(int d)
    :leftSize(0),left(NULL),right(NULL),data(d){
    
    }
};
class BST{
public:
    BST()
    :root(NULL){
        
    }
    void track(int number){
        if(root == NULL){
            root = new TreeNode(number);
        }else{
            _insert(root,number);
        }
        
    }
    
    int getRankOfNumber(int number){
       return _getRankOfNumber(root, number);
    
    }
private:
    TreeNode* root;
    void _insert(TreeNode* &t, int number){
        if(t == NULL){
            t = new TreeNode(number);
        }else if(t->data < number){ // equal put right subtree
            _insert(t->right, number);
        }else if(t->data >= number){
            _insert(t->left, number);
            t->leftSize++;
        }
    }
    //void insert(int number){
    //    _insert(root, number);
    //}
    int _getRankOfNumber(TreeNode* &t, int number){
        if(t == NULL){
            return -1;
        }else if(number == t->data){
            return t->leftSize;
        }else if(number < t->data){
            return _getRankOfNumber(t->left,number);
        }else if(number >= t->data){
            int right_rank = _getRankOfNumber(t->right, number);
            if(right_rank == -1) 
                return -1;
            else
                return t->leftSize + 1 + right_rank;
        }
    }
};
#ifdef GET_RANK
int main(){
    BST ranktree;
    ranktree.track(20);
    ranktree.track(15);
    ranktree.track(10);
    ranktree.track(5);
    ranktree.track(13);
    ranktree.track(25);
    ranktree.track(23);
    ranktree.track(24);
    cout << ranktree.getRankOfNumber(24);
    cout << ranktree.getRankOfNumber(15);
    cout << ranktree.getRankOfNumber(20);
}
#endif