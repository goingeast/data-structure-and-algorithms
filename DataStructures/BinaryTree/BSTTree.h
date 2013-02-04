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
        bool contains(const Comparable& x) const;
        bool isEmpty() const{
            return root == NULL;
        };
        void makeEmpty(){
            _makeEmpty(root);
        };
        void insert(const Comparable& x){
            _insert(x, root);
        };
        
        void remove(const Comparable& x);
        void removeMin();
        
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
       void _insert(const Comparable& x, BinarySearchNode* & t);
       BinarySearchNode* _findMin(BinarySearchNode* t) const{
            if(t == NULL){
                return NULL;
            }else if(t->left == NULL){
                return t;
            }
            _findMin(t);
        };
       BinarySearchNode* _findMax(BinarySearchNode* t) const;
       void _makeEmpty(BinarySearchNode* & t);
};


template<typename Comparable>
void BinarySearchTree<Comparable>::_insert(const Comparable& x, BinarySearchNode* & temp){
    if(temp == NULL){
        temp = new BinarySearchNode(x);
    }else if(temp->element <= x){
        _insert(x, temp->right);
    }else if(temp->element > x){
        _insert(x, temp->left);
    }
}
template<typename Comparable>
void BinarySearchTree<Comparable>::_makeEmpty(BinarySearchNode* & t){
    if(t != NULL){
        _makeEmpty(t->left);
        _makeEmpty(t->right);
        delete t;
    }
    t = NULL;
}
//template<typename Comparable>
//BinarySearchNode* BinarySearchTree<Comparable>::_findMin(BinarySearchNode* t) const{
//    if(t == NULL){
//        return NULL;
//    }else if(t->left == NULL){
//        return t;
//    }
//    _findMin(t);
//}

template<typename Comparable>
BinarySearchNode* BinarySearchTree<Comparable>::_findMax(BinarySearchNode* t) const{
    if(t == NULL){
        return NULL;
    }else if(t->right == NULL){
        return t;
    }
    _findMax(t);
}
#endif	/* BSTTREE_H */

