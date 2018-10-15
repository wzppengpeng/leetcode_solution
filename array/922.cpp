/**
 * Given an array A of non-negative integers, half of the integers in A are odd, and half of the integers are even.

Sort the array so that whenever A[i] is odd, i is odd; and whenever A[i] is even, i is even.

You may return any answer array that satisfies this condition.


 */


/**
 * 用一个辅助数组，安排一下，一次遍历
 */


class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        vector<int> res(A.size());
        size_t j = 0, k = 1;
        for(size_t i = 0; i < A.size(); ++i) {
            if(A[i] % 2 == 0) {
                res[j] = A[i];
                j += 2;
            } else {
                res[k] = A[i];
                k += 2;
            }
        }
        return res;
    }
};