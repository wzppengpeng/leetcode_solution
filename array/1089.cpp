/**
 * Given a fixed length array arr of integers, duplicate each occurrence of zero, shifting the remaining elements to the right.

Note that elements beyond the length of the original array are not written.

Do the above modifications to the input array in place, do not return anything from your function.



Example 1:

Input: [1,0,2,3,0,4,5,0]
Output: null
Explanation: After calling your function, the input array is modified to: [1,0,0,2,3,0,0,4]
 */


/**
 * 该问题只要求了空间复杂度，并没有要求时间复杂度，因此可以进行on^2的方法进行解决
 */

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        auto N = arr.size();
        for(size_t i = 0; i < N; ++i) {
            if(arr[i] == 0) {
                insert_one_zero(arr, 0, i + 1, N);
                ++i;
            }
        }
    }

    void insert_one_zero(vector<int>& arr, int val, size_t start, size_t end) {
        if(start >= end) return;
        int tmp = arr[start];
        arr[start] = val;
        insert_one_zero(arr, tmp, start + 1, end);
    }
};