// problems related to linkedlist
////////////////////////////////////////////////////////////////////////////////
#include<iostream>
#include<tr1/unordered_map>
using namespace std;
using namespace std::tr1;
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

struct Node1{
    int data;
    struct Node* next;
};

 Node* reverseLinkedlist(Node* startNode){
    Node* iter = startNode;
    Node* prev = NULL;
    while(iter != NULL){
        Node* temp = iter->next;
        iter->next = prev;
        prev = iter;
        iter = temp;
    }
    return prev;
}
 
 Node *swapListElements(Node *list,int k)
{
        //Check if the list is empty
        if(list == NULL)
                return NULL;
 
        /*We need 3 pointers
        1.head - This will keep track of starting node of list even after modifying the list
        2.prev - This node will be pointing to the previous node during the traversal and modfications of list
        3. tempNode - This will be used for traversing the list and pointing to current traversing ndoe of list
        count is an interger variable that will be check against value of k
        */
        Node *head = list,*prev = list;
        int count = 1;
        Node *tempNode = head->next;
        while(tempNode != NULL)
        {
                //If count reaches k break the loop
                if(count == k)
                        break;
                
                /*This is the major part;
                Link the prev node to next node of current node and
                link current node to head; so current node moved to 
                beginning of list. Now point current node to next of
                prev node to continue traversing
                */
                prev->next = tempNode->next;
                tempNode->next = head;
                head = tempNode;
                tempNode = prev->next;
                count++;
        }
 
        /*Check if current node is null or not; if not call the
        method again to get the next 3 elements in list got reversed
        */
        if(tempNode != NULL)
                prev->next = swapListElements(tempNode, k);
 
        //Returns head which is the beginning node of modified list
        return head;
}

bool checkPalindrome(Node** head, Node* tail){
    if(tail == NULL)
        return true;
    bool isp = checkPalindrome(head, tail);
    if(isp == false)
        return false;
    bool isp1 = (tail->value == (*head)->value);
    *head = (*head)->next;
    return isp1;
}

/* Question 1: You are given a linked list and a parameter k.
 * You will have to swap values in a certain fashion, swap 
 * value of node 1 with node k, then node (k+1) with node 2k 
 * and go on doing this in the similar fashion.

 * Question 2: For the above question, do it without swapping
 * the values. If you want a swap to occur between two nodes, 
 * then you will have to move the nodes itself.
 */

void swapNode(Node* node, int k){
    Node* first = node;
    Node* second = node;
    Node* temp = node;
    int count = 1;
    while(temp != NULL){
        if(count == k){
            
            int value = first->value;
            first->value = second->value;
            second->value = value;
            
            first = temp->next;
            second = first;
            count = 1;
        }else{
            second = second->next;
            count++;
        }
        temp = temp->next;   
    }
}

Node* swapNode1(Node*& node, int k){
    Node* first = node;
    Node* second = node;
    Node* preFirst = NULL;
    Node* preSecond = NULL;
    Node* temp = node;
    int count = 1;
    while(temp != NULL){
        if(count == k - 1){
            preSecond = temp;
        }
        if(count == k ){
            
            if(preFirst)
                preFirst->next = second;
            if(preSecond)
                preSecond->next = first;
            Node* temp2= first->next;
            first->next = second->next;
            second->next = temp2;
            
            preFirst = first;
            temp= first;
            first = first->next;
            second = first;
            count = 1;
            
        }else{
            second = second->next;
            count++;
        }
        temp = temp->next;   
    }
}
#ifdef LINKED_LIST
int main(){
        Node * a = new Node(6);
    Node * b = new Node(5, a);
    Node * c = new Node(4, b);
    Node * d = new Node(3, c);
    Node * e = new Node(2, d);
    Node * f = new Node(1, e);
    swapListElements(f,6);
    //swapNode1(f, 4);
    cout << 'dd';
}
#endif