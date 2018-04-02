/**
 * Sometimes people repeat letters to represent extra feeling, such as "hello" -> "heeellooo", "hi" -> "hiiii".  Here, we have groups, of adjacent letters that are all the same character, and adjacent characters to the group are different.  A group is extended if that group is length 3 or more, so "e" and "o" would be extended in the first example, and "i" would be extended in the second example.  As another example, the groups of "abbcccaaaa" would be "a", "bb", "ccc", and "aaaa"; and "ccc" and "aaaa" are the extended groups of that string.

For some given string S, a query word is stretchy if it can be made to be equal to S by extending some groups.  Formally, we are allowed to repeatedly choose a group (as defined above) of characters c, and add some number of the same character c to it so that the length of the group is 3 or more.  Note that we cannot extend a group of size one like "h" to a group of size two like "hh" - all extensions must leave the group extended - ie., at least 3 characters long.

Given a list of query words, return the number of words that are stretchy. 
 */

/**
 * 如果两个词当前字符相同，优先向下，此时如果不同有可能是S有毗邻，因此首先考虑是否是中间位置，如果还不通过只剩下最后一种可能，就是超过三个位置，
 * 此时再进行判别
 */


class Solution {
public:
    int expressiveWords(string S, vector<string>& words) {
        if(S.empty() || words.empty()) return 0;
        int res = 0;
        for(auto& w : words) {
            if(w.size() > S.size()) continue;
            size_t i = 0, j = 0;
            for(; i < S.size(); ++i) {
                if(S[i] == w[j]) ++j;
                else if(i > 0 &&  i < S.size() - 1 && S[i] == S[i - 1] && S[i] == S[i + 1])
                    ++i;
                else if(!(i > 1 && S[i] == S[i - 1] && S[i] == S[i - 2])) break;
            }
            if(i == S.size() && j == w.size()) ++res;
        }
        return res;
    }
};