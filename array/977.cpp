/**
 * Given an array of integers A sorted in non-decreasing order, return an array of the squares of each number, also in sorted non-decreasing order.


Example 1:

Input: [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Example 2:

Input: [-7,-3,2,3,11]
Output: [4,9,9,49,121]
 */


/**
 * 平方后再排序，勿重新分配内存
 */


class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        std::for_each(std::begin(A), std::end(A), [](int& a) { a *= a; });
        std::sort(std::begin(A), std::end(A));
        return A;
    }
};