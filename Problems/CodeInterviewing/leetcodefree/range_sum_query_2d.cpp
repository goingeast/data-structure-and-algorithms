class NumMatrix {
private:
	vector<std::vector<int>> sums;
public:
    NumMatrix(vector<vector<int>> &matrix) {
    	int rowSize = matrix.size();
    	int colSize = rowSize > 0 ? matrix[0].size() : 0;
    	sums = vector< vector<int> >(rowSize+1, vector<int>(colSize+1,0));

    	for(int i = 1; i <= rowSize; ++i){
    		for(int j = 1; j <= colSize; ++j){
    			sums[i][j] = sums[i-1][j] + sums[i][j-1] - sums[i-1][j-1] + matrix[i-1][j-1];
    		}
    	}
        
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return sums[row2+1][col2+1] - sums[row2+1][col1] - sums[row1][col2+1] + sums[row1][col1]; 
    }
};