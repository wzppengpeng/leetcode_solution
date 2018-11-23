/**
 * Given an array A, partition it into two (contiguous) subarrays left and right so that:

Every element in left is less than or equal to every element in right.
left and right are non-empty.
left has the smallest possible size.
Return the length of left after such a partitioning.  It is guaranteed that such a partitioning exists.


Example 1:

Input: [5,0,3,8,6]
Output: 3
Explanation: left = [5,0,3], right = [8,6]
Example 2:

Input: [1,1,1,0,6,12]
Output: 4
Explanation: left = [1,1,1,0], right = [6,12]
 */


/**
 * 首先从后往前存下到当前位置的后续最小值，然后从前往后找最大值，若最大值小于当前位置往后的最小值，即可满足条件
 * consider leftMax <= rightMin
 */

class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
        auto N = A.size();
        vector<int> B(N); B[N - 1] = A[N - 1];
        for(int i = N - 2; i >= 0; --i) {
            B[i] = std::min(A[i], B[i + 1]);
        }
        int pmax = A[0];
        for(int i = 1; i < N; ++i) {
            pmax = std::max(pmax, A[i - 1]);
            if(pmax <= B[i]) return i;
        }
        return N - 1;
    }
};