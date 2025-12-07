1class Solution {
2public:
3    int countPartitions(vector<int>& nums, int k) {
4        const int MOD = 1e9 + 7;
5      
6        // Multiset to maintain elements in current window (sorted)
7        multiset<int> currentWindow;
8      
9        int n = nums.size();
10      
11        // dp[i] = number of ways to partition nums[0...i-1]
12        vector<int> dp(n + 1, 0);
13      
14        // prefixSum[i] = cumulative sum of dp[0] + dp[1] + ... + dp[i]
15        vector<int> prefixSum(n + 1, 0);
16      
17        // Base case: empty array has one way to partition
18        dp[0] = 1;
19        prefixSum[0] = 1;
20      
21        // Left pointer for sliding window
22        int leftPtr = 1;
23      
24        // Process each position as potential end of a partition
25        for (int rightPtr = 1; rightPtr <= n; ++rightPtr) {
26            // Add current element to the window
27            int currentElement = nums[rightPtr - 1];
28            currentWindow.insert(currentElement);
29          
30            // Shrink window from left while range exceeds k
31            // Range = max element - min element in current window
32            while (*currentWindow.rbegin() - *currentWindow.begin() > k) {
33                // Remove the leftmost element from window
34                currentWindow.erase(currentWindow.find(nums[leftPtr - 1]));
35                ++leftPtr;
36            }
37          
38            // Calculate number of valid partitions ending at position rightPtr
39            // This equals sum of dp values for all valid starting positions
40            // Valid starting positions are from leftPtr-1 to rightPtr-1
41            int waysFromValidStarts = prefixSum[rightPtr - 1] - 
42                                      (leftPtr >= 2 ? prefixSum[leftPtr - 2] : 0);
43            dp[rightPtr] = (waysFromValidStarts + MOD) % MOD;
44          
45            // Update prefix sum for next iteration
46            prefixSum[rightPtr] = (prefixSum[rightPtr - 1] + dp[rightPtr]) % MOD;
47        }
48      
49        // Return number of ways to partition the entire array
50        return dp[n];
51    }
52};