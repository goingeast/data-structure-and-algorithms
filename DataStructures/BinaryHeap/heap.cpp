#include<iostream>
#include<vector>
#include"heap.h"
using namespace std;

// we use vector to implement heap

int main(){
	BinaryHeap<int> test;
	test.Insert(6);
    test.Print();
    cout << endl;
	test.Insert(2);
    test.Print();cout << endl;
	test.Insert(3);
    test.Print();cout << endl;
	test.Insert(4);
    test.Print();cout << endl;
	test.Insert(1);
    test.Print();cout << endl;
    test.Insert(10);
    test.Print();cout << endl;
    test.Insert(9);
    test.Print();cout << endl;
    test.Insert(5);
    test.Print();cout << endl;
    cout << test.DeleteMin() << endl;
    test.Print();cout << endl;
    cout << test.DeleteMin() << endl;
    test.Print();cout << endl;
    cout << test.DeleteMin() << endl;
    test.Print();cout << endl;
    cout << test.DeleteMin() << endl;
    test.Print();cout << endl;
    cout << test.DeleteMin() << endl;
    test.Print();cout << endl;
    cout << test.DeleteMin() << endl;
    test.Print();cout << endl;

}

