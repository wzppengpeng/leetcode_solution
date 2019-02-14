/**
 * Given an array equations of strings that represent relationships between variables, each string equations[i] has length 4 and takes one of two different forms: "a==b" or "a!=b".  Here, a and b are lowercase letters (not necessarily different) that represent one-letter variable names.

Return true if and only if it is possible to assign integers to variable names so as to satisfy all the given equations.


Example 1:

Input: ["a==b","b!=a"]
Output: false
Explanation: If we assign say, a = 1 and b = 1, then the first equation is satisfied, but not the second.  There is no way to assign the variables to satisfy both equations.
Example 2:

Input: ["b==a","a==b"]
Output: true
Explanation: We could assign a = 1 and b = 1 to satisfy both equations.
Example 3:

Input: ["a==b","b==c","a==c"]
Output: true
Example 4:

Input: ["a==b","b!=c","c==a"]
Output: false
Example 5:

Input: ["c==c","b==d","x!=z"]
Output: true
 */


/**
 *  首先将相等的符号选出来建立并查集
 *  （并查集就是使用一个key-value形式的结构表明当前节点的链接序号）
 *  然后考虑不相等的符号，如果其id相同则矛盾
 *  返回结果
 */

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        if(equations.size() < 2) return true;
        UF();
        for(const auto& s : equations) {
            if(s[1] == '=') union_find(s[0], s[3]);
        }
        for(const auto& s : equations) {
            if(s[1] == '!' && id_[char_to_int(s[0])] == id_[char_to_int(s[3])])
                return false;
        }
        return true;
    }

    inline int char_to_int(char ch) const {
        return ch - 'a';
    }

    void UF() {
        id_.resize(26);
        route_.resize(26, vector<int>(1));
        for(int i = 0; i < 26; ++i) {
            id_[i] = i;
            route_[i][0] = i;
        }
    }

    void union_find(char pch, char qch) {
        int p = char_to_int(pch), q = char_to_int(qch);
        if(id_[p] == id_[q]) return;
        int pid = id_[p], qid = id_[q];
        for(auto l : route_[pid]) {
            id_[l] = qid;
            route_[qid].emplace_back(l);
        }
    }

    vector<int> id_;
    vector<vector<int>> route_;
};