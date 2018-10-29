/**
 * Given a square array of integers A, we want the minimum sum of a falling path through A.

A falling path starts at any element in the first row, and chooses one element from each row.  The next row's choice must be in a column that is different from the previous row's column by at most one.



Example 1:

Input: [[1,2,3],[4,5,6],[7,8,9]]
Output: 12
Explanation:
The possible falling paths are:
[1,4,7], [1,4,8], [1,5,7], [1,5,8], [1,5,9]
[2,4,7], [2,4,8], [2,5,7], [2,5,8], [2,5,9], [2,6,8], [2,6,9]
[3,5,7], [3,5,8], [3,5,9], [3,6,8], [3,6,9]
The falling path with the smallest sum is [1,4,7], so the answer is 12.
 */


/**
 * 和杨辉三角一样的思路，保存到目前为止的最小路径，自顶向下
 */

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int min_res = INT_MAX, N = A.size();
        vector<vector<int>> dp(N, vector<int>(N, 0));
        for(int j = 0; j < N; ++j) {
            dp[0][j] = A[0][j];
            min_res = std::min(min_res, dp[0][j]);
        }
        for(int i = 1; i < N; ++i) {
            min_res = INT_MAX;
            for(int j = 0; j < N; ++j) {
                if(j == 0) {
                    dp[i][j] = std::min(dp[i - 1][j], dp[i - 1][j + 1]) + A[i][j];
                } else if(j == N - 1) {
                    dp[i][j] = std::min(dp[i - 1][j - 1], dp[i - 1][j]) + A[i][j];
                } else {
                    dp[i][j] = std::min(std::min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i - 1][j + 1]) + A[i][j];
                }
                min_res = std::min(min_res, dp[i][j]);
            }
        }
        return min_res;
    }
};