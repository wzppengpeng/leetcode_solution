/**
 * 给你一个整数 n，请你帮忙计算并返回该整数「各位数字之积」与「各位数字之和」的差
 */

/**
 * 注意数字溢出情况即可
 */

class Solution {
public:
    int subtractProductAndSum(int n) {
        unsigned long long prod = 1, sum = 0;
        while (n > 0) {
            int i = n % 10;
            n /= 10;
            prod *= i;
            sum += i;
        }
        return prod - sum;
    }
};