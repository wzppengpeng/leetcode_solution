/**
 * Given two integer arrays A and B, return the maximum length of an subarray that appears in both arrays.

Example 1:
Input:
A: [1,2,3,2,1]
B: [3,2,1,4,7]
Output: 3
Explanation:
The repeated subarray with maximum length is [3, 2, 1].
 */

/**
 * 把A反过来考虑，而对于B，使用数组保存当前位置的最大长度，而每到上一次，刚好就往后平移了一个
 */

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int max_repeat_len = 0;
        vector<int> dp(B.size() + 1);

        for (int i = A.size() - 1; i >= 0; i--) {
            for (int j = 0; j < B.size(); j++) {
                max_repeat_len = max(max_repeat_len, dp[j] = A[i] == B[j] ? dp[j + 1] + 1: 0);  // dp[j+1]为上一次匹配相邻字符的匹配情况
            }
        }
        return max_repeat_len;
    }
};