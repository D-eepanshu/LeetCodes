1class Solution {
2public:
3    int minSubarray(vector<int>& nums, int p) {
4        // Calculate the remainder of the total sum divided by p
5        int totalRemainder = 0;
6        for (int& num : nums) {
7            totalRemainder = (totalRemainder + num) % p;
8        }
9      
10        // If the total sum is already divisible by p, no need to remove any subarray
11        if (totalRemainder == 0) {
12            return 0;
13        }
14      
15        // Hash map to store the last occurrence index of each prefix sum remainder
16        // Key: prefix sum remainder, Value: index
17        unordered_map<int, int> lastIndexMap;
18        lastIndexMap[0] = -1;  // Initialize with remainder 0 at index -1 (before array starts)
19      
20        int n = nums.size();
21        int minLength = n;  // Initialize with array size (worst case: remove entire array)
22        int currentPrefixRemainder = 0;
23      
24        // Iterate through the array to find the minimum length subarray to remove
25        for (int i = 0; i < n; ++i) {
26            // Update current prefix sum remainder
27            currentPrefixRemainder = (currentPrefixRemainder + nums[i]) % p;
28          
29            // Calculate the target remainder we need to find
30            // We need: (currentPrefixRemainder - targetRemainder) % p == totalRemainder
31            // So: targetRemainder = (currentPrefixRemainder - totalRemainder) % p
32            int targetRemainder = (currentPrefixRemainder - totalRemainder + p) % p;
33          
34            // Check if we've seen this target remainder before
35            if (lastIndexMap.count(targetRemainder)) {
36                // Update minimum length if we found a shorter subarray
37                minLength = min(minLength, i - lastIndexMap[targetRemainder]);
38            }
39          
40            // Store the current prefix remainder with its index
41            lastIndexMap[currentPrefixRemainder] = i;
42        }
43      
44        // If minLength is still n, we cannot remove any valid subarray
45        // (cannot remove the entire array), return -1
46        return minLength == n ? -1 : minLength;
47    }
48};
49