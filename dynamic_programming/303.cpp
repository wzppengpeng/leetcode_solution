/**
 * Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

Example:
Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
Note:
You may assume that the array does not change.
There are many calls to sumRange function.
 */

/**
 * 记录所有的和，某个区间的和是现在位置的所有和减去前向位置的所有和
 */


class NumArray {
public:
    NumArray(vector<int> nums) : m_range_sum(nums.size(), 0) {
        for(size_t i = 0; i < nums.size(); ++i) {
            m_range_sum[i] = i == 0 ? nums[i] : nums[i] + m_range_sum[i - 1];
        }
    }

    int sumRange(int i, int j) {
        return i == 0 ? m_range_sum[j] : m_range_sum[j] - m_range_sum[i - 1];
    }

    std::vector<int> m_range_sum;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */