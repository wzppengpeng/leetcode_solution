
/**
 * A matrix is Toeplitz if every diagonal from top-left to bottom-right has the same element.

Now given an M x N matrix, return True if and only if the matrix is Toeplitz.
 */

/**
 * 就是固定一个坐标位置，进行迭代即可，注意结束条件，必须让横纵游标都小于上界
 */

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int i = matrix.size() - 1, j = 1, m = matrix.size(), n = matrix[0].size();
        int old = -1;
        for(; i >=0 ; --i) {
            old = -1;
            for(int ii = i, jj = 0; ii < m && jj < n; ++ii, ++jj) {
                if(old == -1) {
                    old = matrix[ii][jj];
                } else {
                    if(matrix[ii][jj] != old) return false;
                }
            }
        }
        for(; j < n; ++j) {
            old = -1;
            for(int ii = 0, jj = j; ii < m && jj < n; ++ii, ++jj) {
                if(old == -1) {
                    old = matrix[ii][jj];
                } else {
                    if(matrix[ii][jj] != old) return false;
                }
            }
        }
        return true;
    }
};