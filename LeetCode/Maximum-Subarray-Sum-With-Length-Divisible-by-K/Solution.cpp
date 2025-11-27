1class Solution {
2public:
3    long long maxSubarraySum(vector<int>& nums, int k) {
4        using ll = long long;
5      
6        // Initialize constants
7        const ll INF = 1e18;
8      
9        // minPrefixSum[i] stores the minimum prefix sum seen so far 
10        // for indices with remainder i when divided by k
11        vector<ll> minPrefixSum(k, INF);
12      
13        // Initialize the result with negative infinity
14        ll maxSum = -INF;
15      
16        // Running prefix sum
17        ll prefixSum = 0;
18      
19        // Set minPrefixSum[k-1] = 0 to handle subarrays starting from index 0
20        // This allows selecting subarrays of length k, 2k, 3k, etc. from the beginning
21        minPrefixSum[k - 1] = 0;
22      
23        // Iterate through the array
24        for (int i = 0; i < nums.size(); ++i) {
25            // Update the prefix sum
26            prefixSum += nums[i];
27          
28            // Calculate the maximum subarray sum ending at index i
29            // with length that is a multiple of k
30            // This is done by subtracting the minimum prefix sum at compatible positions
31            maxSum = max(maxSum, prefixSum - minPrefixSum[i % k]);
32          
33            // Update the minimum prefix sum for the current remainder class
34            minPrefixSum[i % k] = min(minPrefixSum[i % k], prefixSum);
35        }
36      
37        return maxSum;
38    }
39};
40