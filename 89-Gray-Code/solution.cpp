class Solution {
public:
    vector<int> grayCode(int n) {
        
        vector<int>r;
        for (int i = 0; i < 1<<n; i++)
        {
            r.push_back(i>>1 ^ i);
        }
        return r;
    }
    
    void graycode(int n, int candidate, int prev, vector<int>& result){
        if( n ==  -1){
            result.push_back(candidate);
            return;
        }
        if( prev == 0){
            graycode( n -1, candidate, 0, result);
            candidate |= 1 << n;
            graycode( n - 1, candidate, 1, result);
            candidate &= ~(1 << n);    
        }else{
            candidate |= 1 << n;
            graycode( n - 1, candidate, 0, result);
            candidate &= ~(1 << n); 
            graycode( n -1, candidate, 1, result);
        }
        
        
    }
};