
/**
 * Given two integers L and R, find the count of numbers in the range [L, R] (inclusive) having a prime number of set bits in their binary representation.

(Recall that the number of set bits an integer has is the number of 1s present when written in binary. For example, 21 written in binary is 10101 which has 3 set bits. Also, 1 is not a prime.)
 */

/**
 * 数一定在0~32之间，而32之间的素数一定只有这么多，所以可以提前建个哈希表（在个数比较少的情况下其实用红黑树更快）
 * 然后遍历判断1的个数即可
 */

class Solution {
public:
    int countPrimeSetBits(int l, int r) {
        unordered_set<int> primes = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };
        int cnt = 0;
        for (int i = l; i <= r; i++) {
            int bits = 0;
            for (int n = i; n; n >>= 1)
                bits += n & 1;
            cnt += primes.count(bits);
        }
        return cnt;
    }
};