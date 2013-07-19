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

#ifdef BIT_VECTOR
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
    cout << getSetBitsFromOneToN(6);
    if(1>0){
        cout<<'k';
    }
}
#endif
  

