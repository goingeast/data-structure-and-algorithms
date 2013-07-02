// problems related to linkedlist
////////////////////////////////////////////////////////////////////////////////
#include<iostream>
#include<tr1/unordered_map>
using namespace std;

class Node{
public:
    Node(int v, Node* n = NULL)
    :value(v), next(n){ }
    int value;
    Node* next;
};
class List{
public:
    List(Node* h = NULL)
    :head(h){
    
    }
    Node* head;
};
//chapter 2.1 delete duplicates in a linked list, use unordered_map.
void DeleteDupalicate(List& mylist){
    Node* iterator = mylist.head;
    Node* prev= NULL;
    unordered_map<int,bool> hashmap;
    while(iterator != NULL){
        if(hashmap.count(iterator->value)){
            prev->next = iterator->next;
            delete iterator;
        }else{
            pair<int, bool> it(iterator->value,true);
            hashmap.insert(it);
            prev = iterator;
        }
        iterator = prev->next;

    }
}
// chapter 2.2 interative
Node* findLastKth(List& mylist, int k){
    if(mylist.head == NULL)
        return NULL;
    Node* iterator = mylist.head;
    Node* kth = mylist.head;
    int count = 0;
    while(iterator != NULL){
        count++;
        if(count > k)
            kth = kth->next;
        iterator = iterator->next;
    }
    if(count < k)
        return NULL;
    return kth;
}
//chapter2.2 recursive
//Node* findLastKth(Node& listHead, int k, int& i){
//    if(listHead == NULL)
//        return NULL;
//    Node* temp = findLastKth(listHead.next, k, i);
//    i++;
//    if(i == k)
//        return listHead;
//    return temp;
//    
//}

// chapter2.3 copy next to the node you want to deleted
// chapter2.4 not in place, use two new list Or we can traverse to the end,
// and swap from beginning between end;
// chapter2.5 add methods, it is quite similar as add number in a array
Node* _addLists(Node* l1, Node* l2, int carry){
    if(l1 == NULL && l2 == NULL && carry == 0){
        return NULL;
    }
    int digitSum;
    if(l1 == NULL && l2 != NULL)
        digitSum = l2->value + carry;
    if(l1 != NULL && l2 == NULL)
        digitSum = l1->value + carry;
    if(l1 != NULL && l2 != NULL)
        digitSum = l1->value + l2->value + carry;
    int curCarry = digitSum / 10;
    int digit = digitSum % 10;
    Node * digitNode = _addLists(l1 == NULL? NULL: l1->next,
								 l2 == NULL? NULL: l2->next,
								 curCarry);
    Node * r = new Node(digit, digitNode);
    return r;
}
//2.6 decide is there a loop
Node* isLoop(Node* startNode){
	Node* slowNode = startNode;
	Node* fastNode = startNode;
	// check wheather is a loop
	while((slowNode != NULL) && (fastNode->next != NULL)){
		slowNode = slowNode->next;
		fastNode = fastNode->next->next;
		if(slowNode == fastNode)
			break;
	}
	
	if(fastNode == NULL || fastNode->next == NULL){
		return NULL;
	}
	// get start node of the loop
	slowNode = startNode;
	while(slowNode != fastNode){
		slowNode = slowNode->next;
		fastNode = fastNode->next;
	}
	 return fastNode;
	
}
// Linked list reverse

void reverseLinkedlist(Node* startNode){
    Node* iter = startNode;
    Node* prev = NULL;
    while(iter != NULL){
        Node* temp = iter->next;
        iter->next = prev;
        prev = iter;
        iter = temp;
    }
}
