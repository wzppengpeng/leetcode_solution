class Solution {
public:
    string removeOuterParentheses(string S) {
        string res; res.reserve(S.size());
        int opened = 0;
        for(auto ch : S) {
            if(ch == '(' && opened++ > 0)
                res.push_back(ch);
            else if(ch == ')' && --opened > 0)
                res.push_back(ch);
        }
        return res;
    }
};
