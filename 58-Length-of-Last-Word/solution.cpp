class Solution {
public:
    int lengthOfLastWord(string s) {
        int iter = s.size()-1;
        int length =0;
        while(iter >=0 && s[iter] == ' '){ // get rid of space
            iter--;
        }
        while(iter >=0 && s[iter] != ' '){ //get the length
            length++;
            iter--;
        }
        return length;
    }
};