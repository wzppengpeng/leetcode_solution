/**
 * Given a binary matrix A, we want to flip the image horizontally, then invert it, and return the resulting image.

To flip an image horizontally means that each row of the image is reversed.  For example, flipping [1, 1, 0] horizontally results in [0, 1, 1].

To invert an image means that each 0 is replaced by 1, and each 1 is replaced by 0. For example, inverting [0, 1, 1] results in [1, 0, 0].
 */

/**
 * 调两个STL函数进行解决
 */

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        vector<vector<int>> res(A);
        for(auto& row : res) {
            std::reverse(std::begin(row), std::end(row));
            std::for_each(std::begin(row), std::end(row),
                [](int& val) { val = 1 - val; });
        }
        return res;
    }
};