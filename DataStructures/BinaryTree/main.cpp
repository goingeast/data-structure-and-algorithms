#include "BinaryTree.h"
#include <iostream>
using namespace std;

int main( )
{
	BinaryTree<int> t1( 1 );
	BinaryTree<int> t3( 3 );
	BinaryTree<int> t5( 5 );
	BinaryTree<int> t7( 7 );
	BinaryTree<int> t2;
	BinaryTree<int> t4;
	BinaryTree<int> t6;

	t2.Merge( 2, t1, t3 );
	t6.Merge( 6, t5, t7 );
	t4.Merge( 4, t2, t6 );
	
	t4.PrintInOrder( ); 
	cout << "----------------" << endl;
	t4.PrintPostOrder( ); 
	cout << "----------------" << endl;
	t4.PrintPreOrder( ); 
	cout << "----------------" << endl;
	
	cout << "----------------" << endl;


	cout << "t4 size: " << t4.Size( ) << endl;
	cout << "t4 height: " << t4.Height( ) << endl;

	return 0;
}
