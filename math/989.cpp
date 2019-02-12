/**
 * For a non-negative integer X, the array-form of X is an array of its digits in left to right order.  For example, if X = 1231, then the array form is [1,2,3,1].

Given the array-form A of a non-negative integer X, return the array-form of the integer X+K.


Example 1:

Input: A = [1,2,0,0], K = 34
Output: [1,2,3,4]
Explanation: 1200 + 34 = 1234
Example 2:

Input: A = [2,7,4], K = 181
Output: [4,5,5]
Explanation: 274 + 181 = 455
Example 3:

Input: A = [2,1,5], K = 806
Output: [1,0,2,1]
Explanation: 215 + 806 = 1021
Example 4:

Input: A = [9,9,9,9,9,9,9,9,9,9], K = 1
Output: [1,0,0,0,0,0,0,0,0,0,0]
Explanation: 9999999999 + 1 = 10000000000
 */

/**
 * 还是模拟计算器进位，一边采用指针，一边采用云算法，最后翻转
 */


class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        vector<int> res; res.reserve(A.size() + 1);
        auto it = A.rbegin(); int n = K % 10;
        bool flag = false;
        auto computation = [&res, &flag](int tmp) {
            if(flag) {
                ++tmp;
                flag = false;
            }
            if(tmp >= 10) {
                tmp -= 10;
                flag = true;
            }
            res.emplace_back(tmp);
        };
        while(it != A.rend() && K != 0) {
            auto tmp = *it + n;
            computation(tmp);
            ++it;
            K /= 10; n = K % 10;
        }
        if(K == 0) {
            for(; it != A.rend(); ++it) {
                auto tmp = *it;
                computation(tmp);
            }
        }
        if(K != 0 && it == A.rend()) {
            while(K != 0) {
                auto tmp = n;
                computation(tmp);
                K /= 10; n = K % 10;
            }
        }
        if(flag) res.emplace_back(1);
        std::reverse(std::begin(res), std::end(res));
        return res;
    }
};