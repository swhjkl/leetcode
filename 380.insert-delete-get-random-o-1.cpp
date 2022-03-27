/*
 * @lc app=leetcode id=380 lang=cpp
 *
 * [380] Insert Delete GetRandom O(1)
 */

// @lc code=start
class RandomizedSet {
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (indice.find(val) != indice.end()) {
            return false;
        }
        indice[val] = values.size();
        values.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        auto itr = indice.find(val);
        if (itr == indice.end()) {
            return false;
        }
        auto tail = values.back();
        auto tail_itr = indice.find(tail);
        tail_itr->second = itr->second;
        values[itr->second] = tail;
        values.pop_back();
        indice.erase(itr);
        return true;
    }
    
    int getRandom() {
        return values[rand() % values.size()];
    }

private:
    vector<int> values;
    unordered_map<int, size_t> indice;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end

