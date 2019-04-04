class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool> res; res.reserve(A.size());
        int num = 0;
        for(auto a : A) {
            num = ((num << 1) + a) % 5;
            res.push_back(!num);
        }
        return res;
    }
};