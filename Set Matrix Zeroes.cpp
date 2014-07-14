// Set Matrix Zeroes

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        for(int i = 0; i < matrix.size(); ++i)
            for(int j = 0; j < matrix[0].size(); ++j) 
                if(matrix[i][j] == 0) {
                    for(int k = 0; k < matrix.size(); ++k) {if(matrix[k][j] != 0) matrix[k][j] = -1;}
                    for(int k = 0; k < matrix[0].size(); ++k) {if(matrix[i][k] != 0) matrix[i][k] = -1;}
                }
        for(int i = 0; i < matrix.size(); ++i)
            for(int j = 0; j < matrix[0].size(); ++j)
                if(matrix[i][j] == -1) matrix[i][j] = 0;       
    }
};