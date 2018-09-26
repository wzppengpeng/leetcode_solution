/**
 * Given an array A of integers, for each integer A[i] we may choose any x with -K <= x <= K, and add x to A[i].

After this process, we have some array B.

Return the smallest possible difference between the maximum value of B and the minimum value of B.
 */

/**
 * 找到最大和最小值，然后返回差值减去两倍距离即可，同时注意比0大即可
 */


class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        auto min_max_ptr = std::minmax_element(std::begin(A), std::end(A));
        return std::max(0, (*min_max_ptr.second - *min_max_ptr.first) - 2 * K);
    }
};