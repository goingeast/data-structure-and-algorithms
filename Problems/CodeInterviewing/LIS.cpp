// longest increasing sequence

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int LIS(vector<int> num){
    vector<int> LIS;
    for(int i=0; i < num.size(); ++i){
    
        LIS.push_back(1);
        for(int j=0; j < i; j++){
            if(num[i] > num[j] && LIS[j] + 1 > LIS[i]){
                LIS[i] = LIS[j] + 1;
            }
        }
        
    }
}
/*
 */
int GetCeilIndex(int A[], int T[], int l, int r, int key) {
   int m;
 
   while( r - l > 1 ) {
      m = l + (r - l)/2;
      if( A[T[m]] >= key )
         r = m;
      else
         l = m;
   }
 
   return r;
}

int LongestIncreasingSubsequence(int A[], int size) {
   // Add boundary case, when array size is zero
   // Depend on smart pointers
 
   int *tailIndices = new int[size];
   int *prevIndices = new int[size];
   int len2 = 1;
 
   memset(tailIndices, 0, sizeof(tailIndices[0])*size);
   memset(prevIndices, 0xFF, sizeof(prevIndices[0])*size);
 
   tailIndices[0] = 0;
   prevIndices[0] = -1;
   //len = 1; // it will always point to empty location
   for( int i = 1; i < size; i++ ) {
      if( A[i] < A[tailIndices[0]] ) {
         // new smallest value
         tailIndices[0] = i;
      } else if( A[i] > A[tailIndices[len2-1]] ) {
         // A[i] wants to extend largest subsequence
         prevIndices[i] = tailIndices[len2-1];
         tailIndices[len2++] = i;
      } else {
         // A[i] wants to be a potential condidate of future subsequence
         // It will replace ceil value in tailIndices
        int pos = GetCeilIndex(A, tailIndices, -1, len2-1, A[i]);
 
        prevIndices[i] = tailIndices[pos-1];
        tailIndices[pos] = i;
      }
   }
   cout << "LIS of given input" << endl;
   
   for(int i = 0; i < size; i++){
       cout << tailIndices[i] << ' ';
   }
   cout << endl;
   for(int i = 0; i < size; i++){
       cout << prevIndices[i] <<' ';
   }
   cout << endl;
   cout << len2 << endl;
   cout << tailIndices[len2-1] << endl;
   for( int i = tailIndices[len2-1]; i >= 0; i = prevIndices[i] )
      cout << A[i] << "   ";
   cout << endl;
 
   delete[] tailIndices;
   delete[] prevIndices;
 
   return len2;
}
/* Given an array, print the Next Greater Element (NGE) for every element. 
 * The Next greater Element for an element x is the first greater element 
 * on the right side of x in array. Elements for which no greater element 
 * exist, consider next greater element as -1.
 */
void printNGE(int A[], int n){
    stack<int> box;
    box.push(A[0]);
    for(int i=1; i < n; ++i){
        while(!box.empty() && box.top() < A[i]){
            cout << box.top()<< ".." << A[i]<<',';
            box.pop();
        }
        box.push(A[i]);
    }
    while(!box.empty()){
        cout << box.top() << ".." << -1 << ',';
        box.pop();
    }
}


#ifdef _LIS
int main(){

//    vector<int> num;
//    num.push_back(1);
//    num.push_back(-1);
//    
//    num.push_back(2);
//    num.push_back(-3);
//    
//    num.push_back(4);
//    num.push_back(-5);
//    
//    num.push_back(6);
//    num.push_back(-7);
//    LIS(num);
//    
//    //int A[6] ={3,2,1,6,5,4};
//    int A[5]={1,1,1,1,1};
//    //int A[6] = {1,2,3,4,5,6};
//    //int A[8] ={11,13,21,3,19,20,37,6};
//    //int A[4]={100, 7, 9 ,10};
//    printNGE( A, 5);
    
    int A1[] = { 2, 5, 3, 7, 11, 0, 1, 2, 3,4 };
    int A2[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
   int size = sizeof(A1)/sizeof(A1[0]);
 
   printf("LIS size %d\n", LongestIncreasingSubsequence(A1, size));
    
}
#endif