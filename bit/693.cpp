/**
 * Given a positive integer, check whether it has alternating bits: namely, if two adjacent bits will always have different values.

Example 1:
Input: 5
Output: True
Explanation:
The binary representation of 5 is: 101
Example 2:
Input: 7
Output: False
Explanation:
The binary representation of 7 is: 111.
Example 3:
Input: 11
Output: False
Explanation:
The binary representation of 11 is: 1011.
Example 4:
Input: 10
Output: True
Explanation:
The binary representation of 10 is: 1010.
 */


/**
 * 就是循环取最后一位进行比较
 */

class Solution {
public:
    bool hasAlternatingBits(int n) {
        int last = n % 2;
        n /= 2;
        while(n) {
            int tmp = n % 2;
            if(tmp == last) return false;
            last = tmp;
            n /= 2;
        }
        return true;
    }
};