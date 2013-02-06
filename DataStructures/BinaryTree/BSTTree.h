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
        BinarySearchTree(const BinarySearchTree & rhs)
            :root(NULL){
            *this = rhs;
        }
        const BinarySearchTree & operator=(const BinarySearchTree & rhs);
        ~BinarySearchTree(){
            makeEmpty();
        };
        
        const Comparable& findMin() const{
            if(isEmpty()){
                return NULL;
            }else{
                return _findMin(root)->element;
            }
        };
        
        const Comparable& findMax() const{
            if(isEmpty()){
                return NULL;
            }else{
                return _findMax(root)->element;
            }
        };
        bool contains(const Comparable& x) const{
            return _contains(root, x);
        };
        bool isEmpty() const{
            return root == NULL;
        };
        void makeEmpty(){
            _makeEmpty(root);
        };
        void insert(const Comparable& x){
            _insert(x, root);
        };
        
        void remove(const Comparable& x){
            _remove(root, x);
        };
        void removeMin(){
            _removeMin(root);
        };
        
    private:
        struct BinarySearchNode{
            Comparable element;
            BinarySearchNode* left;
            BinarySearchNode* right;
            BinarySearchNode(const Comparable& theElement, BinarySearchNode* L = NULL, BinarySearchNode* R= NULL )
                 :element(theElement), left(L), right(R){
            }
        };
       
        BinarySearchNode* root;
        void _insert(const Comparable& x, BinarySearchNode* & temp){
             if(temp == NULL){
                 temp = new BinarySearchNode(x);
             }else if(temp->element <= x){
                 _insert(x, temp->right);
             }else if(temp->element > x){
                 _insert(x, temp->left);
             }
        };
        BinarySearchNode* _findMin(BinarySearchNode* t) const{
            if(t == NULL){
                return NULL;
            }else if(t->left == NULL){
                return t;
            }
            _findMin(t);
        };
        BinarySearchNode* _findMax(BinarySearchNode* t) const{
            if(t == NULL){
                return NULL;
            }else if(t->right == NULL){
                return t;
            }
            _findMax(t);
        }
        void _remove(BinarySearchNode* &t, Comparable& x){
            if(t == NULL){
                return NULL;
            }else if()
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

