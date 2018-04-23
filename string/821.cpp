/**
 * Given a string S and a character C, return an array of integers representing the shortest distance from the character C in the string.

Example 1:

Input: S = "loveleetcode", C = 'e'
Output: [3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0]
 */

/**
 * 进行前向和反向的两次比较即可，始终与最近的一个位置进行比较
 */

class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        std::vector<int> res(S.size(), INT_MAX);
        // forward
        int last = -1;
        for(int i = 0; i < S.size(); ++i) {
            if(S[i] == C) {
                res[i] = 0;
                last = i;
            } else if(last >= 0) {
                res[i] = i - last;
            }
        }
        // backward
        last = -1;
        for(int i = S.size() - 1; i >= 0; --i) {
            if(S[i] == C) last = i;
            else if(last >= 0) {
                res[i] = std::min(res[i], last - i);
            }
        }
        return res;
    }
};