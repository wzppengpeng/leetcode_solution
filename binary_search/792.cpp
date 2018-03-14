/**
 * Given string S and a dictionary of words words, find the number of words[i] that is a subsequence of S.

Example :
Input:
S = "abcde"
words = ["a", "bb", "acd", "ace"]
Output: 3
Explanation: There are three words in words that are a subsequence of S: "a", "acd", "ace".
 */

/**
 * 对于每个单词，需要保证每个单词出现的顺序在当前的前面
 * 首先使用顺序表保存下来每个字符出现的顺序，然后只需要使用二分查找找到最近的位置即可。
 */

class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        vector<vector<int>> w(26);
        for(int i = 0; i < S.size(); ++i)
            w[char_to_int(S[i])].emplace_back(i);
        int res = 0;
        for(auto& str : words) {
            int last = -1;
            bool ok = true;
            for(auto ch : str) {
                auto& v = w[char_to_int(ch)];
                if(v.empty()) { ok = false; break; }
                auto it = std::upper_bound(std::begin(v), std::end(v), last);
                if(it != std::end(v)) last = *it;
                else { ok = false; break; }
            }
            if(ok) ++res;
        }
        return res;
    }

    inline int char_to_int(char ch) const {
        return ch - 'a';
    }

};