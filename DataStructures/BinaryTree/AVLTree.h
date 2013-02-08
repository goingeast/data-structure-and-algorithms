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
        int height( AVLTreeNode *t ) const
        {
            return t == NULL ? -1 : t->height;
        }
        
        int max(int r, int l) const{
            return r > l? r:l;
        }
        
        AVLTreeNode* root; // root
        void _insert(const Comparable& x, AVLTreeNode* & temp){ // insert helper
             if(temp == NULL){
                 temp = new AVLTreeNode(x);
             }else if(temp->element > x){ // equal put right subtree
                 _insert(x, temp->left);
                 if(height(temp->left) - height(temp->right) == 2){
                     if(temp->left->element > x){
                         left_left_rotation(temp);
                     }else{
                         left_right_rotation(temp);
                     }
                 }
             }else if(temp->element <= x){
                 _insert(x, temp->right);
                 if(height(temp->right) - height(temp->left) == 2){
                     if(temp->right->element <= x){
                         right_right_rotation(temp);
                     }else{
                         right_left_rotation(temp);
                     }
                 }
             }
             temp->height = max(height(temp->left), height(temp->right)) +1;
        }
        void left_left_rotation(AVLTreeNode*& k2){
            AVLTreeNode* k1 = k2->left;
            k2->left = k1->right;
            k1->right = k2;
            k2->height = max(height(k2->left), height(k2->right))+1;
            k1->height = max(height(k1->left), k2->height)+1;
            k2 = k1;
        }
        void right_right_rotation(AVLTreeNode* & k1){
            AVLTreeNode* k2 = k1->right;
            k1->right = k2->left;
            k2->left = k1;
            k1->height = max(height(k1->left), height(k1->right))+1;
            k2->height = max(height(k2->right), k1->height) +1;
            k1 = k2;
            
        }
        void left_right_rotation(AVLTreeNode* & k3){
            right_right_rotation(k3->left);
            left_left_rotation(k3);
        }
        void right_left_rotation(AVLTreeNode* & k1){
            left_left_rotation(k1->right);
            right_right_rotation(k1);
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

