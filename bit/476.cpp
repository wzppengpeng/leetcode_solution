/**
 * Given a positive integer, output its complement number. The complement strategy is to flip the bits of its binary representation.

Note:
The given integer is guaranteed to fit within the range of a 32-bit signed integer.
You could assume no leading zero bit in the integer’s binary representation.

 */




class Solution {
public:
    int findComplement(int num) {
        int n = num, prev = 0;
        while (n) {
            prev = n;
            n &= n - 1;
        }
        return num ^ ((prev << 1) - 1);
    }
};