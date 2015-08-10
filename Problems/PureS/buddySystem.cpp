/*''' pure storage buddy system bitmap
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
        
'''*/

/* x leftchild = 2x+1, rightchild = 2x-1, parent = (x+1)/2 */

void setBit_down(vector<int>& buddySystem, int x){
    int n = (int)buddySystem.size();
    if(x >= n){
        return;
    }
    if(2 * x + 1 < n && buddySystem[2 * x + 1] == 0){
        buddySystem[ 2 * x + 1] = 1;
        setBit_down( buddySystem, 2*x+1);
    }
    if(2 * x + 2 < n && buddySystem[2 * x + 2] == 0){
        buddySystem[ 2 * x + 2] = 1;
        setBit_down( buddySystem, 2*x+2);
    }
}

void setBit(vector<int>& buddySystem, int pos, int length){
    if(pos < 0 || length <= 0)
        return;
    int boudary = min<int>((int)buddySystem.size(), min( pos+length, 2*pos + 1));
    for(int i = pos; i < boudary; ++i){
        if(buddySystem[i] == 1)
            continue;
        buddySystem[i] = 1;
        setBit_down(buddySystem,i);
        int x = i;
        while(x > 0){
            if( (x%2 == 0 && buddySystem[x-1] == 1) || (x%2 == 1&& buddySystem[x+1] == 1))
                buddySystem[(x-1)/2] = 1;
            x = (x-1)/2;
        }
    }
}

void clearBit(vector<int>& buddySystem, int pos, int length){
    if(pos<0 || length <= 0)
        return;
    int boudary = min<int>((int)buddySystem.size(), pos+length);
    
    for(int i = pos; i < boudary; ++i){
        if(buddySystem[i] == 0)
            continue;
        buddySystem[i] = 0;
        int x = i;
        while(2 * x + 1 < buddySystem.size()){
            buddySystem[2 * x + 1] = 0;
            x = 2 * x + 1;
        }
        x = i;
        while( x > 0){
            if(buddySystem[(x-1)/2] == 0)
                break;
            buddySystem[(x-1)/2] = 0;
            x = (x-1)/2;
        }
    }
}

int main(){
    std::vector<int> v;

}




