#ifndef BinaryTree_h
#define BinaryTree_h
#include "BinaryNode.h"

template <class Object>
class BinaryTree
{
public:
	BinaryTree()
		:root(NULL){}
	BinaryTree(const Object& rootItem)
		:root(new Node(rootItem)){}
	BinaryTree(const BinaryTree &rhs)
		:root(NULL){*this =rhs;}

	~BinaryTree(){MakeEmpty();}
	const BinaryTree & operator= (const BinaryTree & rhs);

	void PrintPreOrder() const{
		if (root != NULL)
		{
			root->PrintPreOrder();
		}
	}
	void PrintInOrder() const{
		if (root != NULL)
		{
			root->PrintInOrder();
		}
	}
	void PrintPostOrder() const	{
		if (root != NULL)
		{
			root->PrintPostOrder();
		}
	}
	void MakeEmpty(){
		MakeEmpty(root);
	}
	bool isEmpty() const{
		return root == NULL;
	}
	int	Size() const{
		return Node::Size(root);
	}
	int Height() const{
		return Node::Height(root);
	}
	void Merge(const Object& rootItem, BinaryTree &t1, BinaryTree &t2);
private:
	typedef BinaryNode<Object> Node;
	Node *root;
	void MakeEmpty(Node * &t);
};

template<class Object>
const BinaryTree<Object>& BinaryTree<Object>::operator=( const BinaryTree<Object> & rhs){
	if (this != &rhs)
	{
		MakeEmpty();
		if (rhs.root != NULL)
		{
			root = rhs.root->Duplicate();
		}
	}
	return *this;
}

template<class Object>
void BinaryTree<Object>::MakeEmpty(BinaryNode<Object>* &t){
	if (t != NULL)
	{
		MakeEmpty(t->left);
		MakeEmpty(t->right);
		delete t;
		t = NULL;
	}
}
template<class Object>
void BinaryTree<Object>::Merge(const Object& rootItem, BinaryTree &t1, BinaryTree &t2){
	if (t1.root == t2.root && t1.root != NULL)
	{
		cerr << "Cannot merge at tree with itself"<< endl;
		return;
	}
	Node *oldRoot = root;
	root = new Node( rootItem, t1.root, t2.root);
	if (this != &t1 && this	!= &t2)
	{
		MakeEmpty(oldRoot);
	}
	if (this != &t1)
	{
		t1.root = NULL;
	}
	if(this != &t2){
		t2.root = NULL;
	}
}

#endif