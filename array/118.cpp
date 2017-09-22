/**
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
 */

/**
 * 按照定义生成即可，注意一下边界问题
 */


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows);
        for(int i = 0; i < numRows; ++i) {
            res[i].resize(i + 1);
            res[i].front() = 1;
            res[i].back() = 1;
            for(int j = 1; j < res[i].size() - 1; ++j) {
                res[i][j] = res[i - 1][j] + res[i - 1][j - 1];
            }
        }
        return std::move(res);
    }
};