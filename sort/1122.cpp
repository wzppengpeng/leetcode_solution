/**
 * Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all elements in arr2 are also in arr1.

Sort the elements of arr1 such that the relative ordering of items in arr1 are the same as in arr2.  Elements that don't appear in arr2 should be placed at the end of arr1 in ascending order.


Example 1:

Input: arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
Output: [2,2,2,1,4,3,3,9,6,7,19]
 */


/**
 * 整体先对第二个数组的结构进行转换，然后依据在第二个结构中的顺序进行排序
 */


class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> val_to_idx;
        for(int i = 0; i < arr2.size(); ++i) {
            val_to_idx[arr2[i]] = i;
        }
        vector<int> res(arr1);
        sort(begin(res), end(res), [&](int left, int right) {
            if(val_to_idx.count(left) && val_to_idx.count(right)) {
                return val_to_idx[left] < val_to_idx[right];
            } else if(val_to_idx.count(left) && val_to_idx.count(right) == 0) {
                return true;
            } else if(val_to_idx.count(left) == 0 && val_to_idx.count(right)) {
                return false;
            } else {
                return left < right;
            }
        });
        return res;
    }
};