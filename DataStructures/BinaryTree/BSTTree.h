/* 
 * File:   BSTTree.h
 * Author: haoruzhao
 *
 * Created on January 31, 2013, 9:40 PM
 */

#ifndef BSTTREE_H
#define	BSTTREE_H
#include <iostream>

template<typename Comparable>
class BinarySearchTree{
    public:
        BinarySearchTree()
            :root(NULL){
            
        }
        BinarySearchTree(const BinarySearchTree & rhs) //copy constructor
            :root(NULL){
            *this = rhs;
        }
        const BinarySearchTree & operator=(const BinarySearchTree & rhs); 
        ~BinarySearchTree(){
            makeEmpty();
        };
/////////////////////recursive version//////////////////////////////////////        
        const Comparable& findMin() const{ // find the minimum element in the tree
            if(isEmpty()){
                return NULL;
            }else{
                return _findMin(root)->element;
            }
        };
        
        const Comparable& findMax() const{ // find the maxmum element in the tree
            if(isEmpty()){
                return NULL;
            }else{
                return _findMax(root)->element;
            }
        };
        bool contains(const Comparable& x) const{ // does the tree contains element x or not
            return _contains(root, x);
        };
        bool isEmpty() const{ // helper function
            return root == NULL;
        };
        void makeEmpty(){  // make the tree empty
            _makeEmpty(root);
        };
        void insert(const Comparable& x){ // insert x
            _insert(x, root);
        };
        
        void remove(const Comparable& x){ // remove
            _remove(root, x);
        };
        void removeMin(){   // remove the minimum element in the tree
            _removeMin(root);
        };
        
    private:
        struct BinarySearchNode{  // node structure
            Comparable element;
            BinarySearchNode* left;
            BinarySearchNode* right;
            BinarySearchNode(const Comparable& theElement, BinarySearchNode* L = NULL, BinarySearchNode* R= NULL )
                 :element(theElement), left(L), right(R){
            }
        };
       
        BinarySearchNode* root; // root
        void _insert(const Comparable& x, BinarySearchNode* & temp){ // insert helper
             if(temp == NULL){
                 temp = new BinarySearchNode(x);
             }else if(temp->element <= x){ // equal put right subtree
                 _insert(x, temp->right);
             }else if(temp->element > x){
                 _insert(x, temp->left);
             }
        };
        BinarySearchNode* _findMin(BinarySearchNode* t) const{ // findMin helper
            if(t == NULL){
                return NULL;
            }else if(t->left == NULL){
                return t;
            }
            _findMin(t);
        };
        BinarySearchNode* _findMax(BinarySearchNode* t) const{ // findMax helper
            if(t == NULL){
                return NULL;
            }else if(t->right == NULL){
                return t;
            }
            _findMax(t);
        }
        void _remove(BinarySearchNode* &t, const Comparable& x){ // remove helper
            if(t == NULL){
                return NULL;
            }else if(t->element > x){
                _remove(t->left, x);
            }else if(t->element <= x){
                _remove(t->right, x);
            }else if(t->element == x){ // find it
                if(t->left != NULL && t->right !=NULL){       // if there are two children 
                    t->element = _findMin(t->right)->element; // find the smallest element in the right subtree
                    _remove(t->element, t->right);            // replace the old one.
                }else{
                    BinarySearchNode* oldNode = t;                // if there are one child
                    t = ( t->left != NULL ) ? t->left : t->right; // just replace the node with its child
                    delete oldNode;
                }
            }
        }
        void _removeMin(BinarySearchNode* &t){
            if(t== NULL){
                return NULL;
            }else if(t->left != NULL){
                _removeMin(t->left);
            }else{
                BinarySearchNode* tmp = t;
                t = t->right;
                delete tmp;
            }
            
        }
        
        void _makeEmpty(BinarySearchNode* & t){
            if(t != NULL){
                _makeEmpty(t->left);
                _makeEmpty(t->right);
                delete t;
            }
            t = NULL;
        }
        bool _contains(BinarySearchNode* &t, Comparable& x){
            if(t == NULL){
                return false;
            }else if(t->element < x){
                _contains(t->right, x);
            }else if(t->element > x){
                _contains(t->left, x);
            }else if(t->element == x){
                return true;
            }
            
        }
};
#endif	/* BSTTREE_H */

