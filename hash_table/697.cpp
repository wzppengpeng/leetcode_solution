/**
 * Given a non-empty array of non-negative integers nums, the degree of this array is defined as the maximum frequency of any one of its elements.

Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums.

Example 1:
Input: [1, 2, 2, 3, 1]
Output: 2
Explanation:
The input array has a degree of 2 because both elements 1 and 2 appear twice.
Of the subarrays that have the same degree:
[1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
The shortest length is 2. So return 2.
Example 2:
Input: [1,2,2,3,1,4,2]
Output: 6
Note:

nums.length will be between 1 and 50,000.
nums[i] will be an integer between 0 and 49,999.

 */


class Solution {
struct Window {
    int count;
    size_t begin;
    size_t end;
    Window(int c, size_t b, size_t e) : count(c), begin(b), end(e) {}
};
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, size_t> index;
        vector<pair<int, Window>> num_cnt;
        num_cnt.reserve(nums.size());
        for(size_t i = 0; i < nums.size(); ++i) {
            if(index.find(nums[i]) != index.end()) {
                ++num_cnt[index[nums[i]]].second.count;
                num_cnt[index[nums[i]]].second.end = i;
            } else {
                num_cnt.emplace_back(std::make_pair(nums[i], Window(1, i, i)));
                index.emplace(nums[i], num_cnt.size() - 1);
            }
        }
        std::sort(std::begin(num_cnt), std::end(num_cnt),
            [](const std::pair<int, Window>& left, const std::pair<int, Window>& right) {
                if(left.second.count > right.second.count) return true;
                if(left.second.count == right.second.count) return (left.second.end - left.second.begin) < (right.second.end - right.second.begin);
                return false;
            });
        return num_cnt.front().second.end - num_cnt.front().second.begin + 1;
    }
};