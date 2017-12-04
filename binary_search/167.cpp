/**
 * Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution and you may not use the same element twice.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
 */

/**
 * 因为确保了一定有解，所以使用二分搜索即可，注意解得结果必须是按大小顺序的，所以排个序，此处排序的开销可以忽略不计
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res(2, 0);
        for(int i = 0; i < numbers.size(); ++i) {
            auto it = std::lower_bound(std::begin(numbers), std::end(numbers), target - numbers[i]);
            if(it != numbers.end() && *it == target - numbers[i] && (it - numbers.begin()) != i) {
                res[0] = i + 1;
                res[1] = (it - numbers.begin()) + 1;
                break;
            }
        }
        std::sort(std::begin(res), std::end(res));
        return res;
    }
};