/**
 * In a string S of lowercase letters, these letters form consecutive groups of the same character.

For example, a string like S = "abbxxxxzyy" has the groups "a", "bb", "xxxx", "z" and "yy".

Call a group large if it has 3 or more characters.  We would like the starting and ending positions of every large group.

The final answer should be in lexicographic order.
 */

/**
 * 顺序查找即可
 */

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>> res;
        if(S.size() < 3) return res;
        int i = 0;
        auto j = S.find_first_not_of(S[i], i);
        while(j != string::npos) {
            if(j - i >= 3) {
                res.emplace_back({i, j - 1});
            }
            i = j;
            j = S.find_first_not_of(S[i], i);
        }
        if(S.size() - i >= 3) {
            res.emplace_back({i, S.size() - 1});
        }
        return res;
    }
};