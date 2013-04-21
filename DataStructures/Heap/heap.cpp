#include<iostream>
#include<vector>
#include"heap.h"
using namespace std;

// we use vector to implement heap

int main(){
	BinaryHeap<int> test;
	test.Insert(6);
	test.Insert(2);
	test.Insert(3);
	test.Insert(4);
	test.Insert(1);
}

