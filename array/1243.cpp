/**
 * Given an initial array arr, every day you produce a new array using the array of the previous day.

On the i-th day, you do the following operations on the array of day i-1 to produce the array of day i:

If an element is smaller than both its left neighbor and its right neighbor, then this element is incremented.
If an element is bigger than both its left neighbor and its right neighbor, then this element is decremented.
The first and last elements never change.
After some days, the array does not change. Return that final array.
 */

/**
 * 暴力法
 */

class Solution {
public:
    vector<int> transformArray(vector<int>& arr) {
        bool flag=true;
        while (flag) {
            vector<int> tmp(arr);
            flag = false;
            for (int i=1;i<arr.size()-1;i++) {
                if (arr[i] > arr[i-1] && arr[i] > arr[i+1]) {
                    tmp[i]--;
                    flag=true;
                }
                else if (arr[i] < arr[i-1] && arr[i] < arr[i+1]) {
                    tmp[i]++;
                    flag=true;
                }
            }
            arr = tmp;
        }
        return arr;
    }
};