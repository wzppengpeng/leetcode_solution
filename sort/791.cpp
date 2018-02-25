/**
 * S and T are strings composed of lowercase letters. In S, no letter occurs more than once.

S was sorted in some custom order previously. We want to permute the characters of T so that they match the order that S was sorted. More specifically, if x occurs before y in S, then x should occur before y in the returned string.

Return any permutation of T (as a string) that satisfies this property.


 */


/**
 * 由于S中只出现一次，所以使用哈希表来保存index，然后制定新的排序策略即可
 */


class Solution {
public:
    string customSortString(string S, string T) {
        unordered_map<char, size_t> index_S;
        for(size_t i = 0; i < S.size(); ++i) {
            index_S[S[i]] = i;
        }
        std::sort(std::begin(T), std::end(T),
            [&index_S](char a, char b) {
                if(index_S.find(a) == index_S.end() && index_S.find(b) == index_S.end()) return a < b;
                if(index_S.find(b) == index_S.end()) return true;
                if(index_S.find(a) == index_S.end()) return false;
                return index_S[a] < index_S[b];
            });
        return T;
    }
};