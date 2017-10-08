/**
 * Given two strings A and B, find the minimum number of times A has to be repeated such that B is a substring of it. If no such solution, return -1.

For example, with A = "abcd" and B = "cdabcdab".

Return 3, because by repeating A three times (“abcdabcdabcd”), B is a substring of it; and B is not a substring of A repeated two times ("abcdabcd").
 */

class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int i = 0, j = 0, count = 1;
        while(j < B.size()){
            while(i < A.size() && A[i] != B[j]) i++;
            if(i == A.size() || count > 1) return -1;
            while(j < B.size() && A[i++] == B[j++]){
                if(j == B.size()) return count;
                if(i == A.size()) i = 0, count++;
            }
            j = 0;
        }
    }
};