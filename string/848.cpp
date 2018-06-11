/**
 * We have a string S of lowercase letters, and an integer array shifts.

Call the shift of a letter, the next letter in the alphabet, (wrapping around so that 'z' becomes 'a'). 

For example, shift('a') = 'b', shift('t') = 'u', and shift('z') = 'a'.

Now for each shifts[i] = x, we want to shift the first i+1 letters of S, x times.

Return the final string after all such shifts to S are applied.

Example 1:

Input: S = "abc", shifts = [3,5,9]
Output: "rpl"
Explanation:
We start with "abc".
After shifting the first 1 letters of S by 3, we have "dbc".
After shifting the first 2 letters of S by 5, we have "igc".
After shifting the first 3 letters of S by 9, we have "rpl", the answer.
Note:

1 <= S.length = shifts.length <= 20000
0 <= shifts[i] <= 10 ^ 9
 */

/**
 * 重点在于shifts里面的偏移量很有可能溢出，使用long long
 */

class Solution {
typedef long long ll;
public:
    string shiftingLetters(string S, vector<int>& shifts) {
        vector<ll> shifts_ll(std::begin(shifts), std::end(shifts));
        for(int i = shifts_ll.size() - 2; i >= 0; --i) {
            shifts_ll[i] += shifts_ll[i + 1];
        }
        string res = S;
        for(size_t i = 0; i < S.size(); ++i) {
            res[i] = map_alphabet(S[i], shifts_ll[i]);
        }
        return res;
    }

    char map_alphabet(char now, ll shift_val) {
        shift_val = shift_val % 26;
        if(now + shift_val <= 'z') return now + shift_val;
        else return 'a' + (shift_val - ('z' - now) - 1);
    }
};