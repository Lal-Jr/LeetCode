class Solution {
public:
    bool isSafe(int row,int col,vector<string>& board,int n){
        int x = row,y = col;
        
        while(y>=0){
            if(board[x][y] == 'Q')
                return false;
            y--;
        }
        
        x = row;
        y = col;
        while(x>=0 && y>=0){
            if(board[x][y] == 'Q')
                return false;
            y--;
            x--;
        }
        
        x = row;
        y = col;
        while(x<n && y>=0){
            if(board[x][y] == 'Q')
                return false;
            y--;
            x++;
        }
        
        return true;
    }
    
    void solve(vector<string>& board, vector<vector<string>>& ans,int n,int col){ 
          if(col == n){
            ans.push_back(board);
            return;
        }
        
        for(int row = 0; row<n; row++){
            if(isSafe(row,col,board,n)){
                board[row][col] = 'Q';
                solve(board, ans, n , col+1);
                board[row][col] = '.';
            }
        }
    }
    
    int totalNQueens(int n) {
        string str(n ,'.');
        vector<string> board(n, str);
        vector<vector<string>> ans;
        solve(board,ans,n,0);
        return ans.size();
    }
};