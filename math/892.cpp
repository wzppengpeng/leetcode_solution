/**
 * On a N * N grid, we place some 1 * 1 * 1 cubes.

Each value v = grid[i][j] represents a tower of v cubes placed on top of grid cell (i, j).

Return the total surface area of the resulting shapes.


Example 1:

Input: [[2]]
Output: 10
Example 2:

Input: [[1,2],[3,4]]
Output: 34
Example 3:

Input: [[1,0],[0,2]]
Output: 16
Example 4:

Input: [[1,1,1],[1,0,1],[1,1,1]]
Output: 32
Example 5:

Input: [[2,2,2],[2,1,2],[2,2,2]]
Output: 46
 */


/**
 * 逐一遍历，考虑每一个单点的上下两个方向，前侧方向，左侧方向（相邻两个会有重叠）即可
 */


class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int area = 0;
        size_t N = grid.size();
        for(size_t i = 0; i < N; ++i) {
            for(size_t j = 0; j < N; ++j) {
                if(grid[i][j]) area += 2;
                if(i == 0) area += grid[i][j];
                if(i == N - 1) area += grid[i][j];
                if(i > 0) area += std::abs(grid[i][j] - grid[i - 1][j]);
                if(j == 0) area += grid[i][j];
                if(j == N - 1) area += grid[i][j];
                if(j > 0) area += std::abs(grid[i][j] - grid[i][j - 1]);
            }
        }
        return area;
    }
};