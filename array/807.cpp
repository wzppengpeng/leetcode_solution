/**
 * In a 2 dimensional array grid, each value grid[i][j] represents the height of a building located there. We are allowed to increase the height of any number of buildings, by any amount (the amounts can be different for different buildings). Height 0 is considered to be a building as well. 

At the end, the "skyline" when viewed from all four directions of the grid, i.e. top, bottom, left, and right, must be the same as the skyline of the original grid. A city's skyline is the outer contour of the rectangles formed by all the buildings when viewed from a distance. See the following example.

What is the maximum total sum that the height of the buildings can be increased?

Example:
Input: grid = [[3,0,8,4],[2,4,5,7],[9,2,6,3],[0,3,1,0]]
Output: 35
Explanation: 
The grid is:
[ [3, 0, 8, 4], 
  [2, 4, 5, 7],
  [9, 2, 6, 3],
  [0, 3, 1, 0] ]

The skyline viewed from top or bottom is: [9, 4, 8, 7]
The skyline viewed from left or right is: [8, 7, 9, 3]

The grid after increasing the height of buildings without affecting skylines is:

gridNew = [ [8, 4, 8, 7],
            [7, 4, 7, 7],
            [9, 4, 8, 7],
            [3, 3, 3, 3] ]


 */

/**
 * 就是理解题意的问题，把最大值先找出来，然后找到其中的较小值，往上添即可
 */

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        size_t m = grid.size(), n = grid[0].size();
        vector<int> row_high(m, 0), col_high(n, 0);
        for(size_t i = 0; i < m; ++i) {
            row_high[i] = *std::max_element(std::begin(grid[i]), std::end(grid[i]));
        }
        for(size_t j = 0; j < n; ++j) {
            col_high[j] = compute_col_high(grid, j);
        }
        int res = 0;
        for(size_t i = 0; i < m; ++i) {
            for(size_t j = 0; j < n; ++j) {
                res += (std::min(row_high[i], col_high[j]) - grid[i][j]);
            }
        }
        return res;
    }

    int compute_col_high(const vector<vector<int>>& grid, size_t j) {
        int max_ele = INT_MIN;
        for(size_t i = 0; i < grid.size(); ++i) {
            if(grid[i][j] > max_ele) max_ele = grid[i][j];
        }
        return max_ele;
    }
};