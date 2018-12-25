/**
 * In a array A of size 2N, there are N+1 unique elements, and exactly one of these elements is repeated N times.

Return the element repeated N times.
 */

/**
 * 说明该数字至少在两个位置以内会有重复
 */

class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        for (int i = 0, n = A.size(); i < n; ++i)
            if (A[i] == A[(i + 1) % n] ||  A[i] == A[(i + 2) % n])
                return A[i];
    }
};