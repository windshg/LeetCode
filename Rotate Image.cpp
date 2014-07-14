// Done
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int n = matrix.size();
        int imin = 0, imax = n - 1, jmin = 0, jmax = n - 1;
        while (true) {
            for (int k = 0; k < jmax - jmin; ++k) {
                int t1 = matrix[imin+k][jmax];
                matrix[imin+k][jmax] = matrix[imin][jmin+k];
                int t2 = matrix[imax][jmax-k];
                matrix[imax][jmax-k] = t1;
                int t3 = matrix[imax-k][jmin];
                matrix[imax-k][jmin] = t2;
                matrix[imin][jmin+k] = t3;
            }
            if (++ imin > -- imax || ++ jmin > -- jmax) break;
        }
    }
};