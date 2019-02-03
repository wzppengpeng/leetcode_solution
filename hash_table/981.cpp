/**
 * Create a timebased key-value store class TimeMap, that supports two operations.

1. set(string key, string value, int timestamp)

Stores the key and value, along with the given timestamp.
2. get(string key, int timestamp)

Returns a value such that set(key, value, timestamp_prev) was called previously, with timestamp_prev <= timestamp.
If there are multiple such values, it returns the one with the largest timestamp_prev.
If there are no values, it returns the empty string ("").
 

Example 1:

Input: inputs = ["TimeMap","set","get","get","set","get","get"], inputs = [[],["foo","bar",1],["foo",1],["foo",3],["foo","bar2",4],["foo",4],["foo",5]]
Output: [null,null,"bar","bar",null,"bar2","bar2"]
Explanation:   
TimeMap kv;   
kv.set("foo", "bar", 1); // store the key "foo" and value "bar" along with timestamp = 1   
kv.get("foo", 1);  // output "bar"   
kv.get("foo", 3); // output "bar" since there is no value corresponding to foo at timestamp 3 and timestamp 2, then the only value is at timestamp 1 ie "bar"   
kv.set("foo", "bar2", 4);   
kv.get("foo", 4); // output "bar2"   
kv.get("foo", 5); //output "bar2"   

Example 2:

Input: inputs = ["TimeMap","set","set","get","get","get","get","get"], inputs = [[],["love","high",10],["love","low",20],["love",5],["love",10],["love",15],["love",20],["love",25]]
Output: [null,null,null,"","high","high","low","low"]
 */


/**
 * 使用哈希表加红黑树的复合结构，第一层使用哈希表判断键值，第二层使用红黑树判断时间
 * 使用upper_bound确定返回的迭代器一定是大于所需值的
 */

class TimeMap {
public:
    /** Initialize your data structure here. */
    TimeMap() {
        store_.clear();
    }

    void set(string key, string value, int timestamp) {
        if(store_.count(key)) {
            store_[key].emplace(timestamp, value);
        } else {
            map<int, string> tmp {{timestamp, value}};
            store_.emplace(std::move(key), std::move(tmp));
        }
    }

    string get(string key, int timestamp) {
        if(store_.count(key) == 0) {
            return "";
        } else {
            auto& m = store_[key];
            auto it = m.upper_bound(timestamp);
            return it != m.begin() ? (--it)->second : "";
        }
    }

    unordered_map<string, std::map<int, string>> store_;

};