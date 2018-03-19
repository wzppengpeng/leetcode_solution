/**
 * 
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note: The solution set must not contain duplicate triplets.

For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
 */


/**
 * 首先排序，然后使用三个指针，使用对第一个从前往后，这样才能遍历到所有情况
 * 每次在向前遍历时注意相同的情况，进行跳过
 */

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size() < 3) return res;
        std::sort(std::begin(nums), std::end(nums));
        for(size_t f = 0; f < nums.size() - 2; ++f) {
            if(f != 0 && nums[f] == nums[f - 1]) continue;
            size_t s = f + 1, t = nums.size() - 1;
            while(s < t) {
                auto cur_sum = nums[f] + nums[s] + nums[t];
                if(cur_sum == 0) res.emplace_back(assign(nums, f, s, t));
                if(cur_sum > 0) {
                    --t;
                    while(s < t && nums[t] == nums[t + 1]) --t;
                } else {
                    ++s;
                    while(s < t && nums[s] == nums[s - 1]) ++s;
                }
            }
        }
        return res;
    }

    vector<int> assign(const vector<int>& nums, size_t f, size_t s, size_t t) {
        vector<int> r(3, 0);
        r[0] = nums[f];
        r[1] = nums[s];
        r[2] = nums[t];
        return r;
    }
};