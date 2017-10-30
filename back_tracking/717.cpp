/**
 * We have two special characters. The first character can be represented by one bit 0. The second character can be represented by two bits (10 or 11).

Now given a string represented by several bits. Return whether the last character must be a one-bit character or not. The given string will always end with a zero.

Example 1:
Input: 
bits = [1, 0, 0]
Output: True
Explanation: 
The only way to decode it is two-bit character and one-bit character. So the last character is one-bit character.
Example 2:
Input: 
bits = [1, 1, 1, 0]
Output: False
Explanation: 
The only way to decode it is two-bit character and two-bit character. So the last character is NOT one-bit
 */

/**
 * 一个简单的回溯算法，因为在某位置只能是0或者1，确定往下只有一种路径可走
 */


class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        if(bits.empty() || bits.back() == 1) return false;
        return back(bits, 0);
    }

    bool back(const vector<int>& bits, int i) {
        if(i >= bits.size()) return false;
        if(i == bits.size() - 1) return true;
        if(bits[i] == 0) {
            return back(bits, i + 1);
        } else {
            return back(bits, i + 2);
        }
    }
};