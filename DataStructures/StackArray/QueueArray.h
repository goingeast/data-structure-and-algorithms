#ifndef QUEUE_ARRAY_H
#define QUEUE_ARRAY_H
#include <vector>
#include <iostream>
using std::vector;
using std::cout;
// use circular array implementation
// when array is full, move front to the corresponding end of array
template<typename dataField>
class Queue{
public:
	Queue()
		:queueArray(1){
			currentSize=0;
			front=0;
			back=queueArray.size()-1;
	}
	bool isEmpty() const;
	const dataField & GetFront() const;
	void makeEmpty();
	dataField Dequeue();
	void Enqueue(const dataField & x);
private:
	vector<dataField> queueArray;
	int currentSize;
	int front;
	int back;
	void DoubleQueue();
};

template<typename dataField>
bool Queue<dataField>::isEmpty()const{
	return currentSize == 0;
}

template<typename dataField>
void Queue<dataField>::makeEmpty(){
	currentSize=0;
	front=0;
	back=queueArray.size()-1;
}
template<typename dataField>
const dataField& Queue<dataField>::GetFront()const{
	if (!isEmpty())
	{
		return queueArray[front];
	}else
		cout << "Empty!";
	
}
template<typename dataField>
void Queue<dataField>::Enqueue(const dataField & x){
	if (currentSize == queueArray.size())
	{
		DoubleQueue();
	}
	back = (++back)% queueArray.size();
	queueArray[back]= x;
	currentSize++;
}

template<typename dataField>
void Queue<dataField>::DoubleQueue(){
	queueArray.resize(2*queueArray.size()+1);
	if (front!=0)
	{
		for (int i= front; i < currentSize; ++i )
		{
			queueArray[currentSize+1+i]= queueArray[i];
		}
		front = currentSize+front+1;
	}
	
}

template<typename dataField>
dataField Queue<dataField>::Dequeue(){
	if (!isEmpty())
	{
		dataField frontItem = queueArray[front];
		front = (++front)%queueArray.size();
		currentSize--;
		return frontItem;
	}else{
		cout<< "Empty!";
		return NULL;
	}
		

}

#endif