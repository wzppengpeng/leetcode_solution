/**
 * Given a list of sorted characters letters containing only lowercase letters, and given a target letter target, find the smallest element in the list that is larger than the given target.

Letters also wrap around. For example, if the target is target = 'z' and letters = ['a', 'b'], the answer is 'a'.
 */

/**
 * 正常情况下直接调用upper_bound寻找第一个大于该值的迭代器，当不满足时说明该值比最大的值都大，那么根据循环性返回第一个值即可
 */


class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        auto it = std::upper_bound(std::begin(letters), std::end(letters), target);
        if(it == letters.end()) return letters.front();
        else return *it;
    }
};