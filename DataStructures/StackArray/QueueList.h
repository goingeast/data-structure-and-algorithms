/* 
 * File:   QueueList.h
 * Author: haoruzhao
 *
 * Created on January 28, 2013, 5:56 PM
 */

#ifndef QUEUELIST_H
#define	QUEUELIST_H
// const 的函数必须调用const 的函数
// function should be defined.
#include <iostream>
template<typename dataField>
class Queue{
    public:
        Queue();
        Queue(const Queue & rhs);
        ~Queue(){ makeEmpty();}; 
        const Queue& operator=( const Queue& rhs);
        
        bool isEmpty() const;
        const dataField& getFront() const;
        void makeEmpty();
        
        dataField dequeue();
        void enqueue(const dataField&);
    private:
        struct ListNode{
            dataField element;
            ListNode* next;
            ListNode( const dataField & theElement, ListNode* n= NULL)
                    :element(theElement), next(n){
                
            }
        };
        ListNode* front;
        ListNode* back;
};

template<typename dataField>
Queue<dataField>::Queue()
    :front(NULL), back(NULL)
{
    
}

template<typename dataField>
Queue<dataField>::Queue( const Queue& rhs){
    front = back = NULL;
    *this = rhs;
}

template<typename dataField>
const Queue<dataField>& Queue<dataField>::operator=(const Queue& rhs){
    if(this != &rhs){
        makeEmpty();
        ListNode* fptr;
        for(fptr = rhs.front; fptr != NULL; fptr = fptr->next){
            enqueue(fptr->element);
        }
    }
    return this;
}

template<typename dataField>
bool Queue<dataField>::isEmpty() const{
    return bool((front == NULL)&&(back == NULL));
}

template<typename dataField>
const dataField& Queue<dataField>::getFront() const{
    if(!isEmpty())
        return front->element;
}

template<typename dataField>
void Queue<dataField>::makeEmpty(){
    while(!isEmpty()){
        dequeue();
    }
}
template<typename dataField>
void Queue<dataField>::enqueue(const dataField& x){
    if(isEmpty()){
        front = back = new ListNode(x);
    }else{
        back = back->next = new ListNode(x);
    }
}

template<typename dataField>
dataField Queue<dataField>::dequeue(){
    if(!isEmpty()){
        dataField element = getFront();
        ListNode* oldFront = front;
        front = front->next;
        delete oldFront;
        return element;
    }
    
}

#endif	/* QUEUELIST_H */

