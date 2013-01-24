#ifndef QUEUE_ARRAY_H
#define QUEUE_ARRAY_H
#include <vector>
// use circular array implementation
// when array is full, move front to the corresponding end of array
template<class dataField>
class QueueArray{
public:
	QueueArray()
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

template<class dataField>
bool QueueArray<dataField>::isEmpty()const{
	return currentSize == 0;
}

template<class dataField>
void QueueArray<dataField>::makeEmpty(){
	currentSize=0;
	front=0;
	back=queueArray.size()-1;
}
template<class dataField>
const dataField& QueueArray<dataField>::GetFront()const{
	if (!isEmpty())
	{
		return queueArray[front];
	}else
		cout << "Empty!";
	
}
template<class dataField>
void QueueArray<dataField>::Enqueue(const dataField & x){
	if (currentSize == queueArray.size())
	{
		DoubleQueue();
	}
	back = (++back)% queueArray.size();
	queueArray[back]= x;
	currentSize++;
}

template<class dataField>
void QueueArray<dataField>::DoubleQueue(){
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

template<class dataField>
dataField QueueArray<dataField>::Dequeue(){
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