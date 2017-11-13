/**
 * Given an array of integers nums, write a method that returns the "pivot" index of this array.

We define the pivot index as the index where the sum of the numbers to the left of the index is equal to the sum of the numbers to the right of the index.

If no such index exists, we should return -1. If there are multiple pivot indexes, you should return the left-most pivot index.
 */

/**
 * 使用一个前向求和数组保存前期求和数据，然后从左到右依次判断相等的位置，返回第一个位置
 */


class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if(nums.empty()) return -1;
        vector<int> sum_vals(nums.size(), nums.front());
        for(size_t i = 1; i < nums.size(); ++i) {
            sum_vals[i] = sum_vals[i - 1] + nums[i];
        }
        int sum_total = sum_vals.back();
        for(int j = 0; j < nums.size(); ++j) {
            if(sum_vals[j] - nums[j] == sum_total - sum_vals[j]) return j;
        }
        return -1;
    }
};