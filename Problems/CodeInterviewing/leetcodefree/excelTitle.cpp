class Solution {
public:
    string convertToTitle(int n) {
        string title;
        int remain = n;
        while(remain){
        	--remain;
        	char temp = 'A' + remain%26;
        	title = temp + title;
        	remain = remain/26;
        }
        return title;
    }
};
