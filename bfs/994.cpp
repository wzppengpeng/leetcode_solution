/**
 * In a given grid, each cell can have one of three values:

the value 0 representing an empty cell;
the value 1 representing a fresh orange;
the value 2 representing a rotten orange.
Every minute, any fresh orange that is adjacent (4-directionally) to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange.  If this is impossible, return -1 instead.


Example 1:



Input: [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
Example 2:

Input: [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation:  The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
Example 3:

Input: [[0,2]]
Output: 0
Explanation:  Since there are already no fresh oranges at minute 0, the answer is just 0.
 */

/**
 * 使用队列进行bfs的层序遍历，注意在最后时刻判断一下是否还有剩余，如果没有剩余则为全部腐烂
 */


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> que;
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[0].size(); ++j) {
                if(grid[i][j] == 2) que.push({i, j});
            }
        }
        int num = que.size(), res = 0;
        auto walk = [this, &grid, &que](int i, int j) {
            if(is_next(i, j, grid)) {
                grid[i][j] = 2;
                que.push({i, j});
            }
        };
        while(!que.empty()) {
            auto& point = que.front();
            int i = point.first, j = point.second;
            que.pop(); --num;
            walk(i + 1, j);
            walk(i - 1, j);
            walk(i, j - 1);
            walk(i, j + 1);
            if(num == 0) {
                num = que.size();
                if(!que.empty())
                    ++res;
            }
        }
        return is_any_one(grid) ? -1 : res;
    }

    inline bool is_next(int i, int j, const vector<vector<int>>& grid) const {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())
            return false;
        return grid[i][j] == 1;
    }

    bool is_any_one(const vector<vector<int>>& grid) const {
        for(const auto& row : grid) {
            for(const auto g : row) {
                if(g == 1) return true;
            }
        }
        return false;
    }
};