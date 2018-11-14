/**
 * In an array A of 0s and 1s, how many non-empty subarrays have sum S?



Example 1:

Input: A = [1,0,1,0,1], S = 2
Output: 4
Explanation:
The 4 subarrays are bolded below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
 */

/**
 * 当求和为s的序列，也可以看成是当前的和pre_sum - S的个数
 */

class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        vector<int> cnt(A.size() + 1, 0);
        cnt[0] = 1;
        int pre_sum = 0, res = 0;
        for(auto a : A) {
            pre_sum += a;
            if(pre_sum - S >= 0) {
                res += cnt[pre_sum - S];
            }
            ++cnt[pre_sum];
        }
        return res;
    }
};