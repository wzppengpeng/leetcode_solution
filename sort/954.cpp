/**
 * 954. Array of Doubled Pairs
Medium
27
4


Given an array of integers A with even length, return true if and only if it is possible to reorder it such that A[2 * i + 1] = 2 * A[2 * i] for every 0 <= i < len(A) / 2.


Example 1:

Input: [3,1,3,6]
Output: false
Example 2:

Input: [2,1,2,6]
Output: false
Example 3:

Input: [4,-2,2,-4]
Output: true
Explanation: We can take two groups, [-2,-4] and [2,4] to form [-2,-4,2,4] or [2,4,-2,-4].
Example 4:

Input: [1,2,4,16,8,4]
Output: false
 */

/**
 * Count all numbers.
Loop all numbers on the order of its absolute.
We have counter[x] of x, so we need the same amount of 2x wo match them.
If c[x] > c[2 * x], then we return false
If c[x] <= c[2 * x], then we do c[2 * x] -= c[x] to remove matched 2x.
Don't worry about 0, it doesn't fit the logic above but it won't break our algorithme.
 */


class Solution {
public:
    bool canReorderDoubled(vector<int>& A) {
        unordered_map<int, int> cnt;
        for(auto a : A) ++cnt[a];
        vector<int> keys(cnt.size());
        std::transform(std::begin(cnt), std::end(cnt), std::begin(keys),
            [](const std::pair<int, int>& p) { return p.first; });
        std::sort(std::begin(keys), std::end(keys),
            [](int l, int r) { return std::abs(l) < std::abs(r); });
        for(int k : keys) {
            if(cnt[k] > cnt[2 * k])
                return false;
            cnt[2 * k] -= cnt[k];
        }
        return true;
    }
};