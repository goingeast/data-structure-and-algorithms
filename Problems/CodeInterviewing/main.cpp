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
#include<tr1/unordered_map>
#include<algorithm>
#include<cstring>
using namespace std;
using namespace tr1;

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

//chapter 2.7 check palidrome
//--------------------------------------<Stack>------------------------------
//
// chapter 3.1 implement three stack in a array
//|----------------------------------------------|
//|->               shift|                     <-|
//|----------------------------------------------|
//1                      3                       2
////////////////////////////////////////////////////
class threeStack{
	#define MAXSIZE 10
public:
	threeStack()
		:stack1Top(-1),stack2Top(MAXSIZE),stack3Top(MAXSIZE/3 - 1),stack3Bot(MAXSIZE/3){
			for(size_t i = 0; i < MAXSIZE; ++i){
				_status[i] = false;
			}
	};
	int pop1(){
        if(stack1Top >= 0){
            _status[--stack1Top]= false;
            return _container[stack1Top+1];
        }else{
            cout << "empty";
        }
	};
	int pop2(){
        if(stack2Top <= MAXSIZE){
            _status[++stack2Top]= false;
            return _container[stack2Top-1];
        }else{
            cout << "empty";
        }
    };
	int pop3(){
        if(stack3Top >= stack3Bot){
            _status[--stack3Top]= false;
            return _container[stack3Top+1];
        }else{
            cout << "empty";
        }
    };
	void push1(int value){
		if(_status[++stack1Top] == false){
			_container[stack1Top] = value;
			_status[stack1Top] = true;
		}else{
			int pos = stack2Top - stack3Top;
			if(pos > 1){
				stack3Shift(pos/2, true); //true for right shift
				_container[stack1Top] = value;
				_status[stack1Top] = true;
			}else{
				cout << "it's full!";
			}
		}
	};
	void push2(int value){
		if(_status[--stack2Top] == false){
			_container[stack2Top] = value;
			_status[stack2Top] = true;
		}else{
			int pos = stack3Bot - stack1Top;
			if(pos > 1){
				stack3Shift(pos/2, false); //false for left shift
				_container[stack2Top] = value;
				_status[stack2Top] == true;
			}else{
				cout << "it's full!";
			}
		}
	};
	void push3(int value){
		if(_status[++stack3Top] == false){
			_container[stack3Top] = value;
			_status[stack3Top] = true;
		}else{
			int pos = stack3Bot - stack1Top;
			if(pos > 1){
				stack3Shift(pos/2, false); //false for left shift
				_container[stack2Top] = value;
				_status[stack2Top] = true;
			}else{
				cout << "it's full!";
			}
		}
	};
private:
	void stack3Shift(int pos, bool direction){
        if(direction == false){
            for(size_t i = stack3Bot; i <= stack3Top; ++i){
                _container[i - pos] = _container[i];
                _status[i - pos] = true;
            }
            for(size_t j = 1; j < pos; ++j){
                _status[stack3Top - j] = false;
            }
            stack3Bot = stack3Bot - pos;
            stack3Top = stack3Top - pos;
        }else{
            for(size_t i = stack3Bot; i <= stack3Top; ++i){
                _container[i + pos] = _container[i];
                _status[i + pos] = true;
            }
            for(size_t j = 1; j < pos; ++j){
                _status[stack3Top + j] = false;
            }
            stack3Bot = stack3Bot + pos;
            stack3Top = stack3Top + pos;
        }
    };
	int stack1Top;
	int stack2Top;
	int stack3Top;
	int stack3Bot;
	int _container[MAXSIZE];
	bool _status[MAXSIZE];
};

//chapter 3.2
// parentheses valid
// post expression
// 


// size of structure
struct {
    int a;
    char b;
}A;
class B{
    
    float b;
    char c;
    char d;
    char a;
};

// N!
int find(int n){

    if(n == 1)
        return 1;
    else{
        return find(n-1)*n;
    }
}

// 3 sum, find three numbers, whose sum equals to the target
// we use three pointers
vector< vector<int> > threeSum(vector<int> &num){
    std::sort(num.begin(), num.end());
    vector<int>::iterator first, second, third;
    size_t length = num.size();
    
    if(length < 3)
    first = num.begin();
    second = num.begin()+1;
    third = num.end() - 1;
    
}

