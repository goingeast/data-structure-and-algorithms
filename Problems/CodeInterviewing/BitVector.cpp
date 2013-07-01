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
#ifdef BIT_VECTOR
int main(){
    bitSet a(3200);
    
    for(int i=0; i < 33; ++i){
    
        if(a.get(i)){
            
        }else{
            a.set(i);
            
        }
    }
    
}
#endif
  

