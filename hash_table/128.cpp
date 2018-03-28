/**
 * Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.
 */

/**
 * 利用哈希set的O(1)查找来求解
 */


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() < 2) return nums.size();
        unordered_set<int> s(std::begin(nums), std::end(nums));
        int max_res = 1;
        for(auto n : nums) {
            if(s.count(n) == 0) continue;
            int tmp = 0, now = n;
            do
            {
                ++tmp;
                s.erase(now);
                ++now;
            } while (s.count(now));
            now = n - 1;
            while(s.count(now)) {
                ++tmp;
                s.erase(now);
                --now;
            }
            max_res = std::max(tmp, max_res);
        }
        return max_res;
    }
};
