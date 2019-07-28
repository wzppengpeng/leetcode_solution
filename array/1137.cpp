/**
 * The Tribonacci sequence Tn is defined as follows:

T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.

Given n, return the value of Tn.


 */


/**
 * 与斐波那契一样的解决方法，用循环而不用递归
 */

class Solution {
public:
    int tribonacci(int n) {
        std::array<int, 3> t {0, 1, 1};
        if(n < 3)
            return t[n];
        int tmp;
        for(int i = 3; i <= n; ++i) {
            tmp = t[0] + t[1] + t[2];
            t[0] = t[1];
            t[1] = t[2];
            t[2] = tmp;
        }
        return t[2];
    }
};