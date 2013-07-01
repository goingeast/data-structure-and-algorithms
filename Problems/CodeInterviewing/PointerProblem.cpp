
// write a mallc/free function that supports allocating memory
#include<iostream>
using namespace std;
void* aligned_malloc(size_t required_bytes, size_t alignment){

    int offset = alignment - 1 + sizeof(void*);
    
    void** p2;
    void* p1 = (void*) malloc (required_bytes + offset);
    if(p1 == NULL)
        return NULL;
    
    p2 = (void**) (((size_t)(p1) + offset) & ~(alignment -1));
    p2[-1] = p1;
    return p2;
}

void aligned_free(void *p2){

    void * p1 = ((void **) p2)[-1];
    free(p1);
}
#ifdef POINTER_
int main(){
    
    int* p =  (int*) aligned_malloc(sizeof(int)* 5,16);
    aligned_free(p);
}
#endif