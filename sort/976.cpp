/**
 * Given an array A of positive lengths, return the largest perimeter of a triangle with non-zero area, formed from 3 of these lengths.

If it is impossible to form any triangle of non-zero area, return 0.

Example 1:

Input: [2,1,2]
Output: 5
Example 2:

Input: [1,2,1]
Output: 0
Example 3:

Input: [3,2,3,4]
Output: 10
Example 4:

Input: [3,6,2,3]
Output: 8
 */

/**
 * 从大到小排序，然后从前往后判断是否能成立为三角形，只要满足此要求，即可得到周长
 */

class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        std::sort(std::begin(A), std::end(A), std::greater<int>());
        int res = 0;
        for(size_t i = 0; i < A.size() - 2; ++i) {
            if(A[i] < A[i + 1] + A[i + 2]) {
                res = A[i] + A[i + 1] + A[i + 2];
                break;
            }
        }
        return res;
    }
};