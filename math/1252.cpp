/**
 * Given n and m which are the dimensions of a matrix initialized by zeros and given an array indices where indices[i] = [ri, ci]. For each pair of [ri, ci] you have to increment all cells in row ri and column ci by 1.

Return the number of cells with odd values in the matrix after applying the increment to all indices.


 */

/**
 * 使用行列计数器分别计数行列加和总和，然后在计算总体结果
 */


class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        vector<int> row_cnt(n, 0), col_cnt(m, 0);
        for (const auto& indi : indices) {
            ++row_cnt[indi[0]];
            ++col_cnt[indi[1]];
        }
        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if ((row_cnt[i] + col_cnt[j]) & 1 != 0) {
                    ++res;
                }
            }
        }
        return res;
    }
};