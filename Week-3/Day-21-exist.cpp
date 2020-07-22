class Solution {
public:
    bool dfs(vector<vector<char>>& board, string word, int i, int j, int k)  {
        if(k == word.size())    return true;
        if(i >= 0 and i < board.size() and j >= 0 and j < board[0].size() and 
           board[i][j] == word[k]) {
            char c = board[i][j];
            board[i][j] = '*';
            bool res = dfs(board, word, i+1, j, k+1) or dfs(board, word, i, j+1, k+1) or 
                dfs(board, word, i-1, j, k+1) or dfs(board, word, i, j-1, k+1);
            board[i][j] = c;
            return res;
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(dfs(board, word, i, j, 0)) return true;
        return false;
    }
};
