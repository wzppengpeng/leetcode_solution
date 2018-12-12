/**
 * 955. Delete Columns to Make Sorted II
Medium
36
7
Favorite
Share
We are given an array A of N lowercase letter strings, all of the same length.

Now, we may choose any set of deletion indices, and for each string, we delete all the characters in those indices.

For example, if we have an array A = ["abcdef","uvwxyz"] and deletion indices {0, 2, 3}, then the final array after deletions is ["bef","vyz"].

Suppose we chose a set of deletion indices D such that after deletions, the final array has its elements in lexicographic order (A[0] <= A[1] <= A[2] ... <= A[A.length - 1]).

Return the minimum possible value of D.length.
 */


/**
 * Initial a boolean array sorted,
sorted[i] = true if and only if A[i] < A[i + 1],
that is to say A[i] and A[i + 1] are sorted.

For each col, we check all unsorted rows.
If A[i][j] > A[i + 1][j], we need to deleted this col, res++.

Otherwise, we can keep this col, and update all sorted rows.
 */

class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int res = 0;
        size_t N = A.size(), M = A.front().size(), i = 0, j = 0;
        vector<bool> is_sorted(N, false);
        for(; j < M; ++j) {
            for(i = 0; i < N - 1; ++i) {
                if(!is_sorted[i] && A[i][j] > A[i + 1][j]) {
                    ++res;
                    break;
                }
            }
            if(i == N - 1) {
                for(i = 0; i < N - 1; ++i) {
                    if(A[i][j] < A[i + 1][j])
                        is_sorted[i] = true;
                }
            }
        }
        return res;
    }
};