/**
 * A website domain like "discuss.leetcode.com" consists of various subdomains. At the top level, we have "com", at the next level, we have "leetcode.com", and at the lowest level, "discuss.leetcode.com". When we visit a domain like "discuss.leetcode.com", we will also visit the parent domains "leetcode.com" and "com" implicitly.

Now, call a "count-paired domain" to be a count (representing the number of visits this domain received), followed by a space, followed by the address. An example of a count-paired domain might be "9001 discuss.leetcode.com".

We are given a list cpdomains of count-paired domains. We would like a list of count-paired domains, (in the same format as the input, and in any order), that explicitly counts the number of visits to each subdomain.

Example 1:
Input: 
["9001 discuss.leetcode.com"]
Output: 
["9001 discuss.leetcode.com", "9001 leetcode.com", "9001 com"]
Explanation: 
We only have one website domain: "discuss.leetcode.com". As discussed above, the subdomain "leetcode.com" and "com" will also be visited. So they will all be visited 9001 times.

Example 2:
Input: 
["900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"]
Output: 
["901 mail.com","50 yahoo.com","900 google.mail.com","5 wiki.org","5 org","1 intel.mail.com","951 com"]
 */

/**
 * 解析+哈希表记录的过程
 */

class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        vector<string> res;
        if(cpdomains.empty()) return res;
        for(auto& str : cpdomains) {
            auto p = parse(str);
            split(p.second, p.first);
        }
        gen_res(res);
        return res;
    }

    unordered_map<string, int> counter_;

    pair<int, string> parse(const string& str) {
        auto i = str.find_first_of(' ');
        return std::make_pair(std::stoi(str.substr(0, i)), str.substr(i + 1));
    }

    void split(const string& domain, int cnt) {
        add_count(domain, cnt);
        size_t i = domain.find_first_of('.');
        while(i != string::npos) {
            add_count(domain.substr(i + 1), cnt);
            i = domain.find_first_of('.', i + 1);
        }
    }

    inline void add_count(const string& d, int cnt) {
        if(counter_.count(d)) counter_[d] += cnt;
        else counter_.emplace(d, cnt);
    }

    void gen_res(vector<string>& res) {
        for(auto& p : counter_) {
            string s = std::to_string(p.second) + " " + p.first;
            res.emplace_back(std::move(s));
        }
    }
};