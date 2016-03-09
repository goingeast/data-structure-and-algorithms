class Solution {
public:
    void solve(vector<vector<char>>& board) {
        //need start points to check out all the board, which is zero on border.
        
        int row = board.size();
        int col = (row != 0) ? board[0].size(): 0;
        if(row == 0 || col == 0){
            return;
        }
        
        for(int i = 0; i < row; ++i){
            if(board[i][0] == 'O'){
                BFS(board, i, 0);
            }
            if(board[i][col-1] == 'O'){
                BFS(board, i, col -1);
            }
        }
        
        for(int j = 0; j < col; ++j){
            if(board[0][j] == 'O'){
                BFS(board, 0, j);
            }
            if(board[row -1][j] == 'O'){
                BFS(board, row - 1, j);
            }
        }
        
        for (int i = 0; i < row; ++i)
            for (int j = 0; j < col; ++j)
                if (board[i][j] == '#') 
                    board[i][j] = 'O';
                else 
                    board[i][j] = 'X';
    }
    
    void BFS(vector<vector<char>>& board, int row, int col){
        queue<pair<int,int>> bfs;
        
        bfs.push(make_pair(row, col));
        while(!bfs.empty()){
            auto top = bfs.front();
            bfs.pop();
            if (top.first >= 0 && top.first < board.size() && top.second >= 0 && top.second < board[0].size() && board[top.first][top.second] == 'O') {
                board[top.first][top.second] = '#';
                bfs.push(make_pair(top.first - 1, top.second));
                bfs.push(make_pair(top.first + 1, top.second));
                bfs.push(make_pair(top.first, top.second + 1));
                bfs.push(make_pair(top.first, top.second - 1));
            }
        }
    }
};