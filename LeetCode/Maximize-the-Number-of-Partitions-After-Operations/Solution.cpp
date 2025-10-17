class Solution {
public:
    int maxPartitionsAfterOperations(string s, int k) {
        int n = s.size();
        this->s = &s;
        this->k = k;
        this->n = n;
        
        memo.clear();
        
        return dfs(0, 0, true);
    }
    
private:
    const string* s;
    int k, n;
    unordered_map<long long, int> memo;
    
    int dfs(int idx, int mask, bool canChange) {
        // Base case: reached end of string
        if (idx >= n) {
            return 1;
        }
        
        // Create unique key for memoization
        long long key = ((long long)idx << 32) | (mask << 1) | canChange;
        
        auto it = memo.find(key);
        if (it != memo.end()) {
            return it->second;
        }
        
        int curBit = 1 << ((*s)[idx] - 'a');
        int newMask = mask | curBit;
        
        // Option 1: Don't change current character
        int res;
        if (__builtin_popcount(newMask) > k) {
            // Too many distinct characters, start new partition
            res = dfs(idx + 1, curBit, canChange) + 1;
        } else {
            // Continue with current partition
            res = dfs(idx + 1, newMask, canChange);
        }
        
        // Option 2: Change current character (if allowed)
        if (canChange) {
            // Try all 26 possible characters
            for (int c = 0; c < 26; c++) {
                int replaceBit = 1 << c;
                int testMask = mask | replaceBit;
                
                if (__builtin_popcount(testMask) > k) {
                    // Changing causes overflow, start new partition
                    res = max(res, dfs(idx + 1, replaceBit, false) + 1);
                } else {
                    // Continue with current partition
                    res = max(res, dfs(idx + 1, testMask, false));
                }
            }
        }
        
        return memo[key] = res;
    }
};