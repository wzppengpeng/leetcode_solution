/**
 * We are given an array A of N lowercase letter strings, all of the same length.

Now, we may choose any set of deletion indices, and for each string, we delete all the characters in those indices.

For example, if we have a string "abcdef" and deletion indices {0, 2, 3}, then the final string after deletion is "bef".

Suppose we chose a set of deletion indices D such that after deletions, each remaining column in A is in non-decreasing sorted order.

Formally, the c-th column is [A[0][c], A[1][c], ..., A[A.length-1][c]]

Return the minimum possible value of D.length.


Example 1:

Input: ["cba","daf","ghi"]
Output: 1
Example 2:

Input: ["a","b"]
Output: 0
Example 3:

Input: ["zyx","wvu","tsr"]
Output: 3
 */


/**
 * 按列判断
 */

class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        size_t n = A.size(), m = A[0].size();
        int res = 0;
        for(size_t j = 0; j < m; ++j) {
            for(size_t i = 1; i < n; ++i) {
                if(A[i][j] < A[i - 1][j]) {
                    ++res;
                    break;
                }
            }
        }
        return res;
    }
};