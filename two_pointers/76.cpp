/**
 * Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

Example:

Input: S = "ADOBECODEBANC", T = "ABC"
Output: "BANC"
 */

/**
 * 使用一个滑动窗口（i,j）区间来控制，用一个count来计数，使用两个哈希表来进行比较即可
 */

class Solution {
public:
    string minWindow(string s, string t) {
        if(s.empty() || t.empty()) return "";
        unordered_map<char, int> cnt, has_in;
        for(auto ch : t) ++cnt[ch];
        string res;
        int min_len = INT_MAX;
        size_t letters = 0;
        for(size_t i = 0, j = 0; j < s.size(); ++j) {
            if(cnt.count(s[j])) {
                ++has_in[s[j]];
                if(has_in[s[j]] <= cnt[s[j]]) ++letters;
            }
            if(letters >= t.size()) {
                while(i < j && (cnt.find(s[i]) == cnt.end() || has_in[s[i]] > cnt[s[i]])) {
                    --has_in[s[i++]];
                }
                if(j - i + 1 < min_len) {
                    min_len = j - i + 1;
                    res = s.substr(i, min_len);
                }
            }
        }
        return res;
    }
};