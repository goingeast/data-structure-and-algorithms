class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int rowSize = matrix.size();
        int colSize = rowSize > 0 ? matrix[0].size() : 0;
        vector<vector<int>> state(rowSize, vector<int>(colSize,0));

        int ret = 0;
        for(int i = 0; i < rowSize; ++i){
        	for(int j = 0; j < colSize; ++j){
        		if(state[i][j] == 0)
        			dfs(matrix, i, j, ret, state);
        	}
        }
        return ret;
    }

    int dfs(vector<vector<int>>& matrix, int row, int col, int& maxlength, vector<vector<int>>& state){
    	if(state[row][col] != 0)
    		return state[row][col];
    		
    	int len1=0, len2=0, len3=0, len4=0;

    	if((row + 1) < matrix.size() && matrix[row+1][col] > matrix[row][col]){
    		len1 = dfs(matrix, row+1, col, maxlength,state);
    	}

    	if((row - 1) >= 0 && matrix[row - 1][col] > matrix[row][col]){
    		len2 = dfs(matrix, row-1, col, maxlength,state);
    	}

    	if((col + 1) < matrix[0].size() && matrix[row][col+1] > matrix[row][col]){
    		len3 = dfs(matrix, row, col+1, maxlength,state);
    	}

    	if((col - 1) >= 0 && matrix[row][col-1] > matrix[row][col]){
    		len4 = dfs(matrix, row, col-1, maxlength,state);
    	}
    	state[row][col] =  max(max(max(len1, len2), len3), len4);
        state[row][col]++;
 
    	maxlength = max(state[row][col], maxlength);
    	return state[row][col];
    }
};