/* 
 * File:   SortTemplates.h
 * Author: haoruzhao
 *
 * Created on January 14, 2013, 6:37 PM
 */

#ifndef SORTTEMPLATES_H
#define	SORTTEMPLATES_H
#include <iostream>
#include <vector>

using std::cout;
using std::vector;

// display
template <typename Comparable>
void Display(vector<Comparable>& a){
    int i;
    for(i = 0; i < a.size(); ++i){
        cout << a[i] << " ";
    }
}

// Insertion sort
template <typename Comparable>
void InsertionSort(vector<Comparable>& a){
    int i,j;
    Comparable key;
    for(i = 1; i < a.size(); ++i){
        key =  a[i];
        j = i;
        while( j > 0 && a[j-1] > key ){
            a[j] = a[j-1];
            j--;
        } 
        a[j] = key;
    }
};
// Bubble sort
template<typename Comparable>
void BubbleSort(vector<Comparable>& a){
    int i,j, temp;
    int size = a.size();
    bool Swapped = false;
    while( !Swapped ){
        Swapped = true;
        for(j = 1; j < size; ++j){
            if(a[j] < a[j-1]){
                temp = a[j];
                a[j] = a[j-1];
                a[j-1] = temp;
                Swapped = false;
            }
        }
        size = size-1;
    }
}
// Selection sort
template<typename Comparable>
void SelectionSort(vector<Comparable>& a){
    int i,j,temp,pos;
    int size = a.size();
    for(i = 0; i < size; ++i){
        pos = i;
        for(j = i + 1; j < size; ++j){
            if(a[j] < a[pos]){
                pos = j;
            }
        }
        temp = a[pos];
        a[pos] = a[i];
        a[i] = temp;
    }
}
// Shell sort, modify insertion sort
template<typename Comparable>
void Shellsort(vector<Comparable>& a){
    int i,j,gap;
    int size = a.size();
    for(gap = size/2; gap > 0; gap = (gap==2 ? 1 : gap/2.2)){
        for( i = gap; i < size; ++i){
            Comparable key = a[i];
            j = i;
            while(j > 0 && a[j - gap] > key){
                a[j] = a[j - gap];
                j -= gap;
            }
            a[j] = key;
        }
    }
}
// Merge sort
template<typename Comparable>
void Merge(vector<Comparable>& a, vector<Comparable>& temp,int left, int mid, int right){
  // left -- mid, mid+1 -- right
    int i, Pos = left, leftPos = left, rightPos = mid + 1;
    for(i = left; i <= right; ++i){
        temp[i] = a[i];
    }
    while(leftPos <= mid && rightPos <= right){
        if(temp[leftPos] <= temp[rightPos]){
            a[Pos++] = temp[leftPos++];
        }else{
            a[Pos++] = temp[rightPos++];
        }
    }
    
    while(rightPos <= right){
        a[Pos++] = temp[rightPos++];
    }
    while(leftPos <= mid){
        a[Pos++] = temp[leftPos++];
    }
}
template<typename Comparable>
void MergeSort(vector<Comparable>& a, vector<Comparable>& temp, int left, int right){
    // terminal condition
    if(left < right){
        int mid = (left+right)/2;
        MergeSort(a,temp, left, mid);
        MergeSort(a,temp, mid+1,right);
        Merge(a, temp, left, mid, right);
    }
}

template<typename Comparable>
void MergeSort(vector<Comparable>& a){
    vector<Comparable> temp(a.size());
    MergeSort(a, temp, 0, a.size() - 1 );
}
// Quicksort
//1. choose pivot
//2. partition
//3. do quicksort(first part) quicksort(second)
template<typename Comparable>
void Quicksort(vector<Comparable>& a, int left, int right){
    // pivot
    int i= left, j = right, temp;
    int pivot = a[(right+left)/2]; // safe choose
    // partition
    while(i <= j){
        while(a[i] < pivot){ i++;}
        while(a[j] > pivot){ j--;}
        if(i <= j){
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    }
    if(left < j)
        Quicksort(a, left, j);
    if(right > i)
        Quicksort(a, i, right);
}
template<typename Comparable>
void Quicksort(vector<Comparable>& a){
    Quicksort(a, 0, a.size()-1);
}
// Heapsort
/*a heap is a specialized tree-based data structure that satisfies the heap property
 *: if A is parent node of B, then key(A) is ordered with respect to key(B) with the
 * same ordering applying across the heap. Either the keys of parent nodes are always
 * greater than or equal to those of the children and the highest key is in the root
 * node(max heap) or the keys of parent nodes are less or equal to those of the children
 * (min heap).
*/
/*Binary heap: created using a binary tree, it can be seen as a binary tree with
 two constraints
 1. The shape property. the tree is a complete binary tree; that is, all levels
  of the tree, except possibly the last one are fully filled, and if the last level
  is not complete, the nodes of that level are filled from left to right
 2. the heap property, each node is greater than or equal to each of its children 
 according to a comparison predicate defined for the data structure*/

// Comb Sort modify bubble sort
template<typename Comparable>
void Combsort(vector<Comparable>& a){
    int i, j, gap = 0, size = a.size();
    Comparable temp;
    bool swapped;
    for(gap = size/1.25; gap > 0; gap = (gap == 2 ? 1:gap/1.25) ){
        swapped = false;
        while(!swapped){
            swapped = true;
            for(i = 0; i+gap < size; ++i ){
                if(a[i] > a[i + gap]){
                    temp = a[i];
                    a[i] = a[i + gap];
                    a[i + gap] = temp;
                    swapped = false;
                }
            }
        }
    }
}

////////////////////todo tmr: /*these three algorithms need more info*/
// Counting sort
// new a vector, size is the max element in th
template<typename Comparable>
void Countingsort(vector<Comparable>& a){
    Comparable min = a[0], max = a[0];
    int i, j, size = a.size();
    
    for(i = 1; i < size; ++i){
        if(a[i] > max){
            max = a[i];
        }else if(a[i] < min){
            min = a[i];
        }
    }
    vector<Comparable> temp(max - min + 1, 0); // create a vector
    for(i = 0; i < size; ++i){ // counting
        temp[a[i] - min] +=1;
    }
    for(i = 0, j = 0; i < temp.size(); ++i){ // 
        while(temp[i]--){
            a[j++] = i + min;
        }
    }
}
// Radix sort
// Bucket sort

// Distribution sort
// Timsort

//large mount of data sort, please refer to: http://en.wikipedia.org/wiki/External_sorting
#endif	/* SORTTEMPLATES_H */