char* removeComma1(char * str){
    char* cur = str, *tail = str;
    while(*cur){
        if(*cur != ','){
            if(cur != tail){
                *tail =  *cur;
            }
            tail++;
            cur++;
        }else
            cur++;
    }
    *tail = '\0';
}

string& removeComma(string & str){
    string::iterator cur = str.begin(), tail = str.begin();
    size_t num = 0;
    while(*cur){
        if(*cur != ','){
            if(cur != tail){
                *tail =  *cur;
            }
            tail++;
            cur++;
        }else{
            cur++;
            num++;
        } 
    }
    *tail = '\0';
    str.resize(str.size() - num);
}

int compr (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

void findKTimes(int num[], size_t size, int k){
    if(size <=1 && k != 1 || size < k)
        return;
 
    qsort(num, size, sizeof(int), compr);
    size_t count = 1 ;
    int cur = num[0];
    for(size_t i = 1; i < size; ++i){
        if(num[i] != num[i-1]){
            count = 1;
        }else{
            count++;
            if(count == k)
                cout << num[i-1] << endl;
        }  
    }
}
//////////////
//backtracking

void FindCombination(int r[], int k, int a[], int size,int n){
#define MAXCANDIDATES 10
    int c[MAXCANDIDATES];
    int ncandidates = 0;
    
    if(n == k){
        for(size_t i = 0; i < n; ++i)
                cout << r[i]; 
        cout<< endl;
    }
    else{
        
        for(size_t i = 0,j = 0; i < size ; ++i){
            //int temp = k -1;
            bool found = false;
            if(k!= 0){
                for(size_t m = 0; m < k; ++m)
                    if(r[m] == a[i]){
                        found = true;
                        break;
                    }
            }
            if(found)
                continue;
            c[j++] = a[i];
            ncandidates++;
        }
        for(size_t i = 0; i < ncandidates; ++i){
            r[k] = c[i];
            FindCombination(r, k+1, a, size, n);
        }
    }
}

/////////////////////////////////////////
// A divide and conquer solution to find a peak element element
//#include <stdio.h>
 
// A binary search based function that returns index of a peak element
int findPeakUtil(int arr[], int low, int high, int n)
{
    // Fin index of middle element
    int mid = low + (high - low)/2;  /* (low + high)/2 */
 
    // Compare middle element with its neighbours (if neighbours exist)
    if ((mid == 0 || arr[mid-1] <= arr[mid]) &&
            (mid == n-1 || arr[mid+1] <= arr[mid]))
        return mid;
 
    // If middle element is not peak and its left neighbor is greater than it
    // then left half must have a peak element
    else if (mid > 0 && arr[mid-1] > arr[mid])
        return findPeakUtil(arr, low, (mid -1), n);
 
    // If middle element is not peak and its right neighbor is greater than it
    // then right half must have a peak element
    else return findPeakUtil(arr, (mid + 1), high, n);
}
 
// A wrapper over recursive function findPeakUtil()
int findPeak(int arr[], int n)
{
    return findPeakUtil(arr, 0, n-1, n);
}
 
/////////////////////////////////////////
//Wild Matching



/////////////////////////////////////////
bool checkPalindrome(unsigned int num){
    unsigned int temp = num;
    unsigned int reversed = 0;
    while(temp){
         reversed = reversed*10+ temp%10;
         temp = temp/10;
    }
    if(reversed != num)
        return false;
    else
        return true;
}

bool checkPalindrome2(string str){
    if(str.empty())
        return false;
    int front = 0;
    int end = str.size() - 1;
    while(front < end){
        if(str[front] != str[end])
            return false;
        front++;
        end--;
    }
    return true;
}
///////////////////////////////////////
//reverse string with words, if we use string lib
//
void _reverse1(char* str){
    if(!str)
        return;
    _reverse1(strtok(NULL, " "));
    cout << str << ' ';
}
void reverseSentence1(char* str){
    _reverse1(strtok(str, " "));
}
//-------------------------------------
// without use cstring lib
// step 1 "I like China"-> "I ekil anihC"
// step 2 "China like I"
void _reverse2(char* begin, char* end){
    char temp;
    while(begin < end){
        temp = *begin;
        *begin++ = *end;
        *end-- = temp;
    }
}
void reverseSentence2(char* str){
    char* temp = str;
    char* begin = NULL;
    while(*temp ){
        if(*temp != ' ' && begin == NULL){
            begin = temp;
        }
        if(begin && (*(temp+1) == ' ' || *(temp+1) == '\0')){
            _reverse2(begin, temp);
            begin = NULL;
        }
        temp++;
    }
    _reverse2(str,temp-1);
}

/////////////////////
int sqrt(int x){
    double x1 = x, x2 = x -0.1;
    while(fabs(x2 - x1) > 0.0001){
        x1 = x2;
        x2 = (x1 + x/x1)/2;
    }
    return (int) x2;
}

double sqrt1(double x){
    double x1 = x, x2 = x -0.1;
    while(fabs(x2 - x1) > 0.0001){
        x1 = x2;
        x2 = (x1 + x/x1)/2;
    }
    return x2;
} 
////////////////////////////////////////
//strstr implementation
char* strstr1(char* dest, char* tar){
    if(*tar == '\0') 
        return dest;
    
   char* dest_iter = dest;
   while(*dest_iter != '\0'){
       
       char* begin = dest_iter;
       char* tar_iter = tar;
       
       while(*dest_iter && *tar_iter && *dest_iter == * tar_iter){
               tar_iter++;
               dest_iter++;
       }
          
       if(*tar_iter == '\0')
           return begin;
       dest_iter = begin + 1;
   }
   return NULL;
}

int strcmp1(char* str1, char* str2){
    while(*str1 || *str2){
        if(*str1 == *str2){
            str1++;
            str2++;
        }else{
            return (*str1 - *str2);
        }
    }
    if(!*str1 && !*str2)
        return 0;
}
int strcmp2(char* str1, char* str2){
    int ret = 0;
    while(!(ret = (*str1 - *str2)) && *str1 && *str2){
        str1++;
        str2++;
    }
    return ret;
}

void *memcpy(void* dst, void* src, size_t n){
    void* ret = dst;
    if(dst <= src|| (char*) dst >= ((char*) src + n ))
        while(n--){
            *(char*) dst = *(char*) src;
            dst = (char*)dst + 1;
            src = (char*)src + 1;
        }
    else{
        dst = (char*) dst + n - 1;
        src = (char*) src + n - 1;
        while(n--){
            *(char*) dst = *(char*) src;
            dst = (char*)dst - 1;
            src = (char*)src - 1;
        }
    }
}
////////////

int main(int argc, char** argv) {
    cout << sqrt1(3);
    char a[] = "aaagee ee";
    char b[] = "   geeee";
    if(strcmp(b, a) == strcmp2(b,a))
        //cout << strstr(a,b);
        //cout << strstr1(a, b);
        cout << "equal";
//    //cout << sizeof(A)<< " "<< endl;
//    //cout << find(3);
//    vector<int> a;
//    a.push_back(3);
//    a.push_back(2);
//    a.push_back(1);   
//    //threeSum(a);
//    //char b[] = "1,,2,3,3,3,3333,34,4,,,";
////    string b = "1,,2,3,3,3,3333,34,4,,,";
////    removeComma(b);
////    cout << b;
////    
////    string s = "1,204,342,544";
////    s.erase(remove(s.begin(), s.end(), ',' ), s.end());
////    cout << s;
//    
//    int c[] = {1,2,3,4,5,6,7};
//    int num[] = {10,20,15,30,21};
//    cout << findPeak(num, 5);
//    int r[2] = {0,0};
//   // findKTimes(c, 15, 3);
//    //FindCombination(r,0,c,7,2);
//    string str = "ababa";
//    cout << checkPalindrome2(str);
//    char st[] = "  I   like China ";
//    reverseSentence2(st);
//    cout << st;
////    Node * a = new Node(8);
////    Node * b = new Node(1, a);
////    Node * c = new Node(3, b);
////    Node * d = new Node(0, c);
////    Node * e = new Node(5, d);
////    Node * f = new Node(3, e);
////    reverseLinkedlist(f);
////    
////    threeStack t;
////    t.push1(1);
////    t.push2(2);
////    t.push3(3);
////    t.push1(4);
////    t.push1(4);
////    t.push1(4);
////    t.push2(5);
////    t.push2(5);
////    t.push2(5);
////    //t.push1(0);
////    t.push2(7);
//    //Node* r = _addLists(b, d,0);
//	//Node* r = isLoop(f);
//    //DeleteDupalicate(m);
//    //cout << findLastKth(m, 7);
//    return 0;
}