/**
 * Given a positive integer N, find and return the longest distance between two consecutive 1's in the binary representation of N.

If there aren't two consecutive 1's, return 0.
 */


class Solution {
public:
    int binaryGap(int N) {
        std::bitset<32> bn(N);
        int res = 0, last = -1;
        for(int i = 0 ; i < 32; ++i) {
            if(bn[i]) {
                if(last != -1) res = std::max(res, i - last);
                last = i;
            }
        }
        return res;
    }
};