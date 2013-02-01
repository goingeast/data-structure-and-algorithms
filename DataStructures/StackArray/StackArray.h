#ifndef STACKARRAY_H
#define STACKARRAY_H
#include <vector>
using namespace std;

template< typename dataField>
class Stack{
public:
	Stack();
	bool isEmpty();
	const dataField & Top() const;
	void MakeEmpty();
	void Pop();
	void Push(const dataField &x);
	dataField TopAndPop();
private:
	vector<dataField> theArray;
	int topOfStack;
};

template<typename dataField>
Stack<dataField>::Stack()
	:theArray(1),topOfStack(-1){
		
}

template<typename dataField>
bool Stack<dataField>::isEmpty(){
	return topOfStack == -1;
}
template<typename dataField>
void Stack<dataField>::MakeEmpty(){
	topOfStack = -1;
}
template<typename dataField>
const dataField &Stack<dataField>::Top() const{
	if (!isEmpty())
		return theArray[topOfStack];
	else
		cout<< "stack is empty!";
		return NULL;
}

template<typename dataField>
void Stack<dataField>::Push(const dataField &x){
	if (topOfStack == theArray.size()-1)
	{
		theArray.resize(theArray.size()*2 + 1);
	}
	theArray[++topOfStack] = x;
}

template<typename dataField>
void Stack<dataField>::Pop(){
	if (!isEmpty())
		topOfStack--;
	else
		cout<< "stack is empty!";
}
template<typename dataField>
dataField Stack<dataField>:: TopAndPop(){
	if (!isEmpty())
	{
		return theArray[topOfStack--];
	}else
		cout << "stack is empty!";
}

#endif