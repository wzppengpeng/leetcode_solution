class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> res(A.size());
        size_t i = 0, j = A.size() - 1;
        for(size_t k = 0; k < A.size(); ++k) {
            if(is_even(A[k])) res[i++] = A[k];
            else res[j--] = A[k];
        }
        return res;
    }

    inline bool is_even(int a) const {
        return (a & 1) == 0;
    }
};