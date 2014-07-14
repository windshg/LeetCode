// stupid method
class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > ret(n, vector<int>(n));
        int val = 1;
        int pad[4] = {0}; // up, right, down, left
        int dmp[4] = {0, 1, 2, 3}; // right, down, left, up
        int dir = 0, i = 0, j = 0, total = n * n;
        while (val <= total) {
            ret[i][j] = val ++;
            
            if (dir == 0 && j == n - pad[1] - 1) {dir = 1; pad[0] ++;}
            else if (dir == 1 && i == n - pad[2] - 1) {dir = 2; pad[1] ++;}
            else if (dir == 2 && j == pad[3]) {dir = 3; pad[2] ++;}
            else if (dir == 3 && i == pad[0]) {dir = 0; pad[3] ++;}
            
            if (dir == 0) ++ j;
            if (dir == 1) ++ i;
            if (dir == 2) -- j;
            if (dir == 3) -- i;
        }
        
        return ret;
    }
};



// generate matrix, shorter solution
class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > ret(n, vector<int>(n));
        if (n <= 0) return ret;
        int imin = 0, imax = n - 1, jmin = 0, jmax = n - 1;
        int i = 0, j = 0, val = 1;
        while (true) {
            for (int j = jmin; j <= jmax; ++j) ret[imin][j] = val ++;
            if (++imin > imax) break;
            for (int i = imin; i <= imax; ++i) ret[i][jmax] = val ++;
            if (--jmax < jmin) break;
            for (int j = jmax; j >= jmin; --j) ret[imax][j] = val ++;
            if (--imax < imin) break;
            for (int i = imax; i >= imin; --i) ret[i][jmin] = val ++;
            if (++jmin > jmax) break;
        }
        return ret;
    }
};