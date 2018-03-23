/**
 * Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
 */

/**
 * 使用第一行第一列进行记录
 */

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix.front().empty()) return;
        size_t m = matrix.size(), n = matrix[0].size();
        bool row = false, col = false;
        for(size_t i = 0; i < m; ++i) {
            for(size_t j = 0; j < n; ++j) {
                if(matrix[i][j] == 0) {
                    if(i == 0) row = true;
                    if(j == 0) col = true;
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for(size_t i = 1; i < m; ++i) {
            if(matrix[i][0] == 0) set_zero_row(matrix, i, n);
        }
        for(size_t j = 1; j < n; ++j) {
            if(matrix[0][j] == 0) set_zero_col(matrix, j, m);
        }
        if(row) set_zero_row(matrix, 0, n);
        if(col) set_zero_col(matrix, 0, m);
    }

    void set_zero_row(vector<vector<int>>& matrix, size_t i, size_t n) {
        for(size_t j = 1; j < n; ++j) matrix[i][j] = 0;
    }

    void set_zero_col(vector<vector<int>>& matrix, size_t j, size_t m) {
        for(size_t i = 1; i < m; ++i) matrix[i][j] = 0;
    }
};
