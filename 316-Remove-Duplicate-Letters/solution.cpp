class Solution {
public:
    string removeDuplicateLetters(string s) {
        //unordered_map<char, int> hash;
        //unordered_map<char,bool> visited;
        vector<int> hash(256);
        vector<int> visited(256,false); 
        
        string res;
        for(char c : s){
            ++hash[c];
           // visited[c] = false;
        }
        for(char c : s){
            hash[c]--;
            if(!visited[c]){
                while( !res.empty() && c < res.back() && hash[res.back()]){
                    visited[res.back()] = false;
                    res.pop_back();
                }
                
                res.push_back(c);
                visited[c] = true;
                
            }
        }
        return res;
    }
};