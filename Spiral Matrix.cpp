class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> ret;
        int m = matrix.size();
        if (m <= 0) return ret;
        int n = matrix[0].size();
        int imin = 0, imax = m - 1, jmin = 0, jmax = n - 1;
        while (true) {
            for (int j = jmin; j <= jmax; ++j) ret.push_back(matrix[imin][j]);
            if (++imin > imax) break;
            for (int i = imin; i <= imax; ++i) ret.push_back(matrix[i][jmax]);
            if (--jmax < jmin) break;
            for (int j = jmax; j >= jmin; --j) ret.push_back(matrix[imax][j]);
            if (--imax < imin) break;
            for (int i = imax; i >= imin; --i) ret.push_back(matrix[i][jmin]);
            if (++jmin > jmax) break;
        }
        return ret;
    }
};