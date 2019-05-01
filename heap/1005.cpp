/**
 * Given an array A of integers, we must modify the array in the following way: we choose an i and replace A[i] with -A[i], and we repeat this process K times in total.  (We may choose the same index i multiple times.)

Return the largest possible sum of the array after modifying it in this way.



Example 1:

Input: A = [4,2,3], K = 1
Output: 5
Explanation: Choose indices (1,) and A becomes [4,-2,3].
 */

/**
 * 不管正数还是负数，相同的都是优先对最小的值进行处理，因此可以使用小根堆的概念进行处理
 * C++中的heap可以使用priority_queue，但是注意这个玩意儿和大小根堆是反着来的
 */


class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> que(std::begin(A), std::end(A));
        while(K-- > 0) {
            int min_val = que.top();
            que.pop();
            que.push(-min_val);
        }
        int sum = 0;
        while(!que.empty()) {
            sum += que.top();
            que.pop();
        }
        return sum;
    }
};