// Surrounded Regions

class Solution {
public:
    void solve(vector<vector<char>> &b) {
        int m = b.size();
        if(m == 0) return;
        int n = b[0].size();
        for(int i = 0; i < m; ++i) {bfs(b, i, 0); bfs(b, i, n-1);}
        for(int j = 1; j < n-1; ++j) {bfs(b, 0, j); bfs(b, m-1, j);}
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(b[i][j] == 'O') b[i][j] = 'X';
                if(b[i][j] == '+') b[i][j] = 'O';
            }
        }
    }
    
    void bfs(vector<vector<char>> &b, int i, int j) {
        if(i == b.size() || i < 0 || j == b[0].size() || j < 0) return;
        if(b[i][j] != 'O') return;
        b[i][j] = '+';
        bfs(b, i+1, j);
        bfs(b, i-1, j);
        bfs(b, i, j+1);
        bfs(b, i, j-1);
    }
};