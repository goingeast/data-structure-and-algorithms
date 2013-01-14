//
//  main.cpp
//  Wrapper
//
//  Created by Haoru Zhao on 1/8/13.
//  Copyright (c) 2013 Haoru Zhao. All rights reserved.
//

#include <iostream>
using namespace std;

template<typename Comparable>
class Pointer{
public:
    explicit Pointer( Comparable *rhs = NULL)
    :pointee( rhs ){
        
    }
    bool operator<(const Pointer &rhs) const{
        return *pointee < *rhs.pointee;
    }
    
    operator Comparable * () const{
        return pointee;
    }
    
    Comparable * get() const{
        return pointee;
    }
    
private:
    Comparable *pointee;
};

bool operator!= (const Pointer<int> &lhs, const Pointer<int> &rhs){
    return lhs < rhs || rhs < lhs;
}

int main(int argc, const char * argv[])
{
    int* p = new int(3);
    Pointer<int> q( new int(4));
    
    if(q != p)
        cout << "this is differet"<< endl;

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

