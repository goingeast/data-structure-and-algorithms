class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size())
            return false;
        unordered_map<char,char> s1;
        unordered_map<char,char> t2;
        for(int i=0; i< s.size(); ++i){
            if(s1[s[i]] ==0 && 0 == t2[t[i]]){
                 s1[s[i]] = t[i];
                 t2[t[i]] = s[i];
            }else if (s1[s[i]] != t[i] || t2[t[i]] != s[i]){
                return false;    
            }
        }
        return true;
    }
};