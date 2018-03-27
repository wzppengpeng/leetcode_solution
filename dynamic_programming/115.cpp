/**
 * Given a string S and a string T, count the number of distinct subsequences of S which equals T.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.
 */

/**
 * General case 1: dp[i][j] = dp[i][j - 1] if t[i - 1] != s[j - 1];
General case 2: dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1] if t[i - 1] == s[j - 1];
Boundary case 1: dp[0][j] = 1 for all j;
Boundary case 2: dp[i][0] = 0 for all positive i.
 */

class Solution {
public:
    int numDistinct(string s, string t) {
        size_t m = s.size(), n = t.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for(size_t i = 0; i < m + 1; ++i) dp[i][0] = 1;
        for(size_t i = 0; i < m; ++i) {
            for(size_t j = 0; j < n; ++j) {
                if(s[i] == t[j]) dp[i + 1][j + 1] = dp[i][j] + dp[i][j + 1];
                else dp[i + 1][j + 1] = dp[i][j + 1];
            }
        }
        return dp[m][n];
    }
};