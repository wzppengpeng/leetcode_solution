/**
 * You're given strings J representing the types of stones that are jewels, and S representing the stones you have.  Each character in S is a type of stone you have.  You want to know how many of the stones you have are also jewels.

The letters in J are guaranteed distinct, and all characters in J and S are letters. Letters are case sensitive, so "a" is considered a different type of stone from "A".


 */


/**
 * 使用哈希集合保存宝石，再遍历统计即可，这里使用STL使代码简洁
 */

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> jewels(std::begin(J), std::end(J));
        int res = 0;
        std::for_each(std::begin(S), std::end(S), [&res, &jewels](char ch) { res += jewels.count(ch); });
        return res;
    }
};