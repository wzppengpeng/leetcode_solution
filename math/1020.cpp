class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum_val = std::accumulate(std::begin(A), std::end(A), 0);
        if(sum_val % 3 != 0) return false;
        auto target = sum_val / 3;
        int count = 0;
        for(auto a : A) {
            count += a;
            if(count == target)
                count = 0;
        }
        return count == 0;
    }
};