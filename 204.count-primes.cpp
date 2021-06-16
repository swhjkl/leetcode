/*
 * @lc app=leetcode id=204 lang=cpp
 *
 * [204] Count Primes
 */

// @lc code=start
class Solution {
public:
    int countPrimes(int n) {
        if (n < 2) {
            return 0;
        }
        vector<bool> nonPrime(n, false);
        for (int i = 2; i <= (int)pow(n, 0.5); i++) {
            if (!nonPrime[i]) {
                for (int j = i * i; j < n; j += i) {
                    nonPrime[j] = true;
                }
            }
        }

        int count = 0;
        for (int i = 2; i < n; i++) {
            count += !nonPrime[i];
        }
        return count;
    }

};
// @lc code=end

