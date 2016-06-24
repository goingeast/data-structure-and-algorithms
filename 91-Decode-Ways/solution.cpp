class Solution {
public:
    int numDecodings(string s) {

    	if(s.size() == 0)
    		return 0;

    	vector<int> dp(s.size()+1, 0);

    	dp[0] = 1;
    	dp[1] = (s[0] == '0') ? 0:1;

    	for(int i = 2; i <= s.size(); ++i){
    		char first = s[i-1];
    		char second = s[i-2];

    		if( first >= '1' && first <= '9'){
    			dp[i] = dp[i-1];
    		}

    		if((second == '1' && (first>= '0' && first <= '9')) || (second == '2' && (first >= '0' && first <= '6'))){
    			dp[i] += dp[i-2];
    		}
    	}
        
        return dp[s.size()];
    }
};