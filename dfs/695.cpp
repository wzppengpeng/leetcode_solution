/**
 * Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)
 */

/**
 * 使用一个辅助矩阵来保存是否遍历过该位置，优先dfs进行判断距离
 */

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        vector<vector<int>> walk(grid.size(), vector<int>(grid[0].size(), 0));
        int max_val = 0;
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[0].size(); ++j) {
                if(walk[i][j] || grid[i][j] == 0) continue;
                int temp = 0;
                dfs(grid, walk, i, j, temp);
                max_val = std::max(max_val, temp);
            }
        }
        return max_val;
    }

    void dfs(const vector<vector<int>>& grid, vector<vector<int>>& walk, int i, int j, int& cnt) {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) return;
        if(walk[i][j] || grid[i][j] == 0) return;
        ++cnt;
        walk[i][j] = 1;
        dfs(grid, walk, i, j + 1, cnt);
        dfs(grid, walk, i, j - 1, cnt);
        dfs(grid, walk, i + 1, j, cnt);
        dfs(grid, walk, i - 1, j, cnt);
    }
};