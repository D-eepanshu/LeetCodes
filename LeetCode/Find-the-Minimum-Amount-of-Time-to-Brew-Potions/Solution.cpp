class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size();
        int m = mana.size();
        vector<long long> dp(n, 0LL);
        // dp[i] means: for the current potion, the finish time of wizard i
        
        for (int j = 0; j < m; ++j) {
            long long x = mana[j];
            // First forward pass:
            for (int i = 0; i < n; ++i) {
                long long timeNeeded = (long long)skill[i] * x;
                if (i > 0) {
                    dp[i] = max(dp[i], dp[i - 1]);
                }
                dp[i] += timeNeeded;
            }
            // Then backward pass to “push back” any wizard starting too early
            for (int i = n - 2; i >= 0; --i) {
                long long timeNeededNext = (long long)skill[i + 1] * x;
                // We adjust dp[i] so that wizard i+1 doesn’t have idle waiting
                long long desired = dp[i + 1] - timeNeededNext;
                dp[i] = max(dp[i], desired);
            }
        }
        return dp[n - 1];
    }
};
