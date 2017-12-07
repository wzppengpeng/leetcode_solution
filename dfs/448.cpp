/**
 * Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

 */

/**
 * 由于一定出现在1 ~ n范围内的数，这种情况很适合使用下标dfs循环的方法来做文章
 * 另外额外空间是可以复用的
 */

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> tmp(nums.size(), 0);
        for(int i = 0; i < nums.size(); ++i) dfs(nums, i, tmp);
        vector<int> res;
        for(auto i = 0; i < tmp.size(); ++i) {
            if(tmp[i] == 0) res.emplace_back(i + 1);
        }
        return res;
    }

    void dfs(vector<int>& nums, int i, vector<int>& tmp) {
        if(nums[i] == -1) return;
        int next = nums[i] - 1;
        tmp[next] = -1;
        nums[i] = -1;
        dfs(nums, next, tmp);
    }
};