class Solution {
public:
    int titleToNumber(string s) {
    	int number = 0;
        for(int i = 0; i < s.size(); ++i){
        	number = (s[i] - 'A' + 1) + number* 26;
        }
        return number;
    }
};