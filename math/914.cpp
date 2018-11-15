/**
 * In a deck of cards, each card has an integer written on it.

Return true if and only if you can choose X >= 2 such that it is possible to split the entire deck into 1 or more groups of cards, where:

Each group has exactly X cards.
All the cards in each group have the same integer.


Example 1:

Input: [1,2,3,4,4,3,2,1]
Output: true
Explanation: Possible partition [1,1],[2,2],[3,3],[4,4]
Example 2:

Input: [1,1,1,2,2,2,3,3]
Output: false
Explanation: No possible partition.
Example 3:

Input: [1]
Output: false
Explanation: No possible partition.
Example 4:

Input: [1,1]
Output: true
Explanation: Possible partition [1,1]
Example 5:

Input: [1,1,2,2,2,2]
Output: true
Explanation: Possible partition [1,1],[2,2],[2,2]
 */


/**
 * 实际上是先统计不同卡片出现的次数，然后只要保证次数的最小公约数 >= 2即可
 */


class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        if(deck.size() < 2) return false;
        unordered_map<int, int> cnt;
        for(auto d : deck) {
            ++cnt[d];
        }
        int gcd_res = 0;
        for(const auto& p : cnt) {
            gcd_res = __gcd(gcd_res, p.second);
        }
        return gcd_res > 1;
    }
};