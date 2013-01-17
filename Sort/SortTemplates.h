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
            while(j > 0 && a[j-gap] > key){
                a[j] = a[j - gap];
                j -= gap;
            }
            a[j] = key;
        }
    }
}
// Merge sort
// Quicksort
// Heapsort


// Comb Sort
// Counting sort
// Radix sort
// Bucket sort
// Distribution sort
// Timsort
#endif	/* SORTTEMPLATES_H */

