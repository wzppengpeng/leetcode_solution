/**
 * Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.


 */

/**
 *Solution:
 * 使用hash_map来保存value和index的映射，然后用two point来查看区间内元素，不过目前依然存在很多不必要的重复查看，需要优化
 *
 * 最优解：使用数组替换哈希表，并且其实至于要记录上一次该字符出现的最后位置即可，每一次都进行最大值记录
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0;
        int res = 0;
        while(j < s.size()) {
            if(m_pre_chars.find(s[j]) != m_pre_chars.end()) {
                if(m_pre_chars[s[j]] < i) {
                    m_pre_chars.erase(s[j]);
                    continue;
                }
                res = max(res, j - i);
                i = m_pre_chars[s[j]] + 1;
                m_pre_chars.erase(s[j]);
            }
            else {
                m_pre_chars.emplace(s[j], j);
                ++j;
            }
        }
        return max(res, j - i);
    }

    int lengthOfLongestSubstring(string s) {
        vector<int> dict(256, -1);
        int maxLen = 0, start = -1;
        for (int i = 0; i != s.length(); i++) {
            if (dict[s[i]] > start)
                start = dict[s[i]];
            dict[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    }

private:
    unordered_map<char, int> m_pre_chars;
};