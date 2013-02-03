#ifndef BinaryTree_Node_h
#define BinaryTree_Node_h
#include <iostream>
using namespace std;

template<typename Object>
class BinaryNode{
public:
	BinaryNode(const Object& data = Object(), BinaryNode *lt = NULL, BinaryNode *rt = NULL);
	static int Size(BinaryNode *t);  // the size of a node is the number of descendants the node has (including itself)
	static int Height(BinaryNode *t); //the height of node is the length of the path from the node to the deepest leaf
	void PrintPostOrder() const;
	void PrintInOrder() const;
	void PrintPreOrder() const;
	BinaryNode *Duplicate() const;
	Object data;
	BinaryNode * left;
	BinaryNode * right;
};

template <typename Object>
BinaryNode< Object>::BinaryNode(const Object& data1, BinaryNode* lt, BinaryNode* rt){
	data = data1;
	right = rt;
	left = lt;
}
template <typename Object>
int BinaryNode<Object>::Size(BinaryNode *t){
	if (t == NULL)
		return 0;
	else
		return 1+Size(t->left)+Size(t->right);
}

template <typename Object>
int BinaryNode<Object>::Height(BinaryNode *t){
	if (t == NULL)
		return -1;
	else
		return 1 + max(Height(t->left),Height(t->right));
}

template<typename Object>
BinaryNode<Object>* BinaryNode<Object>::Duplicate() const{
	BinaryNode<Object>* root = new BinaryNode<Object>(data);
	if (left != NULL)
	{
		root->left = left->Duplicate();
	}
	if (right != NULL)
	{
		root->right = right->Duplicate();
	}
	return root;
}

template<typename Object>
void BinaryNode< Object >::PrintInOrder()const
{
	if (left != NULL)
	{
		left->PrintInOrder();
	}
	cout<< data << endl;
	if (right != NULL)
	{
		right->PrintInOrder();
	}
}

template<typename Object>
void BinaryNode< Object >::PrintPostOrder()const
{
	
	if (left != NULL)
	{
		left->PrintPostOrder();
	}
	if (right != NULL)
	{
		right->PrintPostOrder();
	}
	cout<< data << endl;
}

template<typename Object>
void BinaryNode< Object >::PrintPreOrder()const {
	cout<< data << endl;
	if (left != NULL)
	{
		left->PrintPreOrder();
	}
	if (right != NULL)
	{
		right->PrintPreOrder();
	}
	
}
#endif