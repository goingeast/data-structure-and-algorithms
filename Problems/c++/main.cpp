/* 
 * File:   main.cpp
 * Author: haoruzhao
 *
 * Created on April 26, 2013, 3:35 PM
 */

#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<unordered_map>

using namespace std;

void reverse(char* a){
    char temp;
    char * end = a;
    if(a){
        while(*end != '\0'){
            end++;
        }
        end--;
        while(a < end){
            temp = *a;
            *(a++) = *end;
            *(end--) = temp;
        }
    }

}
// check whether a is a permutation of b
bool isPermutation(string a, string b){
    int temp[256] = {0};
    if(a.size() == b.size()){
        for(size_t i=0; i < a.size(); ++i){
            temp[a[i]] ++;
        }
        for(size_t i=0; i < b.size(); ++i){
            if(--temp[b[i]] < 0)
                return false; 
        }
        return true;
    }
        return false;
}

void stringencode(string& a){
    
    while(a.find(' ') != string::npos){
        size_t pos = a.find(' ');
        a.replace(pos, 1, "%20");
    };    
}
string itos(int i){
    stringstream s;
    s << i;
    return s.str();
}
string compressString(string a){
    int count = 1;
	size_t times = 0;
    char pre = a[0];
    string compressedStr;
    for(size_t i=1; i < a.size(); ++i){
        if(a[i] == pre){
            count++;
        }else{
            
            times++; // check if the compressed string is longer than original
            if(times * 2 > a.size()){
                return a;
            }
            //c = '0'+ count; //convert int to char number
            
            compressedStr.push_back(pre);
            compressedStr.append(itos(count));
            if(compressedStr.size() > a.size())
                return a;
            pre = a[i];
            count = 1;
        }
    }
    //c = '0'+ count;
    compressedStr.push_back(pre);
    compressedStr.append(itos(count));
    return compressedStr;
}

void rotateMatrix(vector< vector<int> >& a){
    int n = a.size();
    for(int layer = 0; layer < n/2; ++layer ){
        int first  = layer;
        int last = n - layer -1;
        for(int i = first; i < last; ++i){
            int offset = i - first;
            int temp = a[first][i];
            a[first][i] = a[last - offset][ first];
            a[last - offset][ first] = a[last][last - offset];
            a[last][last - offset] = a[i][last];
            a[i][last] = temp;
        }
    }
}

void setRowColToZero(vector< vector<int> >& a){
    bool* row = new bool[a.size()];
    bool* col = new bool[a[0].size()];
    
    for(size_t i =0; i < a.size(); ++i){
       for(size_t j = 0; j < a[i].size(); ++j)
           if(a[i][j] == 0){
               row[i] = true;
               col[j] = true;
           }
    }
    
    for(size_t i =0; i < a.size(); ++i){
       for(size_t j = 0; j < a[i].size(); ++j)
           if(row[i] || col[j]){
               a[i][j] = 0;
           }
    }
    
    delete row;
    delete col;
    
}

vector<int> palindromes(string a){
    int seqLen = a.size();
    vector<int> l;
    int i = 0;
    int palLen = 0;
    while(i < seqLen){
        if(i > palLen && a[i - palLen - 1] == a[i] ){
            palLen += 2;
            i += 1;
            continue;
        }
        l.push_back(palLen);
        int s = l.size() - 2;
        int e = s - palLen;
        int j = 0;
        for(j= s; j > e; --j){
            int d = j - e - 1;
            if(l[j] == d){
                palLen = d;
                break;
            }
            l.push_back(min(d,l[j]));
        }
        if(j <= e){
            palLen = 1;
            i +=1;
        }
    }
    l.push_back(palLen);
    int lLen = l.size();
    int s = lLen - 2;
    int e = s - (2 * seqLen + 1 - lLen);
    for(int k = s; k > e; --k){
        int d = k-e -1;
        l.push_back(min(d,l[k]));
    }
    return l;
}


void padi(string s){
    int mx = 0, id = 0;
    cout << s;
    int* p = new int[s.size()];
    for(int i = 1; s[i] !='\0'; ++i){
        p[i] = mx > i ? min(p[2*id - i], mx - i):1;
        cout << p[i];
        while(s[i+p[i]] = s[i - p[i]]) p[i]++;
        if(i + p[i] > mx){
            mx = i+p[i];
            id = i;
        }
    }
    delete p;
}

////////////////////////////////////////////////////////////////////////////////
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

//chapter 2.7 check palidrome
// chapter 3.1 inplement three stack in a array
//|----------------------------------------------|
//|->               42|13                      <-|
//|----------------------------------------------|
class threeStack{
	#define MAXSIZE 30
public:
	threeStack()
		:stack1Top(0),stack2Top(MAXSIZE),stack3Top(MAXSIZE/2){
			for(size_t i = 0; i < MAXSIZE; ++i){
				_status[i] = false;
			}
	};
	pop1(){
	
	};
	pop2();
	pop3();
	void push1(int value){
		if(_status[stack1Top] == false){
			_container[stack1Top] = value;
			_status[stack1Top++] == true;
		}
	};
	void push2(int value){
		if(_status[stack2Top] == false){
			_container[stack2Top] = value;
			_status[stack2Top--] = true;
		}
	};
	void push3(int value){
		if(stack3Top == MAXSIZE/2)
			if(_status[stack3Top] == false){
				_container[stack3Top] = value;
				_status[stack3Top++]
			}
			
	};
private:

	int stack1Top;
	int stack2Top;
	int stack3Top;
	int _container[MAXSIZE];
	bool _status[MAXSIZE];

}
int main(int argc, char** argv) {

    Node * a = new Node(8);
    Node * b = new Node(1);
    Node * c = new Node(3, b);
    Node * d = new Node(0, c);
    Node * e = new Node(5, d);
	b->next = e;
    Node * f = new Node(3, e);
    
    //Node* r = _addLists(b, d,0);
	Node* r = isLoop(f);
    //DeleteDupalicate(m);
    //cout << findLastKth(m, 7);
    return 0;
}

