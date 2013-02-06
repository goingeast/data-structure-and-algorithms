/* 
 * File:   main.cpp
 * Author: haoruzhao
 *
 * Created on January 24, 2013, 12:17 PM
 */

#include <cstdlib>
#include "StackArray/QueueList.h"
#include "StackArray/StackList.h"
#include "LinkedList/LinkedList.h"
//#include "BinaryTree/BSTTree.h"
#include "BinaryTree/BinaryNode.h"
#include "BinaryTree/BinaryTree.h"
#include "BinaryTree/BSTTree.h"
#include <iostream>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //Stack<int> f;
    //f.Push(1);
    //linkedList<int> list;
    //list.addToHead(4);
    BinarySearchTree<int> BST;
    BST.insert(18);
    BST.insert(15);
    BST.insert(26);
//    BinaryTree<int> t1( 1 );
//    BinaryTree<int> t3( 3 );
//    BinaryTree<int> t5( 5 );
//    BinaryTree<int> t7( 7 );
//    BinaryTree<int> t2;
//    BinaryTree<int> t4;
//    BinaryTree<int> t6;
//
//    
//    t2.Merge( 2, t1, t3 );
//    t6.Merge( 6, t5, t7 );
//    t4.Merge( 4, t2, t6 );
//
//    cout << "t4 should be perfect 1-7; t2 empty" << endl;
//    cout << "----------------" << endl;
//    cout << "t4 -- in, post, pre, twice each, level once" << endl;
//    t4.PrintInOrder();
 //   BinarySearchTree<int> t;
 //   t.insert(1);
 //   t.insert(2);
//    Queue<int> q;
// 
// 	for( int j = 0; j < 8; j++ )
// 	{
// 		for( int i = 0; i < 8+j+3; i++ )
// 			q.enqueue( i );
// 
// 		while( !q.isEmpty( ) )
// 			cout << q.dequeue( ) << endl;
// 	}
    
   return 0;
}

