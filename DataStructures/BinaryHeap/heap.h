#ifndef HEAP_H
#define HEAP_H
//A binary heap is a heap data structure created using a binary tree. 
//It can be seen as a binary tree with two additional constraints:
//The shape property: the tree is a complete binary tree; 
//that is, all levels of the tree, except possibly the last one (deepest) are 
//fully filled, and, if the last level of the tree is not complete, the nodes of that
//level are filled from left to right.
//The heap property: each node is greater than or equal to each of its children 
//according to a comparison predicate defined for the data structure

#include<vector>
#include<iostream>
using namespace std;

template <typename itemType>
class BinaryHeap{
	public:
	BinaryHeap();
	BinaryHeap(vector<itemType>& data); //build heap from a vector
	BinaryHeap(const BinaryHeap<itemType>& bH);
	~BinaryHeap(){};
	void Print();
	bool Insert(const itemType& item);
	bool Delete(itemType& item);
	itemType DeleteMin();
	
	const itemType& Min() const { return heap.front();}
	size_t Count() const {return heap.size();}
	
	private:
	vector<itemType> heap;
	size_t GetParent(size_t n);
	size_t GetChildren(size_t n);
    
	void BubbleUp(size_t n);
	void BubbleDown(size_t n);
	void MakeHeap();
	void Swap(itemType& a, itemType& b);
};

template<typename itemType>
BinaryHeap<itemType>::BinaryHeap(){
	
}

template<typename itemType>
BinaryHeap<itemType>::BinaryHeap(vector<itemType>& data){
		for(size_t i=0; i < data.size(); ++i){
			Insert(data[i]);
		}
}

template<typename itemType>
void BinaryHeap<itemType>::Swap(itemType& a, itemType& b){
	itemType temp = a;
	a = b;
	b = temp;
}

template<typename itemType>
size_t BinaryHeap<itemType>::GetParent(size_t n){
	return n/2;
}

template<typename itemType>
size_t BinaryHeap<itemType>::GetChildren(size_t n){
	return 2*n;
}
template<typename itemType>
itemType BinaryHeap<itemType>::DeleteMin(){
    itemType min;
    if(heap.size() == 0){
        cout << "Heap is empty!";
        return NULL;
    }else{
        min = heap[0];
        heap[0] = heap.back(); 
        heap.pop_back();
       // Print();
       // cout << endl;
        BubbleDown(0);
    }
    return min;
}
template<typename itemType>
bool BinaryHeap<itemType>::Insert(const itemType& item){
	heap.push_back(item);
	BubbleUp(heap.size() - 1);	
}
template<typename itemType>
void BinaryHeap<itemType>::Print(){
	for(size_t i=0; i < heap.size(); ++i){
        cout << heap[i] << " ";
    }
}

template<typename itemType>
void BinaryHeap<itemType>::BubbleUp(size_t n){
	if(n == 0)
		return;
	size_t p = GetParent(n);
	if(heap[GetParent(n)] > heap[n]){
		Swap(heap[p], heap[n]);
		BubbleUp(p);
	}
}

template<typename itemType>
void BinaryHeap<itemType>::BubbleDown(size_t n){
	size_t minIndex = n;
	size_t p = GetChildren(n+1);
    for(size_t i=0; i <= 1; ++i){
        size_t pos = p - i;
        if( pos < heap.size()){
            minIndex = heap[minIndex] < heap[pos]? minIndex: pos;
        }
    }
    if(minIndex != n){
        Swap(heap[n], heap[minIndex]);
        //Print();
        //cout<<endl;
        BubbleDown(minIndex);
    }
}
#endif








