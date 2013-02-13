
//
//  LinkedList.cpp
//  LInkedList
//
//  Created by Haoru Zhao on 2/12/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "LinkedList.h"



//bool linkedList::

//----------------------------<Test Stub>----------------------------
int main()
{   
    linkedList<int> list;
    list.addToHead(10);
    list.addToHead(12);
    list.addToTail(11);
    list.addToTail(19);
	list.addToHead(22);
	list.insertNode(2, 40);
	list.insertNode(2, 30);
	list.displayList();
	//std::cout << "--------------"<<std::endl;
	list.removeFromTail();
	list.removeFromHead();
	list.removeFromTail();
	list.removeNode(2);
	list.updateNode(2,77);
	std::cout << list.listSize();
	list.displayList();
    
    return 0;
}









