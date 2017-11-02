/**
 * Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct
 */

/**
 * 使用哈希表进行记录，遍历过程中如果出现重复，返回true，否则返回false
 */


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> cnt;
        for(auto num : nums) {
            if(cnt.find(num) != cnt.end()) return true;
            else cnt.emplace(num);
        }
        return false;
    }
};