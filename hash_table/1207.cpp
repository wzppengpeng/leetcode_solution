/**
 * Given an array of integers arr, write a function that returns true if and only if the number of occurrences of each value in the array is unique.
 */

/**
 * 使用哈希表计数，然后使用哈希表过滤
 */

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> val_cnt;
        std::for_each(std::begin(arr), std::end(arr), [&val_cnt](int val) {
            ++val_cnt[val];
        });
        unordered_set<int> has_in;
        for(const auto& p : val_cnt) {
            if(has_in.count(p.second))
                return false;
            has_in.emplace(p.second);
        }
        return true;
    }
};