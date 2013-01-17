/* 
 * File:   main.cpp
 * Author: haoruzhao
 *
 * Created on January 14, 2013, 6:26 PM
 */

#include "SortTemplates.h"
#include <iostream>
#include <vector>

using std::cout;
using std::vector;
/*
 * 
 */
int main(int argc, char** argv) {

    cout<<"hello world!";
    vector<int> a;
    //3, 7, 4, -1, 9, 5, 2, 6, 1
    a.push_back(3);
    a.push_back(7);
    a.push_back(4);
    a.push_back(-1);
    a.push_back(9);
    a.push_back(5);
    a.push_back(2);
    a.push_back(6);
    a.push_back(1);
    MergeSort(a);
    //Quicksort(a);
    //Shellsort(a);
//    SelectionSort(a);
    //BubbleSort(a);
    //InsertionSort(a);
    Display(a);
    
    return 0;
}

