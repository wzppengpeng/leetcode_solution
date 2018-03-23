/**
 * Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.
 */

/**
 * 只需要记录当前位置可以到达的最远位置即可，如果前面不能到达该位置，则返回false
 */

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.empty()) return false;
        if(nums.size() == 1) return true;
        int last = 0;
        for(int i = 0; i < nums.size() - 1; ++i) {
            if(last < i) return false;
            last = std::max(last, i + nums[i]);
        }
        return last >= (nums.size() - 1);
    }
};