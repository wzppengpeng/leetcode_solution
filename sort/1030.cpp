/**
 * We are given a matrix with R rows and C columns has cells with integer coordinates (r, c), where 0 <= r < R and 0 <= c < C.

Additionally, we are given a cell in that matrix with coordinates (r0, c0).

Return the coordinates of all cells in the matrix, sorted by their distance from (r0, c0) from smallest distance to largest distance.  Here, the distance between two cells (r1, c1) and (r2, c2) is the Manhattan distance, |r1 - r2| + |c1 - c2|.  (You may return the answer in any order that satisfies this condition.)
 */

/**
 * 先把所有的dis算出来，然后用sort排序
 */

class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> coordinates;
        coordinates.reserve(R * C);
        for(int r = 0; r < R; ++r) {
            for(int c = 0; c < C; ++c) {
                coordinates.emplace_back(std::vector<int>{r, c});
            }
        }
        std::sort(std::begin(coordinates), std::end(coordinates),
            [r0, c0, this](const vector<int>& left, const vector<int>& right) {
                return l1_dis(r0, c0, left[0], left[1])
                    < l1_dis(r0, c0, right[0], right[1]);
            });
        return coordinates;
    }

    inline int l1_dis(int r0, int c0, int r, int c) const {
        return std::abs(r0 - r) + std::abs(c0 - c);
    }
};