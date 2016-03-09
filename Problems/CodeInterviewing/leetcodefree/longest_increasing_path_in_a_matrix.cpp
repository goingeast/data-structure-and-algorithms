class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int rowSize = matrix.size();
        int colSize = rowSize > 0 ? matrix[0].size() : 0;
        vector<vector<int>> state(m, vector<int>(n,0));

        int ret = 0;
        for(int i = 0; i < rowSize; ++i){
        	for(int j = 0; j < colSize; ++j){
        		if(state[i][j] == 0)
        			dfs(matrix, i, j, ret, state);
        	}
        }
        return ret;
    }

    void dfs(vector<vector<int>>& matrix, int row, int col, int& maxlength, vector<vector<int>& state){
    	if(state[i][j] != 0)
    		return state[i][j];
    	int len1=0, len2=0, len3=0, len4=0;

    	if((row + 1) < matrix.size() && matrix[row+1][col] > matrix[i][j]){
    		len1 = dfs(matrix, row+1, col, maxlength);
    	}

    	if((row - 1) >= 0 && matrix[row - 1][col] > matrix[i][j]){
    		len2 = dfs(matrix, row-1, col, maxlength);
    	}

    	if((col + 1) < matrix[0].size() && matrix[row][col+1] > matrix[i][j]){
    		len3 = dfs(matrix, row+1, col, maxlength);
    	}

    	if((col - 1) >= 0 && matrix[row][col-1] > matrix[i][j]){
    		len4 = dfs(matrix, row-1, col, maxlength);
    	}
    	state[i][j] =  max(max(max(len1, len2), len3), len4);
        state[i][j]++;
 
    	maxlength = max(state, maxlength);
    	return state[i][j];
    }
};