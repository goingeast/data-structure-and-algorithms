class Solution {
public:
    int lengthOfLastWord(string s) {
        int iter = s.size()-1;
        int length =0;
        while(iter >=0 && s[iter] == ' '){
            iter--;
        }
        while(iter >=0 && s[iter] != ' '){
            length++;
            iter--;
        }
        return length;
    }
};