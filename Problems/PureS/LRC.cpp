//LRU cache, which use hashmap plus + doubly linked list

typdef struct ListNode
{
	int key;
	int value;
	ListNode* prev;
	ListNode* next;
	
} ListNode;


class LRUCache{
public:
	LRUCache(){
		this->head = NULL;
		this->tail = NULL;
	}

	void appendNode(ListNode* latestNode){
		if(head == NULL){
			head = tail = latestNode;
		}else{
			latestNode->prev = tail;
			tail->next = latestNode;
			tail = latestNode;

		}
	}
	void removeOldestNode(){
		ListNode* temp = head;
		head = head->next;
		if(head)
			head->prev = NULL;
		delete temp;
	}
	void updateListNode(ListNode* latestNode){
		if( latestNode == tail){
			return;
		}else if( latestNode == head){
			head->next->prev = NULL;
			head = head->next;
		}else{
			latestNode->prev->next = latestNode->next;
			latestNode->next->prev = latestNode->prev;
		}

		tail->next = latestNode;
		latestNode.prev = tail;
		tail = latestNode;
		latestNode.next = NULL;
	}

	int get(int key){
		if(hashmap.find(key) != hashmap.end()){
			ListNode* node = hashmap[key];
			updateListNode(node)
			return node->value;
		}else{
			return INT_MIN;
		}
	}

	int set(int key , int value){
		if(hashmap.find(key) != hashmap.end()){
			ListNode* node = hashmap[key];
			updateListNode(node);
			node->value = value;
		}else{
			if(hashmap.size() == capacityLimit){
				removeOldestNode();
				hashmap.erase(key);
			}
			ListNode* newNode = new ListNode(key, value);
			hashmap[key] = newNode;
			appendNode(newNode);
		}
	}
private:

	unordered_map<int, ListNode*> hashmap;
	ListNode* head;
	ListNOde* tail;
	int capacityLimit;
}