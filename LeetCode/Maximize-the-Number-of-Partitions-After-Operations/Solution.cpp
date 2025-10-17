class Solution {
public:
    int maxPartitionsAfterOperations(string s, int k) {
        n = s.size();
        this->s = s;
        this->k = k;
        
        memo.clear();
        memo.reserve(n * 128);
        
        return dfs(0, 0, 1);
    }
    
private:
    string s;
    int n, k;
    unordered_map<long long, int> memo;
    
    inline int dfs(int idx, int mask, int canChange) {
        if (idx >= n) return 1;
        
        long long key = ((long long)idx << 32) | ((long long)mask << 1) | canChange;
        
        auto it = memo.find(key);
        if (it != memo.end()) return it->second;
        
        int curBit = 1 << (s[idx] - 'a');
        int newMask = mask | curBit;
        
        // Don't change current character
        int res = (__builtin_popcount(newMask) > k) ? 
                  dfs(idx + 1, curBit, canChange) + 1 : 
                  dfs(idx + 1, newMask, canChange);
        
        // Try changing if allowed
        if (canChange) {
            // Try all 26 characters
            for (int c = 0; c < 26; c++) {
                int bit = 1 << c;
                int testMask = mask | bit;
                
                int val = (__builtin_popcount(testMask) > k) ?
                          dfs(idx + 1, bit, 0) + 1 :
                          dfs(idx + 1, testMask, 0);
                
                if (val > res) res = val;
            }
        }
        
        return memo[key] = res;
    }
};