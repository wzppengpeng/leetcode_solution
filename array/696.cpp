/**
 * Give a string s, count the number of non-empty (contiguous) substrings that have the same number of 0's and 1's, and all the 0's and all the 1's in these substrings are grouped consecutively.

Substrings that occur multiple times are counted the number of times they occur.

Example 1:
Input: "00110011"
Output: 6
Explanation: There are 6 substrings that have equal number of consecutive 1's and 0's: "0011", "01", "1100", "10", "0011", and "01".

Notice that some of these substrings repeat and are counted the number of times they occur.

Also, "00110011" is not a valid substring because all the 0's (and 1's) are not grouped together.

 */


/**
 * 因为只有连续的才可以，所以可以只保存最大长度，最大长度的值就是可以产生的种类数目
 */

class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int> cnt; cnt.reserve(s.size());
        int count = 1;
        for(size_t i = 1; i <= s.size(); ++i) {
            if(s[i] == s[i - 1]) ++count;
            else {
                cnt.emplace_back(count);
                count = 1;
            }
        }
        int res = 0;
        for(size_t i = 1; i < cnt.size(); ++i) {
            res += std::min(cnt[i - 1], cnt[i]);
        }
        return res;
    }
};