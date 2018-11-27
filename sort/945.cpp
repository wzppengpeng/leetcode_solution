/**
 * Given an array of integers A, a move consists of choosing any A[i], and incrementing it by 1.

Return the least number of moves to make every value in A unique.


Example 1:

Input: [1,2,2]
Output: 1
Explanation:  After 1 move, the array could be [1, 2, 3].
Example 2:

Input: [3,2,1,2,1,7]
Output: 6
Explanation:  After 6 moves, the array could be [3, 4, 1, 2, 5, 7].
It can be shown with 5 or less moves that it is impossible for the array to have all unique values.
 */

/**
 * 首先排序，然后从前往后遍历，判断当前值和最大值的差距，即而需要修改的次数，加到总和上
 */


class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        if(A.empty()) return 0;
        std::sort(std::begin(A), std::end(A));
        int res = 0, max_val = A[0];
        for(size_t i = 1; i < A.size(); ++i) {
            auto add_val = std::max(0, max_val - A[i] + 1);
            res += add_val;
            max_val = std::max(max_val, A[i] + add_val);
        }
        return res;
    }
};