#include "StackList.h"
#include "QueueArray.h"

#include <iostream>
using namespace std;
int main(){
	Stack<int> intArray;
	intArray.Push(1);
	intArray.Push(2);
	intArray.Pop();
	cout << intArray.TopAndPop();
	intArray.Pop();
	intArray.Push(10);
	intArray.MakeEmpty();
	cout << intArray.TopAndPop();
// 	QueueArray<int> q;
// 
// 	for( int j = 0; j < 8; j++ )
// 	{
// 		for( int i = 0; i < 8+j+3; i++ )
// 			q.Enqueue( i );
// 
// 		while( !q.isEmpty( ) )
// 			cout << q.Dequeue( ) << endl;
// 	}

	return 0;
}