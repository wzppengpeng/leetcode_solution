/**
 * You are given an array A of strings.

Two strings S and T are special-equivalent if after any number of moves, S == T.

A move consists of choosing two indices i and j with i % 2 == j % 2, and swapping S[i] with S[j].

Now, a group of special-equivalent strings from A is a non-empty subset S of A such that any string not in S is not special-equivalent with any string in S.

Return the number of groups of special-equivalent strings from A.


Example 1:

Input: ["a","b","c","a","c","c"]
Output: 3
Explanation: 3 groups ["a","a"], ["b"], ["c","c","c"]
Example 2:

Input: ["aa","bb","ab","ba"]
Output: 4
Explanation: 4 groups ["aa"], ["bb"], ["ab"], ["ba"]
Example 3:

Input: ["abc","acb","bac","bca","cab","cba"]
Output: 3
Explanation: 3 groups ["abc","cba"], ["acb","bca"], ["bac","cab"]
Example 4:

Input: ["abcd","cdab","adcb","cbad"]
Output: 1
Explanation: 1 group ["abcd","cdab","adcb","cbad"]
 */

/**
 * 其实只要保证基数段和偶数段出现的字符串相同即可
 * 所以首先通过交换的方法得到基数段和偶数段，并通过排序的方法保证组内相同的形式
 * 最后用一个哈希表保存该统一形式
 */


class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        std::unordered_set<string> sset;
        for(auto& s : A) {
            transform(s);
            sset.emplace(std::move(s));
        }
        return sset.size();
    }

    void transform(std::string& s) const {
        if(s.size() > 1) {
            size_t i = 0, j = s.size() % 2 == 0 ? s.size() - 1 : s.size() - 2;
            while(i < j) {
                std::swap(s[i], s[j]);
                i += 2;
                if(j == 1) break;
                j -= 2;
            }
        }
        auto mid = s.size() / 2;
        std::sort(std::begin(s), std::begin(s) + mid);
        std::sort(std::begin(s) + mid, std::end(s));
    }
};