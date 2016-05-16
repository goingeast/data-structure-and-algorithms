class Solution {
public:
    bool isMatch(string s, string p) {
    
    //dp[i][j] means, from 0 to i in the s matches from 0 to j in the p or not
    
        int s_size = s.size();
        int p_size = p.size();
        
        vector<vector<bool>> dp(s_size+1, vector<bool>(p_size+1, false));
        
        dp[0][0] = true;
        for(int j=1; j<=p_size; j++) {
            if(p[j-1]=='*'){
                dp[0][j] = true;
            } else {
                break;
            }
        }
        
        for(int i = 1; i <= s_size; ++i){
            for(int j = 1; j <= p_size; ++j){
                if(p[j-1] == '*'){
                    dp[i][j] = dp[i-1][j]||dp[i][j-1];
                }else if(p[j-1] == '?' || p[j-1] == s[i-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = false;
                }
            }
        }
        return dp[s_size][p_size];
    }
};