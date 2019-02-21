/**
 * The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,
 */

/**
 * 用循环不要用递归
 */

class Solution {
public:
    int fib(int N) {
        if(N < 2) return N;
        int zero = 0, one = 1, tmp;
        for(int i = 2; i <= N; ++i) {
            tmp = zero + one;
            zero = one;
            one = tmp;
        }
        return tmp;
    }
};