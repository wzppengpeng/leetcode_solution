/**
 * You are playing a simplified Pacman game. You start at the point (0, 0), and your destination is (target[0], target[1]). There are several ghosts on the map, the i-th ghost starts at (ghosts[i][0], ghosts[i][1]).

Each turn, you and all ghosts simultaneously *may* move in one of 4 cardinal directions: north, east, west, or south, going from the previous point to a new point 1 unit of distance away.

You escape if and only if you can reach the target before any ghost reaches you (for any given moves the ghosts may take.)  If you reach any square (including the target) at the same time as a ghost, it doesn't count as an escape.

Return True if and only if it is possible to escape.
 */

/**
 * 判断目标距离小于goast目标距离即可
 */

class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& t) {
        int d = abs(t[0]) + abs(t[1]);
        for(auto g: ghosts)
            if (d >= abs(t[0] - g[0]) + abs(t[1] - g[1]))
                return false;
        return true;
    }
};