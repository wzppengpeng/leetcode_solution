/**
 * We have an array A of integers, and an array queries of queries.

For the i-th query val = queries[i][0], index = queries[i][1], we add val to A[index].  Then, the answer to the i-th query is the sum of the even values of A.

(Here, the given index = queries[i][1] is a 0-based index, and each query permanently modifies the array A.)

Return the answer to all queries.  Your answer array should have answer[i] as the answer to the i-th query.


 */


/**
 * 使用一个数先记录偶数和，然后根据A[i]是否偶数以及val是否偶数进行分别判断
 */


class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        vector<int> res; res.reserve(queries.size());
        int even_res = 0;
        for(auto a : A) {
            if((a % 2) == 0)
                even_res += a;
        }
        for(auto& query : queries) {
            int val = query[0], index = query[1];
            if(A[index] % 2 == 0) {
                if(val % 2 == 0) {
                    even_res += val;
                } else {
                    even_res -= A[index];
                }
            } else {
                if(val % 2) {
                    even_res += (A[index] + val);
                }
            }
            A[index] += val;
            res.emplace_back(even_res);
        }
        return res;
    }
};