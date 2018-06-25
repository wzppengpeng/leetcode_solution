/**
 * Given two strings A and B of lowercase letters, return true if and only if we can swap two letters in A so that the result equals B.



Example 1:

Input: A = "ab", B = "ba"
Output: true
Example 2:

Input: A = "ab", B = "ab"
Output: false
Example 3:

Input: A = "aa", B = "aa"
Output: true
Example 4:

Input: A = "aaaaaaabc", B = "aaaaaaacb"
Output: true
Example 5:

Input: A = "", B = "aa"
Output: false
 */


/**
 * 分为字符串相符和不相符两种情况进行判定，其中在相符的情况下，只需要判断是否有重复字符即可。
 */

class Solution {
public:
    bool buddyStrings(string A, string B) {
        if(A.size() != B.size()) return false;
        if(A == B) {
            unordered_set<char> cnt;
            for(auto ch : A) {
                if(cnt.count(ch)) return true;
                cnt.emplace(ch);
            }
            return false;
        }
        vector<size_t> locs;
        for(size_t i = 0; i < A.size(); ++i) {
            if(A[i] != B[i]) locs.push_back(i);
            if(locs.size() > 2) break;
        }
        if(locs.size() != 2 || A[locs[0]] != B[locs[1]]
            || A[locs[1]] != B[locs[0]]) return false;
        return true;
    }
};