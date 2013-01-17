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
// Shell sort
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
  
    int i, j, k, leftPos = left, rightPos = mid+1;
    for(i = left; i <= right; ++i){
        temp[i] = a[i];
    }
    
    int Pos = left;
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


// Comb Sort
// Counting sort
// Radix sort
// Bucket sort
// Distribution sort
// Timsort
#endif	/* SORTTEMPLATES_H */

