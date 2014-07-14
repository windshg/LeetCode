// 

class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        int m = board.size();
        if (m == 0) return false;
        int n = board[0].size();
        if (n == 0) return false;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (exist(board, i, j, word, 0)) 
                    return true;
            }
        }
        return false;
    }
    
    bool exist(vector<vector<char> > &board, int i, int j, string &word, int k) {
        if (k >= word.size()) return true;
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) return false;
        if (board[i][j] != word[k] || board[i][j] == '*') return false;
        board[i][j] = '*';
        bool ret = exist(board, i + 1, j, word, k + 1) ||
                exist(board, i - 1, j, word, k + 1) ||
                exist(board, i, j + 1, word, k + 1) ||
                exist(board, i, j - 1, word, k + 1);
        board[i][j] = word[k];
        return ret;
    }
};