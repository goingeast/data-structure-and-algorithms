// bitvector

#include<iostream>
#include<vector>
using namespace std;

class bitSet{
    vector<int> bits;
    public:
        bitSet(int size){
            for(int i=0; i < (size>>5); ++i){
                bits.push_back(0);
            }
        }
        bool get(int pos){
            int wordNum = (pos >> 5);
            int bitNum = (pos & 0x1F);
            return (bits[wordNum] & (1 << bitNum)) != 0;
        }
        void set(int pos){
            int wordNum = (pos>> 5);
            
            int bitNum = (pos & 0x1F);
            cout << endl;
            cout <<wordNum << ','<< bitNum ;
            bits[wordNum] |= 1 << bitNum;
            
            cout << endl;
            cout << (1 << bitNum);
            cout << endl;
            cout << bits[wordNum];
        }
};


//count the number of 1 in binary from 1 to N;
//
int getSetBitsFromOneToN(int N){
    int period = 2, ans = 0;
    int n = N;
    
    while(n){
        //cout<< n;
        ans += (N/period) * period/2;
        
        if((N%(period) >= period/2 - 1))
            ans += N%(period) - period/2 + 1;
        period <<= 1;
        n>>=1;
    }
    return ans;
}

int getSetBitsFromOneToN1(int N){
    int two = 2,ans = 0;
    int n = N;
    while(n){
        ans += (N/two)*(two>>1);
        if((N&(two-1)) > (two>>1)-1) 
            ans += (N&(two-1)) - (two>>1)+1;
        two <<= 1;
        n >>= 1;
    }
    return ans;
}


/*
 * 32bit integer reverse
 * 0x1010 1010 1010 1010 1010 1010 1010 1010
 * 0x0101 0101 0101 0101 0101 0101 0101 0101
 * 0x1100 1100 1100 1100 1100 1100 1100 1100
 * 0x0011 0011 0011 0011 0011 0011 0011 0011
 * 
 * 
 * 0x1111 0000 1111 0000 1111 0000 1111 0000
 * 0x0000 1111 0000 1111 0000 1111 0000 1111
 * 0x1111 1111 0000 0000 1111 1111 0000 0000
 * 0x0000 0000 1111 1111 0000 0000 1111 1111
 */
unsigned int reverse(unsigned int x)
{
    x = (((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1));
    x = (((x & 0xcccccccc) >> 2) | ((x & 0x33333333) << 2));
    x = (((x & 0xf0f0f0f0) >> 4) | ((x & 0x0f0f0f0f) << 4));
    x = (((x & 0xff00ff00) >> 8) | ((x & 0x00ff00ff) << 8));
    return((x >> 16) | (x << 16));

}

int swapBits(unsigned int x, unsigned int p1, unsigned int p2, unsigned int n)
{
    /* Move all bits of first set to rightmost side */
    unsigned int set1 =  (x >> p1) & ((1U << n) - 1);
 
    /* Move all bits of second set to rightmost side */
    unsigned int set2 =  (x >> p2) & ((1U << n) - 1);
 
    /* XOR the two sets */
    unsigned int xor1 = (set1 ^ set2);
 
    /* Put the xor bits back to their original positions */
    xor1 = (xor1 << p1) | (xor1 << p2);
 
    /* XOR the 'xor' with the original number so that the 
       two sets are swapped */
    unsigned int result = x ^ xor1;
 
    return result;
}

//ifdef BIT_VECTOR
int main(){
//    bitSet a(3200);
//    
//    for(int i=0; i < 33; ++i){
//    
//        if(a.get(i)){
//            
//        }else{
//            a.set(i);
//            
//        }
//    }
//    cout << getSetBitsFromOneToN(6);
//    if(1>0){
//        cout<<'k';
//    }
    size_t i = 6;
    cout << std::hex<<swapBits(6, 1, 3, 1);
}
//#endif
  

