/*
 * @lc app=leetcode id=341 lang=cpp
 *
 * [341] Flatten Nested List Iterator
 */

// @lc code=start
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for(auto ritr = nestedList.rbegin(); ritr != nestedList.rend(); ritr++) {
            s.push(&(*ritr));
        }
    }
    
    int next() {
        auto n = s.top();
        s.pop();
        return n->getInteger();
    }
    
    bool hasNext() {
        while (!s.empty()) {
            auto n = s.top();
            if (n->isInteger()) {
                return true;
            }
            s.pop();
            auto &l = n->getList();
            for(auto ritr = l.rbegin(); ritr != l.rend(); ritr++) {
                s.push(&(*ritr));
            }
        }
        return false;
    }

private:
    stack<NestedInteger*> s;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
// @lc code=end

