
/**
 * A string S of lowercase letters is given. We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.

Example 1:
Input: S = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.
Note:

S will have length in range [1, 500].
S will consist of lowercase letters ('a' to 'z') only.

 */

/**
 * 使用贪心算法，首先记录所有字幕在整个字符串中出现的次数，之后使用哈希表来控制区间中出现的字母数。
 * 当哈希表为空，也就是这个区间中没有多余的字符时，即可以添加该区间的长度。
 */


class Solution {
public:
    vector<int> partitionLabels(string S) {
        m_letter_cnt.resize(26, 0);
        for(auto ch : S) ++m_letter_cnt[char_to_index(ch)];
        int old_loc = -1;
        vector<int> res;
        unordered_map<char, int> tmp_cnt;
        for(int i = 0; i < S.size(); ++i) {
            if(tmp_cnt.find(S[i]) == tmp_cnt.end()) {
                tmp_cnt.emplace(S[i], m_letter_cnt[char_to_index(S[i])]);
            }
            --tmp_cnt[S[i]];
            if(tmp_cnt[S[i]] == 0) tmp_cnt.erase(S[i]);
            if(tmp_cnt.empty()) {
                res.emplace_back(i - old_loc);
                old_loc = i;
            }
        }
        return res;
    }

private:
    vector<int> m_letter_cnt;

    inline size_t char_to_index(char ch) { return ch - 'a'; }
};