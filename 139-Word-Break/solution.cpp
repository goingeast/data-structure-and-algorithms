class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        bool* res = new bool[s.size()+1]();
        res[0] = true;
        for(int i=0; i< s.size(); i++){
            
            for(int j = 0; j<=i; j++){
                
                if(res[j] && wordDict.find(s.substr(j, i-j+1))!=wordDict.end()){
                    res[i+1] = true;
                }
            }
        }
        
        bool ret = res[s.size()];
        return ret;
        
    }
};