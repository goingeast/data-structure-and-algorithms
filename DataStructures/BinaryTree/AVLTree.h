/* 
 * File:   AVLTree.h
 * Author: haoruzhao
 *
 * Created on February 5, 2013, 8:05 PM
 */
///////////////////////////////////////
//Height-Balance Property: For every internal node v of T, 
//the heights of the children of v differ by at most 1;
///////////////////////////////////////
#ifndef AVLTREE_H
#define	AVLTREE_H

#include <iostream>

template<typename Comparable>
class AVLTree{
    public:
        AVLTree()
            :root(NULL){
            
        }
        AVLTree(const AVLTree & rhs) //copy constructor
            :root(NULL){
            *this = rhs;
        }
        const AVLTree & operator=(const AVLTree & rhs); 
        ~AVLTree(){
            makeEmpty();
        }
/////////////////////recursive version//////////////////////////////////////        
        const Comparable& findMin() const{ // find the minimum element in the tree
            if(isEmpty()){
                return NULL;
            }else{
                return _findMin(root)->element;
            }
        }
        
        const Comparable& findMax() const{ // find the maxmum element in the tree
            if(isEmpty()){
                return NULL;
            }else{
                return _findMax(root)->element;
            }
        }
        
        bool contains(const Comparable& x) const{ // does the tree contains element x or not
            return _contains(root, x);
        }
        
        bool isEmpty() const{ // helper function
            return root == NULL;
        }
        
        void makeEmpty(){  // make the tree empty
            _makeEmpty(root);
        }
        
        void insert(const Comparable& x){ // insert x
            _insert(x, root);
        }
        
        void remove(const Comparable& x){ // remove
            _remove(root, x);
        }
        
    private:
        struct AVLTreeNode{  // node structure
            Comparable element;
            AVLTreeNode* left;
            AVLTreeNode* right;
            int height;
            AVLTreeNode(const Comparable& theElement, AVLTreeNode* L = NULL, AVLTreeNode* R= NULL, int h = 0)
                 :element(theElement), left(L), right(R), height(h){
            }
        };
       
        AVLTreeNode* root; // root
        void _insert(const Comparable& x, AVLTreeNode* & temp){ // insert helper
             if(temp == NULL){
                 temp = new AVLTreeNode(x);
             }else if(temp->element <= x){ // equal put right subtree
                 _insert(x, temp->right);
             }else if(temp->element > x){
                 _insert(x, temp->left);
             }
        }
        
        AVLTreeNode* _findMin(AVLTreeNode* t) const{ // findMin helper
            if(t == NULL){
                return NULL;
            }else if(t->left == NULL){
                return t;
            }
            _findMin(t);
        }
        
        AVLTreeNode* _findMax(AVLTreeNode* t) const{ // findMax helper
            if(t == NULL){
                return NULL;
            }else if(t->right == NULL){
                return t;
            }
            _findMax(t);
        }
        
        void _remove(AVLTreeNode* &t, const Comparable& x){ // remove helper
//            if(t == NULL){
//                return NULL;
//            }else if(t->element > x){
//                _remove(t->left, x);
//            }else if(t->element <= x){
//                _remove(t->right, x);
//            }else if(t->element == x){ // find it
//                if(t->left != NULL && t->right !=NULL){       // if there are two children 
//                    t->element = _findMin(t->right)->element; // find the smallest element in the right subtree
//                    _remove(t->element, t->right);            // replace the old one.
//                }else{
//                    AVLTreeNode* oldNode = t;                // if there are one child
//                    t = ( t->left != NULL ) ? t->left : t->right; // just replace the node with its child
//                    delete oldNode;
//                }
//            }
        }
        
        
        void _makeEmpty(AVLTreeNode* & t){
            if(t != NULL){
                _makeEmpty(t->left);
                _makeEmpty(t->right);
                delete t;
            }
            t = NULL;
        }
        
        bool _contains(AVLTreeNode* &t, Comparable& x){
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

#endif	/* AVLTREE_H */

