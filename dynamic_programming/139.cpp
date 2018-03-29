/**
 *
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words. You may assume the dictionary does not contain duplicate words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".
 */

/**
 * 依次判断某位置之前是否是可切割的，进行动态规划！
 */

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(s.empty() || wordDict.empty()) return false;
        unordered_set<string> dict(std::begin(wordDict), std::end(wordDict));
        vector<bool> dp(s.size() + 1, false); dp[0] = true;
        for(size_t i = 1; i < s.size() + 1; ++i) {
            for(size_t j = 0; j < i; ++j) {
                if(dp[j] && dict.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp.back();
    }
};