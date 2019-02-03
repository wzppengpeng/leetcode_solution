/**
 * Given two integers A and B, return any string S such that:

S has length A + B and contains exactly A 'a' letters, and exactly B 'b' letters;
The substring 'aaa' does not occur in S;
The substring 'bbb' does not occur in S.
 

Example 1:

Input: A = 1, B = 2
Output: "abb"
Explanation: "abb", "bab" and "bba" are all correct answers.
Example 2:

Input: A = 4, B = 1
Output: "aabaa"
 */

/**
 * 根据规律递归求解，当A > B时，首先放置aab，当A < B时，首先放置bba
 */

class Solution {
public:
    string strWithout3a3b(int A, int B) {
        if(A == 0) return string(B, 'b');
        else if(B == 0) return string(A, 'a');
        else if(A == B) return string("ab") + strWithout3a3b(A - 1, B - 1);
        else if(A > B) return string("aab") + strWithout3a3b(A - 2, B - 1);
        else return string("bba") + strWithout3a3b(A - 1, B - 2);
    }
};