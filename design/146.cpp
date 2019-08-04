/**
 * Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

Follow up:
Could you do both operations in O(1) time complexity?

Example:

LRUCache cache = new LRUCache( 2 );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4
 */

/**
 * 使用双向链表加哈希表来实现
 */

struct Node
{
    int key;
    Node* next;
    Node* pre;
    Node(int k) : key(k), next(nullptr), pre(nullptr) {}
};

class List {
public:
    List(int capacity) : capacity_(capacity) {}

    void update(int key) {
        auto* node = locs_[key];
        if(node == tail_) return;
        if(node == head_) {
            head_->next->pre = nullptr;
            head_ = head_->next;
            tail_->next = node;
            node->pre = tail_;
            tail_ = node;
        } else {
            node->pre->next = node->next;
            node->next->pre = node->pre;
            tail_->next = node;
            node->pre = tail_;
            tail_ = node;
        }
    }

    int push(int key) {
        // create the nodes
        if(locs_.count(key)) {
            update(key);
            return -1;
        }
        Node* tmp = new Node(key);
        locs_[key] = tmp;
        // add the node to list
        if(tail_) {
            tail_->next = tmp;
            tmp->pre = tail_;
        }
        tail_ = tmp;
        if(!head_) head_ = tmp;
        if(++size_ <= capacity_) return -1;
        else {
            auto* del = head_;
            head_ = head_->next;
            head_->pre = nullptr;
            auto return_key = del->key;
            locs_.erase(return_key);
            delete del;
            del = nullptr;
            return return_key;
        }
    }

private:
    int size_ = 0;
    int capacity_;
    Node* head_ = nullptr;
    Node* tail_ = nullptr;
    unordered_map<int, Node*> locs_;
};


class LRUCache {
public:
    LRUCache(int capacity) : capacity_(capacity), list_(capacity)
    {
    }

    int get(int key) {
        if(capacity_ == 0) return -1;
        int val;
        if(hashmap_.count(key)) {
            list_.update(key);
            val = hashmap_[key];
        } else {
            val = -1;
        }
        return val;
    }

    void put(int key, int value) {
        if(capacity_ == 0) return;
        if(hashmap_.count(key)) {
            hashmap_[key] = value;
            list_.push(key);
        } else {
            hashmap_.emplace(key, value);
            auto erase_key = list_.push(key);
            if(erase_key > 0) hashmap_.erase(erase_key);
        }
    }


private:
    int capacity_;
    List list_;
    unordered_map<int, int> hashmap_;
};