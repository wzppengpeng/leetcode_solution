/**
 * An array is monotonic if it is either monotone increasing or monotone decreasing.

An array A is monotone increasing if for all i <= j, A[i] <= A[j].  An array A is monotone decreasing if for all i <= j, A[i] >= A[j].

Return true if and only if the given array A is monotonic.
 */

class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int state = 0;
        for(size_t i = 1; i < A.size(); ++i) {
            if(A[i] == A[i - 1]) continue;
            else if(A[i] > A[i - 1]) {
                if(state == 0) state = 1;
                else if(state == -1) return false;
            } else {
                if(state == 0) state = -1;
                else if(state == 1) return false;
            }
        }
        return true;
    }
};