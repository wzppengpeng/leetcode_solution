/**
 * Given a matrix A, return the transpose of A.

The transpose of a matrix is the matrix flipped over it's main diagonal, switching the row and column indices of the matrix.
 */


/**
 * 没什么好说的，循环一下
 */

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        size_t row = A.size(), col = A[0].size();
        vector<vector<int>> res(col, vector<int>(row, 0));
        for(size_t i = 0; i < row; ++i) {
            for(size_t j = 0; j < col; ++j) {
                res[j][i] = A[i][j];
            }
        }
        return res;
    }
};