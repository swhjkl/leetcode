/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */

// @lc code=start
class LRUCache {
public:
    LRUCache(int capacity): capacity_(capacity) {
    }
    
    int get(int key) {
        auto index_itr = index_.find(key);
        if (index_itr == index_.end()) {
            return -1;
        }
        if (index_itr->second != cache_.begin()) {
            cache_.splice(cache_.begin(), cache_, index_itr->second);
        }
        return (*index_itr->second).second;
    }
    
    void put(int key, int value) {
        auto index_itr = index_.find(key);
        if (index_itr != index_.end()) {
            (*index_itr->second).second = value;
            if (index_itr->second != cache_.begin()) {
                cache_.splice(cache_.begin(), cache_, index_itr->second);
            }
            return;
        }
        cache_.push_front({key, value});
        index_[key] = cache_.begin();
        if (size_ < capacity_) {
            size_++;
        } else {
            key = cache_.back().first;
            index_.erase(key);
            cache_.pop_back();
        }
    }

private:
    std::unordered_map<int, std::list<pair<int,int>>::iterator> index_;
    std::list<pair<int, int>> cache_;
    size_t size_{0};
    size_t capacity_;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end