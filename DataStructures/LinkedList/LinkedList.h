//
//  LinkedList.h
//  LInkedList
// single linked list
//  Created by Haoru Zhao on 2/12/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef LInkedList_LinkedList_h
#define LInkedList_LinkedList_h

#include "listNode.h"

template<typename value_type>
class linkedList
{
public:
    linkedList();
	linkedList(const linkedList&);
    ~linkedList();
    bool isEmpty();
    size_t listSize();
    bool addToHead(const value_type& );
	bool addToTail(const value_type& );
    bool removeFromHead();
    bool removeFromTail();
    bool removeNode(int);
    bool insertNode(int, const value_type&);
    bool updateNode(int, const value_type&);
    bool displayList();
    bool selectionSortList();
private:
	bool isNodeNumInvalid(int);
    listNode<value_type> *head, *tail;
    listNode<value_type> *listIterator;
};

template<typename value_type>
linkedList<value_type>::linkedList()
	:head(NULL),tail(NULL),listIterator(NULL){

}
template<typename value_type>
linkedList<value_type>::~linkedList(){

}
template<typename value_type>
bool linkedList<value_type>::isEmpty(){
	if (head == NULL) {
		return true;
	}
	return false;
}
template<typename value_type>
size_t linkedList<value_type>::listSize(){
	listIterator = head;
	if (!isEmpty()) {
		size_t temp = 1;
		while (listIterator != tail) {
			listIterator = listIterator->getLink();
			temp++;
		}
		return temp;
	}
	return 0; 
}
template<typename value_type>
bool linkedList<value_type>::addToHead(const value_type& data){
	if (isEmpty()) {
		head = new listNode<value_type>(data, head);
		tail = head;
	}else{
		head = new listNode<value_type>(data, head);
	}
	return true;
}
template<typename value_type>
bool linkedList<value_type>::addToTail(const value_type& data){
	//listIterator = head;
	listNode<value_type>* newNode = new listNode<value_type>(data, NULL);

	if (isEmpty()){
		head = newNode;
		tail = newNode;
		return true;
	}else{
		tail->setLink(newNode);
		tail = newNode;
		return true;
	}
	return false;
}

template<typename value_type>
bool linkedList<value_type>::insertNode(int nodeNum, const value_type& data){

	listNode<value_type>* temp;
	listNode<value_type>* newNode = new listNode<value_type>(data, NULL);
	if (nodeNum < 1){
		std::cout << "node number is invalid";
		return false;
	}
	listIterator = head;
	while (--nodeNum){
		listIterator = listIterator->getLink();
	}
	temp = listIterator->getLink();
	listIterator->setLink(newNode);
	newNode->setLink(temp);
	return true;
}

template<typename value_type>
bool linkedList<value_type>::removeFromHead(){
	listNode<value_type>* temp = head;
	if (isEmpty())
	{
		std::cout << "list is empty, can remove";
	} 
	else
	{
		head = head->getLink();
		if (head == NULL)
		{
			tail = NULL;
		}
		delete temp;
	}
	return true;
}

template<typename value_type>
bool linkedList<value_type>::removeFromTail(){

	if (isEmpty()){
		std::cout << "list is empty, can remove";
	} 
	else if (head == tail){
		delete head;
		head = NULL;
		tail = NULL;
	}else{
		listIterator = head;
		while(listIterator->getLink()!= tail)
		{
			listIterator = listIterator->getLink();
		} 
		listIterator->setLink(NULL);
		delete tail;
		tail = listIterator;
	}
	return true;
}

template<typename value_type>
bool linkedList<value_type>::removeNode(int nodeNum){
	if (isEmpty()){
		std::cout << "List is empty";
		return false;
	}else if (head == tail){
		delete head;
		head = NULL;
		tail = NULL;
		//std::cout << "remove node2";
		return true;
	}else if( isNodeNumInvalid(nodeNum)){
		std::cout << "node number is invalid";
		return false;
	}else if (nodeNum == listSize()){
		removeFromTail();
		//std::cout << "remove node4";
		return true;
	}else{
        
		listNode<value_type> *temp =NULL;
		listIterator = head;
		int previous = nodeNum-1;
		while (--previous){
			listIterator = listIterator->getLink();
		}
		temp = listIterator->getLink();
		listIterator->setLink(temp->getLink());
		delete temp;
		//std::cout << "remove node5";
		return true;
	}	
}
template<typename value_type>
bool linkedList<value_type>::updateNode(int nodeNum, const value_type& data ){
	if (isNodeNumInvalid(nodeNum))
	{
		std::cout << "node number is invalid!";
		return false;
	}else{
		listIterator = head;
		while (--nodeNum){
			listIterator = listIterator->getLink();
		}
		listIterator->setData(data);
		return true;
	}
}
template<typename value_type>
bool linkedList<value_type>::isNodeNumInvalid(int nodeNum){
	if (nodeNum <= 0 || nodeNum > int (listSize()))
	{
		return true;
	}else{
		return false;
	}
}
template<typename value_type>
bool linkedList<value_type>::displayList()
{
	listIterator = head;
	if (head == tail)
	{
		std::cout << "List is empty";
	}

	while (listIterator != NULL) {
		std::cout << (listIterator)->getDate() << " ";
		listIterator = listIterator->getLink();
	}

	//std::cout << (listIterator->getLink()->getDate());
	//    //std::cout << listSize();
	//    for (int i=0; i<listSize(); ++i) {
	//        std::cout << listIterator->getDate();
	//       // std::cout << i << std::endl;
	//        listIterator = listIterator->getLink();
	//    }
	return true;
}
#endif















