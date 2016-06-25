class Solution {
public:
    string simplifyPath(string path) {
        string res, tmp;
        vector<string> stk;
        stringstream ss(path);
        while(getline(ss,tmp,'/')) {
            //if (tmp == "" or tmp == ".") continue;
            if (tmp == ".."){
                if( !stk.empty()){
                    stk.pop_back();
                }
            }else if (tmp != "." && tmp != "") stk.push_back(tmp);
        }
        for(auto str : stk) res += "/"+str;
        return res.empty() ? "/" : res;
    }
};