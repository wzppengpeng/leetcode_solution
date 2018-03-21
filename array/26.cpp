/**
 * Given a sorted array, remove the duplicates in place such that each element appear only once and
 *  return the new length.

    Do not allocate extra space for another array, you must do this in place with constant memory.
 */

/**
 * 使用vector::erase，性能很不错
 */


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //use std::erase
        if(nums.empty()) return 0;
        int now = nums[0];
        for(auto it = nums.begin() + 1; it != nums.end(); ) {
            if(*it == now) {
                nums.erase(it);
            }
            else {
                now = *it;
                ++it;
            }
        }
        return nums.size();
    }
};

/**
 * 正确解法，快排的partion,从左往右进行交换
 */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() < 2) return nums.size();
        int i = 0, j = 1;
        int pre = nums[i];
        while(j < nums.size()) {
            if(nums[j] != pre) {
                std::swap(nums[++i], nums[j]);
                pre = nums[i];
            }
            ++j;
        }
        return i + 1;
    }
};