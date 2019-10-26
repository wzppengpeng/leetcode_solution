/**
 * You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. Check if these points make a straight line in the XY plane.
 */


/**
 * 判断三点是否共线即可，注意存在有0的情况，所以使用乘积式
 */

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        const auto& p0 = coordinates[0];
        const auto& p1 = coordinates[1];
        for (size_t i = 2; i < coordinates.size(); ++i) {
            const auto& p2 = coordinates[i];
            if (!check_tree(p0, p1, p2))
                return false;
        }
        return true;
    }

    bool check_tree(const vector<int>& p0, const vector<int>& p1, const vector<int>& p2) {
        return (p1[0] - p0[0]) * (p2[1] - p0[1]) == (p2[0] - p0[0]) * (p1[1] - p0[1]);
    }

};