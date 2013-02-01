#ifndef STACKLIST_H
#define STACKLIST_H
#include <iostream>
using namespace std;

template<typename dataField>
class Stack{
public:
	Stack();
	Stack(const Stack& rhs);
	~Stack();
	bool isEmpty() const;
	const dataField & Top() const;
	void MakeEmpty();

	void Pop();
	void Push(const dataField &x);
	dataField TopAndPop();
	const Stack & operator=( const Stack & rhs );
private:
	struct StackNode{
		dataField element;
		StackNode* next;

		StackNode(const dataField &theElement, StackNode* n =NULL )
			: element( theElement ), next( n ) { }
	};
	StackNode* topOfStack; 
};

template<typename dataField>
Stack<dataField>::Stack()
	:topOfStack(NULL){

}

template<typename dataField>
Stack<dataField>::Stack(const Stack& rhs){
	topOfStack = NULL;
	*this=rhs;
}

template<typename dataField>
Stack<dataField>::~Stack(){
	MakeEmpty();
}


template<typename dataField>
bool Stack<dataField>::isEmpty() const{
	return topOfStack == NULL;
}

template<typename dataField>
const dataField& Stack<dataField>::Top() const
{
	if (!isEmpty())
	{
		return topOfStack->element;
	}else{
		cout<< "empty!";
		//return NULL;
	}
	
}

template<typename dataField>
void Stack<dataField>::MakeEmpty(){
	while (!isEmpty())
	{
		Pop();
	}
}

template<typename dataField>
void Stack<dataField>::Pop(){
	if (!isEmpty())
	{
		StackNode* iterator = topOfStack;
		topOfStack = iterator->next;
		delete iterator;
	}else{
		cout<< "empty!";
	}
}

template<typename dataField>
void Stack<dataField>::Push(const dataField &x){
	topOfStack = new StackNode(x, topOfStack);
}

template<typename dataField>
dataField Stack<dataField>::TopAndPop(){
	
	dataField item = Top();
	Pop();
	return item;
}

template<typename dataField>
const Stack<dataField> & Stack<dataField>::operator=( const Stack & rhs ){
	if (this != rhs)
	{
		MakeEmpty();
		if (rhs.isEmpty())
		{
			return *this;
		}
	}

	StackNode* rptr = rhs.topOfStack;
	StackNode* ptr = new StackNode(rptr->element);
	this->topOfStack = ptr;
	for (rptr = rptr->next ; rptr != NULL; rptr = rptr->next)
	{
		//ptr->element = rptr->element;
		ptr->next = new StackNode(rptr->element);
		ptr = ptr->next;
	}
	return *this;
}
#endif