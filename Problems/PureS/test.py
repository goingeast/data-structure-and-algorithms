''' pure storage buddy system bitmap
    Given a complete binary tree with nodes of values of either 1 or 0, the following rules always hold:
    (1) a node's value is 1 if and only if all its subtree nodes' values are 1
    (2) a leaf node can have value either 1 or 0
    Implement the following 2 APIs:
    set_bit(offset, length), set the bits at range from offset to offset+length-1
    clear_bit(offset, length), clear the bits at range from offset to offset+length-1
    
    i.e. The tree is like:
                 0
              /     \
             0        1
           /  \      /  \
          1    0    1    1
         /\   / \   / 
        1  1 1   0 1
        Since it's complete binary tree, the nodes can be stored in an array:
        [0,0,1,1,0,1,1,1,1,1,0,1] 
        
'''

def setbit_down(A, x, n):
    if x>=n:
        return
    if 2*x+1<=n and A[2*x+1]==0:
        A[2*x+1]=1
        setbit_down(A,2*x+1,n)
    if 2*x+2<=n and A[2*x+2]==0:
        A[2*x+2]=1
        setbit_down(A,2*x+2,n)
    

def set_bit(A, pos, length):
    if not A or pos<0 or length<=0:
        return
    n = len(A)-1    #last index of A
    for x in range(pos, min(n+1,min(pos+length, 2*pos+1))):
        # set self
        if A[x] == 1:
            continue
        A[x]=1
        # set descendants
        setbit_down(A,x,n)
        # set ancestors
        while x>0:
            if (x%2==0 and A[x-1]==1) or (x%2==1 and x<n and A[x+1]==1):
                A[(x-1)/2] = 1
            x = (x-1)/2

def clear_bit(A, pos, length):
    if not A or pos<0 or length<=0:
        return
    n = len(A)-1    #last index of A
    for x in range(pos, min(n+1, pos+length)):
        # clear self
        if A[x]==0:
            continue
        A[x]=0
        # clear descendants
        while 2*x+1<=n:
            A[2*x+1] = 0
            x=2*x+1
        # clear ancestors
        while x>0:
            if A[(x-1)/2]==0:
                break
            A[(x-1)/2] = 0
            x = (x-1)/2
     
''' Pure storage:
    Given a parameter r2, where the equation x^2+y^2=r2 holds.
    Return a list of points that 
        (1) x and y are both integers
        (2) fits the circle equation
'''

from sets import Set

import profile



def draw_circle(r2):
    result = Set([])
    x = 1
    y = 0
    while x*x <= r2:
        for y in range(x+1):
            if x*x+y*y == r2:
                result.update(Set([(x,y),(x,-y),(-x,-y),(-x,y),(y,x),(y,-x),(-y,-x),(-y,x)]))
        x+=1
    return result

def draw_circle_bi_search(r2):
    result = Set([])
    x = 1
    y = 0
    while x*x <= r2:
        y_start = 0
        y_end = x
        while y_start <= y_end:
            y_mid = y_start+(y_end-y_start)/2
            if x*x + y_mid*y_mid == r2:
                result.update(Set([(x,y_mid),(x,-y_mid),(-x,-y_mid),(-x,y_mid),(y_mid,x),(y_mid,-x),(-y_mid,-x),(-y_mid,x)]))
                break
            elif x*x + y_mid*y_mid < r2:
                y_start = y_mid+1
            else:
                y_end = y_mid-1
                
                 
        x+=1
    return result

if __name__=='__main__':
    profile.run('print draw_circle(16)')
    profile.run('print draw_circle_bi_search(16)')
    

# if __name__=='__main__':
#     A=[0,0,1,1,0,1,1,1,1,1,0,1]
#     test_cases = [(x,y) for x in range(len(A)) for y in range(1,len(A)-x+1)]
    
#     for each_test_case in test_cases:
#         pos, length = each_test_case        
#         A=[0,0,1,1,0,1,1,1,1,1,0,1]
#         set_bit(A,pos, length)
#         print 'after setting bit from ', pos, 'for ', length,'A is: ', A
#         A=[0,0,1,1,0,1,1,1,1,1,0,1]
#         clear_bit(A,pos, length)
#         print 'after clearing bit from ', pos, 'for ', length,'A is: ', A
#         