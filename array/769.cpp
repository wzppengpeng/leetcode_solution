/**
 * Given an array arr that is a permutation of [0, 1, ..., arr.length - 1], we split the array into some number of "chunks" (partitions), and individually sort each chunk.  After concatenating them, the result equals the sorted array.

What is the most number of chunks we could have made?

Example 1:

Input: arr = [4,3,2,1,0]
Output: 1
Explanation:
Splitting into two or more chunks will not return the required result.
For example, splitting into [4, 3], [2, 1, 0] will result in [3, 4, 0, 1, 2], which isn't sorted.
Example 2:

Input: arr = [1,0,2,3,4]
Output: 4
Explanation:
We can split into two chunks, such as [1, 0], [2, 3, 4].
However, splitting into [1, 0], [2], [3], [4] is the highest number of chunks possible.
 */

/**
 * 其实有点像链表进行循环，该区间判断结束的标准是在最大值之内的位置都已经遍历到，同时注意如果该区间还没有遍历完，但是出现了循环，需要加一进行跳出
 */

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int res = 0;
        size_t start = 0, max_loc = 11, local_start = 0;
        vector<size_t> record_loc(arr.size(), 0);
        while(start < arr.size()) {
            if(is_walked(record_loc, max_loc)) {
                ++res;
                start = max_loc + 1;
                local_start = start;
                max_loc = 11;
            } else {
                if(record_loc[start]) {
                    start = ++local_start;
                    continue;
                }
                record_loc[start] = 1;
                max_loc = max_loc == 11 ? local_start : std::max(max_loc, start);
                start = static_cast<size_t>(arr[start]);
                max_loc = max_loc == 11 ? local_start : std::max(max_loc, start);
            }
        }
        return res;
    }

    bool is_walked(const std::vector<size_t>& record_loc, size_t max_loc) {
        for(size_t i = 0; i <= max_loc; ++i) {
            if(!record_loc[i]) return false;
        }
        return true;
    }

};