class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        
        //global[i][j] means at ith day we already have jth trade
        //local[i][j] means we sell on ith day and then we have jth trade
        
        //global[i][j] means then max profit at ith day we already have jth trade

        // global[i][j] = max(local[i][j], global[i-1][j])

        //local[i][j] means we sell on ith day and then we have jth trade
        
        //local[i][j] = max(global[i-1][j] + max(diff, 0) , local[i-1][j] + diff)
        int len = prices.size();
        if(len == 0) return 0;
        
        if(k > len/2){
            int profit = 0;
            for (int i = 1; i < len; i++)
            // as long as there is a price gap, we gain a profit.
                if (prices[i] > prices[i - 1]) profit += prices[i] - prices[i - 1];
            return profit;
        }

        vector<vector<int>> global(len, vector<int>(k+1,0));
        vector<vector<int>> local(len, vector<int>(k+1,0));
        
        for(int i =1 ; i < len; ++i){
            int diff = prices[i] - prices[i-1];
            for(int j = 1; j <=k; ++j){
                local[i][j] = max(global[i-1][j-1]  , local[i-1][j] + diff);
            	global[i][j] = max(local[i][j], global[i-1][j]);
            	
            }
        }
        return global[len-1][k];
        
    }
};