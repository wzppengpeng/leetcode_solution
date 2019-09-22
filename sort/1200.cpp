/**
 * Given an array of distinct integers arr, find all pairs of elements with the minimum absolute difference of any two elements. 

Return a list of pairs in ascending order(with respect to pairs), each pair [a, b] follows

a, b are from arr
a < b
b - a equals to the minimum absolute difference of any two elements in arr

 */

/**
 * 排序后，依次计算
 */


class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        std::sort(std::begin(arr), std::end(arr));
        vector<vector<int>> res;
        size_t i = 1;
        int min_res = arr[i] - arr[0];
        for(; i < arr.size(); ++i) {
            min_res = std::min(min_res, std::abs(arr[i] - arr[i - 1]));
        }
        i = 1;
        for(; i < arr.size(); ++i) {
            if(std::abs(arr[i] - arr[i - 1]) == min_res) {
                int min_val = std::min(arr[i - 1], arr[i]),
                    max_val = std::max(arr[i - 1], arr[i]);
                res.emplace_back(vector<int>{min_val, max_val});
            }
        }
        return res;
    }
};