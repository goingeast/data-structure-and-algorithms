class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        bool* res = new bool[s.size()+1]();
        res[0] = true;
        for(int i=1; i<= s.size(); i++){
            
            for(int j = i -1; j>=0; j--){
                
                if(res[j] && wordDict.find(s.substr(j, i-j))!=wordDict.end()){
                    res[i] = true;
                }
            }
        }
        
        bool ret = res[s.size()];
        return ret;
        
    }
};