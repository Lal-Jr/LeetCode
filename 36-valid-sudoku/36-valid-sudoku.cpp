class Solution {
public:
bool isSafe(vector<vector<char>> &board, int r, int c, char val){
    for(int i=0; i<board.size(); i++){
        if(board[i][c] == val)
            return false;
        
        if(board[r][i] == val)
            return false;
        
        if(board[3*(r/3) + i/3][3*(c/3) + i%3] == val)
            return false;
    }
    return true;
}

bool isValidSudoku(vector<vector<char>>& board) {
    for(int row=0; row<board.size(); row++){
        for(int col=0; col<board.size(); col++){   
            if(board[row][col] != '.'){
                char val = board[row][col];
                board[row][col] = '.';
                if(!isSafe(board, row, col, val))
                    return false;
                board[row][col] = val;
            }
        }
    }
    return true;
}
};