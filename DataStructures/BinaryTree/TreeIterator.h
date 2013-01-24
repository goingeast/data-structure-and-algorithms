#ifndef TREEITERATOR_H
#define TREEITERATOR_H
#include"BinaryTree.h"
#include <exception>
#include <stack>
template <class Object>
class TreeIterator{
public:
	TreeIterator(const BinaryTree<Object>& theTree)
		:root(theTree.root),current(NULL){}
	virtual ~TreeIterator(){}
	virtual void First()=0;
	virtual void Advance()=0;
	bool isValid() const {return current != NULL;}
	const Object & retrieve() const;
protected:
	const BinaryNode<Object> *root;
	const BinaryNode<Object> *current;
};

template<class Object>
const Object & TreeIterator<Object>::retrieve() const{
	if (!isValid())
	{
		throw BadIterator("Illegal retrieve");
	}
	return current->data;
}

/////////////////StNode///////////////////
template <class Object>
struct StNode{
	const BinaryNode<Object>* node;
	int timesPopped;
	StNode(const BinaryNode<Object>*n=0)
		:node(n), timesPopped(0){}
};
////////////////PostOrder////////////////
template<class Object>
class PostOrder: public TreeIterator<Object>{
	~PostOrder(){}
	void First();
	void Advance();
protected:
	Stack< StNode<Object> > s;
};

template<class Object>
PostOrder<Object>::PostOrder(const BinaryNode<Object> & theTree)
	:TreeIterator<Object>(theTree)	{
		s.Push(StNode<Object>(root));
}

template <class Object>
void PostOrder<Object>::First(){
	s.Empty()
}
#endif
